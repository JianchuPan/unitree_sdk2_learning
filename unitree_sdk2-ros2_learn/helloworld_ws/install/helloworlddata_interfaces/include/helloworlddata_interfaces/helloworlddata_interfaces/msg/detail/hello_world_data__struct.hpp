// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice

#ifndef HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__STRUCT_HPP_
#define HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__helloworlddata_interfaces__msg__HelloWorldData __attribute__((deprecated))
#else
# define DEPRECATED__helloworlddata_interfaces__msg__HelloWorldData __declspec(deprecated)
#endif

namespace helloworlddata_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HelloWorldData_
{
  using Type = HelloWorldData_<ContainerAllocator>;

  explicit HelloWorldData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_id = 0ll;
      this->name = "";
      this->message = "";
    }
  }

  explicit HelloWorldData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->user_id = 0ll;
      this->name = "";
      this->message = "";
    }
  }

  // field types and members
  using _user_id_type =
    int64_t;
  _user_id_type user_id;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__user_id(
    const int64_t & _arg)
  {
    this->user_id = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator> *;
  using ConstRawPtr =
    const helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__helloworlddata_interfaces__msg__HelloWorldData
    std::shared_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__helloworlddata_interfaces__msg__HelloWorldData
    std::shared_ptr<helloworlddata_interfaces::msg::HelloWorldData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HelloWorldData_ & other) const
  {
    if (this->user_id != other.user_id) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const HelloWorldData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HelloWorldData_

// alias to use template instance with default allocator
using HelloWorldData =
  helloworlddata_interfaces::msg::HelloWorldData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace helloworlddata_interfaces

#endif  // HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__STRUCT_HPP_
