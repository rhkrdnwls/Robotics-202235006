// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/RobotPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/robot_pose.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/robot_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotPose_theta
{
public:
  explicit Init_RobotPose_theta(::custom_interfaces::msg::RobotPose & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::RobotPose theta(::custom_interfaces::msg::RobotPose::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::RobotPose msg_;
};

class Init_RobotPose_y
{
public:
  explicit Init_RobotPose_y(::custom_interfaces::msg::RobotPose & msg)
  : msg_(msg)
  {}
  Init_RobotPose_theta y(::custom_interfaces::msg::RobotPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_RobotPose_theta(msg_);
  }

private:
  ::custom_interfaces::msg::RobotPose msg_;
};

class Init_RobotPose_x
{
public:
  Init_RobotPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotPose_y x(::custom_interfaces::msg::RobotPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_RobotPose_y(msg_);
  }

private:
  ::custom_interfaces::msg::RobotPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::RobotPose>()
{
  return custom_interfaces::msg::builder::Init_RobotPose_x();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__ROBOT_POSE__BUILDER_HPP_
