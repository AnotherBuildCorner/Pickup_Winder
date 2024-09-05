// ----------------------- Servo Parameters----------------------
int wind_count = 8750;
float arm_length = 13;//arm length from servo center in mm.  19 standard
int underwind = 0; //% underwind  set overwind to 0
int overwind = 0; //% overwind, set underwind to 0
int spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
float faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
float error_margin = 5; // Percent of bobbin width to remove for accident prevention.

//-------------------------- Bobbin Parameters-----------------------


float bobbin_width = 11; //Width in Millimeters gap between two faces for winds.
float bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
float bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

//------------------- Extra parameters---------------

int scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
bool HandWind = false; // Shuts down the servo, for hand winding.  recode for manual servo sweep maybe?

int servoZeroInt = 35; // used to set the minimum point for the servo arm, closest to the plate.
float wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
float wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
int ScatterMin = 1; // scatterwind steps. for the randomizer,
int ScatterMax = 10;
int Pattern [] = {1,3,7,3,2,1,5,2,1,2};
int* ScatterPattern = Pattern;
int Patternlength = 10;
int patternplace = 1;