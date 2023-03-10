//
// Created by itamar on 3/7/23.
//

#include <ros/ros.h>
#include <scene_builder.hpp>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "scene_builder_test");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    // Test the scene builder with ros services
    ros::ServiceClient client = nh.serviceClient<scene_builder::SceneObject>("scene_builder/add_object");
    scene_builder::SceneObject srv;
    srv.request.shape_type = 1;
    srv.request.object_name = "test_box";
    srv.request.position_x = 1.55;
    srv.request.position_y = 0.0;
    srv.request.position_z = 0.325;
    srv.request.dimension_x = 1.95;
    srv.request.dimension_y = 0.90;
    srv.request.dimension_z = 0.65;
    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    // Add a cylinder
    srv.request.shape_type = 2;
    srv.request.object_name = "test_cylinder";
    srv.request.position_x = -0.5;
    srv.request.position_y = -0.5;
    srv.request.position_z = -0.5;
    srv.request.radius = 0.5;
    srv.request.dimension_z = 0.5;
    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    // Add a sphere
    srv.request.shape_type = 3;
    srv.request.object_name = "test_sphere";
    srv.request.position_x = 0.5;
    srv.request.position_y = -0.5;
    srv.request.position_z = -0.5;
    srv.request.radius = 0.5;

    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    // Add a mesh - right side panel:
    srv.request.shape_type = 4;
    srv.request.object_name = "right_side_panel";
    srv.request.position_x = 1.55;
    srv.request.position_y = 0.0;
    srv.request.position_z = 0.325;
    srv.request.dimension_x = 1.95;
    srv.request.dimension_y = 0.90;
    srv.request.dimension_z = 0.65;
    srv.request.mesh_resource = "package://scene_builder/meshes/frame_objects/stl/left_right_plate.STL";

    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    return 0;
}