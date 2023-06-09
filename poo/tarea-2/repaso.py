series ={
    'Disney Plus':[
        {
            'The Mandalorian':{
                'temporadas':{
                    'Temporada 1':{
                        'episodios':'8',
                        'direccion':'El Cheems',
                        'calificacion':9.2,
                        'vistas':'32000000',
                        'tags':('star wars','filoniverse','dark saber')
                    },
                    'Temporada 2':{
                        'episodios':8,
                        'direccion':'Enrique Segoviano',
                        'calificacion':9.5,
                        'vistas':40000000,
                        'tags':('baby yoda','coursant','beskar')
                    }
                }
            }
        },
        {
            'The Bad Batch':{
                'temporadas':{
                    'Temporada 1':{
                        'episodios':'16',
                        'direccion':'El Canaca',
                        'calificacion':8.9,
                        'vistas':30000000,
                        'tags':('violencia animada','relleno')
                    },
                    'Temporada 2':{
                        'episodios':16,
                        'direccion':'El Canaca',
                        'calificacion':8.0,
                        'vistas':15000000,
                        'tags':('relleno','piu piu')
                    } 
                }
            }
        }
    ],
    'Netflix':[
        {
            'Dark':{
                'temporadas':{
                    'Temporada 1':{
                        'episodios':10,
                        'direccion':'Donald Trump',
                        'calificacion':9.5,
                        'vistas':20000000,
                        'tags':('such confusion','much time travel','wow')
                    },
                    'Temporada 2':{
                        'episodios':'8.0',
                        'direccion':'Donald Trump',
                        'calificacion':9.6,
                        'vistas':25500000,
                        'tags':('canciones ochenteras','spoiler')
                    },
                    'Temporada 3':{
                        'episodios':8,
                        'direccion':'Donald Trump',
                        'calificacion':9.7,
                        'vistas':'34000000',
                        'tags':('somos los malos?','best ending ever')
                    }
                }
            }
        },
        {
            '1899':{
                'temporadas':{
                    'Temporada 1':{
                        'episodios':8,
                        'direccion':'El Cheems',
                        'calificacion':9.5,
                        'vistas':40000000,
                        'tags':('cancelacion','misterio','barquitos')
                    }
                }
            }
        },
        {
            'Squid Game':{
                'temporadas':{
                    'Temporada 1':{
                        'episodios':9,
                        'direccion':'Calamardo Tentaculos',
                        'calificacion':9.5,
                        'vistas':60000000,
                        'tags':('violencia','jpop','cachetadas')
                    }
                }
            }
        }
    ],
    'HBO':[
        {
            'House of the Dragon':{
                'temporadas':{
                    'Temporada 1':{
                        'episodios':'10',
                        'direccion':'Viserys Targaryen',
                        'calificacion':9.5,
                        'vistas':40000000,
                        'tags':('acero valirio','dragones','reds vs greens')
                    }
                }
            }
        },
        {
            'The Last of Us':{
                'temporadas':{
                    'Temporada 1':{
                        'episodios':9,
                        'direccion':'Crash Bandicoot',
                        'calificacion':9.8,
                        'vistas':45000000,
                        'tags':('pan bimbo','hongos malos','terror')
                    }
                }
            }
        }
    ]
}

#Instrucciones
# Nota: Calculen promedios sin usar ciclos for, hagan las actividades en orden

#1) Obtener el promedio de vistas de todas las temporadas de la serie Dark... 
print("Promedio de vistas de todas las temporadas de la serie Dark: ")
prom1 = (series['Netflix'][0]['Dark']['temporadas']['Temporada 1']['vistas'] 
            + series['Netflix'][0]['Dark']['temporadas']['Temporada 2']['vistas'] 
            + int(series['Netflix'][0]['Dark']['temporadas']['Temporada 3']['vistas'])) / len(series['Netflix'][0]['Dark']['temporadas'])
print(prom1)

#2) Obtener el promedio de calificacion de todas las temporadas de la serie The Mandalorian
print("Promedio de calificacion de todas las temporadas de la serie The Mandalorian:")
prom2 = (series['Disney Plus'][0]['The Mandalorian']['temporadas']['Temporada 1']['calificacion']) / len(series['Disney Plus'][0]['The Mandalorian']['temporadas'])

print(prom2)

#3) Obtener el primer tag de la temporada 1 de The Last of Us
print("Primer tag de la temporada 1 de The Last of Us:")
tag = series['HBO'][1]['The Last of Us']['temporadas']['Temporada 1']['tags'][0]

print(tag)

#4) Obtener el numero de series emitidas por Disney Plus
print("Numero de series emitidas por Disney Plus:")
numSeries = len(series['Disney Plus'])

print(numSeries)

#5) Obtener nombre del director de la primera temporada de The Mandalorian
print("Director de la primera temporada de The Mandalorian:")
nomDir = series['Disney Plus'][0]['The Mandalorian']['temporadas']['Temporada 1']['direccion']

print(nomDir)

#6) Obtener el numero de series emitidas por Netflix
print("Numero de series emitidas por Netflix:")
numSerNetflix = len(series['Netflix'])

print(numSerNetflix)

#7) Obtener el tercer tag de la temporada 1 de Squid Game
print("Tag 3 de la temporada 1 de Squid Game:")
tag3SquidGame = series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['tags'][2]

print(tag3SquidGame)

#8) Obtener nombre del director de la primera temporada de Squid Game
print("Director de la primera temporada de Squid Game:")
dirPrimTempSquidGame = series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['direccion']

