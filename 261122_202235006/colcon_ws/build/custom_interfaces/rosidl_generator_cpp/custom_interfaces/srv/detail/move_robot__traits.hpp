// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:srv/MoveRobot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/move_robot.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__TRAITS_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/srv/detail/move_robot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'current_pose'
#include "custom_interfaces/msg/detail/robot_pose__traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveRobot_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_pose
  {
    out << "current_pose: ";
    to_flow_style_yaml(msg.current_pose, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveRobot_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pose:\n";
    to_block_style_yaml(msg.current_pose, out, indentation + 2);
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveRobot_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::MoveRobot_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::MoveRobot_Request & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::MoveRobot_Request>()
{
  return "custom_interfaces::srv::MoveRobot_Request";
}

template<>
inline const char * name<custom_interfaces::srv::MoveRobot_Request>()
{
  return "custom_interfaces/srv/MoveRobot_Request";
}

template<>
struct has_fixed_size<custom_interfaces::srv::MoveRobot_Request>
  : std::integral_constant<bool, has_fixed_size<custom_interfaces::msg::RobotPose>::value> {};

template<>
struct has_bounded_size<custom_interfaces::srv::MoveRobot_Request>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::msg::RobotPose>::value> {};

template<>
struct is_message<custom_interfaces::srv::MoveRobot_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result_pose'
// already included above
// #include "custom_interfaces/msg/detail/robot_pose__traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveRobot_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result_pose
  {
    out << "result_pose: ";
    to_flow_style_yaml(msg.result_pose, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveRobot_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result_pose:\n";
    to_block_style_yaml(msg.result_pose, out, indentation + 2);
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveRobot_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::MoveRobot_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::MoveRobot_Response & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::MoveRobot_Response>()
{
  return "custom_interfaces::srv::MoveRobot_Response";
}

template<>
inline const char * name<custom_interfaces::srv::MoveRobot_Response>()
{
  return "custom_interfaces/srv/MoveRobot_Response";
}

template<>
struct has_fixed_size<custom_interfaces::srv::MoveRobot_Response>
  : std::integral_constant<bool, has_fixed_size<custom_interfaces::msg::RobotPose>::value> {};

template<>
struct has_bounded_size<custom_interfaces::srv::MoveRobot_Response>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::msg::RobotPose>::value> {};

template<>
struct is_message<custom_interfaces::srv::MoveRobot_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace custom_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const MoveRobot_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MoveRobot_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MoveRobot_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::srv::MoveRobot_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::srv::MoveRobot_Event & msg)
{
  return custom_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::srv::MoveRobot_Event>()
{
  return "custom_interfaces::srv::MoveRobot_Event";
}

template<>
inline const char * name<custom_interfaces::srv::MoveRobot_Event>()
{
  return "custom_interfaces/srv/MoveRobot_Event";
}

template<>
struct has_fixed_size<custom_interfaces::srv::MoveRobot_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_interfaces::srv::MoveRobot_Event>
  : std::integral_constant<bool, has_bounded_size<custom_interfaces::srv::MoveRobot_Request>::value && has_bounded_size<custom_interfaces::srv::MoveRobot_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<custom_interfaces::srv::MoveRobot_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_interfaces::srv::MoveRobot>()
{
  return "custom_interfaces::srv::MoveRobot";
}

template<>
inline const char * name<custom_interfaces::srv::MoveRobot>()
{
  return "custom_interfaces/srv/MoveRobot";
}

template<>
struct has_fixed_size<custom_interfaces::srv::MoveRobot>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_interfaces::srv::MoveRobot_Request>::value &&
    has_fixed_size<custom_interfaces::srv::MoveRobot_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_interfaces::srv::MoveRobot>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_interfaces::srv::MoveRobot_Request>::value &&
    has_bounded_size<custom_interfaces::srv::MoveRobot_Response>::value
  >
{
};

template<>
struct is_service<custom_interfaces::srv::MoveRobot>
  : std::true_type
{
};

template<>
struct is_service_request<custom_interfaces::srv::MoveRobot_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_interfaces::srv::MoveRobot_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__TRAITS_HPP_
