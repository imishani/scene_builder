//
// Created by itamar on 3/6/23.
//

#ifndef SMPL_ZTP_SCENE_BUILDER_HPP
#define SMPL_ZTP_SCENE_BUILDER_HPP

#include <ros/ros.h>
#include <geometric_shapes/mesh_operations.h>
#include <geometric_shapes/shape_operations.h>
#include <geometric_shapes/shapes.h>
#include "moveit/planning_scene_interface/planning_scene_interface.h"

// custom services
#include "scene_builder/SceneObject.h"
#include "scene_builder/ObjDeleter.h"


namespace scene{

    struct object{
        object()= default;; // Default constructor
        void init(std::string& name_, shapes::ShapeType &shape_,
                  std::vector<double>& pose_,
                  std::vector<double> &dimension_,
                  std::string& frame_id_);
        ~object();

        std::string name;
        std::vector<double> pose;
        shapes::ShapeType shape;
        std::string frame_id;
        std::vector<double> dimension;

        bool operator==(const object& other) const {
            return this->name == other.name;
        }
    };

    /// \brief A class that builds a scene from a given set of objects
    class scene_builder {
        public:
            scene_builder(ros::NodeHandle& nh, ros::NodeHandle& pnh);
            ~scene_builder();

            /// \brief Create a box object
            /// \param name The name of the object
            /// \param pose The pose of the object with respect to frame_id_
            /// \param dimensions The dimensions of the object. The first element is the x dimension, the second is the y dimension, and the third is the z dimension
            /// \param object_color The color of the object
            bool create_box(std::string &name, std::vector<double> &pose,
                            std::vector<double> &dimensions_,
                            moveit_msgs::ObjectColor object_color_=moveit_msgs::ObjectColor());

            /// \brief Create a cylinder object
            /// \param name The name of the object
            /// \param pose The pose of the object with respect to frame_id_
            /// \param dimensions The dimensions of the object. The first element is the radius, the second is the height
            /// \param object_color The color of the object
            bool create_cylinder(std::string& name,
                                 std::vector<double>& pose,
                                 std::vector<double>& dimensions_,
                                 moveit_msgs::ObjectColor object_color_=moveit_msgs::ObjectColor());

            /// \brief Create a sphere object
            /// \param name The name of the object
            /// \param pose The pose of the object with respect to frame_id_
            /// \param dimensions The dimensions of the object. The first element is the radius
            /// \param object_color The color of the object
            bool create_sphere(std::string& name,
                               std::vector<double>& pose,
                               std::vector<double>& dimensions_,
                               moveit_msgs::ObjectColor object_color_=moveit_msgs::ObjectColor());

            /// \brief Create a mesh object
            /// \param name The name of the object
            /// \param pose The pose of the object with respect to frame_id_
            /// \param mesh_path The path to the mesh file
            /// \param object_color The color of the object
            bool create_mesh(std::string& name,
                             std::vector<double>& pose,
                             std::string& mesh_path,
                             moveit_msgs::ObjectColor object_color_=moveit_msgs::ObjectColor());


            /// \brief Add a an object to the scene
            /// \param name The name of the object
            /// \param shape The shape of the object. Can be a box, cylinder, sphere, or mesh
            /// \param pose The pose of the object in the world
            /// \return True if the object was added successfully, false otherwise
            template<typename T>
            bool add_object(std::string &name, T *shape,
                            std::vector<double> &pose,
                            std::vector<double> &dimensions,
                            moveit_msgs::ObjectColor &object_color);

            /// \brief Remove an object from the scene
            /// \param name The name of the object
            /// \return True if the object was removed successfully, false otherwise
            bool remove_object(std::string& name);

            /// \brief Remove all objects from the scene
            /// \return True if all objects were removed successfully, false otherwise
            bool remove_all_objects();

            /// \brief Ros service callback for adding an object to the scene
            /// \param req The request
            /// \param res The response
            /// \return True if the object was added successfully, false otherwise
            bool add_object_cb(::scene_builder::SceneObject::Request &req, ::scene_builder::SceneObject::Response &res);

            /// \brief Ros service callback for removing an object from the scene
            /// \param req The request
            /// \param res The response
            /// \return True if the object was removed successfully, false otherwise
            bool remove_object_cb(::scene_builder::ObjDeleter::Request &req, ::scene_builder::ObjDeleter::Response &res);

            /// \brief Ros service callback for removing all objects from the scene
            /// \param req The request
            /// \param res The response
            /// \return True if all objects were removed successfully, false otherwise
            bool remove_all_objects_cb(::scene_builder::ObjDeleter::Request &req, ::scene_builder::ObjDeleter::Response &res);

            /// \brief Get the number of objects in the scene
            /// \return size_t The number of objects in the scene
            size_t get_object_counter() const;


        protected:
            ros::NodeHandle nh_;
            ros::NodeHandle pnh_;

            moveit::planning_interface::PlanningSceneInterface planning_scene_interface_;

            size_t object_counter;

            std::vector<object> objects_;

            std::string frame_id_;

    };
}; // namespace scene


#endif //SMPL_ZTP_SCENE_BUILDER_HPP
