#include "Contador.h"
#define PIN_BOTON_A 2
#define PIN_BOTON_B 3

Contador C1, C2;

void setup()
{
  Serial.begin(9600);
  pinMode(PIN_BOTON_A, INPUT_PULLUP);
  pinMode(PIN_BOTON_B, INPUT);
  C1.SetContador(10);
  C2.SetContador(100);
}
void loop()
{
  if (detectaFlanco(PIN_BOTON_A) == -1) {
    C1.Incrementar() ;
    Serial.print("C1 = ") ; Serial.println(C1.GetCont());

    C2.Incrementar() ; C2.Incrementar() ; C2.Incrementar();
    Serial.print("C2 = ") ; Serial.println(C2.GetCont());
  }
}

int detectaFlanco(int pin) {
  //Devuelve 1 flanco ascendente, -1 flanco descendente y 0 si no hay nada
  static boolean anterior_estado = digitalRead(pin);
  boolean estado = digitalRead(pin);

  if (anterior_estado != estado) {
    if (estado == HIGH) {
      anterior_estado = estado;
      return 1;
    }
    else {
      anterior_estado = estado;
      return -1;
    }
  }
  else {
    anterior_estado = estado;
    return 0;
  }
}

