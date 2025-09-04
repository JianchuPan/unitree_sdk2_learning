#include <iostream>
#include <chrono>
#include <thread>
#include "unitree/robot/channel/channel_publisher.hpp"
#include <unitree/common/time/time_tool.hpp>
#include "idl_files/user_data.hpp"  // 由 IDL 文件生成的头文件（需通过 SDK 工具编译）

#define TOPIC "topic_cpp"

using namespace unitree::robot;
using namespace unitree::common;

int main(int argc,char* argv[]) 
{
    std::cout << "cpp_Publisher started." << std::endl;

    //argc:参数数量，argv:参数数组
    // 检查参数数量：argc应为2（程序名 + 1个参数）
    if (argc != 2) {
        std::cerr << "错误：请传入且仅传入一个参数！" << std::endl;
        std::cerr << "使用方法：" << argv[0] << " <字符串参数>" << std::endl;
        return 1; // 返回非0表示程序异常退出
    }
    // 将参数转换为string类型，打印处理后的参数
    std::string input_arg = argv[1];
    std::cout << "您输入的参数是：" << input_arg << std::endl;

    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<UserDataModule::UserData> publisher(TOPIC); // UserDataModule是IDL 中定义的模块名

    publisher.InitChannel();

    // 正确拼接字符串：先将第一个字符串转为std::string再拼接
    std::string message = std::string("cpp_Publisher: ") + "HelloWorld! --" + input_arg;

    while (true)
    {
        UserDataModule::UserData user_data(message.c_str(),static_cast<double>(unitree::common::GetCurrentTimeMillisecond()));;
        publisher.Write(user_data);
        
        // std::cout << "cpp_Publisher Publish success. msg:" << user_data.float_data() <<user_data.string_data() << std::endl;
        if (publisher.Write(user_data,0.5)){
            std::cout << "cpp_Publisher Publish success. msg:" << user_data.float_data() <<user_data.string_data() << std::endl;
        }else{
            std::cout << "cpp_Publisher Waitting for subscriber." << std::endl;
        }
        
        sleep(1);
    }

    // 实际不会执行到这里，仅作为规范
    publisher.CloseChannel();
    return 0;
}