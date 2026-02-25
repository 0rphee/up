import time
import logging
from flask import Flask, request, render_template_string

# logger
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)

app = Flask(__name__)

# bd simulada
USERS = {"admin": "secreto123"}

# diccionario para almacenar intentos fallidos y bloqueos
# formato: { "usuario": {"intentos": int, "bloqueado_hasta": float} }
LOGIN_ATTEMPTS = {}
MAX_ATTEMPTS: int = 5
LOCKOUT_TIME = 300  # 5 minutos en segundos

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
        <button type="submit">Entrar</button>
    </form>
    <br>
</body>
</html>
"""

@app.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        return render_template_string(LOGIN_HTML)
    
    username = request.form.get('username')
    password = request.form.get('password')
    current_time = time.time()
    
    # iniciar egistro del usuario si no existe
    if username not in LOGIN_ATTEMPTS:
        LOGIN_ATTEMPTS[username] = {"intentos": 0, "bloqueado_hasta": 0}
        
    user_data = LOGIN_ATTEMPTS[username]
    
    # comprobar que usuario no este en timeout
    if current_time < user_data["bloqueado_hasta"]:
        tiempo_restante = int(user_data["bloqueado_hasta"] - current_time)
        logging.warning(f"[BLOQUEO] Intento de acceso rechazado para '{username}'. Bloqueado por {tiempo_restante}s más.")
        return render_template_string(
            LOGIN_HTML, 
            error=f"Usuario bloqueado temporalmente por demasiados intentos fallidos. Intente de nuevo en {tiempo_restante} segundos."
        ), 403

    # credenciales
    if USERS.get(username) == password:  # pyright: ignore[reportArgumentType]
        # Éxito: limpiar el historial de fallos
        user_data["intentos"] = 0
        user_data["bloqueado_hasta"] = 0
        logging.info(f"[ÉXITO] El usuario '{username}' ha iniciado sesión correctamente.")
        return "<h3>¡Login Exitoso! Bienvenido.</h3>"
    else:
        # fallo de autenticacion
        user_data["intentos"] += 1
        intentos_restantes: int = MAX_ATTEMPTS - user_data["intentos"]
        
        logging.warning(f"[FALLO] Credenciales incorrectas para '{username}'. Intento {user_data['intentos']}/{MAX_ATTEMPTS}.")
        
        # 3. Aplicar timeout si llega al límite
        if user_data["intentos"] >= MAX_ATTEMPTS:
            user_data["bloqueado_hasta"] = current_time + LOCKOUT_TIME
            logging.error(f"[TIMEOUT] El usuario '{username}' ha sido bloqueado por 5 minutos.")
            return render_template_string(LOGIN_HTML, error="Demasiados intentos fallidos. Cuenta bloqueada por 5 minutos."), 403
            
        return render_template_string(LOGIN_HTML, error=f"Credenciales incorrectas. Te quedan {intentos_restantes} intentos."), 401


if __name__ == '__main__':
    logging.info("Servidor iniciando en http://127.0.0.1:5000")
    app.run(debug=True)