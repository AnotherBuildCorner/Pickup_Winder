#include <Presets.ino>

//----------------------- Functions ---------------------------------------
static int time2 = 0;
static int ECT = 0;
bool state = true;
static bool flag = false;
static int cases = 0;
int status;
int full_len;
float DC;
int av1[] = {0,0,0,0};
int dead = 2000;


void Status(){
Serial.print("Count: ");
Serial.print(rev_count);
Serial.print("   Speed: ");
Serial.print(Speed);

Serial.print("   Current Angle: ");
Serial.print(current_angle);

Serial.print("   Dir: ");
Serial.print(dir);
Serial.print("   Steps: ");   
Serial.print(steps);
Serial.print("   RPM: ");
Serial.println(RPM);
}

void StatusV2(){

if(sysrevs <= rev_count){
  sysrevs = rev_count + 5;
  Status();
}
}

void SpoolDown(){
  if(rev_count >= winds - Spool){
    if(RPM >= SpoolRPM){
      CWMaxSpeed += 1;
      CCWMaxSpeed -=1;
    }
  }
  }

int JoystickRead(){

int joyx = analogRead(JoyX);  
int joyy = analogRead(JoyY);
joyx = max(joyx,dead);
joyy = max(joyy,dead); 
int joyxy = -joyx+joyy;

joyxy = map(joyxy,-2095,2095,-1000,1000);
Serial.println(joyxy);
return joyxy;
}

void RangeTest(){
bool active = digitalRead(SwitchPin);
if(active == false){
  int joy = JoystickRead();
  PotVal = analogRead(PotPin);
  //Serial.println(PotVal);
  float range;
  if(joy != 0){
    range = map(joy,-1000,1000,servoZero,angle);
  }
  else{
    range = map(PotVal,Potmin,Potmax,servoZero,angle);
  }

  
  PotValPast=range;
  servo.write(range);
}}

float ServoDir(float current_angle, int dir, int steps){
  
  float angle_div = steps*angle_seg*rev_mult;
  float out_angle = current_angle + angle_div * dir;

      if(out_angle >= angle){
        out_angle = angle;
        dir = dir * -1;}
      if(out_angle <= servoZero){
        out_angle = servoZero;
        dir = dir * -1;
      }
      
  return out_angle;
}

void ServoControl(){
current_angle = ServoDir(current_angle,dir,steps);
int joy = JoystickRead();
if(joy != 0){
  joy = map(joy,-1000,1000,servoZero,angle);
  servo.write(joy); }
 else{ servo.write(current_angle);}
if(scatterwind == 1){
   steps = random(ScatterMin,ScatterMax);}
if(scatterwind == 3){
  steps = ScatterPattern[patternplace - 1];
  patternplace +=1;
  if(patternplace >= Patternlength){
    patternplace = 1;
  }
}
}

void GateCount(){
GateRead = analogRead(GatePin);
GateRead = 4095-GateRead;
int RPMC;
if(GateRead >= GateMax && Gateflag == 0){
  rev_count = rev_count + 1;
  Gateflag = 1;
  Dif = (millis()-RPMpast)/(1000);
  RPMC = 60/(Dif);
  RPMpast = millis();
  av1[4] = av1[3];
  av1[3] = av1[2];
  av1[2] = av1[1];
  av1[1] = RPMC;
  RPM = (av1[1]+av1[2]+av1[3]+av1[4])/4;

  //Status();
  ServoControl();
  SpoolDown();

  }

if(GateRead <= GateMin && Gateflag == 1){
Gateflag = 0;  
}}

void SpeedControl(){
  PotVal = analogRead(PotPin);
if(spin_dir == -1 && Go == true){
  Speed = map(PotVal,Potmin,Potmax,Stop,CWMaxSpeed);}
if(spin_dir == 1 && Go == true){
  Speed = map(PotVal,Potmin,Potmax,Stop,CCWMaxSpeed);}  
if(Go == false){
    Speed = Stop;
  }
  
  ESC.write(Speed);

}



int Flip(float in_angle){
        if(in_angle >= angle){
        dir = dir * -1;
        if(scatterwind == 2){
          steps = random(ScatterMin,ScatterMax);}
        if(scatterwind == 4){
  steps = ScatterPattern[patternplace - 1];
  patternplace +=1;
  if(patternplace >= Patternlength){
    patternplace = 1;
  }
}
          
}
      if(in_angle <= servoZero){
        dir = dir * -1;
       }
        return dir;

}



void Calculate_len(){
  int layers = winds / layer_winds;
  float wire_len = 0;
  
  for (int x = 0; x <= layers ; x+=1){
    float height = wire_dia*x;
    float wind_len = (((bobbin_length-bobbin_height)+height)*2+((bobbin_height+height)*3.14));
    float one_layer = layer_winds*wind_len;
    wire_len+=one_layer;
  }
  full_len=wire_len/1000;
  DC = DCR*full_len/1000;

  Serial.print("Winds per layer:  ");
  Serial.println(layer_winds);
  Serial.print("Layers of winds:  ");
  Serial.println(layers);
  Serial.print("Meters of wire:  ");
  Serial.println(full_len);
  Serial.print("Estimated DCR:  ");
  Serial.println(DC);
  
}


void startup_disp(){
   Serial.println("------ initializing ------");
   Serial.print("Desired Winds:  ");
   Serial.println(wind_count);
   Serial.print("Bobbin Width in mm:  ");
   Serial.println(bobbin_width);
      Serial.print("Wind Width in mm:  ");
   Serial.println(calculated_width);
   Serial.print("Servo Angle: ");
   Serial.println(sweep);  
      Serial.print("Servo step: ");
   Serial.println(angle_seg);
//      Serial.print("Layer Winds: ");
//   Serial.println(layer_winds);
      Serial.print("Wire Diameter mm: ");
   Serial.println(wire_dia);
   Serial.print("Left Zero: ");
   Serial.print(servoZero);
   Serial.print("   Right limit Zero: ");
   Serial.println(angle);
      Serial.println("----- Estimated Parameters-----");
}

void status_readout(){
  int time1 = millis();
  bool test = digitalRead(SwitchPin);
  if(time1 > time2){
  time2 = time1+200;
  Serial.println("");
  Serial.print(" Gate: ");
  Serial.print(GateRead);
  Serial.print(" Go: ");
  Serial.print(test);
  Serial.print(" Pot: ");
  Serial.print(PotVal);
  Serial.print(" count: ");
  Serial.print(rev_count);
}
}

void spam(){
  int x = GateRead;
  int thresh = 100;
  if(x > thresh){
    Serial.println(x);}
}

int Enc_Sw(int time){
  state = digitalRead(EncoderSW);
  int debounce = 100;
  int holdtime = 750;
  static bool flag = false;
  static int t2 = 0;
  status = 0;
  
switch(cases){
  case 0:
    if(state == false){
      cases = 1;
      t2 = time;

      }
  break;

  case 1:

  if(time - debounce > t2){
      cases = 2;
    }
    break;

  case 2:

  if(time - holdtime > t2 && state == true){
      cases = 4;
      break;   
  }
  else if(state == true){
    cases = 3;
  }
  break;

  case 3:
  status = 1;
  cases = 0;
  ECT = 3;
  flag = true;
  return status;
  break;

  case 4:
  status = 2;
  cases = 0;
  ECT = 4;
  flag = true;
  return status;
  break;
}
return status;
}

