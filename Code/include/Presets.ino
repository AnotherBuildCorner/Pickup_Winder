#include <Pre_Calcs.ino>
#include <Patterns.ino>
enum PRE {TB,HB,JM,ST,P90,FB,NP,JAG};
PRE Preset = NP;




void Presets(){
switch(Preset){

case TB:
wind_count = 5500;
arm_length = 13;//arm length from servo center in mm.  19 standard
underwind = 5; //% underwind  set overwind to 0
overwind = 0; //% overwind, set underwind to 0
spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
error_margin = 8; // Percent of bobbin width to remove for accident prevention.

bobbin_width = 6; //Width in Millimeters gap between two faces for winds.
bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
ScatterPattern = Pat1;
Patternlength = Pat1len;
DCR = 5.71;
break;
//---------------------------------------------------------------
case HB:
wind_count = 5500;
arm_length = 13;//arm length from servo center in mm.  19 standard
underwind = 5; //% underwind  set overwind to 0
overwind = 0; //% overwind, set underwind to 0
spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
error_margin = 8; // Percent of bobbin width to remove for accident prevention.

bobbin_width = 6; //Width in Millimeters gap between two faces for winds.
bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
ScatterPattern = Pat1;
Patternlength = Pat1len;
DCR = 5.71;
break;
//---------------------------------------------------------------
case JM:
wind_count = 5500;
arm_length = 13;//arm length from servo center in mm.  19 standard
underwind = 5; //% underwind  set overwind to 0
overwind = 0; //% overwind, set underwind to 0
spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
error_margin = 8; // Percent of bobbin width to remove for accident prevention.

bobbin_width = 6; //Width in Millimeters gap between two faces for winds.
bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
ScatterPattern = Pat1;
Patternlength = Pat1len;
DCR = 5.71;
break;
//---------------------------------------------------------------
case ST:
wind_count = 5500;
arm_length = 13;//arm length from servo center in mm.  19 standard
underwind = 5; //% underwind  set overwind to 0
overwind = 0; //% overwind, set underwind to 0
spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
error_margin = 8; // Percent of bobbin width to remove for accident prevention.

bobbin_width = 6; //Width in Millimeters gap between two faces for winds.
bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
ScatterPattern = Pat1;
Patternlength = Pat1len;
DCR = 5.71;
break;
//---------------------------------------------------------------
case P90:
wind_count = 5500;
arm_length = 13;//arm length from servo center in mm.  19 standard
underwind = 5; //% underwind  set overwind to 0
overwind = 0; //% overwind, set underwind to 0
spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
error_margin = 8; // Percent of bobbin width to remove for accident prevention.

bobbin_width = 6; //Width in Millimeters gap between two faces for winds.
bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
ScatterPattern = Pat1;
Patternlength = Pat1len;
DCR = 5.71;
break;
//---------------------------------------------------------------
case FB:
wind_count = 5500;
arm_length = 13;//arm length from servo center in mm.  19 standard
underwind = 5; //% underwind  set overwind to 0
overwind = 0; //% overwind, set underwind to 0
spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
error_margin = 8; // Percent of bobbin width to remove for accident prevention.

bobbin_width = 6; //Width in Millimeters gap between two faces for winds.
bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
ScatterPattern = Pat1;
Patternlength = Pat1len;
DCR = 5.71;
break;
//---------------------------------------------------------------
case JAG:
wind_count = 5500;
arm_length = 13;//arm length from servo center in mm.  19 standard
underwind = 5; //% underwind  set overwind to 0
overwind = 0; //% overwind, set underwind to 0
spin_dir = -1; // set to -1 for Counter Clockwise, and 1 for Clockwise.
faceplateOffset =0; // distance off of the faceplate to the inside of the bobbin, good for thicker flatwork.
error_margin = 8; // Percent of bobbin width to remove for accident prevention.

bobbin_width = 6; //Width in Millimeters gap between two faces for winds.
bobbin_length = 57; // Length of bobbin in mm. just for estimating wire usage.
bobbin_height = 5; // Width across bobbin in mm. just for esitmating wire usage,

scatterwind = 4; // Set to 1 for random per Layer, 2 for Pattern per step,.
wire_gauge = .0030; //Wire gauge 0.0030 for heavy  0.0025 standard
wire_unit = 25.4;  //(set to 25.4 for inches, 1 for mm)
ScatterPattern = Pat1;
Patternlength = Pat1len;
DCR = 5.71;
break;
//---------------------------------------------------------------
default:
break;
}}