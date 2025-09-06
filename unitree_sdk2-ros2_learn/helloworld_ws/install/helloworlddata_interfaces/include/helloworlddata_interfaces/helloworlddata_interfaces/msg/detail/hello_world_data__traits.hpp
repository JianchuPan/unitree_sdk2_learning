// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from helloworlddata_interfaces:msg/HelloWorldData.idl
// generated code does not contain a copyright notice

#ifndef HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__TRAITS_HPP_
#define HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "helloworlddata_interfaces/msg/detail/hello_world_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace helloworlddata_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HelloWorldData & msg,
  std::ostream & out)
{
  out << "{";
  // member: user_id
  {
    out << "user_id: ";
    rosidl_generator_traits::value_to_yaml(msg.user_id, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HelloWorldData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: user_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "user_id: ";
    rosidl_generator_traits::value_to_yaml(msg.user_id, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HelloWorldData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace helloworlddata_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use helloworlddata_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const helloworlddata_interfaces::msg::HelloWorldData & msg,
  std::ostream & out, size_t indentation = 0)
{
  helloworlddata_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use helloworlddata_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const helloworlddata_interfaces::msg::HelloWorldData & msg)
{
  return helloworlddata_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<helloworlddata_interfaces::msg::HelloWorldData>()
{
  return "helloworlddata_interfaces::msg::HelloWorldData";
}

template<>
inline const char * name<helloworlddata_interfaces::msg::HelloWorldData>()
{
  return "helloworlddata_interfaces/msg/HelloWorldData";
}

template<>
struct has_fixed_size<helloworlddata_interfaces::msg::HelloWorldData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<helloworlddata_interfaces::msg::HelloWorldData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<helloworlddata_interfaces::msg::HelloWorldData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // HELLOWORLDDATA_INTERFACES__MSG__DETAIL__HELLO_WORLD_DATA__TRAITS_HPP_
