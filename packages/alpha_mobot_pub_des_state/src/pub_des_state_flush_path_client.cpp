//pub_des_state_flush_path_client:
// illustrates how to send a request to the flush_path_queue_service service

#include <ros/ros.h>
#include <iostream>
#include <alpha_mobot_pub_des_state/path.h>

using namespace std;

int main(int argc, char **argv) {
    ros::init(argc, argv, "flush_path_client");
    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<alpha_mobot_pub_des_state::path>("flush_path_queue_service");
    
    while (!client.exists()) {
      ROS_INFO("waiting for service...");
      ros::Duration(1.0).sleep();
    }
    ROS_INFO("connected client to service");
    alpha_mobot_pub_des_state::path path_srv;

    client.call(path_srv); // Does it have to put a parameter? here actually we are calling a function without using parameters

    return 0;
}
