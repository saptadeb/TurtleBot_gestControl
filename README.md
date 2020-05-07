# Hand Gesture Control of a Robot using Intelligent Techniques
Research conducted at Hochschule Fulda, Germany, for the fulfillment of undergraduate thesis under the supervision of [Dr. Alexander Gepperth](https://www.hs-fulda.de/angewandte-informatik/ueber-uns/professuren/details/person/prof-dr-alexander-gepperth-1238/contactBox) and co-supervised by [Dr. V. Kalaichelvi](https://universe.bits-pilani.ac.in/dubai/kalaichelvi/profile).

## Contents:
- [Overview](https://github.com/saptadeb/TurtleBot_gestControl#overview)
- [Hardware Used](https://github.com/saptadeb/TurtleBot_gestControl#hardware-used)
- [Running the code](https://github.com/saptadeb/TurtleBot_gestControl#running-the-code)
- [Misc](https://github.com/saptadeb/TurtleBot_gestControl#misc)
- [Videos](https://github.com/saptadeb/TurtleBot_gestControl#videos)
- [References](https://github.com/saptadeb/TurtleBot_gestControl#references)


## Overview

<div style="text-align: justify"> 
This research presents a unique application of hand gestures in the robotics field, to control the movement of a mobile robot using hand gestures. It is carried out in two folds – a study on machine learning algorithms to detect four classes of hand gestures and an elaborate investigation on the implementation of Robot Operating System on the research platform, TurtleBot. The initial part of this thesis revolves around the study of both the areas and preliminary tests. In recent times, a lot of emphasis has been put on the use of Recurrent Neural Networks for applications which have a temporal dependency. A major advantage of using RNN is its ability to adapt its network with the influx of new incoming data.
</div>

## Hardware Used

- TurtleBot 2, the robot platform for this research
- Orbecc Astra camera, onboard 3D sensor
- Intel NUC,  onboard computer

TurtleBot – Host PC Network Configuration:
![](/images/network-config.png)

Flowchart of the whole system:
![](/images/pipeline.png)

## Running the code

### 1. To read the Point-cloud data and save it in usable form
- `roslaunch softkinetic_camera softkinetic_cameraj.launch` 
- `roslaunch fullpkg readnsave.launch`

### 2. Full execution

#### On Turtlebot
- `minimal.launch`

#### On Offboard Computer

Terminal 1
- `cd ws`
- `catkin_make`
- `source devel/setup.bash`
- `roslaunch fullpkg campf.launch`

Terminal 2
- `source tensorflow/bin/activate`
- `cd model`
- `python lstmnodetest.py`

Terminal 3
- `roslaunch turtlebot_teleop key`

## Misc

Check out the [final report](/report/final-report.pdf) for more information regarding the research.

### Videos
[Point-to-Point Autonomous Navigation](https://youtu.be/dKH0LBlqB9U)

[Dynamic Obstacle Avoidance](https://youtu.be/lyR__Aati1U)

## References

1. Xu, D., 2006, August. A neural network approach for hand gesture recognition in virtual reality driving training system of SPG. In Pattern Recognition, 2006. ICPR 2006. 18th International Conference on (Vol. 3, pp. 519-522). IEEE.
1. Buchmann, V., Violich, S., Billinghurst, M. and Cockburn, A., 2004, June. FingARtips: gesture based direct manipulation in Augmented Reality. In Proceedings of the 2nd international conference on Computer graphics and interactive techniques in Australasia and South East Asia (pp. 212-221). ACM.
1. Sarkar, A., Gepperth, A., Handmann, U., & Kopinski, T. “Dynamic Hand Gesture Recognition for Mobile Systems Using Deep LSTM”. In 2017 International Conference on Intelligent Human Computer Interaction (pp. 19-31). Springer, Cham.
1. Pasarica, A., Miron, C., Arotaritei, D., Andruseac, G., Costin, H., & Rotariu, C. “Remote control of a robotic platform based on hand gesture recognition”. In E-Health and Bioengineering Conference (EHB), 2017 (pp. 643-646). IEEE.
1. Gao, X., Shi, L., & Wang, Q. “The design of robotic wheelchair control system based on hand gesture control for the disabled”. In Robotics and Automation Sciences (ICRAS), 2017 International Conference on (pp. 30-34). IEEE.
1. Yu, Y., Wang, X., Zhong, Z., & Zhang, Y. “ROS-based UAV control using hand gesture recognition”. In Control and Decision Conference (CCDC), 2017 29th Chinese (pp. 6795-6799). IEEE.
1. O'Kane, J.M., 2014. A gentle introduction to ROS.
1. Quigley, M., Conley, K., Gerkey, B., Faust, J., Foote, T., Leibs, J., Wheeler, R. and Ng, A.Y., 2009, May. ROS: an open-source Robot Operating System. In ICRA workshop on open source software (Vol. 3, No. 3.2, p. 5).
1. Abadi, M., Barham, P., Chen, J., Chen, Z., Davis, A., Dean, J., Devin, M., Ghemawat, S., Irving, G., Isard, M. and Kudlur, M., 2016, November. TensorFlow: A System for Large- Scale Machine Learning. In OSDI (Vol. 16, pp. 265-283).
1. Mikolov, T., Karafiát, M., Burget, L., Černocký, J. and Khudanpur, S., 2010. Recurrent neural network based language model. In Eleventh Annual Conference of the International Speech Communication Association.
1. Zaremba, W., Sutskever, I. and Vinyals, O., 2014. Recurrent neural network regularization. arXiv preprint arXiv:1409.2329.
1. Hochreiter, S. and Schmidhuber, J., 1997. Long short-term memory. Neural computation, 9(8), pp.1735-1780. 23
1. Thrun, S., Fox, D., Burgard, W. and Dellaert, F., 2001. Robust Monte Carlo localization for mobile robots. Artificial intelligence, 128(1-2), pp.99-141.
