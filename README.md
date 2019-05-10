# jb2a
Robotic arm project

## TODO
Todo list, those objectives can be decomposed in simpler problems if necessary.
* [ ] Find an alimentation for the robot.
* [ ] model robot in gazebo (integrated in ros).
  - correcty place each joint of the robot from the stl file.
  - Compute devnavit and hartenberg parameters for the arm.
* [ ] Run ros on multiple computers, different nodes on raspberry pi and on computer.
* [ ] market study of depth camera and simple RGB camers. Also need to evaluate current stereoscopy state of the art.
* [ ] evaluate current state of the art in inverse kinematics, current research idea, solve inverse kinmatics with RL + [HER](https://arxiv.org/abs/1707.01495). Fist as in the paper, by providing as input the angle of each joint with the desired wrist position, and in a second time, extending the paper by providing as input only a depth map of the scene.
* [ ] design a hand for grasping using [The hand servos][1]
* [ ] evaluate inertia for the piece of the robot. Meshlab is supposed to provide a tool for this, maybe by hand or with an other tool.
## Links

- [The arm servos](https://www.amazon.fr/dp/B0716V3WNH/ref=pe_3044141_185740131_TE_item)
- [The hand servos][1]
- [Adfruit pwm board tutorial](https://learn.adafruit.com/adafruit-16-channel-servo-driver-with-raspberry-pi/overview)
- [ROS tutorial](http://wiki.ros.org/ROS/Tutorials)
- [ROS cheatsheet](https://github.com/ros/cheatsheet/releases)
- [ROS urdf tutorial](https://github.com/ros/urdf_tutorial)
- [ROS tf tutorial](http://wiki.ros.org/tf/Tutorials)

[1]: https://www.amazon.fr/dp/B07KQC5R4H/ref=pe_3044141_185740131_TE_item

## Remarks

- Fred, why is the orientation of servo from arm one opposit to the one in arm2 ? Couldn't we gain a couple of robot workinspace.
- Fred, I would need the object to be placed in the correct orientation in theire own reference frame, i should also get the distance from the reference frame to the rotational axis. 

## Start

1. Install ros kinetict. (follow the tutorials)
2. Create a catkin workspace.
3. copy all cat packages in the src folder of the new catkin workspace.

### Packages

1. jb2a description:
	```
	$ roscd jb2a_description
	$ roslaunch jb2a_description display.launch model:=urdf/jb2a.urdf.xarco
	```
2. Simple robot control:
	```
	$ roscd jb2a_description
	$ roslaunch jb2a_description display2.launch model:=urdf/jb2a.urdf.xarco
	```
   The source code can be found in the src file.


