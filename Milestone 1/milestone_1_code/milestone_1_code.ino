#include <Wire.h>
#include <ZumoShield.h>

ZumoMotors motors;

void setup() {

}

void loop() {

  stop_bot();
  delay(500);

  drive_forward();
  delay(5000);
  
  stop_bot();
  delay(500);

}


void stop_bot() {
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
}

void drive_forward() { 
    motors.setLeftSpeed(100);
    motors.setRightSpeed(92.5);  
}
