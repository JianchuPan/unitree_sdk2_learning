// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice

#ifndef HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__STRUCT_H_
#define HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/HelloWorldData in the package helloworlddata_interfaces.
typedef struct helloworlddata_interfaces__msg__HelloWorldData
{
  /// 对应IDL中的long long
  int64_t user_id;
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String message;
} helloworlddata_interfaces__msg__HelloWorldData;

// Struct for a sequence of helloworlddata_interfaces__msg__HelloWorldData.
typedef struct helloworlddata_interfaces__msg__HelloWorldData__Sequence
{
  helloworlddata_interfaces__msg__HelloWorldData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} helloworlddata_interfaces__msg__HelloWorldData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__STRUCT_H_
