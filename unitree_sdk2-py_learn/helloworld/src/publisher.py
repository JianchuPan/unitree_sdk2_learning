import sys
from pathlib import Path
# 获取项目根目录（src的父目录）
root_dir = Path(__file__).parent.parent
# 将根目录添加到系统路径，确保能找到 messages 文件夹
sys.path.append(str(root_dir))

# 之后正常导入
from messages.user_data import *

import time
# 直接把源码文件中unitree_sdk2_python文件夹
# 复制到"~/miniconda3/envs/ros2_humble/lib/python3.10/site-packages"下,否则报警告且无代码提示
import unitree_sdk2py
from unitree_sdk2py.core.channel import ChannelPublisher, ChannelFactoryInitialize

def main():
    print("publisher脚本启动!")

    # 假设从命令行获取输入参数（类似C++的argv[1]）
    if len(sys.argv) != 2:
        print("错误:请传入一个参数!使用方法:python publisher.py <字符串>")
        return
    input_arg = sys.argv[1]
    print(f"您输入的参数是：{input_arg}")

    ChannelFactoryInitialize()

    # Create a publisher to publish the data defined in UserData class
    pub = ChannelPublisher("topic", UserDefineData)
    pub.Init()

    for i in range(50):
        # Create a Userdata message
        msg = UserDefineData(" ", 0)
        msg.string_data = f"HelloWorld! --{input_arg}"
        msg.float_data = time.time()

        # Publish message
        if pub.Write(msg, 0.5):
            print("Publish success. msg:", msg)
        else:
            print("Waitting for subscriber.")

        time.sleep(1)

    pub.Close()

if __name__ == "__main__":
    main()
