//
// Created by itamar on 3/10/23.
//


#include <ros/ros.h>
#include <ros/package.h>
#include <scene_builder.hpp>
// include for YAML
#include <yaml-cpp/yaml.h>

// TF2
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>


int main(int argc, char** argv)
{
    ros::init(argc, argv, "scene_builder_frame");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    // check id recieved argument of sleep
    if (argc == 2)
    {
        ROS_INFO_STREAM("Sleeping for " << argv[1] << " seconds");
        ros::Duration(std::stod(argv[1])).sleep();
    }


    // before running this node, call service /scene_builder/remove_all_objects
    // to remove all objects from the scene
    ros::ServiceClient client_remove_all = nh.serviceClient<scene_builder::ObjDeleter>("scene_builder/remove_all_objects");
    scene_builder::ObjDeleter srv_remove_all;
    if (client_remove_all.call(srv_remove_all))
    {
        ROS_INFO("Success: %d", srv_remove_all.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    // Test the scene builder with ros services
    ros::ServiceClient client = nh.serviceClient<scene_builder::SceneObject>("scene_builder/add_object");
    scene_builder::SceneObject srv;
    srv.request.shape_type = 1;
    srv.request.object_name = "rod_left";
    srv.request.position_x = 0.341429 - 0.4191;
    srv.request.position_y = (1.218/2.) + 0.61165 + (0.025/2.);
    srv.request.position_z = 0.973125 - 0.04314 + (0.9779/2.0);
    srv.request.dimension_x = 0.025;
    srv.request.dimension_y = 0.025;
    srv.request.dimension_z = 977.9/1000.;

    srv.request.colors.id = srv.request.object_name;
    srv.request.colors.color.r = 211./255.;
    srv.request.colors.color.g = 211./255.;
    srv.request.colors.color.b = 211./255.;
    srv.request.colors.color.a = 0.8;

    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.shape_type = 1;
    srv.request.object_name = "rod_right";
    srv.request.position_y = -((1.218/2.) + 0.61165 + (0.045/2.));

    srv.request.colors.id = srv.request.object_name;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }


    srv.request.shape_type = 1;
    srv.request.object_name = "rod_left_top_1";
    srv.request.position_y = (1.218/2.) + 0.61165 + 0.025 - 0.35052/2.;
    srv.request.position_z = 0.973125 - 0.04314 + 0.9779 + 0.025/2;
    srv.request.dimension_x = 0.025;
    srv.request.dimension_y = 0.35052;
    srv.request.dimension_z = 0.025;

    srv.request.colors.id = srv.request.object_name;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.shape_type = 1;
    srv.request.object_name = "rod_right_top_1";
    srv.request.position_y = -((1.218/2.) + 0.61165 + 0.025 - 0.35052/2.);
    srv.request.position_z = 0.973125 - 0.04314 + 0.9779 + 0.025/2;
    srv.request.dimension_x = 0.025;
    srv.request.dimension_y = 0.35052;
    srv.request.dimension_z = 0.025;

    srv.request.colors.id = srv.request.object_name;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.shape_type = 1;
    srv.request.object_name = "rod_left_top_2";
    srv.request.position_y = (1.218/2.) + 0.61165 + 0.025 - 0.35052 + 0.025/2.;
    srv.request.position_z = 0.973125 - 0.04314 + 0.9779 + 0.025/2;
    srv.request.dimension_x = 0.35052;
    srv.request.dimension_y = 0.025;
    srv.request.dimension_z = 0.025;

    srv.request.colors.id = srv.request.object_name;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.shape_type = 1;
    srv.request.object_name = "rod_right_top_2";
    srv.request.position_y = -((1.218/2.) + 0.61165 + 0.025 - 0.35052 + 0.025/2.);
    srv.request.position_z = 0.973125 - 0.04314 + 0.9779 + 0.025/2;
    srv.request.dimension_x = 0.35052;
    srv.request.dimension_y = 0.025;
    srv.request.dimension_z = 0.025;

    srv.request.colors.id = srv.request.object_name;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.shape_type = 1;
    srv.request.object_name = "middle_rod_left";
    srv.request.position_x = 0.88;
    srv.request.position_y = 0.20;
    srv.request.position_z = 0.85;
    srv.request.dimension_x = 1.05;
    srv.request.dimension_y = 0.05;
    srv.request.dimension_z = 0.05;

    srv.request.colors.id = srv.request.object_name;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.shape_type = 1;
    srv.request.object_name = "middle_rod_right";
    srv.request.position_y = -0.20;
    srv.request.colors.id = srv.request.object_name;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    // read all objects from objects.yaml in the config folder
    std::string scene_builder_path = ros::package::getPath("scene_builder");
    std::string objects_description_path = scene_builder_path + "/config/objects.yaml";

    YAML::Node config = YAML::LoadFile(objects_description_path);
    for (auto object : config)
    {

        auto part = object.second;

        srv.request.shape_type = 4;
        srv.request.object_name = part["name"].as<std::string>();
        srv.request.mesh_resource = "package://scene_builder/meshes/frame_objects/stl/" + part["mesh_stl_name"].as<std::string>();
        srv.request.position_x = part["pose"]["position"]["x"].as<double>();
        srv.request.position_y = part["pose"]["position"]["y"].as<double>();
        srv.request.position_z = part["pose"]["position"]["z"].as<double>();
        srv.request.orientation_x = part["pose"]["orientation"]["x"].as<double>();
        srv.request.orientation_y= part["pose"]["orientation"]["y"].as<double>();
        srv.request.orientation_z = part["pose"]["orientation"]["z"].as<double>();
        srv.request.orientation_w = part["pose"]["orientation"]["w"].as<double>();

        srv.request.colors.id = srv.request.object_name;
        // make default color
        srv.request.colors.color.r = 0.5;
        srv.request.colors.color.g = 0.5;
        srv.request.colors.color.b = 0.5;
        srv.request.colors.color.a = 1.0;

        if (client.call(srv))
        {
            ROS_INFO("Success: %d", srv.response.success);
        }
        else
        {
            ROS_ERROR("Failed to call service");
            return 1;
        }
    }


    srv.request.shape_type = 1;
    srv.request.object_name = "rectangle_1";
    srv.request.position_x = 0.45;   // std::sqrt(2) / 4
    srv.request.position_y = 1.04;
    srv.request.position_z = 1.77;

    srv.request.orientation_w = 1.0;
    srv.request.orientation_x = 0.0;
    srv.request.orientation_y = 0.0;
    srv.request.orientation_z = 0.0;

    srv.request.dimension_x = 0.02;
    srv.request.dimension_y = std::sqrt(2);
    srv.request.dimension_z = 1.6;

    srv.request.colors.id = srv.request.object_name;
    srv.request.colors.color.r = 1.0;
    srv.request.colors.color.g = 0.0;
    srv.request.colors.color.b = 0.0;
    srv.request.colors.color.a = 0.05;


    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.object_name = "rectangle_2";
    srv.request.position_y = -1.0;

    srv.request.colors.id = srv.request.object_name;

    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }
//
//    // Adding "demmy" objects to the scene as screws, TODO: Change to real screws
//    // Add as cylinder
//    for (int i = 0; i < 6; i++) {
//        srv.request.shape_type = 2;
//        srv.request.object_name = "screw_" + std::to_string(i);
//        srv.request.position_x = 1.7 + 0.05 * i;
//        srv.request.position_y = 1.0;
//        srv.request.position_z = 0.68;
//        srv.request.orientation_w = 1.0;
//        srv.request.orientation_x = 0.0;
//        srv.request.orientation_y = 0.0;
//        srv.request.orientation_z = 0.0;
//        srv.request.dimension_z = 0.05;
//        srv.request.radius = 0.01;
//
//        srv.request.colors.id = srv.request.object_name;
//        srv.request.colors.color.r = 0.5;
//        srv.request.colors.color.g = 0.0;
//        srv.request.colors.color.b = 0.5;
//        srv.request.colors.color.a = 0.8;
//
//        if (client.call(srv)) {
//            ROS_INFO("Success: %d", srv.response.success);
//        } else {
//            ROS_ERROR("Failed to call service");
//            return 1;
//        }
//    }



    return 0;
}