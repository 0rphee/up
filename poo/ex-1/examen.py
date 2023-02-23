# MAURO ROGELIO GALINDO IBARRA

musica = {
    'The Black Keys':{
        'El Camino':{
            'Lonely Boy':{
                'liked':False,
                'reproducciones':'397810130',
                'duracion_ms':187800,
                'tags':('Rock','Catchy Tunes')
            },
            'Little Black Submarines':{
                'liked':True,
                'reproducciones':'89206240',
                'duracion_ms':246600,
                'tags':('Rock & Roll','Classics','Blues','Ballad',
                        'Rock','Ballad','Blues','Classics','Classics',
                        'Ballad','Rock & Roll','Classics','Blues',
                        'Rock & Roll','Classics','Rock & Roll','Blues')
            },
            'Hell of a Season':{
                'liked':True,
                'reproducciones':10425570,
                'duracion_ms':207000,
                'tags':('Rock')
            }
        }
    },
    'Greta Van Fleet':{
        'From the Fires':{
            'Safari Song':{
                'liked':True,
                'reproducciones':104450524,
                'duracion_ms':'212400',
                'tags':('Rock','Classics')
            },
            'Edge of Darkness':{
                'liked':False,
                'reproducciones':'47756093',
                'duracion_ms':256800,
                'tags':('Rock')
            },
            'Highway Tune':{
                'liked':True,
                'reproducciones':'181238080',
                'duracion_ms':180000,
                'tags':('Hard Rock')
            },
            'Black Smoke Rising':{
                'liked':True,
                'reproducciones':119129373,
                'duracion_ms':251400,
                'tags':('Rock','Classics')
            }
        },
        'The Battle at Gardens Gate':{
            'Heat Above':{
                'liked':True,
                'reproducciones':67071430,
                'duracion_ms':324600,
                'tags':('Rock','Ballad')
            },
            'Age of Machine':{
                'liked':False,
                'reproducciones':'23667326',
                'duracion_ms':391800,
                'tags':('Rock')
            },
            'Stardust Chords':{
                'liked':False,
                'reproducciones':16001476,
                'duracion_ms':274200,
                'tags':('Ballad')
            },
        }
    },
    'Stromae':{
        'Racine Carree':{
            'Ta Fete':{
                'liked':False,
                'reproducciones':75156132,
                'duracion_ms':'153000',
                'tags':('French Pop','Electro')
            },
            'Tous le Memes':{
                'liked':True,
                'reproducciones':194588900,
                'duracion_ms':198000,
                'tags':('French Pop','Electro')
            },
            'Ave Cesaria':{
                'liked':True,
                'reproducciones':'50747834',
                'duracion_ms':245400,
                'tags':('French Pop','Electro','Ethnic')
            }
        },
        'Multitude':{
            'Invaincu':{
                'liked':True,
                'reproducciones':'16732216',
                'duracion_ms':123000,
                'tags':('French Pop','Electro')
            },
            'Sante':{
                'liked':True,
                'reproducciones':'92011201',
                'duracion_ms':'186600',
                'tags':('Ethnic')
            },
            'Fils de Joie':{
                'liked':False,
                'reproducciones':'34948659',
                'duracion_ms':189000,
                'tags':('French Pop')
            },
        }
    },
}

#INDICACIONES
#NOTA:
'''
El diccionario provisto sigue la siguiente estructura
'Artista':{
        'Disco':{
            'Cancion':{
                'Si la Cancion nos gusta o no':False,
                'Cuantas reproducciones tiene':'397810130',
                'Cuanto Dura en milisegundos':18700,
                'Tags asociados':('Rock','Catchy Tunes')
            },
        }
    } 
'''
#1--- Imprimir el numero de reproducciones de la cancion "Highway Tune"
print("Número de reproducciones de Highway Tune")

temp = musica["Greta Van Fleet"]["From the Fires"]["Highway Tune"]["reproducciones"]

print(temp, end="\n\n")

