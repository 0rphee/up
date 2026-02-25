import sys
from collections import Counter

def analizar_archivo(ruta_archivo: str):
    passwords: list[str] = []
    
    try:
        with open(ruta_archivo, 'r', encoding='utf-8') as f:
            for linea in f:
                linea = linea.strip()
                # Extraer contenido después de ?:
                if linea.startswith('?:'):
                    pwd = linea.split('?:')[-1].strip()
                    if pwd:  # Solo agregar si no está vacío
                        passwords.append(pwd)
    except FileNotFoundError:
        print(f"Error: El archivo '{ruta_archivo}' no existe.")
        return

    if not passwords:
        print("No se encontraron contraseñas válidas en el formato '?:password'")
        return

    total = len(passwords)
    conteo = Counter(passwords)

    # Reporrte
    print("-" * 50)
    print(f"ANÁLISIS DE SEGURIDAD: {ruta_archivo}")
    print("-" * 50)
    print(f"Total de passwords procesados: {total}")
    print(f"Passwords únicos: {len(conteo)}")
    print("\nTOP 10 CONTRASEÑAS MÁS REPETIDAS:")
    print(f"{'Password':<25} | {'Frecuencia':<10}")
    print("-" * 40)
    for pwd, freq in conteo.most_common(10):
        print(f"{pwd:<25} | {freq:<10}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Uso: python3 analysis.py nombre_del_archivo.txt")
    else:
        analizar_archivo(sys.argv[1])