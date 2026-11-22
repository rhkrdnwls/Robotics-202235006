// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/MoveRobot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/move_robot.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/move_robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveRobot_Request_distance
{
public:
  explicit Init_MoveRobot_Request_distance(::custom_interfaces::srv::MoveRobot_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::MoveRobot_Request distance(::custom_interfaces::srv::MoveRobot_Request::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::MoveRobot_Request msg_;
};

class Init_MoveRobot_Request_current_pose
{
public:
  Init_MoveRobot_Request_current_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobot_Request_distance current_pose(::custom_interfaces::srv::MoveRobot_Request::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_MoveRobot_Request_distance(msg_);
  }

private:
  ::custom_interfaces::srv::MoveRobot_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::MoveRobot_Request>()
{
  return custom_interfaces::srv::builder::Init_MoveRobot_Request_current_pose();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveRobot_Response_success
{
public:
  explicit Init_MoveRobot_Response_success(::custom_interfaces::srv::MoveRobot_Response & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::MoveRobot_Response success(::custom_interfaces::srv::MoveRobot_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::MoveRobot_Response msg_;
};

class Init_MoveRobot_Response_result_pose
{
public:
  Init_MoveRobot_Response_result_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobot_Response_success result_pose(::custom_interfaces::srv::MoveRobot_Response::_result_pose_type arg)
  {
    msg_.result_pose = std::move(arg);
    return Init_MoveRobot_Response_success(msg_);
  }

private:
  ::custom_interfaces::srv::MoveRobot_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::MoveRobot_Response>()
{
  return custom_interfaces::srv::builder::Init_MoveRobot_Response_result_pose();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveRobot_Event_response
{
public:
  explicit Init_MoveRobot_Event_response(::custom_interfaces::srv::MoveRobot_Event & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::MoveRobot_Event response(::custom_interfaces::srv::MoveRobot_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::MoveRobot_Event msg_;
};

class Init_MoveRobot_Event_request
{
public:
  explicit Init_MoveRobot_Event_request(::custom_interfaces::srv::MoveRobot_Event & msg)
  : msg_(msg)
  {}
  Init_MoveRobot_Event_response request(::custom_interfaces::srv::MoveRobot_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveRobot_Event_response(msg_);
  }

private:
  ::custom_interfaces::srv::MoveRobot_Event msg_;
};

class Init_MoveRobot_Event_info
{
public:
  Init_MoveRobot_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveRobot_Event_request info(::custom_interfaces::srv::MoveRobot_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveRobot_Event_request(msg_);
  }

private:
  ::custom_interfaces::srv::MoveRobot_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::MoveRobot_Event>()
{
  return custom_interfaces::srv::builder::Init_MoveRobot_Event_info();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__BUILDER_HPP_
