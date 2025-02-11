#include <Arduino.h>

int sensor = 23;
int led = 22;

int estado_led = 0;

void setup()
{
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
}

void loop()
{
  int sinal = digitalRead(sensor);
  int cont = 0;

  if (sinal == 0 && estado_led == 0)
  {
    delay(200);
    int i = 0;
    while (i < 300)
    {
      int sinal = digitalRead(sensor);
      if (sinal == 0)
      {
        digitalWrite(led, 1);
        estado_led = 1;
      }
      delay(1);
      i++;
    }
  }
  else if (sinal == 0 && estado_led == 1)
  {
    delay(200);
    int i = 0;
    while (i < 300)
    {
      int sinal = digitalRead(sensor);
      if (sinal == 0)
      {
        digitalWrite(led, 0);
        estado_led = 0;
      }
      delay(1);
      i++;
    }
  }
}
