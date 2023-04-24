'''
Comenzando en Python
------------------------------------------------------------------------------------------------------------------------------------
Anotaciónes de clase:
------------------------------------------------------------------------------------------------------------------------------------
Operadores:
------------------------------------------------------------------------------------------------------------------------------------

Operatoros aritmeticos:

suma            ->  +
resta           ->  -    
multiplicación  ->  *
división        ->  /
potencia        ->  **
residuo         ->  %
floor division  ->  //
------------------------------------------------------------------------------------------------------------------------------------
Operadores logicos:

Igual a         ->  ==
Mayor a         ->  >
Menor a         ->  <
Mayor igual a   ->  >=
Menor igual a   ->  <=
Diferente a     ->  !=
------------------------------------------------------------------------------------------------------------------------------------
Variables:

int

float

string

bool

------------------------------------------------------------------------------------------------------------------------------------
Comandos:

print()     # Imprime un texto

    print(f"Hola" {Nombre})

input("")   # El usuario ingresa un string 

type()      # Nos da el tipo de dato de una variable

StringMayusculas = N.upper
StringMinusculas = N.lower
StringCapitalizado = N.capitalize
StringCapitalizado = N.title
StringCapitalizado = N.swapcase

------------------------------------------------------------------------------------------------------------------------------------
Operadores con strings:

in                  // nos dicen si existe un string dentro de otro
not in              // nos dicen si no existe un string dentro de otro

String.count("")           // cuenta la cantidad de veces que se repite un string
String.replace("","")      // remplaza un string con otro
String.find("")            // nos dice en que indice se encuentra un string
String.index("")           // nos dice en que indice se encuentra un string
String.split("")           // separa un string en base a un caracter
String.join("")            // une un string con otro
String.strip()             // elimina los espacios en blanco de un string
String.lstrip()            // elimina los espacios en blanco de un string a la izquierda
String.rstrip()            // elimina los espacios en blanco de un string a la derecha
String.startswith("")      // nos dice si un string empieza con un caracter
String.endswith("")        // nos dice si un string termina con un caracter
String.isalpha()           // nos dice si un string es alfabético
String.isalnum()           // nos dice si un string es alfanumérico
String.isdigit()           // nos dice si un string es numérico
String.islower()           // nos dice si un string esta en minusculas
String.isupper()           // nos dice si un string esta en mayusculas
String.istitle()           // nos dice si un string esta capitalizado
String.isnumeric()         // nos dice si un string es numerico
String.isdecimal()         // nos dice si un string es decimal
String.isidentifier()      // nos dice si un string es un identificador
String.isprintable()       // nos dice si un string es imprimible
String.isascii()           // nos dice si un string es ascii
String.isdecimal()         // nos dice si un string es decimal

------------------------------------------------------------------------------------------------------------------------------------
Estructuras de datos:
------------------------------------------------------------------------------------------------------------------------------------
String:

Los strings son estructuras, o sea cadena de caracteres y cada caracter es una casilla.
sin embargo son inmutables y se pueden repetir elementos // String[0] = "A" -> No sirve NO se puden cambiar sus elementos

String = "Shrek es amor"
String2 = "Hola" + String[0:5] // esto toma las primeras 5 casillas y le agrega "Hola"  sin considerar la ultima casilla o sea realmente solo 4
                         [-5:] // si usamos indices negativos seleccina las casillas pero en sentido contrario.

------------------------------------------------------------------------------------------------------------------------------------
Estructuras "formales":
------------------------------------------------------------------------------------------------------------------------------------
Listas:

Estructura de datos ordenada y mutable y se pueden repetir elementos // se puden cambiar sus elementos

Lista = ["Casilla 0","Casilla 1","Casilla 2"]

Lista2 = ["1","2",Lista]   ó   Lista2 = ["1","2",["Casilla 0","Casilla 1","Casilla 2"]]

print(Lista2[2][1])  // esto accede  a Casilla 1

Agregar cosas a listas:

Lista = []
Cosa = "Hola"
Lista.append(Cosa)  // .append() agrega cosas a una lista

------------------------------------------------------------------------------------------------------------------------------------
Tupla:

Estructura de datos ordenada e inmutable y se pueden repetir elementos // NO se puden cambiar sus elementos

Tupla = (0,1,2,3) // se hacen con el uso de () parentesis

# Las tuplas o se pueden cambiar sin embargo si metes una tupla a una lista puedes modificar la lista de este modo}
cambias la tupla sin embargo no sus contenidos, es decir remplazas la tupla dentro de la lista por otra cosa.

# Nota a las tuplas is se les puede hacer .append()

Hackear Tuplas ;)

Tupla = (0,1,3)
print(Tupla)
print(type(Tupla))
Tupla = list(Tupla)
print(type(Tupla))
Tupla[0] = "Xd"
Tupla = tuple(Tupla)
print(type(Tupla))
print(Tupla)

------------------------------------------------------------------------------------------------------------------------------------
Set:

Estructura de datos NO ordenada e inmutable y se  NO pueden repetir elementos // NO se puden cambiar sus elementos, elimina los duplicados

Set = {0,1,2,3,2,"2"}

------------------------------------------------------------------------------------------------------------------------------------
Diccionarios:
------------------------------------------------------------------------------------------------------------------------------------

Estructura de datos que almacena datos en base de Key-words

Estructura = {
    "Cosa1":"circulo",
    "Cosa2":"Cubo",
    "Cosa3":"Esfera",
    "Estructura2":[
        {
        "Cosa4":"Rectangulo",
        "Cosa5":"Triangulo"
        }
    ]
}

    // para acceder

print(Estructura["Estructura2"][0]["Cosa5"])  // Imprime Cubo

    // Nota: Usar comillas simples para las Key SIEMPRE!!!

    // agregar cosas a un diccionario

Estructura['Cosa6'] = "Hexagono"

------------------------------------------------------------------------------------------------------------------------------------
Condicionales:
------------------------------------------------------------------------------------------------------------------------------------

If y Else:

Nos permite evaluar condicines ejemplo:

if( A < B ):
    print("A es menor a B")
else:
    print("A no es menor a B")          // tener cuidado con la indentación


Elif:                                   // evalua condiciones 

------------------------------------------------------------------------------------------------------------------------------------
Ciclos:
------------------------------------------------------------------------------------------------------------------------------------

repetir una operación siempre y cuando satisfaga una condición.

------------------------------------------------------------------------------------------------------------------------------------
While:                  // se repite hasta que se deja de cumplir la condición

N = 0
while(N < 6):           // imprime del 0 al 5 y el valor de N es igual a 6
    print(N)
    N += 1

------------------------------------------------------------------------------------------------------------------------------------
Range:                  // Nos da un rsngo de números entre un limite inferior y uno superior - 1 es como una lista de numeros separados por comas

------------------------------------------------------------------------------------------------------------------------------------
For:                    //

for num in range(5,500,100):      // numeros del 5 al 500 de 100 en 100
    print(num)                   // imprime 5 105 205 305 405


------------------------------------------------------------------------------------------------------------------------------------
Funciones:
------------------------------------------------------------------------------------------------------------------------------------

Las funciones son bloques de código que se pueden llamar cuantas veces se quiera y se pueden usar en cualquier parte del código.
se usan para no repetir código y para hacer el código más legible.

se usa def para definir una función

def NombreFuncion():

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Sin parametros:

def NombreFuncion():
    print("Hola")             // imprime Hola

NombreFuncion()               // llama a la función que en este caso es imprime Hola

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ahora con parametros:

def NombreFuncion(Nombre):
    print(f"Hola {Nombre}")   // imprime Hola + el nombre que le demos

NombreFuncion("Juan")         // llama a la función que en este caso es imprime Hola Juan

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ahora con parametros y type annotation:

def NombreFuncion(Nombre: str) -> str:   // lo de la flecha es para decirle que tipo de dato va a devolver la función
    return f"Hola {Nombre}"              // devuelve Hola + el nombre que le demos pero, habra que imprimir la función para ver el resultado

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ahora con parametros y type annotation y default:

def NombreFuncion(Nombre: str = "Juan") -> str:   // lo de la flecha es para decirle que tipo de dato va a devolver la función
    return f"Hola {Nombre}"              // devuelve Hola + el nombre que le demos, habra que imprimir la función para ver el resultado

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ahora con *args:

def NombreFuncion(*args):    // el asterisco es para decirle que puede recibir un numero indefinido de parametros
    print(args)              // imprime una tupla con los parametros que le demos

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ahora con **kwargs:

def NombreFuncion(**kwargs):    // el doble asterisco es para decirle que puede recibir un numero indefinido de parametros
    for key, value in kwargs.items():
        print(f"{key} = {value}")  // imprime los parametros que le demos con su valor 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ahora con parametros *args y **kwargs:

def NombreFuncion(Nomre,*args, **kwargs):    // Primero los parametros normales, luego los *args y por ultimo los **kwargs
    print(Nombre)
    print(args)
    print(kwargs)                       
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
otros ejemplos:

def Suma(*args):
    resultado = 0
    for num in args:
        resultado += num
    return resultado

print(Suma(1,2,3,4,5,6,7,8,9,10))  // imprime 55

// si en cambio los numeros por suumar estan en una lista o tupla

lista_num = [1,2,3,4,5,6,7,8,9,10]
print(Suma(*lista_num))  // imprime 55 de nuevo, sin embargo cuando se usa * se desempaqueta la lista o tupla

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def saludosuma(Nombre, *args):
    print(f"Hola {Nombre}")
    resultado = 0
    for num in args:
        resultado += num
    return resultado

Nombre = input("Ingresa tu nombre: ")
print(saludosuma(Nombre,1,2,3,4,5,6,7,8,9,10))  // imprime Hola + el nombre que le demos + 55

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
def desempaqutado(**kwargs):
    for key, value in kwargs.items():
        print(f"{key} ..... {value}")

diccionario = {
    "Nombre":"Juan",
    "Apellido":"Perez",
    "Edad":20
}

desempaqutado(**diccionario)    // imprime Nombre ..... Juan
                                // imprime Apellido ..... Perez
                                // imprime Edad ..... 20

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

------------------------------------------------------------------------------------------------------------------------------------
Excepciones:
------------------------------------------------------------------------------------------------------------------------------------

Son errores que se pueden manejar en el código.

try:                                   // intenta ejecutar el codigo

except:                                // si hay un error ejecuta el codigo

else:                                  // si no hay error ejecuta el codigo

finally:                               // se ejecuta siempre

raise Exception():                                 // levanta una excepcion

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Usar while para que el usuario ingrese un numero entero:

while True:
    try:                                                        // intenta ejecutar el codigo
        num = int(input("Ingresa un numero entero: "))

    except:                                                     // si hay un error ejecuta el codigo     
        print("No es un numero entero")
        continue                                                // continua el ciclo

    else:
        print("Gracias")
        break                                                   // rompe el ciclo

    finally:                                                    // se ejecuta siempre
        print("Fin de la iteracion")                            

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

------------------------------------------------------------------------------------------------------------------------------------
Modulos:
------------------------------------------------------------------------------------------------------------------------------------

Son archivos que contienen código que podemos importar a nuestro programa.

import NombreModulo                     // importa el modulo

from NombreModulo import *              // importa todo el modulo

import NombreModulo.NombreFuncion       // importa una funcion especifica del modulo

import NombreModulo as NM               // importa el modulo y le da un alias

import NombreModulo.NombreFuncion as NF // importa una funcion especifica del modulo y le da un alias

from NombreModulo import NombreFuncion  // importa una funcion especifica del modulo

NombreModulo.NombreFuncion()            // llama a la funcion del modulo

 se ejecuta siempre
        
------------------------------------------------------------------------------------------------------------------------------------
Clases:
------------------------------------------------------------------------------------------------------------------------------------

Las clases son plantillas para crear objetos.

Constructor: es un metodo que se ejecuta al crear un objeto de la clase. se usa el metodo _init_(). se usa self para referirse a la clase, }
se usa self.atributo para crear atributos de la clase. se usa self.metodo para crear metodos de la clase. 
se usa self.atributo = valor para asignarle un valor a un atributo de la clase. se usa self.metodo() para llamar a un metodo de la clase. 


class NombreClase():                                                        // se usa la palabra reservada class
    def __init__(self, Nombre, Localidad):                                    // metodo de la clase que se ejecuta al crear un objeto de la clase
        self.Nombre = Nombre                                                // atributo de la clase que se le pasa por parametro
        self.Localidad = Localidad                                          // atributo de la clase que se le pasa por parametro
        self.Color = input("Ingresa el color: ")                            // atributo de la clase que se le pasa por input
        print(f"Se ha creado un objeto de la clase de {self.Localidad}")
    atributo1 = 0.5                                                         // atributos de la clase
    atributo2 = input("Ingresa un valor: ")                                 // atributos de la clase pasados por input

    def Saludo(self):                                                       // metodo de la clase, self se referencia a la clase
        print(f"Hola {self.Nombre}")
    
cosa = NombreClase('Carlos','CDMX')                                         // creamos un objeto de la clase
print(isinstance(cosa, NombreClase))                                        // imprime True
cosa.Saludo()                                                               // llama al metodo Saludo de la clase

------------------------------------------------------------------------------------------------------------------------------------
Herencia:
------------------------------------------------------------------------------------------------------------------------------------

Es la capacidad que tienen las clases de heredar atributos y metodos de otras clases.

import datetime                                                             // importamos el modulo datetime

class NombreClasePadre():                                                   // clase padre
    def __init__(self, Nombre, Matricula):                                    // metodo de la clase que se ejecuta al crear un objeto de la clase
        self.Nombre = Nombre                                                // atributo de la clase que se le pasa por parametro
        self.Localidad = Matricula                                          
        self.fecha_alta = datetime.datetime.now()                           // datetime.datetime.now() es un metodo del modulo datetime que devuelve la fecha y hora actual

    def saludo(self):
        print(f"Se ha creado una persona con el nombre de {self.Nombre} con la matricula {self.Matricula}")
        
class NombreClaseHija(NombreClasePadre):                                    // clase hija que hereda de la clase padre debe ir dentro de ():
    def __init__(self, Nombre, Matricula, Carrera, Promedio):
        super()._init_(Nombre, Matricula)                                   // super() llama al metodo de la clase padre
        self.Carrera = Carrera
        self.Promedio = Promedio

    def saludo(self):
        print(f"Se ha creado un alumno con el nombre de {self.Nombre} con la matricula {self.Matricula} con la carrera de {self.Carrera} y con un promedio de {self.Promedio}")

Persona = NombreClasePadre('Carlos', 123456)                                // creamos un objeto de la clase padre
Persona.saludo()                                                            

Alumno = NombreClaseHija('Juan', 654321, 'Ingenieria', 9.5)                 // creamos un objeto de la clase hija
Alumno.saludo()

------------------------------------------------------------------------------------------------------------------------------------
Herecia multiple:

class NombreClasePadre1():
    def __init__(self, Nombre):
        self.Nombre = Nombre

    def saludo(self):   
        print(f"Hola {self.Nombre}")

class NombreClasePadre2():
    def __init__(self, Matricula):
        self.Matricula = Matricula

    def matricula(self):
        print(f"Mi matricula es: {self.Matricula}")

class NombreClaseHija(NombreClasePadre1, NombreClasePadre2):                // se hereda de dos clases
    def __init__(self, Nombre, Matricula):
        NombreClasePadre1._init_(self, Nombre)                              // se llama al constructor de la clase padre1
        NombreClasePadre2._init_(self, Matricula)                           // se llama al constructor de la clase padre2
        
        


------------------------------------------------------------------------------------------------------------------------------------
Polimorfismo:

Es la capacidad de reescribir metodos heredados y se hace de la siguiente manera:

class NombreClasePadre():
    def __init__(self, Nombre):
        self.Nombre = Nombre

    def saludo(self):                                                            // metodo de la clase
        print(f"Hola {self.Nombre}")        

class NombreClaseHija(NombreClasePadre):
    def __init__(self, Nombre, Matricula):
        super()._init_(Nombre)
        self.Matricula = Matricula

    def saludo(self):                                                           // reescribimos el metodo saludo de la clase padre
        print(f"Hola {self.Nombre} con la matricula {self.Matricula}")

------------------------------------------------------------------------------------------------------------------------------------
Modificadores de acceso:
------------------------------------------------------------------------------------------------------------------------------------

Son palabras reservadas que se usan para proteger los atributos de una clase.
Estas palabras reservadas son:

public: se usa para que los atributos de una clase puedan ser accedidos desde fuera de la clase.

private: se usa para que los atributos de una clase no puedan ser accedidos desde fuera de la clase.

protected: se usa para que los atributos de una clase puedan ser accedidos desde fuera de la clase pero solo por clases hijas.

Ejemplo:

class NombreClase():
    def __init__(self, Nombre):
        self.Nombre = Nombre                                                // atributo publico
        self._Nombre = Nombre                                               // atributo privado son dos __ (guiones bajos)
        self.__Nombre = Nombre                                              // atributo protegido son tres __ (guiones bajos)

------------------------------------------------------------------------------------------------------------------------------------
Metodos gettter y setter:

Son metodos que se usan para acceder a los atributos de una clase.

Ejemplo:

class NombreClase():
    def __init__(self, NombrePublic, NombrePrivate, NombreProtected):
        self.NombrePublic = NombrePublic                                               
        self._NombrePrivate = NombrePrivate                                           
        self.__NombreProtected = NombreProtected 

    def get_Nombre(self):                                                   // metodo getter
        return self.Nombre                                                  // retorna el valor del atributo Nombre

    def set_Nombre_public(self, Nombre):                                    // metodo setter
        self.NombrePublic = NombrePublic                                    // asigna un valor al atributo NombrePublic

    def set_Nombre_privado(self, Nombre):                                   // metodo setter
        self._NombrePrivate = NombrePrivate                                 // asigna un valor al atributo _NombrePrivate

    def set_Nombre_protegido(self, Nombre):                                 // metodo setter
        self.__NombreProtected = NombreProtected                            // asigna un valor al atributo __NombreProtected

------------------------------------------------------------------------------------------------------------------------------------
Manejo de archivos:
------------------------------------------------------------------------------------------------------------------------------------

Hay 4 modos para manejar archivos:

r: modo lectura, solo se puede leer el archivo.

w: modo escritura, solo se puede escribir en el archivo.

a: modo append, se puede leer y escribir en el archivo.

r+: modo lectura y escritura, se puede leer y escribir en el archivo.

------------------------------------------------------------------------------------------------------------------------------------

file = open('NombreArchivo','X')                                            // se abre el archivo en modo equis

file.write('Hola')                                                          // se escribe en el archivo

file.close()                                                                // se cierra el archivo

------------------------------------------------------------------------------------------------------------------------------------
With:

Es una forma de manejar archivos que se usa para abrir y cerrar archivos de forma automatica.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Ejemplo:

import datetime 

mascotas = ['Tacho','Cuka','Rocky','Frank']

with open('LogMascotas.txt','w') as file:
    for mascota in mascotas:
        fecha = datetime.datetime.now()
        file.write(f"{mascota} Se dio de alta ---> {fecha} \n")

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
        
------------------------------------------------------------------------------------------------------------------------------------
API: (Application Programming Interface)
------------------------------------------------------------------------------------------------------------------------------------

Es un conjunto de funciones y procedimientos que permite el desarrollo de aplicaciones.

------------------------------------------------------------------------------------------------------------------------------------
Metodos HTTP:

get():          // Obtiene un recurso.

post():         // Añade un recurso.

put():          // Actualiza un recurso, lo remplaza.

delete():       // Elimina un recurso.

patch():        // Actualiza parcialmente un recurso.

head():         // Obtiene los metadatos de un recurso.

------------------------------------------------------------------------------------------------------------------------------------
Respuestas HTTP:

1xx:    // Informacion.

2xx:    // Exito.

3xx:    // Redireccion.

4xx:    // Error del cliente.

5xx:    // Error del servidor.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HTTP Status Codes:

200:    // OK.

201:    // Created.

204:    // No Content.

400:    // Bad Request.

401:    // Unauthorized.

403:    // Forbidden.

404:    // Not Found.

405:    // Method Not Allowed.

500:    // Internal Server Error.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
------------------------------------------------------------------------------------------------------------------------------------
JSON:
-------------------------------------------------------------------------------------------------------------------------------------

Es un formato de texto ligero para el intercambio de datos.

------------------------------------------------------------------------------------------------------------------------------------

json.dump():    // convierte un diccionario en un archivo json.

json.load():    // convierte un archivo json en un diccionario.

------------------------------------------------------------------------------------------------------------------------------------

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
import json

data = {
    'nombre': 'Pancho',
    'apellido': 'Perez',
    'edad': 25,
    'hijos': None,
    'mascotas': [
        {'nombre': 'Tacho', 'edad': 5},
        {'nombre': 'Cuka', 'edad': 7}
    ],
    'casado': False
}   

with open('data.json','w') as file:                     // se abre el archivo en modo escritura
    json.dump(data,file)                                // se guarda el diccionario en un archivo json

with open('data.json','r') as file:                     // se abre el archivo en modo lectura
    data = json.load(file)                              // se carga el archivo json en un diccionario

print(data)                                             // se imprime el diccionario
    
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

------------------------------------------------------------------------------------------------------------------------------------
Pandas:
------------------------------------------------------------------------------------------------------------------------------------

Es una libreria de python que permite el manejo de datos.

------------------------------------------------------------------------------------------------------------------------------------

import pandas as pd

------------------------------------------------------------------------------------------------------------------------------------

data = pd.DataFrame()                                   // se crea un dataframe vacio

df = pd.DataFrame({'A': [1, 2, 3], 'B': [4, 5, 6]})     // se crea un dataframe con datos

df = pd.DataFrame([[1, 4], [2, 5], [3, 6]], columns=['A', 'B']) // se crea un dataframe con datos

------------------------------------------------------------------------------------------------------------------------------------

data = pd.read_csv('data.csv')                          // se carga un archivo csv en un dataframe

data.to_csv('data.csv')                                 // se guarda un dataframe en un archivo csv

------------------------------------------------------------------------------------------------------------------------------------

data = pd.read_excel('data.xlsx')                       // se carga un archivo excel en un dataframe

data.to_excel('data.xlsx')                              // se guarda un dataframe en un archivo excel

------------------------------------------------------------------------------------------------------------------------------------

data = pd.read_json('data.json')                        // se carga un archivo json en un dataframe

data.to_json('data.json')                               // se guarda un dataframe en un archivo json

------------------------------------------------------------------------------------------------------------------------------------

data = pd.read_html('data.html')                        // se carga un archivo html en un dataframe

data.to_html('data.html')                               // se guarda un dataframe en un archivo html

------------------------------------------------------------------------------------------------------------------------------------

data = pd.read_sql('data.sql')                          // se carga un archivo sql en un dataframe

data.to_sql('data.sql')                                 // se guarda un dataframe en un archivo sql

------------------------------------------------------------------------------------------------------------------------------------
Funciones de pandas:
------------------------------------------------------------------------------------------------------------------------------------

df.head()                                               // muestra las primeras 5 filas del dataframe

df.tail()                                               // muestra las ultimas 5 filas del dataframe

df.shape()                                              // muestra la cantidad de filas y columnas del dataframe

df.info()                                               // muestra informacion del dataframe

df.describe()                                           // muestra estadisticas del dataframe

df.columns()                                            // muestra las columnas del dataframe

df.index()                                              // muestra los indices del dataframe

df.dtypes()                                             // muestra los tipos de datos del dataframe

df.values()                                             // muestra los valores del dataframe

df.isnull()                                             // muestra los valores nulos del dataframe

df.notnull()                                            // muestra los valores no nulos del dataframe

df.dropna()                                             // elimina los valores nulos del dataframe

df.fillna()                                             // reemplaza los valores nulos del dataframe

df.rename()                                             // renombra las columnas del dataframe

df.sort_values()                                        // ordena los valores del dataframe

df.groupby()                                            // agrupa los valores del dataframe

df.merge()                                              // une los dataframes

df.join()                                               // une los dataframes

df.append()                                             // agrega filas al dataframe

df.drop()                                               // elimina filas del dataframe

df.reset_index()                                        // reinicia los indices del dataframe

df.set_index()                                          // establece los indices del dataframe

df.loc()                                                // selecciona filas y columnas por etiqueta

df.iloc()                                               // selecciona filas y columnas por posicion

df.at()                                                 // selecciona un valor por etiqueta

df.iat()                                                // selecciona un valor por posicion

df.where()                                              // selecciona valores que cumplan una condicion

df.query()                                              // selecciona valores que cumplan una condicion

df.copy()                                               // copia el dataframe

df.apply()                                              // aplica una funcion a cada valor del dataframe

df.applymap()                                           // aplica una funcion a cada valor del dataframe

df.map()                                                // aplica una funcion a cada valor del dataframe

df.replace()                                            // reemplaza valores del dataframe

df.astype()                                             // cambia el tipo de datos del dataframe

df.to_numpy()                                           // convierte el dataframe en un array

df.to_dict()                                            // convierte el dataframe en un diccionario

df.to_string()                                          // convierte el dataframe en un string

df.to_html()                                            // convierte el dataframe en un archivo html

df.to_json()                                            // convierte el dataframe en un archivo json

df.to_csv()                                             // convierte el dataframe en un archivo csv

df.to_excel()                                           // convierte el dataframe en un archivo excel

df.to_sql()                                             // convierte el dataframe en un archivo sql

------------------------------------------------------------------------------------------------------------------------------------

.mean()      // calcula la media de una columna del dataframe

.sum()       // calcula la suma de una columna del dataframe

.std()       // calcula la desviacion estandar de una columna del dataframe

.min()       // calcula el valor minimo de una columna del dataframe

.max()       // calcula el valor maximo de una columna del dataframe

.count()     // calcula la cantidad de valores de una columna del dataframe

.apply()     // aplica una funcion a una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna']                                           // selecciona una columna del dataframe

df[['columna1','columna2']]                             // selecciona varias columnas del dataframe

df.columna                                              // selecciona una columna del dataframe

df.columna1.columna2                                    // selecciona una columna del dataframe

df.loc['fila']                                          // selecciona una fila del dataframe

df.loc[['fila1','fila2']]                               // selecciona varias filas del dataframe

df.loc['fila','columna']                                // selecciona un valor del dataframe

df.loc[['fila1','fila2'],['columna1','columna2']]        // selecciona varios valores del dataframe

df.loc['fila':'fila']                                   // selecciona un rango de filas del dataframe

df.loc[:,'columna':'columna']                           // selecciona un rango de columnas del dataframe

df.loc['fila':'fila','columna':'columna']               // selecciona un rango de filas y columnas del dataframe

df.iloc[0]                                              // selecciona una fila del dataframe

df.iloc[[0,1]]                                          // selecciona varias filas del dataframe

df.iloc[0,1]                                            // selecciona un valor del dataframe

df.iloc[[0,1],[0,1]]                                    // selecciona varios valores del dataframe

df.iloc[0:2]                                            // selecciona un rango de filas del dataframe

df.iloc[:,0:2]                                          // selecciona un rango de columnas del dataframe

df.iloc[0:2,0:2]                                        // selecciona un rango de filas y columnas del dataframe

df.at['fila','columna']                                 // selecciona un valor del dataframe

df.iat[0,1]                                             // selecciona un valor del dataframe

df.where(df['columna'] > 0)                             // selecciona valores que cumplan una condicion

df.query('columna > 0')                                 // selecciona valores que cumplan una condicion

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].apply(lambda x: x*2)      // aplica una funcion a una columna del dataframe

df['columna'] = df['columna'].map(lambda x: x*2)        // aplica una funcion a una columna del dataframe

df['columna'] = df['columna'].replace(0,1)              // reemplaza valores de una columna del dataframe

df['columna'] = df['columna'].astype('int')             // cambia el tipo de datos de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].fillna(0)                 // reemplaza los valores nulos de una columna del dataframe

df['columna'] = df['columna'].fillna(df['columna'].mean()) // reemplaza los valores nulos de una columna del dataframe

df['columna'] = df['columna'].fillna(method='ffill')    // reemplaza los valores nulos de una columna del dataframe

df['columna'] = df['columna'].fillna(method='bfill')    // reemplaza los valores nulos de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df.dropna()                                             // elimina los valores nulos del dataframe

df.dropna(subset=['columna'])                           // elimina los valores nulos de una columna del dataframe

df.dropna(how='all')                                    // elimina las filas que tengan todos los valores nulos

df.dropna(thresh=2)                                     // elimina las filas que tengan menos de 2 valores no nulos

df.dropna(axis=1)                                       // elimina las columnas que tengan valores nulos

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].drop_duplicates()         // elimina los valores duplicados de una columna del dataframe

df.drop_duplicates()                                    // elimina los valores duplicados del dataframe

df.drop_duplicates(subset=['columna'])                  // elimina los valores duplicados de una columna del dataframe

df.drop_duplicates(subset=['columna1','columna2'])      // elimina los valores duplicados de varias columnas del dataframe

df.drop_duplicates(keep='last')                         // elimina los valores duplicados del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].sort_values()             // ordena los valores de una columna del dataframe

df.sort_values(by='columna')                            // ordena los valores de una columna del dataframe

df.sort_values(by=['columna1','columna2'])              // ordena los valores de varias columnas del dataframe

df.sort_values(by=['columna1','columna2'],ascending=False) // ordena los valores de varias columnas del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].rank()                    // asigna un valor a cada valor de una columna del dataframe

df['columna'] = df['columna'].rank(method='first')      // asigna un valor a cada valor de una columna del dataframe

df['columna'] = df['columna'].rank(method='min')        // asigna un valor a cada valor de una columna del dataframe

df['columna'] = df['columna'].rank(method='max')        // asigna un valor a cada valor de una columna del dataframe

df['columna'] = df['columna'].rank(method='dense')      // asigna un valor a cada valor de una columna del dataframe

df['columna'] = df['columna'].rank(ascending=False)     // asigna un valor a cada valor de una columna del dataframe

df['columna'] = df['columna'].rank(pct=True)            // asigna un valor a cada valor de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].cumsum()                  // suma los valores de una columna del dataframe

df['columna'] = df['columna'].cumprod()                 // multiplica los valores de una columna del dataframe

df['columna'] = df['columna'].cummax()                  // selecciona el valor maximo de una columna del dataframe

df['columna'] = df['columna'].cummin()                  // selecciona el valor minimo de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].diff()                    // calcula la diferencia entre valores de una columna del dataframe

df['columna'] = df['columna'].pct_change()              // calcula el porcentaje de cambio entre valores de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].shift(1)                  // desplaza los valores de una columna del dataframe

df['columna'] = df['columna'].shift(-1)                 // desplaza los valores de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].rolling(2).mean()        // calcula la media movil de una columna del dataframe

df['columna'] = df['columna'].rolling(2).sum()         // calcula la suma movil de una columna del dataframe

df['columna'] = df['columna'].rolling(2).std()         // calcula la desviacion estandar movil de una columna del dataframe

df['columna'] = df['columna'].rolling(2).min()         // calcula el valor minimo movil de una columna del dataframe

df['columna'] = df['columna'].rolling(2).max()         // calcula el valor maximo movil de una columna del dataframe

df['columna'] = df['columna'].rolling(2).count()       // calcula la cantidad de valores moviles de una columna del dataframe

df['columna'] = df['columna'].rolling(2).apply(lambda x: x*2) // aplica una funcion a una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].expanding().mean()       // calcula la media movil de una columna del dataframe

df['columna'] = df['columna'].expanding().sum()        // calcula la suma movil de una columna del dataframe

df['columna'] = df['columna'].expanding().std()        // calcula la desviacion estandar movil de una columna del dataframe

df['columna'] = df['columna'].expanding().min()        // calcula el valor minimo movil de una columna del dataframe

df['columna'] = df['columna'].expanding().max()        // calcula el valor maximo movil de una columna del dataframe

df['columna'] = df['columna'].expanding().count()      // calcula la cantidad de valores moviles de una columna del dataframe

df['columna'] = df['columna'].expanding().apply(lambda x: x*2) // aplica una funcion a una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].ewm(span=2).mean()       // calcula la media movil exponencial de una columna del dataframe

df['columna'] = df['columna'].ewm(span=2).sum()        // calcula la suma movil exponencial de una columna del dataframe

df['columna'] = df['columna'].ewm(span=2).std()        // calcula la desviacion estandar movil exponencial de una columna del dataframe

df['columna'] = df['columna'].ewm(span=2).min()        // calcula el valor minimo movil exponencial de una columna del dataframe

df['columna'] = df['columna'].ewm(span=2).max()        // calcula el valor maximo movil exponencial de una columna del dataframe

df['columna'] = df['columna'].ewm(span=2).count()      // calcula la cantidad de valores moviles exponenciales de una columna del dataframe

df['columna'] = df['columna'].ewm(span=2).apply(lambda x: x*2) // aplica una funcion a una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].fillna(0)                // reemplaza los valores nulos de una columna del dataframe

df['columna'] = df['columna'].fillna(method='ffill')   // reemplaza los valores nulos de una columna del dataframe

df['columna'] = df['columna'].fillna(method='bfill')   // reemplaza los valores nulos de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].replace(0,1)             // reemplaza los valores de una columna del dataframe

df['columna'] = df['columna'].replace([0,1],[1,2])     // reemplaza los valores de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------

df['columna'] = df['columna'].astype('int')            // convierte el tipo de dato de una columna del dataframe

------------------------------------------------------------------------------------------------------------------------------------



'''

'''
------------------------------------------------------------------------------------------------------------------------------------
Hacks del Roger:
------------------------------------------------------------------------------------------------------------------------------------
class NombreClase():
    def __init__(self,nombre):
        self.__NombrePrivate = nombre                                           

pancho = NombreClase("soy pancho")

print(pancho._NombreClase__NombrePrivate)

pancho._NombreClase__NombrePrivate = "Roberto"

print(pancho._NombreClase__NombrePrivate)

------------------------------------------------------------------------------------------------------------------------------------
'''
