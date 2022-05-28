/*

#include <Servo.h>
Servo servo1;

void setup() {
    servo1.attach(9);
    Serial.begin(9600);

}

void loop() {

    if (Serial.available() > 0) {
        String info;
        info = Serial.readStringUntil('\n');
        if (info.equals("1")) {
            Serial.println("MOVIENDO");
            servo1.write(0);
            delay(500);
            servo1.write(10);
            delay(500);
            servo1.write(40);
            delay(1000);
            servo1.write(80);
            delay(1000);
            servo1.write(120);
            delay(1000);
            servo1.write(160);
            delay(1000);
            servo1.write(170);
            delay(1000);
            servo1.write(180);
            delay(100);
        }
        else if (info.equals("2")) {

            Serial.println("CORRIENDO");
            servo1.write(0);
            delay(500);
            servo1.write(10);
            delay(500);
            servo1.write(80);
            delay(500);
            servo1.write(120);
            delay(500);
            servo1.write(160);
            delay(500);
            servo1.write(180);
            delay(100);

        }
    }
}

*/