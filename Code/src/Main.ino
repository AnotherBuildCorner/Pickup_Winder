#include <Screen.ino>

#define revdiv 2

// --------------------Startup code--------------------
void setup()
{  
   display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
   Serial.begin(9600);

             // set up Serial library at 9600 bps
  PinDeclare();
  Calculate_len();
   //Presets();
   
 //analogWrite(GateLED,GateLEDPwr);
 ESC.attach(ESCPin);
 servo.attach(ServoPin);  
 TestScreen();  
 startup_disp(); 
 delay(1000);
}

//--------------------- Main code -------------------------------
void loop(){
static bool disable_flag = false;
int t1 = millis();
int sw;
static int screen = 1;
static int t2 = 0;
if(disable_flag == false){


GateCount();
SpeedControl();
RangeTest();
StatusV2();

sw = Enc_Sw(t1);

screen = RunScreenCtrl(screen,sw,3);
if(t1 - refresh > t2){
  t2 = t1;
  if (Go == true){
  //rev_count += 50;
  }
Serial.println(GateRead);
RunScreen(Go,rev_count,t1,screen);
}


if (rev_count < winds){  
if(rev_count < winds-Spool){
  Go = digitalRead(SwitchPin);}


if(Go == true && HandWind == false){
//current_angle = ServoDir(current_angle,dir,steps);
dir = Flip(current_angle);  

          
}}}

if(rev_count >= winds-Spool){
Go = false;        
}


if(rev_count >= winds){


  if(disable_flag == false){
    Go = false;
   disable_flag = true;
    Serial.println("Winding Finished");
    Serial.println(rev_count);
    Calculate_len();
    FinishScreen(rev_count,full_len,DC);
    delay(1000);

  }

  ExitCtrl(t1,t2);
  

   
    
    
    }}
    
