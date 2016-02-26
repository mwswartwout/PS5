cmake_minimum_required(VERSION 2.8.3)
project(alpha_mobot_pub_des_state)

find_package(catkin_simple REQUIRED)

find_package(Boost REQUIRED COMPONENTS system thread)
catkin_simple()

cs_add_executable(alpha_mobot_pub_des_state src/pub_des_state_main.cpp src/pub_des_state.cpp)
cs_add_executable(alpha_open_loop_controller src/open_loop_controller.cpp)
cs_add_executable(alpha_pub_des_state_path_client src/pub_des_state_path_client.cpp)

cs_install()
cs_export()
    
