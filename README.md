# unitree_sdk2_learning
unitree_sdk2_learning base on 

1. **[unitree_sdk2](https://github.com/unitreerobotics/unitree_sdk2)(C++)**
    1. [CycloneDDS](https://github.com/eclipse-cyclonedds/cyclonedds)(idlc工具) 
    2. [CycloneDDS-CXX](https://github.com/eclipse-cyclonedds/cyclonedds-cxx)(idlc for c++的依赖)

2. **[unitree_sdk2_python](https://github.com/unitreerobotics/unitree_sdk2_python)(Python)**

3. **[unitree_ros2](https://github.com/unitreerobotics/unitree_ros2)(ROS2,CPP,Python)**

## First: **[unitree_sdk2-cpp_learn](./unitree_sdk2-cpp_learn/)**
### 依赖
1. **unitree_sdk**
2. **CycloneDDS** -->for idlc工具
3. **CycloneDDS-CXX** -->给idlc工具提供C++依赖，libcycloneddsidlc++.so-->由libcycloneddsidlcpp.so重新映射得来

[**注**]由源码编译安装后需在~/.bashrc文件中添加环境变量，如下:
```
# ~/.bashrc文件
# 1.unitree_sdk2
export CMAKE_PREFIX_PATH=~/Install/unitree_sdk2/lib/cmake/unitree_sdk2:$CMAKE_PREFIX_PATH # 提供unitree_sdk2库的路径，用于CMakeLists.txt中的find_package()
# 2.CycloneDDS
export PATH=~/Install/CycloneDDS/bin:$PATH # 提供idlc工具的执行文件路径
# export LD_LIBRARY_PATH=/home/pjc/Install/CycloneDDS/lib:$LD_LIBRARY_PATH
# 3.CycloneDDS-CXX
export LD_LIBRARY_PATH=/home/pjc/Install/CycloneDDS-CXX/lib:$LD_LIBRARY_PATH # 给idlc工具提供C++依赖,libcycloneddsidlc++.so
```
### SimpleTest for idlc and unitree_sdk2 publisher/subscriber
Two method in CMakeLists.txt when want to use a idlc for .idl transfer to .cpp/.hpp:
1. **[Test06](./unitree_sdk2-cpp_learn/Test06/)**
```CMake
# 定义IDL转换命令（使用用户安装的idlc）
add_custom_command(
  OUTPUT 
    ${GEN_DIR}/${IDL_FILE_NAME}.hpp
    ${GEN_DIR}/${IDL_FILE_NAME}.cpp
  COMMAND 
    cd ${GEN_DIR} && ${IDLC_EXE} -l c++ ${CMAKE_CURRENT_LIST_DIR}/${IDL_FILE}
  DEPENDS 
    ${IDL_FILE}  # IDL文件修改时自动重新生成，依赖控制
  COMMENT 
    "使用用户安装的idlc转换IDL文件: ${IDLC_EXE}"
)
```
2. **[Test07](./unitree_sdk2-cpp_learn/Test07/)**
```CMake
idlcxx_generate(
  TARGET HelloWorldData
  FILES ${IDL_FILE}
  WARNINGS no-implicit-extensibility
)
```

## Second: **[unitree_sdk2-py_learn](./unitree_sdk2-py_learn/)**

### 依赖
1. 依赖First中的**unitree_sdk**
[**注**]由源码编译安装后需在~/.bashrc文件中添加环境变量，如下:
```
# ~/.bashrc文件
# 1.unitree_sdk2
export LD_LIBRARY_PATH=~/Install/unitree_sdk2/lib:$LD_LIBRARY_PATH # libunitree_sdk2.a库的路径
```
2. unitree_sdk2_python
- [**注**]库名：**unitree_sdk2py**, 该接口会调用底层 C++ 库
- **Dependencies**
  - Python >= 3.8
  - cyclonedds == 0.10.2
  - numpy
  - opencv-python
- **从源码安装**
  ```
  conda activate ros2_humble # or your owner conda env
  cd ~/Install # or your install path
  sudo apt install python3-pip
  git clone https://github.com/unitreerobotics/unitree_sdk2_python.git
  cd unitree_sdk2_python
  pip3 install -e .  # unitree_sdk2_python库会被安装到该虚拟环境的Python站点包（site-packages）目录下
  ```

- **使用**
  - 导入
    `import unitree_sdk2py`
    `from unitree_sdk2py.core.channel import ChannelPublisher, ChannelFactoryInitialize`

  












