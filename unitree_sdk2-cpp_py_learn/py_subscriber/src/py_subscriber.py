import sys
from pathlib import Path
# 获取项目根目录（src的父目录）
root_dir = Path(__file__).parent.parent
# 将根目录添加到系统路径，确保能找到 messages 文件夹
sys.path.append(str(root_dir))

# 之后正常导入
from messages.user_data import *

import time
import unitree_sdk2py
from unitree_sdk2py.core.channel import ChannelSubscriber, ChannelFactoryInitialize

TOPIC = "topic_cpp"

# 定义消息处理回调函数
def handle_message(msg):
    if msg is not None:
        print(f"Received message: string_data={msg.string_data}, float_data={msg.float_data}")
    else:
        print("Received empty message")

def main():
    print("py_subscriber启动了!")
    ChannelFactoryInitialize()
    # Create a subscriber to subscribe the data defined in UserData class
    sub = ChannelSubscriber(TOPIC, UserData)
    sub.Init(handle_message)  # 这里应该传入回调处理函数

    try:
        while True:
            time.sleep(1)  # 保持程序运行
    except KeyboardInterrupt:
        print("程序退出")
    finally:
            sub.Close()

if __name__ == "__main__":
    main()
