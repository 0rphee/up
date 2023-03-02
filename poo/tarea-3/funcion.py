
def duracionDisco(disco: dict):
    total = 0
    for cancion in disco.values():
        total += int(cancion["duracion_ms"])
    return total
