#include <Servo.h>

const int SERVO_PIN = 12;
const int trigPin = 10;
const int echoPin = 11;

// Límites un poco más estrechos que 15–165: menos esfuerzo mecánico (menos crujido)
const int ANGLE_MIN = 30;
const int ANGLE_MAX = 150;
const int ANGLE_STEP = 2;

const int MAX_DISTANCE_CM = 120;
const unsigned long PULSE_TIMEOUT_US = 35000UL;

// Tiempo con servo energizado para llegar al ángulo (SG90 con carga ligera)
const unsigned int SERVO_MOVE_MS = 180;

Servo myServo;
int currentAngle = ANGLE_MIN;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  myServo.attach(SERVO_PIN);
  moveServoTo(ANGLE_MIN);
  delay(400);
}

void loop() {
  sweep(ANGLE_MIN, ANGLE_MAX, ANGLE_STEP);
  sweep(ANGLE_MAX, ANGLE_MIN, -ANGLE_STEP);
}

void sweep(int from, int to, int step) {
  if (step > 0) {
    for (int i = from; i <= to; i += step) {
      readAndSend(i);
    }
  } else {
    for (int i = from; i >= to; i += step) {
      readAndSend(i);
    }
  }
}

void readAndSend(int angle) {
  moveServoTo(angle);
  int dist = measureDistanceCm();
  sendReading(angle, dist);
}

void moveServoTo(int angle) {
  angle = constrain(angle, ANGLE_MIN, ANGLE_MAX);
  currentAngle = angle;
  myServo.write(angle);
  delay(SERVO_MOVE_MS);
}

void sendReading(int angle, int dist) {
  Serial.print(angle);
  Serial.print(',');
  Serial.print(dist);
  Serial.print('.');
}

int measureDistanceCm() {
  myServo.detach();
  delay(3);

  // Tomamos varias muestras y usamos la MEDIANA en vez del mínimo.
  // El mínimo es muy sensible a un solo eco falso/ruidoso (rebote eléctrico,
  // interferencia, etc.): basta UNA lectura corta espuria para que siempre
  // reporte esa misma distancia "fantasma". La mediana ignora ese tipo de
  // valores sueltos mientras la mayoría de las muestras coincidan.
  const int NUM_SAMPLES = 5;
  int samples[NUM_SAMPLES];
  int count = 0;

  for (int s = 0; s < NUM_SAMPLES; s++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    unsigned long echoUs = pulseIn(echoPin, HIGH, PULSE_TIMEOUT_US);

    if (echoUs > 0) {
      int d = (int)(echoUs * 0.034 / 2);
      if (d >= 2 && d <= MAX_DISTANCE_CM) {
        samples[count++] = d;
      }
    }
    delayMicroseconds(100); // deja que el eco anterior se disipe antes del siguiente pulso
  }

  myServo.attach(SERVO_PIN);
  myServo.write(currentAngle);

  if (count == 0) {
    return -1; // ningún eco válido -> indeterminado (marcador explícito, no una distancia)
  }

  // Ordena las muestras válidas (count es pequeño, un sort simple basta)
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (samples[j] < samples[i]) {
        int tmp = samples[i];
        samples[i] = samples[j];
        samples[j] = tmp;
      }
    }
  }

  return samples[count / 2]; // valor mediano
}
