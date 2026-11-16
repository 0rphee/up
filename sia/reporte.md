## 1. Introducción

Hay muchas maneras de detectar objetos, una de ellas: el radar. Un radar es un sistema que detecta objetos y estima su posición emitiendo una onda y midiendo el tiempo que tarda su eco en regresar. Se utilizan en numerosas aplicaciones, como en aeronaútica, la industria militar, para emitir multas de conducción, y más. Pueden implementarse mediante ondas electromagnéticas o de sonido.

En este proyecto se construyó un radar de barrido sónico capaz de detectar una moneda de 10 pesos mexicanos a una máxima distancia de 100cm, midiendo la distancia entre el sensor y la moneda. El sistema usa un sensor ultrasónico HC-SR04 montado sobre un servomotor, el cual gira de forma continua de un lado a otro para cubrir 120°. Un Arduino Uno se encarga del control del servomotor y el sensor, así como de los cálculos de distancia. El Arduino envía el ángulo y la distancia de detección a una computadora conectada a él, la cual dibuja en tiempo real una pantalla de radar polar, el ángulo actual, la distancia medida y los puntos donde se detectaron objetos.

---

## 2. Objetivos

### Objetivo general

Diseñar y construir un sistema de radar de barrido que detecte una moneda de 10 pesos colocada a diferentes distancias dentro de un área de 1 m × 1 m, e indique la distancia de medida.

### Objetivos específicos

1. Montar físicamente el sensor sobre el motor, controlados por el arduino, logrando girar y detectar objetos.
2. Programar el arduino para el control de movimiento y de emisión de señales, así como el cálculo distancia.
3. Desarrollar una interfaz gráfica que muestre en tiempo real las detecciones del sistema. 

---

## 3. Materiales

- 1 Arduino Uno
  - Opera a 5 V (alimentado por USB)
  - 14 pines digitales (6 con PWM)
- 1 Servomotor MOT-110: gira el sensor para hacer el barrido.
  - Opera de 4.8 V a 6 V
  - Rango de giro de 0° a 180°
- 1 Sensor ultrasónico HC-SR04: mide la distancia a los objetos.
  - Opera a 5 V DC, con un consumo de 15 mA
  - Rango de 2 cm a 400 cm, con precisión de hasta 3 mm
  - Ángulo de medición de 15°
- 9 cables Dupont
- 1 Protoboard
- 1 Computadora
- 1 Moneda de 10 pesos: objeto a detectar

---

## 4. Metodología

### 4.1 Armado

El sensor HC-SR04 se fijó sobre el servomotor, de modo que al girar el servo el sensor apunta a distintos ángulos.

Conexiones:
- 5 V y GND del Arduino a la protoboard, y de ahí al servo y al sensor.
- Señal del servo al pin 12.
- Trig del sensor al pin 10 y Echo al pin 11.

### 4.2 Programa del Arduino

- El servo gira de 30° a 150° y de regreso, en pasos de 2°, de forma continua.
- En cada ángulo, el Arduino espera a que el servo llegue, toma 5 mediciones con el sensor y se queda con la mediana. Así se descartan lecturas falsas aisladas.
- Cada lectura se envía a la computadora por el puerto serial con el formato `angulo,distancia.`. Si no se detectó eco, se envía `-1` como distancia.

### 4.3 Programa de la computadora

- Un programa en Python lee los datos del puerto serial y dibuja una pantalla de radar con la línea de barrido.
- Si la distancia está entre 2 cm y 100 cm, muestra "DETECTADO" con la distancia y marca un punto rojo en la posición del objeto.

### 4.4 Pruebas

Se colocó la moneda verticalmente frente al sensor, a 10, 20, 40, 60, 80 y 100 cm (medidos con flexómetro), y se comparó con la distancia que mostró el radar.

---


## 5. Resultados

El radar hace el barrido de forma continua y muestra en pantalla el ángulo, la distancia y la posición de la moneda cuando la detecta.

| Distancia real (cm) | Distancia medida (cm) | Error (cm) |
|:---:|:---:|:---:|
| 10 | 13 | 3 |
| 20 | 21 | 1 |
| 40 | 41 | 1 |
| 60 | 58 | 2 |
| 80 | 79 | 1 |
| 100 | 97 | 3 |

- La moneda se detectó en todas las distancias, hasta 100 cm.
- El error promedio fue de 1.8 cm.
- El mayor error relativo fue a 10 cm; de 20 cm a 100 cm el error fue de 3 cm o menos.
- La moneda se detecta bien frente al sensor.

---

## 6. Conclusiones

Se construyó un radar de barrido que detecta una moneda de 10 pesos hasta 100 cm y muestra en la computadora su distancia, con un error promedio de 1.8 cm. Con esto se cumplió el objetivo del proyecto.

El sensor ultrasónico sobre un servomotor funcionó bien porque mide la distancia directamente y no depende de la iluminación. Los problemas de lecturas falsas se resolvieron tomando varias mediciones por ángulo y usando la mediana.

La principal limitación es el tamaño de la moneda: se detecta bien de frente, pero no cuando está acostada o inclinada. También hay mucha sensibilidad a ruido de objetos, donde un pequeño obstáculo puede modificar las lecturas.

---

## 7. Bibliografía

Arduino. (s. f.). *Arduino Uno*. https://docs.arduino.cc/hardware/uno-rev3/

Arduino. (s. f.). *Basic Servo Control*. https://docs.arduino.cc/tutorials/generic/basic-servo-control/
ElecFreaks. (s. f.). *Ultrasonic Ranging Module HC-SR04*. https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

Tower Pro. (s. f.). *SG90 Micro Servo* [Hoja de datos].

Liechti, C. (s. f.). *pySerial documentation*. https://pyserial.readthedocs.io/

The Matplotlib Development Team. (s. f.). *API Reference — Matplotlib documentation*. https://matplotlib.org/stable/api/index
