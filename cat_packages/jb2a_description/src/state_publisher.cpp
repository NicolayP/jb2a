#include <ros/ros.h>
#include <string>
#include <sensor_msgs/JointState.h>

int main(int argc, char **argv){
  ros::init(argc, argv, "state_publisher");
  ros::NodeHandle n;
  ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
  ros::Rate rate(30.0);

  double degree(M_PI/180);

  double angle_base(0);

  sensor_msgs::JointState joint_state;

  while(ros::ok()){
    joint_state.header.stamp = ros::Time::now();
    joint_state.name.resize(5);
    joint_state.position.resize(5);
    joint_state.name[0] = "base_piece100_joint";
    joint_state.position[0] = angle_base;
    joint_state.name[1] = "servo2_arm1-piece12_joint";
    joint_state.position[1] = angle_base;
    joint_state.name[2] = "servo3_arm1-piece15_joint";
    joint_state.position[2] = angle_base;
    joint_state.name[3] = "servo4_arm2-piece16_joint";
    joint_state.position[3] = -angle_base;
    joint_state.name[4] = "servo5_arm3-piece17_joint";
    joint_state.position[4] = -angle_base;

    joint_pub.publish(joint_state);

    angle_base += degree;
    if (angle_base > M_PI/2){
      angle_base = M_PI/2;
      degree *= -1;
    }else if (angle_base < -M_PI/2){
      angle_base = -M_PI/2;
      degree *= -1;
    }
    rate.sleep();
  }
  return 0;
}
