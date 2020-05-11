#include <Wire.h>
#include <ZumoShield.h>

ZumoMotors motors;
ZumoBuzzer buzzer;
ZumoReflectanceSensorArray linesensors(QTR_NO_EMITTER_PIN);

const char startup[] PROGMEM = 
  "! V10 L8 >e- e-16 b-. a-.. >e- b-..";

const char completed[] PROGMEM =
  "! V10 L8 g#e-<g#<b-";

const char right[] PROGMEM = 
  "! V10 L16 >c>d>e";

const char left[] PROGMEM = 
  "! V10 L16 >e>d>c";


int BASE_SPEED_L = 325;
int BASE_SPEED_R = 300;
double PROPORTION_GAIN = 0.2;
double DERIVATIVE_GAIN = 1;
int last_error = 0;

int INTERSECTION_LEFT_TURN = 0;
int INTERSECTION_RIGHT_TURN = 1;
int INTERSECTION_T = 2;
int INTERSECTION_CROSS = 3;
int INTERSECTION_LEFT_T = 4;
int INTERSECTION_RIGHT_T = 5;
int FINISH = 6;
int NO_INTERSECTION = 7;


void setup() {

  Serial.begin(9600);
  Serial.print("Starting...");
  
  buzzer.playFromProgramSpace(startup);

  // calibrating sensors to darkest and lightest values in environment
  int i;
  int spin_direction = 1;
  motors.setSpeeds(80*spin_direction, -80*spin_direction);

  for(i = 0; i<250; i++){
    linesensors.calibrate();
    if(i%50 == 25){ // every 50 loops, starting on loop 25...
      spin_direction = -spin_direction;
      motors.setSpeeds(80*spin_direction, -80*spin_direction);
    }                              
    delay(20);
  }
  motors.setSpeeds(0,0);
  delay(500);

}

// to store line sensor data
unsigned int sensor_vals[6];
int line_position;

char solution[25];
int solution_position = 0;

void loop() {

  line_position = linesensors.readLine(sensor_vals);

  if (sensor_vals[0] == 1000 && sensor_vals[5] == 1000) {
    complete();
  
  } else if (sensor_vals[2] == 0 && sensor_vals[3] == 0) {
    buzzer.playNote(NOTE_C(5), 200, 15);
    u_turn();
    
  } else if (sensor_vals[0] > 800 && sensor_vals[1] > 800) {
    buzzer.playFromProgramSpace(left);

    turn_left();
    solution[turn_counter] = 1;
  
  } else if (sensor_vals[4] > 800 && sensor_vals[5] > 800) {
    buzzer.playFromProgramSpace(right);
    
    turn_right();
    solution[turn_counter] = 2;
  
  } else {
    keep_following();
  
  }
}


//////////////////////////////////////////////////////////////////////////////////////////

int get_intersection_type() {
  
  bool line_on_left = sensor_vals[0] > 500;
  bool line_on_right = sensor_vals[5] > 500;
  
  bool line_on_left_ever = line_on_left;
  bool line_on_right_ever = line_on_right;

  int finish_counter = 0;
  
  while(line_on_left || line_on_right){
    linesensors.read(sensor_vals);
    line_on_left = sensor_vals[0] > 500;
    line_on_right = sensor_vals[5] > 500;

    line_on_left_ever = line_on_left || line_on_left_ever;
    line_on_right_ever = line_on_right || line_on_right_ever;

    finish_counter++;
    if(finish_counter > 60){
      return FINISH;
    }
  }
}

void turn_left() {
  solution_position++;
  motors.setSpeeds(-BASE_SPEED_L, BASE_SPEED_R);
  
  linesensors.read(sensor_vals);
  while(sensor_vals[0] > 500 && sensor_vals[1] > 500){
      linesensors.read(sensor_vals);
  }
  delay(90);
}


void turn_right() {
  solution_position++;
  motors.setSpeeds(BASE_SPEED_L, -BASE_SPEED_R);
  
  linesensors.read(sensor_vals);
  while(sensor_vals[0] > 500 && sensor_vals[1] > 500){
      linesensors.read(sensor_vals);
  }
  delay(90); 
}

void u_turn() {
  motors.setSpeeds(-BASE_SPEED_L, BASE_SPEED_R);
  delay(400);
}


void keep_following() {

    int error = line_position - 2500;
    int error_change = error - last_error;
    int left_speed = BASE_SPEED_L + PROPORTION_GAIN * error + DERIVATIVE_GAIN * error_change;
    int right_speed = BASE_SPEED_R + -PROPORTION_GAIN * error + -DERIVATIVE_GAIN * error_change;
    last_error = error;
    
    motors.setSpeeds(left_speed, right_speed); 
}


void complete() {
  motors.setSpeeds(0, 0);
  buzzer.playFromProgramSpace(startup);
    
  while(true) {
    // stay stopped!
  }
}
