// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice

#ifndef HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__BUILDER_HPP_
#define HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "helloworlddata_interfaces/msg/detail/hello_world_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace helloworlddata_interfaces
{

namespace msg
{

namespace builder
{

class Init_HelloWorldData_message
{
public:
  explicit Init_HelloWorldData_message(::helloworlddata_interfaces::msg::HelloWorldData & msg)
  : msg_(msg)
  {}
  ::helloworlddata_interfaces::msg::HelloWorldData message(::helloworlddata_interfaces::msg::HelloWorldData::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::helloworlddata_interfaces::msg::HelloWorldData msg_;
};

class Init_HelloWorldData_name
{
public:
  explicit Init_HelloWorldData_name(::helloworlddata_interfaces::msg::HelloWorldData & msg)
  : msg_(msg)
  {}
  Init_HelloWorldData_message name(::helloworlddata_interfaces::msg::HelloWorldData::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_HelloWorldData_message(msg_);
  }

private:
  ::helloworlddata_interfaces::msg::HelloWorldData msg_;
};

class Init_HelloWorldData_user_id
{
public:
  Init_HelloWorldData_user_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HelloWorldData_name user_id(::helloworlddata_interfaces::msg::HelloWorldData::_user_id_type arg)
  {
    msg_.user_id = std::move(arg);
    return Init_HelloWorldData_name(msg_);
  }

private:
  ::helloworlddata_interfaces::msg::HelloWorldData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::helloworlddata_interfaces::msg::HelloWorldData>()
{
  return helloworlddata_interfaces::msg::builder::Init_HelloWorldData_user_id();
}

}  // namespace helloworlddata_interfaces

#endif  // HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__BUILDER_HPP_
