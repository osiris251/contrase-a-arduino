#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
#define trigger 5
#define echo 6
#define sound 4
#define pul_1 1
#define pul_2 2
#define pul_3 3

int pul1_bool = false;
int pul2_bool = false;
int pul3_bool = false;

int estadoBoton1 = 0;
int estadoBoton2 = 0;
int estadoBoton3 = 0;

bool limite = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(sound, OUTPUT);
  pinMode(pul_1, INPUT);
  pinMode(pul_2, INPUT);
  pinMode(pul_3, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  //lcd.print("Introducir texto");
}

void loop() {
  // put your main code here, to run repeatedly:
   String text = "buenas";
   long t;
   long d;

   estadoBoton1 = digitalRead(pul_1);
   estadoBoton2 = digitalRead(pul_2);
   estadoBoton3 = digitalRead(pul_3);

   digitalWrite(trigger, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigger, LOW);

   t = pulseIn(echo, HIGH);
   d = t/59;

   if(d <50) {
    if(limite == false) {
       tone(sound, 440, 1000);
       lcd.print("Ingresa");
       lcd.setCursor(0, 1);
       lcd.print("Contraseña");
       if(estadoBoton1 == LOW) {
        pul1_bool = true;
       }
       if(estadoBoton2 == LOW) {
        pul2_bool = true;
       }
       if(estadoBoton3 == LOW) {
        pul3_bool = true;
       }
       if(pul1_bool == false && pul2_bool == true && pul3_bool == true) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Contraseña ");
        lcd.setCursor(0, 1);
        lcd.print("correcta!");
       } else {
        pul1_bool = false;
        pul2_bool = false;
        pul3_bool = false;
       }
       limite = true;
    }
   } else {
    lcd.clear();
    pul1_bool = false;
    pul2_bool = false;
    pul3_bool = false;
    limite = false;
   }

   delay(100);
}
