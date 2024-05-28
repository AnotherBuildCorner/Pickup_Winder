#include <Core_Functions.ino>



#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_ADDR   0x3c  // OLED display I2C address

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int Comp = 0;
int Ap_len = 0;
int Ap_Dcr = 0;
static int screen_ctrl = 1;
bool switch1=false;

void TestScreen(){
    display.clearDisplay(); // Clear the previous display
    display.setTextSize(2); // Set text size
    display.setTextColor(SSD1306_WHITE); // Set text color
    display.setCursor(0, 0); // Set cursor position
    display.println("Booting"); // Print text
    display.display(); // Display the text
    //delay(1000); // Wait for a second
    


}
int RunScreenCtrl(int screen,int sw,int s_max){
    if(sw == 1){
        screen += 1;
    }
    if( screen > s_max){
        screen = 1;}
    return screen;
}
void RunScreen(int go, int revs, int time, int sw){
    screen_ctrl = sw;
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

        switch(screen_ctrl){
            case 1:
            display.setTextSize(2); // Set text size
            display.setCursor(0, 0); // Set cursor position

            display.setTextSize(1);
            display.print("Target: "); // Print text
            display.println(winds); // Print text
            display.println("-----------------");
            display.setTextSize(2);
            display.println("Count: "); // Print text
            display.println(revs); // Print text

            Comp = (revs*100)/winds;
            
            display.print("%: "); // Print text
            display.println(Comp); // Print text
            

            break;

            case 2:

            display.setTextSize(2); // Set text size
            display.setCursor(0, 0); // Set cursor position

            display.print("RPM: "); // Print text
            display.println(RPM); // Print text
            display.print("Speed: "); // Print text
            display.println(Speed); // Print text
            display.print("Ang: "); // Print text
            display.println(current_angle); // Print text

            break;

            case 3:

            display.setTextSize(2); // Set text size
            display.setCursor(0, 0); // Set cursor position

            Ap_len = (bobbin_length+bobbin_height)*revs/1000;
            Ap_Dcr = DCR*Ap_len;

            display.print("Length [M]: "); // Print text
            display.println(Ap_len); // Print text
            display.print("DCR: "); // Print text
            display.println(Ap_Dcr); // Print text

            break;

            default:

            break;
        
        }
            display.display(); // Display the text


}

void FinishScreen(int revs,int len, float dcr){
            display.clearDisplay();
            display.setTextColor(SSD1306_WHITE);
            display.setTextSize(2); // Set text size
            display.setCursor(0, 0); // Set cursor position

            display.print("-Complete- "); // Print text
            display.setTextSize(1); // Set text size

            display.print("Winds: "); // Print text
            display.println(revs); // Print text
            display.print("DCR: "); // Print text
            display.print(dcr); // Print text
            display.println(" kOhms");
            display.print("Wire: "); // Print text
            display.print(len); // Print text
            display.println(" Meters");
            display.println("--------------");
            display.println("Move switch to off position to reset");

            display.display(); // Display the text
}

void ResetScreen(){
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(2); // Set text size
    display.setCursor(0, 0); // Set cursor position
    display.println("Push");
    display.println("Button");
    display.println("to");
    display.println("reset");
    display.display(); // Display the text
}

void ExitCtrl(int t1, int t2){
  if(t1 - 100 > t2){
    static int exitcase = 2;
    t2 = t1;
    bool ext = digitalRead(SwitchPin);
    bool enc = digitalRead(EncoderSW);
    switch(exitcase){
      case 0:
      if(ext == false){
        exitcase = 1;
        ResetScreen();
        break;
      }
      break;
      case 1:
      
      if(ext == true){
        exitcase = 2;
        break;}
      else if(enc == false){
        exit(0);}
      case 2:
      if(ext == true){
        exitcase = 0;
        FinishScreen(rev_count,full_len,DC);
        break;
      }
      break;
      }
    }
}
    //delay(1000); // Wait for a second
    


