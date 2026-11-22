// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:srv/MoveRobot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/srv/move_robot.hpp"


#ifndef CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__STRUCT_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'current_pose'
#include "custom_interfaces/msg/detail/robot_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__MoveRobot_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__MoveRobot_Request __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveRobot_Request_
{
  using Type = MoveRobot_Request_<ContainerAllocator>;

  explicit MoveRobot_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  explicit MoveRobot_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->distance = 0.0;
    }
  }

  // field types and members
  using _current_pose_type =
    custom_interfaces::msg::RobotPose_<ContainerAllocator>;
  _current_pose_type current_pose;
  using _distance_type =
    double;
  _distance_type distance;

  // setters for named parameter idiom
  Type & set__current_pose(
    const custom_interfaces::msg::RobotPose_<ContainerAllocator> & _arg)
  {
    this->current_pose = _arg;
    return *this;
  }
  Type & set__distance(
    const double & _arg)
  {
    this->distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__MoveRobot_Request
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__MoveRobot_Request
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveRobot_Request_ & other) const
  {
    if (this->current_pose != other.current_pose) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveRobot_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveRobot_Request_

// alias to use template instance with default allocator
using MoveRobot_Request =
  custom_interfaces::srv::MoveRobot_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


// Include directives for member types
// Member 'result_pose'
// already included above
// #include "custom_interfaces/msg/detail/robot_pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__MoveRobot_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__MoveRobot_Response __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveRobot_Response_
{
  using Type = MoveRobot_Response_<ContainerAllocator>;

  explicit MoveRobot_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit MoveRobot_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _result_pose_type =
    custom_interfaces::msg::RobotPose_<ContainerAllocator>;
  _result_pose_type result_pose;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__result_pose(
    const custom_interfaces::msg::RobotPose_<ContainerAllocator> & _arg)
  {
    this->result_pose = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__MoveRobot_Response
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__MoveRobot_Response
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveRobot_Response_ & other) const
  {
    if (this->result_pose != other.result_pose) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveRobot_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveRobot_Response_

// alias to use template instance with default allocator
using MoveRobot_Response =
  custom_interfaces::srv::MoveRobot_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_interfaces__srv__MoveRobot_Event __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__srv__MoveRobot_Event __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct MoveRobot_Event_
{
  using Type = MoveRobot_Event_<ContainerAllocator>;

  explicit MoveRobot_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit MoveRobot_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::MoveRobot_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_interfaces::srv::MoveRobot_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__srv__MoveRobot_Event
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__srv__MoveRobot_Event
    std::shared_ptr<custom_interfaces::srv::MoveRobot_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveRobot_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveRobot_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveRobot_Event_

// alias to use template instance with default allocator
using MoveRobot_Event =
  custom_interfaces::srv::MoveRobot_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_interfaces

namespace custom_interfaces
{

namespace srv
{

struct MoveRobot
{
  using Request = custom_interfaces::srv::MoveRobot_Request;
  using Response = custom_interfaces::srv::MoveRobot_Response;
  using Event = custom_interfaces::srv::MoveRobot_Event;
};

}  // namespace srv

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__MOVE_ROBOT__STRUCT_HPP_
