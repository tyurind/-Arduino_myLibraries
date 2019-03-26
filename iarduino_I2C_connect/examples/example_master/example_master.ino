// Библиотека iarduino_I2C_connect разработана для удобства соединения нескольких arduino по шине I2C
// Данная Arduino является ведущим устройством на шине I2C
// Arduino                                            http://iarduino.ru/shop/arduino/
// Trema кнопка                                       http://iarduino.ru/shop/Expansion-payments/knopka-trema-modul.html
// Trema светодиод                                    http://iarduino.ru/shop/Expansion-payments/svetodiod---zelenyy-trema-modul.html
//
// Светодиод нужно подключить к цифровому выводу D13, а кнопку к цифровому выводу D2

// Подключаем библиотеки:
#include <Wire.h>                                     // подключаем библиотеку для работы с шиной I2C
#include <iarduino_I2C_connect.h>                     // подключаем библиотеку для соединения arduino по шине I2C

// Объявляем переменные и константы:
iarduino_I2C_connect I2C2;                            // объявляем переменную для работы c библиотекой iarduino_I2C_connect
const byte           PIN_Button = 2;                  // объявляем константу с указанием номера цифрового вывода, к которому подключена кнопка
const byte           PIN_LED    = 13;                 // объявляем константу с указанием номера цифрового вывода, к которому подключен светодиод

void setup(){
//Wire.setClock(400000);                              // устанавливаем скорость передачи данных по шине I2C = 400кБит/с
  Wire.begin();                                       // инициируем подключение к шине I2C в качестве ведомого (slave) устройства, с указанием своего адреса на шине.
  pinMode(PIN_Button, INPUT);                         // Устанавливаем режим работы вывода кнопки, как вход
  pinMode(PIN_LED, OUTPUT);                           // Устанавливаем режим работы вывода светодиода, как выход
}

void loop(){
//Отправляем данные:
  I2C2.writeByte(0x01,1,digitalRead(PIN_Button));     // Отправляем состояние собственной кнопки ведомому (адрес ведомого 0x01, номер регистра 1, состояние кнопки)
  digitalWrite(PIN_LED, I2C2.readByte(0x01,0));       // Управляем светодиодом в соответствии со значением 0 ячейки массива ведомого с адресом 0x01
}
