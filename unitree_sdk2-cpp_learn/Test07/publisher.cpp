#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "HelloWorldData.hpp"

// #define TOPIC "TopicHelloWorld"
#define TOPIC "TopicTest06"

using namespace unitree::robot;
using namespace unitree::common;

int main()
{
    std::cout << "Publisher4 started." << std::endl;
    ChannelFactory::Instance()->Init(0);
    ChannelPublisher<HelloWorldData::Msg> publisher(TOPIC);

    publisher.InitChannel();

    while (true)
    {
        HelloWorldData::Msg msg(unitree::common::GetCurrentTimeMillisecond(),"Publisher3:", "HelloWorld.");
        publisher.Write(msg);
        sleep(1);
    }

    return 0;
}