print(dirPrimTempSquidGame)

#9) Obtener nombre del director de la segunda temporada de The Mandalorian
print("Director de la segunda temporada de The Mandalorian:")
dirSegundaTempMand = series['Disney Plus'][0]['The Mandalorian']['temporadas']['Temporada 2']['direccion']

print(dirSegundaTempMand)

#10) Cambiar el segundo tag de la temporada 1 de The Last of Us por "hongos buenos"
print("Cambio de segundo tag de la temporada 1 de The Last of Us:")
series['HBO'][1]['The Last of Us']['temporadas']['Temporada 1']['tags'] = list(series['HBO'][1]['The Last of Us']['temporadas']['Temporada 1']['tags']) 

series['HBO'][1]['The Last of Us']['temporadas']['Temporada 1']['tags'][1] = 'hongos buenos'
series['HBO'][1]['The Last of Us']['temporadas']['Temporada 1']['tags'] = tuple(series['HBO'][1]['The Last of Us']['temporadas']['Temporada 1']['tags'])

print(series['HBO'][1]['The Last of Us']['temporadas']['Temporada 1']['tags'])

#11) Cambiar el segundo tag de la temporada 1 de Squid Game por "kpop"
print("Cambio de segundo tag de la temporada 1 de Squid Game:")
series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['tags'] = list(series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['tags'])

series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['tags'][1] = 'kpop'

series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['tags'] = tuple(series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['tags'])

print(series['Netflix'][2]['Squid Game']['temporadas']['Temporada 1']['tags'])

#12) Cambiar la calificion de la tercr temporada de dark a 10
print("Cambio de calificacion de la tercera temporada de Dark:")
series['Netflix'][0]['Dark']['temporadas']['Temporada 3']['calificacion'] = 10

print(series['Netflix'][0]['Dark']['temporadas']['Temporada 3']['calificacion'])

#13) Obtener el promedio de calificaciones de todas las temporadas de la serie Dark
print("Promedio de calificaciones de todas las temporadas de la serie Dark:")

promCalifDark = (series['Netflix'][0]['Dark']['temporadas']['Temporada 1']['calificacion']
                 + series['Netflix'][0]['Dark']['temporadas']['Temporada 2']['calificacion']
                 + series['Netflix'][0]['Dark']['temporadas']['Temporada 3']['calificacion']) / len(series['Netflix'][0]['Dark']['temporadas'])

print(promCalifDark)

#14) Via consola, pedir al usuario que escriba un tag con el que le gustaria calificar la primer temporada de House of the Dragon.
#Si el tag ya existe dentro de los tags, indicar al usuario que dicho tag ya existe e imprimir la estructura
#correspondiente. Si el tag no existe, preguntar al usuario si desearia agregar dicho tag a la estructura.
#Si el usuario selecciona "Si" agregar el tag, si selecciona "No" imprimir "ta bueno pues"
#Imprimir la estrucutra final

print("\n--------------------------------------------------")
userTag = input("Escribe un tag para calificar la primera temporada de House of the Dragon: ")
if userTag in series['HBO'][0]['House of the Dragon']['temporadas']['Temporada 1']['tags']:
    print("El tag ya existe")
    print(series['HBO'][0]['House of the Dragon']['temporadas']['Temporada 1']['tags'])
else:
    if input("El tag no existe, deseas agregarlo?: ").lower() == "si":
        series['HBO'][0]['House of the Dragon']['temporadas']['Temporada 1']['tags'] = list(series['HBO'][0]['House of the Dragon']['temporadas']['Temporada 1']['tags'])
        series['HBO'][0]['House of the Dragon']['temporadas']['Temporada 1']['tags'].append(userTag)
        tuple(series['HBO'][0]['House of the Dragon']['temporadas']['Temporada 1']['tags'])
        print(series['HBO'][0]['House of the Dragon']['temporadas']['Temporada 1']['tags'])
    else:
        print("Ta bueno pues")

print("--------------------------------------------------\n")

#15 via consola, el usuario debe ingresar los campos que compondran la temporada 2 de the last of us.
#La consola debe pedir al usuario el numero de episodios, el nombre del director, la calificacion,
#las vistas y una tag. Aniadir estos datos a la estructura correspondiente. Al final, imprimir el diccionario completo
#El resultado debe verse mas  o menos asi:
#RECUERDEN COMO SE AGREGAN KEYS A UN DICCIONARIO GUINIO GUINIO
'''
'The Last of Us':{
                'temporadas':{
                    'Temporada 1':{
                        **Estos datos ya estan comododados
                    },
                    'Temporada 2':{
                        **Aqui van los datos recolectados via consola
                    }
                }
'''
print("\n--------------------------------------------------")

print("A continuación ingresarás los datos de la temporada 2 de The Last of Us")
numEpisodios = int(input("Ingresa el numero de episodios: "))
nomDirTLU = input("Ingresa el nombre del director: ") 
califTLU = float(input("Ingresa la calificación: "))
vistasTLU = int(input("Ingresa las vistas: "))
tagsTLU = tuple([input("Ingresa un tag: ")])

series['HBO'][1]['The Last of Us']['temporadas']['Temporada 2'] = {'episodios': numEpisodios, 
                                                                   'direccion': nomDirTLU, 
                                                                   'calificacion': califTLU, 
                                                                   'vistas': vistasTLU, 
                                                                   'tags': tagsTLU
                                                                   }
print(series['HBO'][1])

print("--------------------------------------------------\n")


