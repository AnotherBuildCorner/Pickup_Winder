# Pickup Coil Winder. V2
Tried looking for pickup winders on the internet, only to be blown away by the crazy price tags?

I bet you've tried the old school method of a Drill and your fingers, and I can also guess it didn't go well either.

Want the ability to wind a picckup bobbin, without breaking the bank, and without having to sit there with laser focus trying to keep that 42 gauge wire from breaking while the cat is in the way?

Then this design might just be what you need!



Based off of commonly available Hobby RC components, and an ESP32 microcontroller. With a small handful of 3D printed components added, this device can wind all your common guitar pickup bobbins with minimal user input.

![IMG_5642](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/001d1aa1-185a-4b71-91f8-2f50c634e74a)

###Overview:
At the heart of this design is a simple IO PCB with a 5V linear regulator, ESP32, and pin headers to connect other components

![IMG_5639](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/7aef1c27-5cb4-474b-82e9-8dca2aaf58a2)
![PCB Sch](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/14c1607c-d7c3-4524-8521-6694153aa0ad)

And a 3D printed mechanics housing, integrating a 550 sized RC motor, 4:1 Pulley drive, 5mm bearing rod and bearings, encoder wheel, optical sensor, and optional Hall effect sensor

![Drive Assembly v2](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/5dba3096-fec4-483e-a37b-e1ff70a68aa4)
(Full Drive Assembly model)

Assembly Video


https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/35dab373-d6de-44d6-9a98-b22964a5057d


![IMG_5637](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/52068223-d8c1-4400-b09a-177da14368d7)

![Belt Drive v4](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/ec30a706-4a4c-4571-932b-fc76cfe3e652)
![IMG_5631](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/70417786-dd31-46b8-8b7c-052f4ad91959)
![IMG_5632](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/65f10ab3-144d-4912-b9cc-227bc3de0cba)

Annotated image:
![IMG_5642-1](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/9cc1ec5e-1a12-4764-9564-5acf2faf21b4)

On top Panel are three things: The OLED readout, the traverse servo and cradle, and the Wire tensioner/guide assembly.
The oled is a simple Adafruit 1306 OLED  128X64. in a custom holder

![Oled Holder v4](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/328f092b-f39d-47f6-bdab-f88c528b03d8)

The Traverse servo is a commonly available SG90 micro servo located in a 3d printed dovetail cradle with spring tension

![Servo Cradle v5](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/9eef42c2-3ba5-4bfc-8f2e-199b3d4f4d05)

and the wire tensioner is a simple piece of plexiglass with a smooth hole in one end, with a pair of Cymbal felts tensioned by a bolt. The wire passes between the felts, and through a hole in the arm of the servo before being wound to the bobbin.

## Design Choices
### Why the RC components
Initially, back in V 0.5, a stepper motor driver was used instead of RC motors, which eliminates the need for other encoders. However this proved unreliable in testing, as the motor torque was terrible, the drive would sometimes get confused and reverse, runing the bobbin, and the stepper libraries caused the motor to ramp up and down in speed for the auto traverse.

At the time I also had some RC components laying about, and decided to try them as they were "free to me". And for a system to control the auto traverse, a micro servo was the simplest method available since all that's needed is a servo library and micro controller. 

### Belt Drive?
So i've tried direct drive, Gear drive, and belt drive.  They all have pros and cons.

For the direct drive. Motor selection becomes a primary concern. as 550 size RC motors are available in a multitude of torque and speed configurations defined by their turn count.
Problem is these motors are meant to run several thousand RPM. So the 1000 RPM needed is hard to control, and the speed jumps from too slow, to too fast easily. Plus the most commonly available motors don't have enough torque.
Also, if a hall effect sensor is added. the magnet is mounted to the drive flange, which causes instability at high speeds.

So, gear drive?
Two problems here. One is the geartrain to get a 4:1 reduction, as well as enough distance between motor and drive flange. is HUGE. 
Also, the noise was unbearable.

Belt drive on the other hand, has but one major downside over direct drive.  The additional bearings and shafts needed to support the drive flange add cost. 
5mm bore pulleys are easily obtainable and inexpensive. In fact, future versions may receive a CNC style timing belt drive.

