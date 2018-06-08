# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "fullpkg: 1 messages, 0 services")

set(MSG_I_FLAGS "-Ifullpkg:/home/fdai5587/ws/src/fullpkg/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(fullpkg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg" NAME_WE)
add_custom_target(_fullpkg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fullpkg" "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg" "std_msgs/MultiArrayDimension:std_msgs/MultiArrayLayout"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(fullpkg
  "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fullpkg
)

### Generating Services

### Generating Module File
_generate_module_cpp(fullpkg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fullpkg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(fullpkg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(fullpkg_generate_messages fullpkg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg" NAME_WE)
add_dependencies(fullpkg_generate_messages_cpp _fullpkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fullpkg_gencpp)
add_dependencies(fullpkg_gencpp fullpkg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fullpkg_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(fullpkg
  "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fullpkg
)

### Generating Services

### Generating Module File
_generate_module_eus(fullpkg
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fullpkg
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(fullpkg_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(fullpkg_generate_messages fullpkg_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg" NAME_WE)
add_dependencies(fullpkg_generate_messages_eus _fullpkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fullpkg_geneus)
add_dependencies(fullpkg_geneus fullpkg_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fullpkg_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(fullpkg
  "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fullpkg
)

### Generating Services

### Generating Module File
_generate_module_lisp(fullpkg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fullpkg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(fullpkg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(fullpkg_generate_messages fullpkg_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg" NAME_WE)
add_dependencies(fullpkg_generate_messages_lisp _fullpkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fullpkg_genlisp)
add_dependencies(fullpkg_genlisp fullpkg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fullpkg_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(fullpkg
  "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fullpkg
)

### Generating Services

### Generating Module File
_generate_module_nodejs(fullpkg
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fullpkg
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(fullpkg_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(fullpkg_generate_messages fullpkg_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg" NAME_WE)
add_dependencies(fullpkg_generate_messages_nodejs _fullpkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fullpkg_gennodejs)
add_dependencies(fullpkg_gennodejs fullpkg_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fullpkg_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(fullpkg
  "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fullpkg
)

### Generating Services

### Generating Module File
_generate_module_py(fullpkg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fullpkg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(fullpkg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(fullpkg_generate_messages fullpkg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fdai5587/ws/src/fullpkg/msg/mesg.msg" NAME_WE)
add_dependencies(fullpkg_generate_messages_py _fullpkg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fullpkg_genpy)
add_dependencies(fullpkg_genpy fullpkg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fullpkg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fullpkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fullpkg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(fullpkg_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fullpkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fullpkg
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(fullpkg_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fullpkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fullpkg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(fullpkg_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fullpkg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fullpkg
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(fullpkg_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fullpkg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fullpkg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fullpkg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(fullpkg_generate_messages_py std_msgs_generate_messages_py)
endif()
