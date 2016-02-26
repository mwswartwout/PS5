#include "pub_des_state.h"
int main(int argc, char **argv) {
    ros::init(argc, argv, "des_state_publisher");
    ros::NodeHandle nh;
    //instantiate a desired-state publisher object
    DesStatePublisher desStatePublisher(nh);
    //dt is set in header file pub_des_state.h    
    ros::WallRate looprate(1 / dt); //timer for fixed publication rate
    desStatePublisher.set_init_pose(0,0,0); //x=0, y=0, psi=0
    //put some points in the path queue--hard coded here
    desStatePublisher.append_path_queue(5.0,0.0,0.0);
    desStatePublisher.append_path_queue(0.0,0.0,0.0);
    
    // main loop; publish a desired state every iteration
    while (ros::ok()) {
        //ROS_INFO("Going to next state");
        desStatePublisher.pub_next_state();
        //ROS_INFO("Spinning");
        ros::spinOnce();
        //ROS_INFO("Sleeping");
        looprate.sleep(); //sleep for defined sample period, then do loop again
        //ROS_INFO("Done sleeping");
    }
    ROS_INFO("ROS is not okay, exited loop");
}

