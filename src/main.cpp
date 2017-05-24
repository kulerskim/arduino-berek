#include <L298N.h>
#include <NewPing.h>
#include "main.h"

NewPing proximity(PROXIMITY_TRIG, PROXIMITY_ECHO, 200);
L298N wheels(LEFT_SPEED, LEFT_FORWARD, LEFT_BACKWARD, RIGHT_FORWARD, RIGHT_BACKWARD, RIGHT_SPEED);

void setup() {

}

void loop() {

  if(digitalRead(CENTER_LINE_DETECTOR) == HIGH){
    wheels.backward(255, 500);
  }else{
    bool is_something_found = (proximity.ping_cm() < 30 && proximity.ping_cm() > 0);
    if(is_something_found){
      wheels.forward(255, 200);
    }else{
      wheels.turn_left(155, 20);
    }
  }
}
