#include <ros/ros.h>
#include <std_msgs/String.h>

void callBack(const std_msgs::String::ConstPtr& msg){
    //display the received message
    ROS_INFO("Listener [%s]", msg->data.c_str());
}

int main(int argc, char** argv){
    //initialize the node
    ros::init(argc, argv, "hello_world_listener");
    //create the node handler
    ros::NodeHandle nh;
    //create a subscriber handler
    ros::Subscriber sub = nh.subscribe("chatter",1000,callBack);
    ros::spin();
    return 0;
}
