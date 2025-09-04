cmake_minimum_required(VERSION 3.14) 

#项目名称、版本号、描述、语言
project(unitree_sdk2_learningProject 
    VERSION 0.1 
    DESCRIPTION "unitree_sdk2 learning CPP/python Project" 
    LANGUAGES CXX
    )

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 开启详细编译日志
set(CMAKE_VERBOSE_MAKEFILE ON)  # 放在文件开头

# 指定可执行文件输出到项目根目录下的 bin 文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

message("执行cpp_publisher中的CMakeLists")
# 1. 验证idlc工具是否可用（依赖系统环境变量PATH）
find_program(IDLC_EXE NAMES idlc)
if(NOT IDLC_EXE)
  message(FATAL_ERROR "未找到idlc工具,请检查环境变量PATH是否包含CycloneDDS的bin目录")
endif()
message(STATUS "找到idlc工具: ${IDLC_EXE}")  # 确认使用的是用户安装的版本

# 2. 配置IDL文件和生成目录
set(IDL_FILE "user_data.idl")  # 你的IDL文件
set(GEN_DIR "${CMAKE_CURRENT_LIST_DIR}/idl_files")  # 生成文件存放目录

# 3. 创建生成目录
file(MAKE_DIRECTORY ${GEN_DIR})

# 4. 关键修正：使用string命令截断文件名后缀（替代%语法）
# 从IDL_FILE中移除".idl"后缀，得到纯文件名（如HelloWorldData）
string(REPLACE ".idl" "" IDL_FILE_NAME ${IDL_FILE})

# 5. 定义IDL转换命令（使用用户安装的idlc）
add_custom_command(
  OUTPUT 
    ${GEN_DIR}/${IDL_FILE_NAME}.hpp
    ${GEN_DIR}/${IDL_FILE_NAME}.cpp
  COMMAND 
    cd ${GEN_DIR} && ${IDLC_EXE} -l c++ ${CMAKE_CURRENT_LIST_DIR}/${IDL_FILE}
  DEPENDS 
    ${IDL_FILE}  # IDL文件修改时自动重新生成，依赖控制
  COMMENT 
    "使用用户安装的idlc转换IDL文件: ${IDLC_EXE}" # 提示信息
)

# 6. 创建自定义目标确保IDL转换优先执行,将生成的文件关联到目标（如 generate_idl）
add_custom_target(generate_idl ALL
  DEPENDS ${GEN_DIR}/${IDL_FILE_NAME}.hpp ${GEN_DIR}/${IDL_FILE_NAME}.cpp
)

# 7. 找到unitree_sdk2库（仅用于链接运行时，不影响IDL转换）
find_package(unitree_sdk2 REQUIRED)
if (NOT unitree_sdk2_FOUND)
    message(FATAL_ERROR "unitree_sdk2 not found")
else()
    message(STATUS "unitree_sdk2 found: ${unitree_sdk2_DIR}")
endif()

# 8. 添加可执行目标cpp_publisher
add_executable(cpp_publisher
  publisher.cpp  # 你的主程序
  ${GEN_DIR}/${IDL_FILE_NAME}.cpp  # 生成的C++代码
)
# 9. 确保先完成IDL转换再编译主程序
add_dependencies(cpp_publisher generate_idl)
# 10. 链接依赖（同时链接用户的unitree_sdk2）
target_link_libraries(cpp_publisher PRIVATE
  unitree_sdk2
)
# 11. 添加生成目录的头文件路径
target_include_directories(cpp_publisher PRIVATE
  ${GEN_DIR}
)