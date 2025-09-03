#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "HelloWorldData.hpp"

// #define TOPIC "TopicHelloWorld"
#define TOPIC "TopicTest06"

using namespace unitree::robot;
using namespace unitree::common;

void Handler(const void* msg)
{
    const HelloWorldData::Msg* pm = (const HelloWorldData::Msg*)msg;

    std::cout << "userID:" << pm->userID() << ", name:" << pm->name() << ", message:" << pm->message() << std::endl;
}

int main()
{
    std::cout << "Subscriber3 started." << std::endl;
    ChannelFactory::Instance()->Init(0);
    ChannelSubscriber<HelloWorldData::Msg> subscriber(TOPIC);
    subscriber.InitChannel(Handler);

    sleep(5);
    subscriber.CloseChannel();

    std::cout << "reseted. sleep 3" << std::endl;

    sleep(3);
    subscriber.InitChannel();

    sleep(5);
    subscriber.CloseChannel();

    std::cout << "reseted. sleep 3" << std::endl;

    sleep(3);
    subscriber.InitChannel();

    while (true)
    {
        sleep(10);
    }

    return 0;
}
