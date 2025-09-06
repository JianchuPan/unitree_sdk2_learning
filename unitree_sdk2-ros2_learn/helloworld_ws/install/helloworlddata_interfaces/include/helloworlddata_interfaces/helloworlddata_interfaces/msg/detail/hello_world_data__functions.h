// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice

#ifndef HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__FUNCTIONS_H_
#define HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "helloworlddata_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "helloworlddata_interfaces/msg/detail/hello_world_data__struct.h"

/// Initialize msg/HelloWorldData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * helloworlddata_interfaces__msg__HelloWorldData
 * )) before or use
 * helloworlddata_interfaces__msg__HelloWorldData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
bool
helloworlddata_interfaces__msg__HelloWorldData__init(helloworlddata_interfaces__msg__HelloWorldData * msg);

/// Finalize msg/HelloWorldData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
void
helloworlddata_interfaces__msg__HelloWorldData__fini(helloworlddata_interfaces__msg__HelloWorldData * msg);

/// Create msg/HelloWorldData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * helloworlddata_interfaces__msg__HelloWorldData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
helloworlddata_interfaces__msg__HelloWorldData *
helloworlddata_interfaces__msg__HelloWorldData__create();

/// Destroy msg/HelloWorldData message.
/**
 * It calls
 * helloworlddata_interfaces__msg__HelloWorldData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
void
helloworlddata_interfaces__msg__HelloWorldData__destroy(helloworlddata_interfaces__msg__HelloWorldData * msg);

/// Check for msg/HelloWorldData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
bool
helloworlddata_interfaces__msg__HelloWorldData__are_equal(const helloworlddata_interfaces__msg__HelloWorldData * lhs, const helloworlddata_interfaces__msg__HelloWorldData * rhs);

/// Copy a msg/HelloWorldData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
bool
helloworlddata_interfaces__msg__HelloWorldData__copy(
  const helloworlddata_interfaces__msg__HelloWorldData * input,
  helloworlddata_interfaces__msg__HelloWorldData * output);

/// Initialize array of msg/HelloWorldData messages.
/**
 * It allocates the memory for the number of elements and calls
 * helloworlddata_interfaces__msg__HelloWorldData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
bool
helloworlddata_interfaces__msg__HelloWorldData__Sequence__init(helloworlddata_interfaces__msg__HelloWorldData__Sequence * array, size_t size);

/// Finalize array of msg/HelloWorldData messages.
/**
 * It calls
 * helloworlddata_interfaces__msg__HelloWorldData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
void
helloworlddata_interfaces__msg__HelloWorldData__Sequence__fini(helloworlddata_interfaces__msg__HelloWorldData__Sequence * array);

/// Create array of msg/HelloWorldData messages.
/**
 * It allocates the memory for the array and calls
 * helloworlddata_interfaces__msg__HelloWorldData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
helloworlddata_interfaces__msg__HelloWorldData__Sequence *
helloworlddata_interfaces__msg__HelloWorldData__Sequence__create(size_t size);

/// Destroy array of msg/HelloWorldData messages.
/**
 * It calls
 * helloworlddata_interfaces__msg__HelloWorldData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
void
helloworlddata_interfaces__msg__HelloWorldData__Sequence__destroy(helloworlddata_interfaces__msg__HelloWorldData__Sequence * array);

/// Check for msg/HelloWorldData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
bool
helloworlddata_interfaces__msg__HelloWorldData__Sequence__are_equal(const helloworlddata_interfaces__msg__HelloWorldData__Sequence * lhs, const helloworlddata_interfaces__msg__HelloWorldData__Sequence * rhs);

/// Copy an array of msg/HelloWorldData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_helloworlddata_interfaces
bool
helloworlddata_interfaces__msg__HelloWorldData__Sequence__copy(
  const helloworlddata_interfaces__msg__HelloWorldData__Sequence * input,
  helloworlddata_interfaces__msg__HelloWorldData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__FUNCTIONS_H_
