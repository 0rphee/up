import sys
from collections import Counter

def analizar_hashes(archivo_entrada: str):
    hashes: list[str] = []
    
    try:
        with open(archivo_entrada, 'r') as f:
            for linea in f:
                # Limpiar espacios y saltos de línea
                h = linea.strip().lower()
                # Validar que sea un hash hexadecimal de 32 caracteres (MD5/NTLM)
                if len(h) == 32 and all(c in '0123456789abcdef' for c in h):
                    hashes.append(h)
    except FileNotFoundError:
        print(f"Error: El archivo '{archivo_entrada}' no existe.")
        return

    if not hashes:
        print("No se encontraron hashes válidos de 32 caracteres.")
        return

    total = len(hashes)
    conteo = Counter(hashes)
    unicos = len(conteo)
    duplicados = total - unicos

    # --- Reporte ---
    print("="*50)
    print(f"ANÁLISIS DE ESTRUCTURA DE HASHES: {archivo_entrada}")
    print("="*50)
    print(f"Total de hashes procesados: {total}")
    print(f"Hashes únicos: {unicos}")
    print(f"Hashes repetidos: {duplicados} ({(duplicados/total)*100:.1f}%)")
    print("-"*50)
    
    if duplicados > 0:
        print("TOP 10 HASHES MÁS REPETIDOS (Cuentas con misma clave):")
        print(f"{'Hash':<35} | {'Repeticiones':<12}")
        print("-"*50)
        for h, freq in conteo.most_common(10):
            if freq > 1:
                print(f"{h:<35} | {freq:<12}")
    else:
        print("No se encontraron contraseñas compartidas. ¡Buena señal de entropía!")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Uso: python3 hash_analyzer.py Manuel_hashes.txt")
    else:
        analizar_hashes(sys.argv[1])
