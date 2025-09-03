cmake_minimum_required(VERSION 3.14) 

#项目名称、版本号、描述、语言
project(unitree_sdk2_learningProject 
    VERSION 0.1 
    DESCRIPTION "unitree_sdk2 learning CPP Project" 
    LANGUAGES CXX
    )

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 开启详细编译日志
set(CMAKE_VERBOSE_MAKEFILE ON)  # 放在文件开头

# 指定可执行文件输出到项目根目录下的 bin 文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Test06)

# 以下两个不能同时开
# add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Test07/idl_generate) # 先处理idl_generate(生成IDL->CPP/HPP)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Test07) # 再处理Test07(编译运行程序)