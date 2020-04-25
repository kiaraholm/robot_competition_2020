#include <Wire.h>
#include <ZumoShield.h>

ZumoMotors motors;
ZumoBuzzer buzzer;
ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);

const char jeopardy[] PROGMEM = 
  "! V9 T130 cfc<fcfc.. cfcfa. g8f8e8d8c#8"
  "cfc<fcfc.. MS f R8 d8c<b-<a<g<f";

void setup() {

  Serial.begin(9600);

  buzzer.playFromProgramSpace(jeopardy);
  // calibrating sensors to darkest and lightest values in environment
  int i;
  int spin_direction = 1;
  motors.setSpeeds(50*spin_direction, -50*spin_direction);
  for(i = 0; i<250; i++){
    linesensors.calibrate();
    if(i%50 == 25){ // every 50 loops, starting on loop 25...
      spin_direction = -spin_direction;
      motors.setSpeeds(50*spin_direction, -50*spin_direction);
    }
    delay(20);
  }
  motors.setSpeeds(0,0);
  delay(500);

}

// to store line sensor data
unsigned int sensor_vals[6];
int last_error = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int line_position = linesensors.readLine(sensor_vals);
  int error = line_position - 2500;

  Serial.println(line_position);
  
  if(error > 50){
    motors.setSpeeds(120,20);
  } else if(error < -50){
    motors.setSpeeds(20,120);
  } else {
    motors.setSpeeds(120,120);
  }
  
}
