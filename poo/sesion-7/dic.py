alumnos = [
    {
        'nombre': 'El cheems',
        'calificacion': 89
    },
    {
        'nombre': 'Medio metro',
        'calificacion': 70
    },
    {
        'nombre': 'Chabelo',
        'calificacion': 100
    }
]

prom = sum([alumno["calificacion"] for alumno in alumnos])/len(alumnos)
print(prom)


nomAlumns = [alumno["nombre"] for alumno in alumnos]
print(nomAlumns)

