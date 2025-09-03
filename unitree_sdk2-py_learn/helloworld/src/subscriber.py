import sys
from pathlib import Path
# 获取项目根目录（src的父目录）
root_dir = Path(__file__).parent.parent
# 将根目录添加到系统路径，确保能找到 messages 文件夹
sys.path.append(str(root_dir))

# 之后正常导入
from messages.user_data import *

import time
from unitree_sdk2py.core.channel import ChannelSubscriber, ChannelFactoryInitialize

def main():
    ChannelFactoryInitialize()
    # Create a subscriber to subscribe the data defined in UserData class
    sub = ChannelSubscriber("topic", UserData)
    sub.Init()

    while True:
        msg = sub.Read()
        if msg is not None:
            print("Subscribe success. msg:", msg)
        else:
            print("No data subscribed.")
            break
    sub.Close()

if __name__ == "__main__":
    main()