#2--- Imprimir el numero de reproducciones de la cancion "Heat Above"
print("Número de reproducciones de Heat Above")

temp = musica["Greta Van Fleet"]["The Battle at Gardens Gate"]["Heat Above"]["reproducciones"]

print(temp, end="\n\n")


#3--- Imprimir la duracion de la cancion "Sante"
print("Duración en ms de Sante")

temp = musica["Stromae"]["Multitude"]["Sante"]["duracion_ms"]

print(temp, end="\n\n")

#4--- Imprimir el segundo tag de la cancion "Lonely Boy"
print("Segundo tag de Lonely Boy")

temp = musica["The Black Keys"]["El Camino"]["Lonely Boy"]["tags"][1]

print(temp, end="\n\n")

#5--- Imprimir la duracion de la cancion "Little Black Submarines"
print("Duración en ms Little Black Submarines")

temp = musica["The Black Keys"]["El Camino"]["Little Black Submarines"]["duracion_ms"]

print(temp, end="\n\n")


#6--- Obtener la duracion total del disco "Multitude"
print("Duración total de disco Multitude")

temp = sum([int(song["duracion_ms"]) for song in musica["Stromae"]["Multitude"].values()])

print(temp, end="\n\n")

#7--- Obtener el promedio de reproducciones del disco "The Battle at Gardens Gate"
print("Promedio de duraciones de disco The Battle at Gardens Gate")

temp = sum([int(song["reproducciones"]) for song in musica["Greta Van Fleet"]["The Battle at Gardens Gate"].values()])/len(musica["Greta Van Fleet"]["The Battle at Gardens Gate"])

print(temp, end="\n\n")

#8--- Obtener el numero de discos de The Black Keys y de Greta Van Fleet. Determinar quien tiene mas discos
print("Quién tiene más discos, The Black Keys o Greta Van Fleet?")

temp = len(musica["Greta Van Fleet"])
temp2 = len(musica["The Black Keys"])

if temp > temp2:
    print("Greta Van Fleet", end="\n\n")
else:
    print("The Black Keys", end="\n\n")

#9--- Sustituir los tags de la cancion 'Little Black Submarines' por una tupla que contenga 
#     los valores unicos de la estructura original. Es decir, eliminar duplicados
print("Sustituir tags de Little Black Submarines con tupla sin duplicados")

temp = musica["The Black Keys"]["El Camino"]["Little Black Submarines"]["tags"]

temp = tuple(set(temp))

print(temp, end="\n\n")


#10--- Obtener la duracion promedio de las canciones del disco "Racine Carree"
print("Promedio de duraciones de disco Racine Carrine")

temp = sum([int(song["reproducciones"]) for song in musica["Stromae"]["Racine Carree"].values()])/len(musica["Stromae"]["Racine Carree"])

print(temp, end="\n\n")


#11--- Imprimir el nombre del disco con mas Likes de Greta Van Fleet
print("Disco don más likes de Greta Van Fleet")


temp = max( 
            [ 
              ( #tuple 
                sum( [1 for cancion in discoValues.values() if cancion["liked"] ] )
              , discoName
              ) #endtuple
        
             for discoName, discoValues in musica["Greta Van Fleet"].items()  
            ]
          )

print(temp, end="\n\n")

#12--- Aniadir el tag "Cumbia" a la cancion "Sante"

## ya no

#13--- Agregar la cancion "Tiene Espinas el Rosal" al disco "El Camino". La informacion de dicha cancion es la siguiente:
temp = {
           'liked':True,
           'reproducciones':'92011201',
           'duracion_ms':'186600',
           'tags':('Cumbion bien loco', 'Lo mejor para tus bodas')
        }

print("Añadir Cancion  Tiene Espinas el Rosal a disco El Camino")

musica["The Black Keys"]["El Camino"]["Tiene Espinas el Rosal"] = temp

temp = musica["The Black Keys"]["El Camino"]

print("Diccionario de canciones de El Camino con nueva cancion añadida con nueva cancion añadida")
print(temp, end="\n\n")


