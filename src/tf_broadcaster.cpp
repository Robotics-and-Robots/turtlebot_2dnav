#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "robot_tf_publisher");
  ros::NodeHandle tf_node;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(tf_node.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0, 0, 1), tf::Vector3(0.05, 0.0, 0.205)),
        ros::Time::now(),"base_link", "base_laser_link"));
    // broadcaster.sendTransform(
    //   tf::StampedTransform(
    //     tf::Transform(tf::Quaternion(0, 0, 0.964, 0.267), tf::Vector3(0, 0, 0)),
    //     ros::Time::now(),"world", "map"));
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(0, 0.9635582, 0.2674988, 1), tf::Vector3(15.75, 14.3, 0)),
        ros::Time::now(),"map", "odom"));
    r.sleep();
  }
}
