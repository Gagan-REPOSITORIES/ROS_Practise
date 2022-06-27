#include<ros/ros.h>
#include<std_msgs/String.h>
#include<std_msgs/Int32.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "hello_world_talker");
}