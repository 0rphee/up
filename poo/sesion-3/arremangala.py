import pyttsx3

letra = """
¡Y esto es lo que traigo de mi costa
Pa' que todo el mundo lo baile
Y que nadie se quede sentado porque será multado
¡Y vámonos todos con el baile costeño pues se va!
¡Ay!, arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
Y arremángala y arrempújala
¡Si, señor!, el baile costeño
¡Juy, juy, juy!
¡Ay!, arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
¡Juy!
¡Ay!, arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala, sí
Arremángala, arrempújala, no
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala
Arremángala, arrempújala, sí
¡Iuh, iuh! ¡oh, oh!
"""
print(f"La letra tiene { letra.lower().count('arremángala') } arremángalas")
print(f"La letra tiene { letra.lower().count('arrempújala') } arrempujalas")

engine = pyttsx3.init()

voices = engine.getProperty('voice')

engine.say(letra)
engine.runAndWait()
