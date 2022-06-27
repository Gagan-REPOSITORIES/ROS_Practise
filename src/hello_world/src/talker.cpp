#include<ros/ros.h>
#include<std_msgs/String.h>
#include <sstream>

int main(int argc, char** argv){
    //first initialize this node with the identifier
    ros::init(argc, argv,"hello_world_talker");
    //create a node handler
    ros::NodeHandle nh;
    //create a topic publisher with the help of node handler
    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter",1000);//chatter is topic name , chatter_pub is handler
    //create a sleep handler
    ros::Rate loop_rate(1); //its the frequency of execution
    int count = 0; //temp variable to count

    while(ros::ok()) {
        //create a string variable to publish the message
        std_msgs::String msg;
        //create a variable to put it to terminal like cout ; here we are using stringstream object ss; like temp variable
        std::stringstream ss;
        ss<<"Hello World "<<count; //put the data into ss
        msg.data = ss.str(); //now transfer to message variable
        ROS_INFO("%s",msg.data.c_str());
        chatter_pub.publish(msg);
        ros::spinOnce(); //need to use after publishing the topic
        loop_rate.sleep(); 
        ++count; //increament the count variable
    }
    return 0;


}