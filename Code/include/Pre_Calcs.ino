#include <Defines.ino>
#include <Parameters.ino>

//---------- Basic setup parameters. Adjustment not required--------
int dir = 1;
int steps = 1;
float deg = 180/3.14;
int rev_mult = 1;
int GateRead = 0;
//bool GateRead = false;
float Speed = 500;
int count = 0;
int Gateflag = 1;
int PotVal = 0;
int PotValPast = 0;
float RPMpast = 0;
float RPM = 0;
float Dif = 0;
bool Go = true;
int motor_steps = 1;
float DCR_42 = 5.71; // Ohms/m
int CWMaxSpeed=CWMaxSpeed_Def;
int CCWMaxSpeed = CCWMaxSpeed_def;
//  ----------- Startup Calculations -------------------------------
int decrement = 0;
float calculated_width = bobbin_width*(1-error_margin/100);
float sweep = deg*(2*asin(calculated_width/(2*arm_length)));
float servoZero = servoZeroInt+deg*(2*asin(faceplateOffset/(2*arm_length)));
float angle = servoZero + sweep;
float current_angle=servoZero;
int winds = wind_count*(1-underwind/100+overwind/100);
int total_steps = winds*motor_steps;
float wire_dia = wire_gauge*wire_unit;
int layer_winds = calculated_width/wire_dia;
float angle_seg = sweep/layer_winds;
int rev_count = 0;
int pos = 0;
int sysrevs = 1;
float DCR = DCR_42;