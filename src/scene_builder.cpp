//
// Created by itamar on 3/6/23.
//

#include "scene_builder.hpp"


scene::scene_builder::scene_builder(std::string frame_id) : frame_id_(frame_id) {
    object_counter = 0;
}

scene::scene_builder::scene_builder(ros::NodeHandle& nh, ros::NodeHandle& pnh) : nh_(nh), pnh_(pnh){
    object_counter = 0;
    pnh_.param<std::string>("frame_id", frame_id_, "world");
}

scene::scene_builder::scene_builder(ros::NodeHandle& nh, ros::NodeHandle& pnh, std::string& frame_id) : nh_(nh), pnh_(pnh), frame_id_(frame_id){
    object_counter = 0;
}


scene::scene_builder::~scene_builder() {
//    for (auto& object : objects_){
//        delete object;
//    }
}

void scene::object::init(std::string& name_, shapes::ShapeType &shape_,
                         std::vector<double>& pose_, std::vector<double> &dimension_,
                         std::string& frame_id_) {
    this->name = name_;
    this->pose = pose_;
    this->shape = shape_;
    this->dimension = dimension_;
    this->frame_id = frame_id_;
}

scene::object::~object() {
}

template<typename T>
bool scene::scene_builder::add_object(std::string &name, T *shape,
                                      std::vector<double> &pose,
                                      std::vector<double> &dimensions,
                                      moveit_msgs::ObjectColor &object_color) {
    // Check if the object already exists by that name
    for (auto& object : objects_){
        if (object.name == name){
            ROS_ERROR("Object %s already exists", name.c_str());
            return false;
        }
    }
    // Create the object
    auto object = scene::object();
    object.init(name, shape->type, pose, dimensions, frame_id_);
    objects_.push_back(object);
    object_counter++;
    // Add the object to the planning scene
    moveit_msgs::CollisionObject collision_object;
    collision_object.header.frame_id = frame_id_;
    collision_object.id = object.name;
    collision_object.primitives.resize(1);
    // Set the shape of the object based on the shape type
    switch (object.shape) {
        case shapes::ShapeType::BOX:
            collision_object.primitives[0].type = collision_object.primitives[0].BOX;
            break;
        case shapes::ShapeType::CYLINDER:
            collision_object.primitives[0].type = collision_object.primitives[0].CYLINDER;
            break;
        case shapes::ShapeType::SPHERE:
            collision_object.primitives[0].type = collision_object.primitives[0].SPHERE;
            break;
        case shapes::ShapeType::MESH: {
            shape_msgs::Mesh mesh;
            shapes::ShapeMsg mesh_msg;
            shapes::constructMsgFromShape(shape, mesh_msg);
            mesh = boost::get<shape_msgs::Mesh>(mesh_msg);
            collision_object.meshes.resize(1);
            collision_object.meshes[0] = mesh;
            collision_object.mesh_poses.resize(1);
            collision_object.mesh_poses[0].position.x = 0.0;
            collision_object.mesh_poses[0].position.y = 0.0;
            collision_object.mesh_poses[0].position.z = 0.0;
            collision_object.mesh_poses[0].orientation.x = 0.0;
            collision_object.mesh_poses[0].orientation.y = 0.0;
            collision_object.mesh_poses[0].orientation.z = 0.0;
            collision_object.mesh_poses[0].orientation.w = 1.0;
            collision_object.pose.position.x = object.pose[0];
            collision_object.pose.position.y = object.pose[1];
            collision_object.pose.position.z = object.pose[2];
            collision_object.pose.orientation.x = object.pose[3];
            collision_object.pose.orientation.y = object.pose[4];
            collision_object.pose.orientation.z = object.pose[5];
            collision_object.pose.orientation.w = object.pose[6];
            collision_object.operation = collision_object.ADD;
            planning_scene_interface_.applyCollisionObjects({collision_object}, {object_color});
            return true;
        }
        default:
            ROS_ERROR("Shape type not supported");
            return false;
    }
    
    collision_object.primitives[0].dimensions = object.dimension;

    collision_object.primitive_poses.resize(1);
    collision_object.primitive_poses[0].position.x = object.pose[0];
    collision_object.primitive_poses[0].position.y = object.pose[1];
    collision_object.primitive_poses[0].position.z = object.pose[2];
    collision_object.primitive_poses[0].orientation.x = object.pose[3];
    collision_object.primitive_poses[0].orientation.y = object.pose[4];
    collision_object.primitive_poses[0].orientation.z = object.pose[5];
    collision_object.primitive_poses[0].orientation.w = object.pose[6];

    collision_object.operation = collision_object.ADD;
    planning_scene_interface_.applyCollisionObjects({collision_object}, {object_color});
    return true;
}

bool scene::scene_builder::remove_object(std::string &name) {
    for (auto &object: objects_)
        if (object.name == name) {
            planning_scene_interface_.removeCollisionObjects({name});
            // Sleep and let it go
            ros::Duration(0.5).sleep();
            // Remove the object from the vector
            objects_.erase(std::remove(objects_.begin(), objects_.end(), object), objects_.end());
            object_counter--;
            return true;
        }

    return false;
}

bool scene::scene_builder::remove_all_objects() {
    // Iterating through the object names:
    std::vector<std::string> object_names;
    for (auto &object: objects_) {
        object_names.push_back(object.name);
    }
    // Removing the objects
    for (auto &object_name: object_names) {
        if (!remove_object(object_name)) {
            return false;
        }
    }

    return true;
}


