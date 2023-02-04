'''
1) Imprimir la frase "Efren es alumno del curso de Python"
'''
alumnos = ['Efren','Sara', 'Carlos','Garza']

print(alumnos[0] + " es alumno del curso de Python")

'''
2) Crear una lista donde el dato 0 sea el nombre de usuario y el dato 1 sea su edad. 
Los datos deben recolectarse usando "input", la edad debe guardarse como un entero dentro de la lista
Imprimir estructura resultante
'''

usuario = [input("Ingrese el nombre del usuario: "), int(input("Ingrese la edad del usuario"))]

print(usuario)

'''
3) De la lista anterior, cambiar la edad por el doble de su valor. Imprimir estructura resultante
'''

usuario[1] = usuario[1] * 2

print(usuario)

'''
4) Indicar cuantos nombres unicos de alumnos existen en la siguiente estructura de datos
'''
alumnos2 = ['Oscar', 'Daniel',' Amiel', 'Alejandra', 'Danna', 'Daniel', 'Danna','Adrian',' Amiel', 
'Danna', 'Daniel',' Amiel',' Amiel', 'Danna','Oscar','Ivan', 'Diego', 'Daniel']

print(len(set(alumnos2)), " nombres únicos en 'alumnos2'")

'''
5) Cambiar "Velma" por "The Last of Us" en la siguiente estructura de datos
'''
los_mejores_shows = ('House of the Dragon', 'Rick & Morty', 'Celebrity Deathmatch', 'Velma')

los_mejores_shows = list(los_mejores_shows)
los_mejores_shows[-1] = "The Last of Us"
print(tuple(los_mejores_shows))


'''
6) Imprimir la frase "La alumna Alejandra tiene 9 de promedio
'''
estudiantes = [('Oscar',9),('Alejandra',9),('Ivan',7)]

nom, prom = estudiantes[1]
print(f"La alumna {nom} tiene {prom} de promedio")

'''
7) Imprimir la frase "El Alumno Oscar esta inscrito en Animacion 101
'''
estudiantes2 = [('Oscar',['Animacion 101','Finanzas']),
('Alejandra',['Matematicas Avanzadas','Hackeo Avanzado']),
('Ivan',['Memelogia','Como entrenar a tu dragon'])]

nom1, materias = estudiantes2[0]
print(f"El alumno {nom1} esta inscrito en {materias[0]}")

'''
8) Cambiar la materia "Memelogia" a "Teoria Sonidera Aplicada". Imprimir estructura resultante
'''
estudiantes2 = [('Oscar',['Animacion 101','Finanzas']),
('Alejandra',['Matematicas Avanzadas','Hackeo Avanzado']),
('Ivan',['Memelogia','Como entrenar a tu dragon'])]

iv = list(estudiantes2[2])
iv[1][0] = "Teoría Sonidera Aplicada"
estudiantes2[2] = tuple(iv)
print(estudiantes2)

