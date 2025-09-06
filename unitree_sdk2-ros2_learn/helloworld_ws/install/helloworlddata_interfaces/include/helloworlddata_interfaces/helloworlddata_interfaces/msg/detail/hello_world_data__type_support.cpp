// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "helloworlddata_interfaces/msg/detail/hello_world_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace helloworlddata_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void HelloWorldData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) helloworlddata_interfaces::msg::HelloWorldData(_init);
}

void HelloWorldData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<helloworlddata_interfaces::msg::HelloWorldData *>(message_memory);
  typed_message->~HelloWorldData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember HelloWorldData_message_member_array[3] = {
  {
    "user_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(helloworlddata_interfaces::msg::HelloWorldData, user_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(helloworlddata_interfaces::msg::HelloWorldData, name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(helloworlddata_interfaces::msg::HelloWorldData, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers HelloWorldData_message_members = {
  "helloworlddata_interfaces::msg",  // message namespace
  "HelloWorldData",  // message name
  3,  // number of fields
  sizeof(helloworlddata_interfaces::msg::HelloWorldData),
  HelloWorldData_message_member_array,  // message members
  HelloWorldData_init_function,  // function to initialize message memory (memory has to be allocated)
  HelloWorldData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t HelloWorldData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &HelloWorldData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace helloworlddata_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<helloworlddata_interfaces::msg::HelloWorldData>()
{
  return &::helloworlddata_interfaces::msg::rosidl_typesupport_introspection_cpp::HelloWorldData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, helloworlddata_interfaces, msg, HelloWorldData)() {
  return &::helloworlddata_interfaces::msg::rosidl_typesupport_introspection_cpp::HelloWorldData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
