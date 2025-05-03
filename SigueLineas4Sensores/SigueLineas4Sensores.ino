#include "Pines.h"
#include <QTRSensors.h>

QTRSensors sigueLineas;

const uint8_t SensorCount = 8;

uint16_t sensorValues[SensorCount];

const int freq = 5000;
const int resolution = 8;

const int umbral = 3333;


void setup() {
  Serial.begin(9600);
  inicializarQTR();
  inicializarMotores();
  while (digitalRead(BOTON) == 0) {
  }
}
void loop() {
  sigueLineas.read(sensorValues);
  for (int i = 0; i < 8; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.print('\n');

  if (sensorValues[2] > umbral && sensorValues[3] > umbral && sensorValues[4] < umbral && sensorValues[5] < umbral) {
    Motor(10, -80);
  } else if (sensorValues[2] < umbral && sensorValues[3] < umbral && sensorValues[4] > umbral && sensorValues[5] > umbral) {
    Motor(-80, 10);
  } else if (sensorValues[4] > umbral && sensorValues[5] > umbral && sensorValues[6] > umbral && sensorValues[7] > umbral) {
    Motor(50, 50);
    delay(666);
    Motor(-60, 60);
    delay(1333);
    Motor(50, 50);
    delay(100);
  } else if (sensorValues[0] > umbral && sensorValues[1] > umbral && sensorValues[2] > umbral && sensorValues[3] > umbral) {
    Motor(50, 50);
    delay(666);
    Motor(60, -60);
    delay(1333);
    Motor(50, 50);
    delay(100);
  } else {
    Motor(50, 50);
  }

  if (sensorValues[0] > umbral) {
    Motor(10, -100);
  } else if (sensorValues[7] > umbral) {
    Motor(-100, 10);
  }
}