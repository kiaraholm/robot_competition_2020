#include <Wire.h>
#include <ZumoShield.h>

ZumoMotors motors;
ZumoBuzzer buzzer;
ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);

const char startup[] PROGMEM = 
  "! V10 L8 >e- e-16 b-. a-.. >e- b-..";

const char complete[] PROGMEM =
  "! V10 L8 g#e-<g#<b-";

void setup() {

  Serial.begin(9600);
  buzzer.playFromProgramSpace(startup);

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

int BASE_SPEED_L = 200;
int BASE_SPEED_R = 185;
double PROPORTION_GAIN = 0.2;
double DERIVATIVE_GAIN = 1;
int last_error = 0;

void loop() {
  // put your main code here, to run repeatedly:

    int line_position = linesensors.readLine(sensor_vals);
    Serial.print(sensor_vals[0]);
    Serial.print(" ");
    Serial.println(sensor_vals[5]);
  
    int error = line_position - 2500;
    int error_change = error - last_error;
    int left_speed = BASE_SPEED_L + PROPORTION_GAIN * error + DERIVATIVE_GAIN * error_change;
    int right_speed = BASE_SPEED_R + -PROPORTION_GAIN * error + -DERIVATIVE_GAIN * error_change;
    last_error = error;
    
    motors.setSpeeds(left_speed, right_speed);
  
  while (sensor_vals[0] == 1000 && sensor_vals[5] == 1000) {
    motors.setSpeeds(0, 0);
  }
}
