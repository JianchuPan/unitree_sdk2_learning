cmake_minimum_required(VERSION 3.8)
project(helloworld_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(unitree_sdk2 REQUIRED)
find_package(helloworlddata_interfaces REQUIRED)

add_executable(helloworld_cpp_pub
  src/helloword_cpp_pub.cpp  # 你的主程序
  src/HelloWorldData.cpp  # 生成的C++代码
)
add_executable(helloworld_cpp_pub1
  src/helloworld_cpp_pub1.cpp  # 你的主程序
  src/HelloWorldData.cpp  # 生成的C++代码
)
add_executable(helloworld_cpp_pub2
  src/helloworld_cpp_pub2.cpp  # 你的主程序
)
add_executable(helloworld_cpp_sub
  src/helloworld_cpp_sub.cpp  # 你的主程序
  src/HelloWorldData.cpp  # 生成的C++代码
)
add_executable(helloworld_cpp_sub2
  src/helloworld_cpp_sub2.cpp  # 你的主程序
)

ament_target_dependencies(helloworld_cpp_pub rclcpp)
ament_target_dependencies(helloworld_cpp_pub1 rclcpp)
ament_target_dependencies(helloworld_cpp_pub2 rclcpp helloworlddata_interfaces)
ament_target_dependencies(helloworld_cpp_sub rclcpp)
ament_target_dependencies(helloworld_cpp_sub2 rclcpp helloworlddata_interfaces)

target_link_libraries(helloworld_cpp_pub unitree_sdk2)
target_link_libraries(helloworld_cpp_pub1 unitree_sdk2)
target_link_libraries(helloworld_cpp_pub2 unitree_sdk2)
target_link_libraries(helloworld_cpp_sub unitree_sdk2)

target_include_directories(helloworld_cpp_pub PUBLIC
  include/${PROJECT_NAME}
)
target_include_directories(helloworld_cpp_pub1 PUBLIC
  include/${PROJECT_NAME}
)
target_include_directories(helloworld_cpp_sub PUBLIC
  include/${PROJECT_NAME}
)

# 关键：安装可执行文件到指定目录
install(TARGETS
  helloworld_cpp_pub helloworld_cpp_pub1 helloworld_cpp_pub2 helloworld_cpp_sub helloworld_cpp_sub2
  DESTINATION lib/${PROJECT_NAME}  # 必须安装到 lib/包名 目录下
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