#14--- Determinar cual es el disco con mas likes de todos
print("Disco con más likes de todos")


temp = max( 
            [ 
              ( #tuple 
                sum( [1 for cancion in discoValues.values() if cancion["liked"] ] )
              , discoName
              , artista
              ) #endtuple
        
             for artista, artistaValues in musica.items()
             for discoName, discoValues in artistaValues.items()
            ]
          )

print(temp, end="\n\n")


#15--- Determinar cual es el disco con mayor duracion de todos
print("Disco con mayor duración de todos")


temp = max( 
            [ 
              ( #tuple 
                sum( [ int(cancion["duracion_ms"]) for cancion in discoValues.values() ] )
              , discoName
              , artista
              ) #endtuple
        
             for artista, artistaValues in musica.items()
             for discoName, discoValues in artistaValues.items()
            ]
          )

print(temp, end="\n\n")


#16--- Via consola, mostrar al usuario el nombre de los discos de  Greta Van Fleet. Pedirle al usuario que seleccione uno
#      una vez seleccionado, mostrar las canciones que lo componen. Pedir al usuario que seleccione una.
#      una vez seleccionada, preguntarle al usuario si le gustaria agregar un tag a la cancion. Si dice que si, determinar si el 
#      tag ya estaba presente en los tags. Si no estaba, agregarlo. Si ya estaba, imprimir "Hijole joven, no se va a poder"
#      imprimir la estructura resultante

albumOptions = {str(key): albumName  for albumName, key in zip(musica["Greta Van Fleet"], range(0,len(musica["Greta Van Fleet"]))) }

print("Ingrese un disco de Greta Van Fleet")

for key, val in albumOptions.items():
    print(f"-- {key} para seleccionar {val}")

selectedAlbum = albumOptions[input("> ")]
    
albumDict = musica["Greta Van Fleet"][selectedAlbum]


print("\nSeleccione una canción del disco elegido")

songOptions = {str(key): cancionName  for cancionName, key in zip(albumDict, range(0,len(albumDict))) }

for key, val in songOptions.items():
    print(f"-- {key} para seleccionar {val}")

selectedSong = songOptions[input("> ")]
    

print("\n¿Desea agregar un tag a la canción? (S/N)")
if input("> ").upper() == "S":
    newTag = input("Ingrese nuevo tag\n> ")
    if newTag in musica["Greta Van Fleet"][selectedAlbum][selectedSong]["tags"]:
        print("\nHíjole joven, no se va a poder")
    else:
        temp = list(musica["Greta Van Fleet"][selectedAlbum][selectedSong]["tags"])
        temp.append(newTag)
        musica["Greta Van Fleet"][selectedAlbum][selectedSong]["tags"] = tuple(temp)
        print("\nSí se pudo joven:")
    print(selectedSong, ": ", musica["Greta Van Fleet"][selectedAlbum][selectedSong])




#EXTRA --- Estos no son a fuerza, pero si quieren un desafio y puntos extra valdria la pena intentarlo
#A--- Obtener el promedio de reproducciones del disco "The Battle at Gardens Gate" usando Ciclos For

print("Promedio reproducciones The Battle at Gardens Gate")

temp = 0
for cancion in musica["Greta Van Fleet"]["The Battle at Gardens Gate"].values():
    temp += int(cancion["reproducciones"])

temp = temp/len(musica["Greta Van Fleet"]["The Battle at Gardens Gate"].values())

print(temp, end="\n\n")


#B--- Obtener la duracion total del disco "Multitude" usando Ciclos For
print("Duración total de Multitude")

temp = 0
for cancion in musica["Stromae"]["Multitude"].values():
    temp += int(cancion["duracion_ms"])

print(temp, end="\n\n")
#C--- Crear e imprimir una lista con los nombres de los Discos de Stroma usando List Comprehension

print("Lista de nombres de discos de Stromae")

temp = [discoName for discoName in musica["Stromae"].keys()]

print(temp, end="\n\n")
