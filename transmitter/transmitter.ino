int btnShoulder = 2;
int btnElbow = 3;
int btnWrist = 4;
int btnPalm = 5;

int stateShoulder = 0;
int stateElbow = 0;
int stateWrist = 0;
int statePalm = 0;

void setup(){
  pinMode(btnShoulder, INPUT);
  pinMode(btnElbow, INPUT);
  pinMode(btnWrist,INPUT);
  pinMode(btnPalm, INPUT);
  Serial.begin(9600);
}

void loop(){
  stateShoulder = digitalRead(btnShoulder);
  stateElbow = digitalRead(btnElbow);
  stateWrist = digitalRead(btnWrist);
  statePalm = digitalRead(btnPalm);

  if(stateShoulder == HIGH){
    Serial.write(1);
  }
  if(stateElbow == HIGH){
    Serial.write(2);
  }
  if(stateWrist == HIGH){
    Serial.write(3);
  }
  if(statePalm == HIGH){
    Serial.write(4);
  }
}
