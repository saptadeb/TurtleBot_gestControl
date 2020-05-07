# HAND GESTURE CONTROL OF A ROBOT USING INTELLIGENT TECHNIQUES
Research conducted at Hochschule Fulda, Germany, for the fulfillment of undergraduate thesis under the supervision of [Dr. Alexander Gepperth](https://www.hs-fulda.de/angewandte-informatik/ueber-uns/professuren/details/person/prof-dr-alexander-gepperth-1238/contactBox) and co-supervised by [Dr. V. Kalaichelvi](https://universe.bits-pilani.ac.in/dubai/kalaichelvi/profile).

## Contents:
- Overview
- Robot Platform
- Running the code
- Misc


## Overview
## Robot Platform
## Running the code
## Misc




changes in 
/share/turtlebot_teleop/package.xml .... and
/lib/turtlebot_teleop/turtlebot_teleop_key.py



#####

run the following commands

ON TURTLEBOT
minimal.launch

ON PC

WINDOW 1
cd ws
catkin_make
source devel/setup.bash
roslaunch fullpkg campf.launch

WINDOW 2
cd
source tensorflow/bin/activate
cd 
cd model
python lstmnodetest.py

WINDOW 3
cd
roslaunch turtlebot_teleop key.....

#####


first run roslaunch softkinetic_camera softkinetic_cameraj.launch 
then roslaunch fullpkg readnsave.launch




roslaunch fullpkg campf.launch
roslaunch softkinetic_camera softkinetic_camera_demo.launch
roslaunch softkinetic_camera softkinetic_cameraj.launch