bool scene::scene_builder::create_box(std::string &name, std::vector<double> &pose,
                                      std::vector<double> &dimensions_,
                                      moveit_msgs::ObjectColor object_color_) {
    auto* box = new shapes::Box(dimensions_[0], dimensions_[1], dimensions_[2]);
    return add_object(name, box, pose, dimensions_, object_color_);
}


bool scene::scene_builder::create_cylinder(std::string &name, std::vector<double> &pose,
                                           std::vector<double> &dimensions_,
                                           moveit_msgs::ObjectColor object_color_) {
    auto* cylinder = new shapes::Cylinder(dimensions_[0], dimensions_[1]);
    return add_object(name, cylinder, pose, dimensions_, object_color_);
}

bool scene::scene_builder::create_sphere(std::string &name, std::vector<double> &pose,
                                         std::vector<double> &dimensions_,
                                         moveit_msgs::ObjectColor object_color_) {
    auto* sphere = new shapes::Sphere(dimensions_[0]);
    return add_object(name, sphere, pose, dimensions_, object_color_);
}

bool scene::scene_builder::create_mesh(std::string &name, std::vector<double> &pose,
                                       std::string &mesh_path,
                                       moveit_msgs::ObjectColor object_color_) {
    // Create a mesh object from stl file
    Eigen::Vector3d scale(0.001, 0.001, 0.001);
    shapes::Mesh* mesh = shapes::createMeshFromResource(mesh_path, scale);
    if (!mesh){
        ROS_ERROR("Failed to create mesh from file %s", mesh_path.c_str());
        return false;
    }
    // Making sure the center of the mesh is at its origin
    Eigen::Vector3d centroid = Eigen::Vector3d::Zero();
    for (int i {0}; i < mesh->vertex_count; i++){
        centroid += Eigen::Vector3d(mesh->vertices[3*i], mesh->vertices[3*i+1], mesh->vertices[3*i+2]);
    }
    centroid /= mesh->vertex_count;
    for (int i {0}; i < mesh->vertex_count; i++){
        mesh->vertices[3*i] -= centroid[0];
        mesh->vertices[3*i+1] -= centroid[1];
        mesh->vertices[3*i+2] -= centroid[2];
    }

    std::vector<double> dimensions;
    dimensions.push_back(mesh->triangle_count);
    return add_object(name, mesh, pose, dimensions, object_color_);
}

bool scene::scene_builder::add_object_cb(::scene_builder::SceneObject::Request &req,
                                         ::scene_builder::SceneObject::Response &res) {
    // Check if the object already exists by that name
    for (auto& object : objects_){
        if (object.name == req.object_name){
            ROS_ERROR("Object %s already exists. You can add it again with a prefix!", req.object_name.c_str());
            return false;
        }
    }
    std::vector<double> pose{req.position_x, req.position_y, req.position_z,
                             req.orientation_x, req.orientation_y, req.orientation_z,
                             req.orientation_w};

    switch (req.shape_type){
        case 1: {
            // Create a box
            std::vector<double> dimensions{req.dimension_x, req.dimension_y, req.dimension_z};
            if (!create_box(req.object_name, pose, dimensions, req.colors)) {
                return false;
            }
            break;
        }

        case 2: {
            // Create a cylinder
            std::vector<double> dimensions {req.dimension_z, req.radius};
            if (!create_cylinder(req.object_name, pose, dimensions, req.colors)) {
                return false;
            }
            break;
        }
        case 3: {
            // Create a sphere
            std::vector<double> dimensions {req.radius};
            if (!create_sphere(req.object_name, pose, dimensions, req.colors)) {
                return false;
            }
            break;
        }
        case 4: {
            // Create a mesh
            std::string mesh_path = req.mesh_resource;
            if (!create_mesh(req.object_name, pose, mesh_path, req.colors)) {
                return false;
            }
            break;
        }
        default:
            ROS_ERROR("Shape type %d is not supported", req.shape_type);
            return false;
    }
    res.success = true;
    return true;

}

bool scene::scene_builder::remove_object_cb(::scene_builder::ObjDeleter::Request &req,
                                            ::scene_builder::ObjDeleter::Response &res) {
    if (!remove_object(req.name)){
        res.success = false;
        return false;
    }
    res.success = true;
    return true;
}

bool scene::scene_builder::remove_all_objects_cb(::scene_builder::ObjDeleter::Request &req,
                                                 ::scene_builder::ObjDeleter::Response &res) {
    if (!remove_all_objects()){
        res.success = false;
        return false;
    }
    res.success = true;
    return true;
}

size_t scene::scene_builder::get_object_counter() const {
    return object_counter;
}

bool scene::scene_builder::get_object(std::string &name, object& obj) {
    for (auto& object : objects_){
        if (object.name == name){
            obj = object;
            return true;
        }
    }
    ROS_ERROR("Object %s does not exist", name.c_str());
    return false;
}

std::vector<scene::object> scene::scene_builder::get_objects() const {
    return objects_;
}



int main(int argc, char** argv){

    ros::init(argc, argv, "scene_builder");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    // make a ros service server
    scene::scene_builder scene_builder(nh, pnh);

    ros::ServiceServer service = nh.advertiseService("scene_builder/add_object", &scene::scene_builder::add_object_cb, &scene_builder);
    ros::ServiceServer service2 = nh.advertiseService("scene_builder/remove_object", &scene::scene_builder::remove_object_cb, &scene_builder);
    ros::ServiceServer service3 = nh.advertiseService("scene_builder/remove_all_objects", &scene::scene_builder::remove_all_objects_cb, &scene_builder);
    /// @TODO: add a service to get the list of objects in the scene

    ROS_INFO("Scene builder is ready to add/remove objects");

    ros::spin();

    return 0;
}