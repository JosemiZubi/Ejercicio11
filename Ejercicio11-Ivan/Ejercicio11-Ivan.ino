#include "Contador.h"
#define pin 3
int flanco = 0; // variable para detectar cambios de estado


Contador Micontador;

void setup() {
  // put your setup code here, to run once:
  Micontador.SetContador(0);
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (detectarFlanco(digitalRead(pin)) == 1) {
    Micontador.Incrementar();
    Serial.println(Micontador.GetCont());
  }
}

int detectarFlanco(boolean estado) { // funcion para detectar el cambio de estado del pin
  if (estado == true && flanco == 0) {
    flanco = 1;
    //pulsaciones += 10;
    Serial.println("Flanco ascendente!");
    return 1;
  }
  if (estado == false && flanco == 1) { // si pin deja de estar high ponemos el flanco a 0
    flanco = 0;
    Serial.println("Flanco descendente!");
    return -1;
  }
  if (estado == true && flanco == 1) {
    return 0;
  }
}
