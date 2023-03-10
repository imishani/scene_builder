//
// Created by itamar on 3/10/23.
//

//
// Created by itamar on 3/7/23.
//

#include <ros/ros.h>
#include <scene_builder.hpp>

// TF2
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>


int main(int argc, char** argv)
{
    ros::init(argc, argv, "scene_builder_frame");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    // Test the scene builder with ros services
    ros::ServiceClient client = nh.serviceClient<scene_builder::SceneObject>("scene_builder/add_object");
    scene_builder::SceneObject srv;
    srv.request.shape_type = 1;
    srv.request.object_name = "table";
    srv.request.position_x = 1.55;
    srv.request.position_y = 0.0;
    srv.request.position_z = 0.325;
    srv.request.dimension_x = 1.95;
    srv.request.dimension_y = 0.90;
    srv.request.dimension_z = 0.65;

    srv.request.colors.id = srv.request.object_name;
    srv.request.colors.color.r = 205./255.;
    srv.request.colors.color.g = 133./255.;
    srv.request.colors.color.b = 63./255.;
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

    // Add a mesh - right side panel:
    srv.request.shape_type = 4;
    srv.request.object_name = "right_side_panel";
    srv.request.position_x = 1.2;
    srv.request.position_y = 0.0;
    srv.request.position_z = 0.67;

    tf2::Quaternion q;
    q.setRPY(0, M_PI, -M_PI / 2);
    srv.request.orientation_x = q.x();
    srv.request.orientation_y = q.y();
    srv.request.orientation_z = q.z();
    srv.request.orientation_w = q.w();

    srv.request.mesh_resource = "package://scene_builder/meshes/frame_objects/stl/left_right_plate.STL";

    // Set the color:
    srv.request.colors.id = srv.request.object_name;
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

    // Add a mesh - left side panel:
    srv.request.object_name = "left_side_panel";
    srv.request.position_x = 1.9;
    srv.request.position_y = -1.;

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

    // Add a mesh - Part C1:
    srv.request.object_name = "part_c1_1";
    srv.request.position_x = 0.0;
    srv.request.position_y = 0.5;
    srv.request.position_z = 0.68;

    q.setRPY(M_PI / 2, 0, 0);
    srv.request.orientation_x = q.x();
    srv.request.orientation_y = q.y();
    srv.request.orientation_z = q.z();
    srv.request.orientation_w = q.w();

    srv.request.mesh_resource = "package://scene_builder/meshes/frame_objects/stl/C1.STL";

    // Set the color to Mango color:
    srv.request.colors.id = srv.request.object_name;
    srv.request.colors.color.r = 244./255.;
    srv.request.colors.color.g = 187./255.;
    srv.request.colors.color.b = 68./255.;
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

    // Add two more duplicate meshes of C1, one on the left and one on the right:
    srv.request.object_name = "part_c1_2";
    srv.request.colors.id = srv.request.object_name;
    srv.request.position_x = 0.2;

    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    srv.request.object_name = "part_c1_3";
    srv.request.colors.id = srv.request.object_name;
    srv.request.position_x = -0.2;

    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    // Add a mesh - Part C2:
    srv.request.object_name = "part_c2";
    srv.request.position_x = -0.2;
    srv.request.position_y = 0.7;

    srv.request.mesh_resource = "package://scene_builder/meshes/frame_objects/stl/C2.STL";

    // Set the color to Fern Green color:
    srv.request.colors.id = srv.request.object_name;
    srv.request.colors.color.r = 79./255.;
    srv.request.colors.color.g = 121./255.;
    srv.request.colors.color.b = 66./255.;

    if (client.call(srv))
    {
        ROS_INFO("Success: %d", srv.response.success);
    }
    else
    {
        ROS_ERROR("Failed to call service");
        return 1;
    }

    // Add a mesh - Part C5:
    srv.request.object_name = "part_c5";
    srv.request.position_x = 0.2;
    srv.request.position_y = 0.7;

    srv.request.mesh_resource = "package://scene_builder/meshes/frame_objects/stl/C5.STL";

    // Set the color to Blue Green color:
    srv.request.colors.id = srv.request.object_name;
    srv.request.colors.color.r = 8./255.;
    srv.request.colors.color.g = 143./255.;
    srv.request.colors.color.b = 143./255.;

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