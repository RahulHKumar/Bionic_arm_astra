/*Rough code to control a bionic arm
 * using 3 electronic muscle sensors and
 * have complete control over wrist, fingers
 * and arm lift motions
 * NOTE: The code below is subject to changes 
 * after further research and practice about the 
 * bionic arm concept
 */

#include <Stepper.h>
#include <Servo.h>

//The analog signals from 3 muscle sensors
int mus_sense1=A0;
int mus_sense2=A1;
int mus_sense3=A2;
//Servo motors for the fingers' close & open motion
int servo_fing=9;
Servo four_fing;
int servo_thumb=10;
Servo thumb;
//Servo motor at elbow joint
int servo_elbow=11;
Servo elbow;
//Stepper motion for the wrist
//subject to values from datasheet
int stepsPerRevolution=2048;
int motSpeed=1;
int dt=500;
Stepper wrist(stepsPerRevolution,4,5,6,7);

void setup() {
  Serial.begin(9600);
  //sensor inputs
  pinMode(mus_sense1,INPUT);
  pinMode(mus_sense2,INPUT);
  pinMode(mus_sense3,INPUT);
  pinMode(mus_sense4,INPUT);
  //servo and stepper outputs
  wrist.setSpeed(motSpeed);
  four_fing.attach(servo_fing);
  thumb.attach(servo_thumb);

void loop() {
  //Say for example (SFE),sensor1 controls elbow joint
  sense1=analogRead(mus_sense1);
  pos1=(130./1023.)*sense1+20;//subject to servo angle as per data sheet
  elbow.write(pos1)
  //SFE, sensor2 controls finger movements
  sense2=analogRead(mus_sense2);
  pos2=(130./1023.)*sense2+20;//subject to servo angle as per data sheet
  four_fing.write(pos2)
  thumb.write(pos2)
  //SFE, sensor3 controls the wrist
  if(analogRead(mus_sense3)>50)//subject to testing of the sensor
  {
    wrist.step(stepsPerRevolution/3);
    delay(dt);
    wrist.step(-stepsPerRevolution/3);
    delay(dt);
    //the above code snippet sways the wrist back and forth through 120 degrees
    //the future updates of this code should be able to control the angle based on the signal
  }
}
  

}