### Why not an Arduino?
For a few reasons
One, Arduinos lack the general IO I wanted/needed to upgrade this system.  Version 1 was driven off of a Nano, and couldn't handle the inclusion of a rotary encoder
Two, I have a few ESP32's laying around from other projects, as well as experience using them
Three, ESP32's are Arduino code enabled. So no need to change code base
Four, ESP32's have integrated WiFi, Bluetooth, and Serial Coms. So if the desire should ever strike to create a webpage to control the winder, or maybe an app. The device is already ready to do so.
Five, ESP32's are pretty inexpensive. For the one I used, $10 for a 5MHz clock, around 20 available GPIO, and the communications above? No Brainer in my book.

## Features:

At present the enabled features are:
- Serial communication readout
- Multi screen OLED readout, including estimted DC resistance, wire length usage, and RPM
- Auto Traverse with multiple winding patterns available
- Variable speed and direction control with Auto Stop
- Multiple parameter adjustment, including:
  + Bobbin Size
  + Wire Gauge
  + Insulation Thickness
  + Winding Pattern
  + Faceplate Offset
  + Wind Count
  + Under/Overwind
  + Error margin
- Presets enabled via code edit
- Manual adjustment of winding via joystick control
In the future a set of coded presets will be included and enabled via the Encoder knob and OLED. With the ability to adjust parameters after a preset is selected. This will completely untether the unit from a computer for general usage.

## Parts list
Note, some of these parts come in multiple quantites, prices reflect a Price Per in most cases
- 550 Motor and ESC, $30
- ESP32 Devkit-C V4, $10
- SG90 Micro Servo, $2.50
- Support Bearings, $2
- Drive Shaft, $2
- PCB, $8 for 5, with S&H included (minimum order)
- Cymbal Felts, $4
- Optical Sensor, $1
- Potentiometer, $1
- OLED, $5
- Rotary Encoder, $2
- Switch, $1
- Drive Belt material, $5
- Main Drive flange, $4

Links Will be added at a later date.  

## But what about those 3D parts
Critically, none of the 3D printed parts are a deal breaker for the design. The original V1 design located below) used a plexiglass mount plate and no 3D printed parts.

The belt drive tower can easily be fashioned from a pair of plates, perhaps even wood. So long as the motor can be mounted to it via the faceplate screws, and the bearings fit with enough space for the encoder wheel, the rest is optional. 

The encoder wheel could be simply made with a block of material with a hole through the center, colored white on one side, and black on the other.

the servo cradle is a nice but not required extra. The original was held down by a plate secured with two screws (see V1 below)

The control box isn't required, just makes things a little nicer to look at. A simple piece of thin stock with holes cut in for the power jack, knobs, and switch is all that's needed.
## Original V1 design

![IMG_5275](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/d1dd50ee-d4de-40ff-aab9-2209793f55f2)
![IMG_5626](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/4e65b043-5e4f-4dd3-bda4-283b2693fce7)
![IMG_5628](https://github.com/AnotherBuildCorner/Pickup_Winder/assets/112969078/a21604b3-ff50-4475-9eef-beb4c4613ad2)




The original design utilized an Arduino Nano microcontroller, with a direct drive motor, and custom infared light gate. With a circuit board built on a solderable breadboard. This functioned as an excelent prototype but had a few key problems I wanted to update.

First and foremost, direct drive has it's downsides. While being the quietest operation, it requires specific motor selection to achieve, as 550 size RC motors are classed by turn count, with 12T being a low torque high speed, and up to 80T being high torque Low speed.  Problem is 12T models are the most commonly available, and the speed controller can't control them effectively at the 1000 RPM range, and the available torque is borderline too low to overcome the wire tension.

Additionally, the direct drive requires adding the magnet to the flywheel for the hall sensor. This causes vibrations near the top speed.
Lastly, the Nano lacked the complete GPIO desired to run an OLED, encoder, servo, potentiometer, switch, and extras.
With the lack of an OLED and encoder, the system was permanently tethered to a computer for serial programming and monitoring.

