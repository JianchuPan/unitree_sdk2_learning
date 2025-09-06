// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "helloworlddata_interfaces/msg/detail/hello_world_data__rosidl_typesupport_introspection_c.h"
#include "helloworlddata_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "helloworlddata_interfaces/msg/detail/hello_world_data__functions.h"
#include "helloworlddata_interfaces/msg/detail/hello_world_data__struct.h"


// Include directives for member types
// Member `name`
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  helloworlddata_interfaces__msg__HelloWorldData__init(message_memory);
}

void helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_fini_function(void * message_memory)
{
  helloworlddata_interfaces__msg__HelloWorldData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_member_array[3] = {
  {
    "user_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(helloworlddata_interfaces__msg__HelloWorldData, user_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(helloworlddata_interfaces__msg__HelloWorldData, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(helloworlddata_interfaces__msg__HelloWorldData, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_members = {
  "helloworlddata_interfaces__msg",  // message namespace
  "HelloWorldData",  // message name
  3,  // number of fields
  sizeof(helloworlddata_interfaces__msg__HelloWorldData),
  helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_member_array,  // message members
  helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_init_function,  // function to initialize message memory (memory has to be allocated)
  helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_type_support_handle = {
  0,
  &helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_helloworlddata_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, helloworlddata_interfaces, msg, HelloWorldData)() {
  if (!helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_type_support_handle.typesupport_identifier) {
    helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &helloworlddata_interfaces__msg__HelloWorldData__rosidl_typesupport_introspection_c__HelloWorldData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
