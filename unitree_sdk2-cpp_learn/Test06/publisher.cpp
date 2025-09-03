#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "HelloWorldData.hpp"

// #define TOPIC "TopicHelloWorld"
#define TOPIC "TopicTest06"

using namespace unitree::robot;
using namespace unitree::common;

int main(int argc,char* argv[])
{
    std::cout << "Publisher3 started." << std::endl;

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
    ChannelPublisher<HelloWorldData::Msg> publisher(TOPIC);

    publisher.InitChannel();

    // 正确拼接字符串："HelloWorld! --" + 输入参数
    std::string message = "HelloWorld! --" + input_arg;
    while (true)
    {
        HelloWorldData::Msg msg(unitree::common::GetCurrentTimeMillisecond(),"Publisher3:", message.c_str());
        publisher.Write(msg);
        sleep(1);
    }

    return 0;
}
