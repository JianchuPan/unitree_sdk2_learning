// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice
#include "helloworlddata_interfaces/msg/detail/hello_world_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
helloworlddata_interfaces__msg__HelloWorldData__init(helloworlddata_interfaces__msg__HelloWorldData * msg)
{
  if (!msg) {
    return false;
  }
  // user_id
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    helloworlddata_interfaces__msg__HelloWorldData__fini(msg);
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    helloworlddata_interfaces__msg__HelloWorldData__fini(msg);
    return false;
  }
  return true;
}

void
helloworlddata_interfaces__msg__HelloWorldData__fini(helloworlddata_interfaces__msg__HelloWorldData * msg)
{
  if (!msg) {
    return;
  }
  // user_id
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
helloworlddata_interfaces__msg__HelloWorldData__are_equal(const helloworlddata_interfaces__msg__HelloWorldData * lhs, const helloworlddata_interfaces__msg__HelloWorldData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // user_id
  if (lhs->user_id != rhs->user_id) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
helloworlddata_interfaces__msg__HelloWorldData__copy(
  const helloworlddata_interfaces__msg__HelloWorldData * input,
  helloworlddata_interfaces__msg__HelloWorldData * output)
{
  if (!input || !output) {
    return false;
  }
  // user_id
  output->user_id = input->user_id;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

helloworlddata_interfaces__msg__HelloWorldData *
helloworlddata_interfaces__msg__HelloWorldData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  helloworlddata_interfaces__msg__HelloWorldData * msg = (helloworlddata_interfaces__msg__HelloWorldData *)allocator.allocate(sizeof(helloworlddata_interfaces__msg__HelloWorldData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(helloworlddata_interfaces__msg__HelloWorldData));
  bool success = helloworlddata_interfaces__msg__HelloWorldData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
helloworlddata_interfaces__msg__HelloWorldData__destroy(helloworlddata_interfaces__msg__HelloWorldData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    helloworlddata_interfaces__msg__HelloWorldData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
helloworlddata_interfaces__msg__HelloWorldData__Sequence__init(helloworlddata_interfaces__msg__HelloWorldData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  helloworlddata_interfaces__msg__HelloWorldData * data = NULL;

  if (size) {
    data = (helloworlddata_interfaces__msg__HelloWorldData *)allocator.zero_allocate(size, sizeof(helloworlddata_interfaces__msg__HelloWorldData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = helloworlddata_interfaces__msg__HelloWorldData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        helloworlddata_interfaces__msg__HelloWorldData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
helloworlddata_interfaces__msg__HelloWorldData__Sequence__fini(helloworlddata_interfaces__msg__HelloWorldData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      helloworlddata_interfaces__msg__HelloWorldData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

helloworlddata_interfaces__msg__HelloWorldData__Sequence *
helloworlddata_interfaces__msg__HelloWorldData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  helloworlddata_interfaces__msg__HelloWorldData__Sequence * array = (helloworlddata_interfaces__msg__HelloWorldData__Sequence *)allocator.allocate(sizeof(helloworlddata_interfaces__msg__HelloWorldData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = helloworlddata_interfaces__msg__HelloWorldData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
helloworlddata_interfaces__msg__HelloWorldData__Sequence__destroy(helloworlddata_interfaces__msg__HelloWorldData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    helloworlddata_interfaces__msg__HelloWorldData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
helloworlddata_interfaces__msg__HelloWorldData__Sequence__are_equal(const helloworlddata_interfaces__msg__HelloWorldData__Sequence * lhs, const helloworlddata_interfaces__msg__HelloWorldData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!helloworlddata_interfaces__msg__HelloWorldData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
helloworlddata_interfaces__msg__HelloWorldData__Sequence__copy(
  const helloworlddata_interfaces__msg__HelloWorldData__Sequence * input,
  helloworlddata_interfaces__msg__HelloWorldData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(helloworlddata_interfaces__msg__HelloWorldData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    helloworlddata_interfaces__msg__HelloWorldData * data =
      (helloworlddata_interfaces__msg__HelloWorldData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!helloworlddata_interfaces__msg__HelloWorldData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          helloworlddata_interfaces__msg__HelloWorldData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!helloworlddata_interfaces__msg__HelloWorldData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
