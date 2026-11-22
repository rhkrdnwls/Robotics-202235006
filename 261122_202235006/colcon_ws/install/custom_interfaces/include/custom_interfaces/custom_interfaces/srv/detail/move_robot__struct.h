// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/MoveRobot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/move_robot.h"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'current_pose'
#include "custom_interfaces/msg/detail/robot_pose__struct.h"

/// Struct defined in srv/MoveRobot in the package custom_interfaces.
typedef struct custom_interfaces__srv__MoveRobot_Request
{
  custom_interfaces__msg__RobotPose current_pose;
  double distance;
} custom_interfaces__srv__MoveRobot_Request;

// Struct for a sequence of custom_interfaces__srv__MoveRobot_Request.
typedef struct custom_interfaces__srv__MoveRobot_Request__Sequence
{
  custom_interfaces__srv__MoveRobot_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__MoveRobot_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result_pose'
// already included above
// #include "custom_interfaces/msg/detail/robot_pose__struct.h"

/// Struct defined in srv/MoveRobot in the package custom_interfaces.
typedef struct custom_interfaces__srv__MoveRobot_Response
{
  custom_interfaces__msg__RobotPose result_pose;
  bool success;
} custom_interfaces__srv__MoveRobot_Response;

// Struct for a sequence of custom_interfaces__srv__MoveRobot_Response.
typedef struct custom_interfaces__srv__MoveRobot_Response__Sequence
{
  custom_interfaces__srv__MoveRobot_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__MoveRobot_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  custom_interfaces__srv__MoveRobot_Event__request__MAX_SIZE = 1
};
// response
enum
{
  custom_interfaces__srv__MoveRobot_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/MoveRobot in the package custom_interfaces.
typedef struct custom_interfaces__srv__MoveRobot_Event
{
  service_msgs__msg__ServiceEventInfo info;
  custom_interfaces__srv__MoveRobot_Request__Sequence request;
  custom_interfaces__srv__MoveRobot_Response__Sequence response;
} custom_interfaces__srv__MoveRobot_Event;

// Struct for a sequence of custom_interfaces__srv__MoveRobot_Event.
typedef struct custom_interfaces__srv__MoveRobot_Event__Sequence
{
  custom_interfaces__srv__MoveRobot_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__MoveRobot_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__STRUCT_H_
