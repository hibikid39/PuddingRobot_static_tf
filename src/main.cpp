#include <ros/ros.h>
#include <tf2_ros/static_transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <cstdio>
#include <tf2/LinearMath/Quaternion.h>

#define MY_PI 3.14159265358979323846

int main(int argc, char **argv) {
  ros::init(argc,argv, "tf2_lidar");
  
  static tf2_ros::StaticTransformBroadcaster static_broadcaster;
  
  geometry_msgs::TransformStamped static_transformStamped_front;
  geometry_msgs::TransformStamped static_transformStamped_left;
  geometry_msgs::TransformStamped static_transformStamped_right;

  tf2::Quaternion quat;

  static_transformStamped_front.header.stamp = ros::Time::now();
  static_transformStamped_front.header.frame_id = "world";
  static_transformStamped_front.child_frame_id = "laser_front";
  static_transformStamped_front.transform.translation.x = 0.06;
  static_transformStamped_front.transform.translation.y = 0;
  static_transformStamped_front.transform.translation.z = 0;
  quat.setRPY(0, 0, 0);
  static_transformStamped_front.transform.rotation.x = quat.x();
  static_transformStamped_front.transform.rotation.y = quat.y();
  static_transformStamped_front.transform.rotation.z = quat.z();
  static_transformStamped_front.transform.rotation.w = quat.w();
  static_broadcaster.sendTransform(static_transformStamped_front);


  static_transformStamped_left.header.stamp = ros::Time::now();
  static_transformStamped_left.header.frame_id = "world";
  static_transformStamped_left.child_frame_id = "laser_left";
  static_transformStamped_left.transform.translation.x = -0.20;
  static_transformStamped_left.transform.translation.y = -0.27;
  static_transformStamped_left.transform.translation.z = 0;
  quat.setRPY(0, 0, MY_PI/2.0);
  static_transformStamped_left.transform.rotation.x = quat.x();
  static_transformStamped_left.transform.rotation.y = quat.y();
  static_transformStamped_left.transform.rotation.z = quat.z();
  static_transformStamped_left.transform.rotation.w = quat.w();
  static_broadcaster.sendTransform(static_transformStamped_left);


  static_transformStamped_right.header.stamp = ros::Time::now();
  static_transformStamped_right.header.frame_id = "world";
  static_transformStamped_right.child_frame_id = "laser_right";
  static_transformStamped_right.transform.translation.x = -0.20;
  static_transformStamped_right.transform.translation.y = 0.27;
  static_transformStamped_right.transform.translation.z = 0;
  quat.setRPY(0, 0, -MY_PI/2.0);
  static_transformStamped_right.transform.rotation.x = quat.x();
  static_transformStamped_right.transform.rotation.y = quat.y();
  static_transformStamped_right.transform.rotation.z = quat.z();
  static_transformStamped_right.transform.rotation.w = quat.w();
  static_broadcaster.sendTransform(static_transformStamped_right);

  ROS_INFO("Spinning");
  ros::spin();
  return 0;
};
