# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "scene_builder: 0 messages, 2 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/noetic/share/trajectory_msgs/cmake/../msg;-Imoveit_msgs:/opt/ros/noetic/share/moveit_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg;-Ishape_msgs:/opt/ros/noetic/share/shape_msgs/cmake/../msg;-Iobject_recognition_msgs:/opt/ros/noetic/share/object_recognition_msgs/cmake/../msg;-Ioctomap_msgs:/opt/ros/noetic/share/octomap_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(scene_builder_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv" NAME_WE)
add_custom_target(_scene_builder_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scene_builder" "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv" "moveit_msgs/ObjectColor:std_msgs/ColorRGBA"
)

get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv" NAME_WE)
add_custom_target(_scene_builder_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "scene_builder" "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/moveit_msgs/cmake/../msg/ObjectColor.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scene_builder
)
_generate_srv_cpp(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scene_builder
)

### Generating Module File
_generate_module_cpp(scene_builder
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scene_builder
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(scene_builder_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(scene_builder_generate_messages scene_builder_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_cpp _scene_builder_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_cpp _scene_builder_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scene_builder_gencpp)
add_dependencies(scene_builder_gencpp scene_builder_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scene_builder_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/moveit_msgs/cmake/../msg/ObjectColor.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scene_builder
)
_generate_srv_eus(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scene_builder
)

### Generating Module File
_generate_module_eus(scene_builder
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scene_builder
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(scene_builder_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(scene_builder_generate_messages scene_builder_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_eus _scene_builder_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_eus _scene_builder_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scene_builder_geneus)
add_dependencies(scene_builder_geneus scene_builder_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scene_builder_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/moveit_msgs/cmake/../msg/ObjectColor.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scene_builder
)
_generate_srv_lisp(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scene_builder
)

### Generating Module File
_generate_module_lisp(scene_builder
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scene_builder
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(scene_builder_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(scene_builder_generate_messages scene_builder_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_lisp _scene_builder_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_lisp _scene_builder_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scene_builder_genlisp)
add_dependencies(scene_builder_genlisp scene_builder_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scene_builder_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/moveit_msgs/cmake/../msg/ObjectColor.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scene_builder
)
_generate_srv_nodejs(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scene_builder
)

### Generating Module File
_generate_module_nodejs(scene_builder
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scene_builder
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(scene_builder_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(scene_builder_generate_messages scene_builder_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_nodejs _scene_builder_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_nodejs _scene_builder_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scene_builder_gennodejs)
add_dependencies(scene_builder_gennodejs scene_builder_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scene_builder_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/moveit_msgs/cmake/../msg/ObjectColor.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scene_builder
)
_generate_srv_py(scene_builder
  "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scene_builder
)

### Generating Module File
_generate_module_py(scene_builder
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scene_builder
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(scene_builder_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(scene_builder_generate_messages scene_builder_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/SceneObject.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_py _scene_builder_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/itamar/work/code/algorithms/manipulation_ws/src/scene_builder/srv/ObjDeleter.srv" NAME_WE)
add_dependencies(scene_builder_generate_messages_py _scene_builder_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(scene_builder_genpy)
add_dependencies(scene_builder_genpy scene_builder_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS scene_builder_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scene_builder)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/scene_builder
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(scene_builder_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(scene_builder_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET trajectory_msgs_generate_messages_cpp)
  add_dependencies(scene_builder_generate_messages_cpp trajectory_msgs_generate_messages_cpp)
endif()
if(TARGET moveit_msgs_generate_messages_cpp)
  add_dependencies(scene_builder_generate_messages_cpp moveit_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scene_builder)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/scene_builder
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(scene_builder_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(scene_builder_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET trajectory_msgs_generate_messages_eus)
  add_dependencies(scene_builder_generate_messages_eus trajectory_msgs_generate_messages_eus)
endif()
if(TARGET moveit_msgs_generate_messages_eus)
  add_dependencies(scene_builder_generate_messages_eus moveit_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scene_builder)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/scene_builder
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(scene_builder_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(scene_builder_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET trajectory_msgs_generate_messages_lisp)
  add_dependencies(scene_builder_generate_messages_lisp trajectory_msgs_generate_messages_lisp)
endif()
if(TARGET moveit_msgs_generate_messages_lisp)
  add_dependencies(scene_builder_generate_messages_lisp moveit_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scene_builder)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/scene_builder
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(scene_builder_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(scene_builder_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET trajectory_msgs_generate_messages_nodejs)
  add_dependencies(scene_builder_generate_messages_nodejs trajectory_msgs_generate_messages_nodejs)
endif()
if(TARGET moveit_msgs_generate_messages_nodejs)
  add_dependencies(scene_builder_generate_messages_nodejs moveit_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scene_builder)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scene_builder\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/scene_builder
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(scene_builder_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(scene_builder_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET trajectory_msgs_generate_messages_py)
  add_dependencies(scene_builder_generate_messages_py trajectory_msgs_generate_messages_py)
endif()
if(TARGET moveit_msgs_generate_messages_py)
  add_dependencies(scene_builder_generate_messages_py moveit_msgs_generate_messages_py)
endif()
