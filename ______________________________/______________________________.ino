
#include <TimerOne.h>
const int Trig = 13;
const int Echo = 12;
const int ledPin = 10;  

void setup()
{
pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);
pinMode(ledPin, OUTPUT);

Serial.begin(9600);

  Timer1.initialize(500); 
  Timer1.pwm(10, 0); 

  pinMode(10, OUTPUT);
}

unsigned int time_us=0;

unsigned int distance_sm=0;

void loop()
{
digitalWrite(Trig, HIGH); // Подаем сигнал на выход микроконтроллера
delayMicroseconds(10); // Удерживаем 10 микросекунд
digitalWrite(Trig, LOW); // Затем убираем
time_us=pulseIn(Echo, HIGH); // Замеряем длину импульса
distance_sm=time_us/58; // Пересчитываем в сантиметры
Serial.println(distance_sm); // Выводим на порт

if (distance_sm<100) // Если расстояние менее 100 сантиметром

{
 for(int i=1023; i>=0;i--)
{
  Timer1.pwm(10, i); 
  delay(30); // ставим задержку для эффекта
}
}
}/*else
{
digitalWrite(ledPin, 0); // иначе тушим
}

delay(10)
}*/

