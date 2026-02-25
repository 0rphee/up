import time
import logging
import pyotp
import qrcode
import io
import base64
from flask import Flask, request, render_template_string

# Configurar logger
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)

app = Flask(__name__)

# Base de datos simulada (ahora incluye el secreto 2FA)
USERS = {
    "admin": {
        "password": "secreto123",
        "2fa_secret": None  # Se llenará al generar el QR
    }
}

# Registro de intentos fallidos y bloqueos
LOGIN_ATTEMPTS: dict[str, dict[str, float]] = {}
MAX_ATTEMPTS = 5
LOCKOUT_TIME = 300  # 5 minutos en segundos

# --- PLANTILLAS HTML ---

LOGIN_HTML = """
<!DOCTYPE html>
<html>
<head><title>Login</title></head>
<body>
    <h2>Iniciar Sesión</h2>
    {% if error %}<p style="color:red;">{{ error }}</p>{% endif %}
    <form method="POST" action="/">
        <label>Usuario:</label><br>
        <input type="text" name="username" required><br><br>
        <label>Contraseña:</label><br>
        <input type="password" name="password" required><br><br>
        <label>Código 2FA (6 dígitos):</label><br>
        <input type="text" name="totp_code" pattern="[0-9]{6}" title="Debe ser un código de 6 números"><br><br>
        <button type="submit">Entrar</button>
    </form>
    <br>
    <a href="/generar-2fa">Generar código QR para Google Authenticator</a>
</body>
</html>
"""

QR_FORM_HTML = """
<!DOCTYPE html>
<html>
<head><title>Generar 2FA</title></head>
<body>
    <h2>Generar QR para 2FA</h2>
    <form method="POST" action="/generar-2fa">
        <label>Usuario asociado (ej. admin):</label><br>
        <input type="text" name="username" required><br><br>
        <label>Ingresa tu correo electrónico:</label><br>
        <input type="email" name="email" required><br><br>
        <button type="submit">Generar QR</button>
    </form>
    <br>
    <a href="/">Volver al Login</a>
</body>
</html>
"""

QR_RESULT_HTML = """
<!DOCTYPE html>
<html>
<head><title>Google Authenticator QR</title></head>
<body>
    <h2>Autenticación 2FA para {{ email }}</h2>
    <p>Escanea este código QR para Google Authenticator:</p>
    <img src="data:image/png;base64,{{ img_b64 }}" alt="QR Code">
    <p>O ingresa el código secreto manualmente: <strong>{{ secret }}</strong></p>
    <br>
    <a href="/generar-2fa">Generar otro QR</a> | <a href="/">Volver al Login</a>
</body>
</html>
"""

# --- RUTAS ---

@app.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        return render_template_string(LOGIN_HTML)
    
    username: str = request.form.get('username')  # pyright: ignore[reportAssignmentType]
    password: str = request.form.get('password')  # pyright: ignore[reportAssignmentType]
    totp_code: str = request.form.get('totp_code') # pyright: ignore[reportAssignmentType]
    current_time = time.time()
    
    # registro
    if username not in LOGIN_ATTEMPTS:
        LOGIN_ATTEMPTS[username] = {"intentos": 0, "bloqueado_hasta": 0}
        
    user_data = LOGIN_ATTEMPTS[username]
    
    # bloqueo
    if current_time < user_data["bloqueado_hasta"]:
        tiempo_restante = int(user_data["bloqueado_hasta"] - current_time)
        logging.warning(f"[BLOQUEO] Intento rechazado para '{username}'. Bloqueado {tiempo_restante}s.")
        return render_template_string(
            LOGIN_HTML, 
            error=f"Usuario bloqueado temporalmente. Intente en {tiempo_restante} segundos."
        ), 403

    # validar
    user_record = USERS.get(username)
    
    if user_record and user_record["password"] == password:
        # Verificar 2FA si está configurado para el usuario
        if user_record.get("2fa_secret"):
            totp = pyotp.TOTP(user_record["2fa_secret"])
            if not totp_code or not totp.verify(totp_code):
                return render_template_string(LOGIN_HTML, error="Código 2FA incorrecto o no proporcionado."), 401
                
        user_data["intentos"] = 0
        user_data["bloqueado_hasta"] = 0
        logging.info(f"[ÉXITO] Sesión iniciada: '{username}'.")
        return "<h3>¡Login Exitoso! Bienvenido.</h3>"
    else:
        user_data["intentos"] += 1
        intentos_restantes = MAX_ATTEMPTS - user_data["intentos"]
        logging.warning(f"[FALLO] Credenciales incorrectas '{username}'. Intento {user_data['intentos']}/{MAX_ATTEMPTS}.")
        
        # Aplicar timeout si corresponde
        if user_data["intentos"] >= MAX_ATTEMPTS:
            user_data["bloqueado_hasta"] = current_time + LOCKOUT_TIME
            logging.error(f"[TIMEOUT] Usuario '{username}' bloqueado por 5 minutos.")
            return render_template_string(LOGIN_HTML, error="Demasiados intentos. Cuenta bloqueada 5 minutos."), 403
            
        return render_template_string(LOGIN_HTML, error=f"Credenciales incorrectas. Intentos restantes: {intentos_restantes}."), 401


@app.route('/generar-2fa', methods=['GET', 'POST'])
def generate_2fa():
    if request.method == 'GET':
        return render_template_string(QR_FORM_HTML)
    
    username: str = request.form.get('username') # pyright: ignore[reportAssignmentType]
    email: str = request.form.get('email', 'usuario@miapp.com')
    
    if username not in USERS:
         return render_template_string(QR_FORM_HTML) + "<p style='color:red;'>Usuario no encontrado.</p>"

    # Generar secreto y guardarlo en la DB simulada
    secret = pyotp.random_base32()
    USERS[username]["2fa_secret"] = secret
    
    totp = pyotp.TOTP(secret)
    provisioning_uri = totp.provisioning_uri(name=email, issuer_name="MiAppSegura")

    # crear QR
    qr = qrcode.make(provisioning_uri)
    buf = io.BytesIO()
    qr.save(buf, format="PNG")  # pyright: ignore[reportCallIssue]
    img_b64 = base64.b64encode(buf.getvalue()).decode('utf-8')

    logging.info(f"QR 2FA generado y guardado para el usuario {username} ({email}).")

    return render_template_string(QR_RESULT_HTML, img_b64=img_b64, secret=secret, email=email)


if __name__ == '__main__':
    logging.info("Servidor iniciando en http://127.0.0.1:5000")
    app.run(debug=True)