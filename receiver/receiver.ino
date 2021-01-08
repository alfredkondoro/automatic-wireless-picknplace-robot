#include <Servo.h>
#include <LiquidCrystal.h>

Servo shoulder, elbow, wrist, palm;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
char incomingByte = 0;

void setup(){
  Serial.begin(9600);

  lcd.begin(16, 4);  
  lcd.clear();      
  lcd.setCursor(0,0);
  lcd.print("MATIC BOT");

  shoulder.attach(2);
  elbow.attach(3);
  wrist.attach(4);
  palm.attach(5);
  
}

void loop(){
  if(Serial.available()>0){
    incomingByte = Serial.read();
    if(incomingByte == 1){
      for(int i=20;i<80;i+=1){
         shoulder.write(i);
         elbow.write(i);
         wrist.write(i);
         palm.write(i);
      }            
      lcd.setCursor (0, 1);
      lcd.print("Shoulder");
    }
    else if(incomingByte == 2){
      for(int i=20;i<80;i+=1){
         elbow.write(i);
         wrist.write(i);
         palm.write(i);
      }             
      lcd.setCursor (0, 1);
      lcd.print("Elbow");
    }
    else if(incomingByte == 3){
      for(int i=20;i<80;i+=1){
         wrist.write(i);
         palm.write(i);
      }            
      lcd.setCursor (0, 1);
      lcd.print("Wrist");
    }
    else if(incomingByte == 4){
      for(int i=20;i<80;i+=1){
         palm.write(i);
      }            
      lcd.setCursor (0, 1);
      lcd.print("Palm");
    }
    else{
      lcd.clear();   
      lcd.setCursor (0, 1);
      lcd.print("Press");
    }
  }
}
