
#1 De la siguiente lista, imprima el resultado de elevar cada elemento al cuadrado:
mi_lista = [1,3,9,7,11]
for i in mi_lista:
    print(i**2)

print()

#2 De la siguiente lista, imprima el resultado de elevar cada elemento al cuadrado:
mi_lista_2 = [1,'3',9,'7','11']
for i in mi_lista_2:
    print(int(i)**2)

print()
#3 De la siguiente lista, imprima el resultado de elevar cada elemento al cuadrado. Solo castear 
# tipo de datos cuando se requiera. No castear todo el tiempo
mi_lista_2 = [1,'3',9,'7','11']
for i in mi_lista_2:
    if type(i) != int:
        i = int(i)
    print(i**2)

print()
#4 Recorrer con un for la siguiente lista de nombres, imprimir "Hola nombre_en_la lista" por cada nombre
nombres =['Cheems','Cholondrina','Medio Metro']
for nombre in nombres:
    print(f"Hola {nombre}")

print()
#5 Pedir al usuario un valor inicial, un valor final y el tipo de cambio
# Realizar un conversor de divisas donde se imprima el resultado de multiplicar desde al valor
# inicial al valor final por el tipo de cambio.
# Ejemplo, si el valor inicial es 1 y el final es 3, con un tipo de cambio de 10, debera mostrarse:
# 1 dolar son 10 pesos
# 2 dolar son 20 pesos
# 3 dolares son 30 pesos

inicial = int(input("Ingrese el valor inicial para la conversión: "))
final = int(input("Ingrese el valor final para la conversión: "))
cambio = int(input("Ingrese el tipo de cambio: "))

for i in range(inicial, final+1):
    print(f"{i} dólar son {i*cambio} pesos")
    

print()
#6 Pedir al usuario un valor inicial y un valor final, devolver una lista con un rango de valores
# entre esos numeros que contenga el valor al cubo de los mismos, por ejemplo, si 1 es inicial y 
#3 es final, la lista resultante debe ser [1,8,27]

ini = int(input("Ingrese el límite inferior para la lista: "))
fin = int(input("Ingrese el límite superior para la lista: "))

lista = [i**3 for i in range(ini, fin+1)]

print(lista)
