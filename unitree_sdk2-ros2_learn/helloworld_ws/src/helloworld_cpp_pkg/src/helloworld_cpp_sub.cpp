#include "rclcpp/rclcpp.hpp"
#include <unitree/robot/channel/channel_subscriber.hpp>  // 引入Unitree订阅器
#include "HelloWorldData.hpp"  // 使用IDL生成的消息类型
#include <unitree/common/time/time_tool.hpp>

#define TOPIC "TopicHelloWorld_ros2"  // 保持与发布者相同的话题名

using namespace unitree::robot;
using namespace unitree::common;

class HelloSubNode : public rclcpp::Node
{
private:
    // Unitree DDS订阅器，类型为IDL生成的HelloWorldData::Msg
    ChannelSubscriber<HelloWorldData::Msg> subscriber_;

    // 订阅回调函数（注意参数类型为const void*）
    void on_message(const void* msg_ptr)
    {
        // 将void*转换为HelloWorldData::Msg*
        const HelloWorldData::Msg* msg = static_cast<const HelloWorldData::Msg*>(msg_ptr);
        if (msg == nullptr) {
            RCLCPP_ERROR(this->get_logger(), "Received null message");
            return;
        }

        // 打印收到的消息（使用IDL消息的成员函数访问字段）
        RCLCPP_INFO(this->get_logger(), "收到消息:");
        RCLCPP_INFO(this->get_logger(), "  user_id: %ld", msg->user_id());
        RCLCPP_INFO(this->get_logger(), "  name: %s", msg->name().c_str());
        RCLCPP_INFO(this->get_logger(), "  message: %s", msg->message().c_str());
        RCLCPP_INFO(this->get_logger(), "------------------------");
    }

public:
    HelloSubNode() : Node("helloworld_cpp_sub_node"), subscriber_(TOPIC)
    {
        // 初始化Unitree ChannelFactory（全局一次）
        ChannelFactory::Instance()->Init(0);

        // 初始化订阅通道，绑定回调函数（注意参数类型匹配）
        try {
            // 回调函数需转换为std::function<void(const void*)>
            subscriber_.InitChannel(std::bind(&HelloSubNode::on_message, this, std::placeholders::_1));
            RCLCPP_INFO(this->get_logger(), "订阅者节点已启动，正在等待消息...");
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "订阅器初始化失败: %s", e.what());
        } catch (...) {
            RCLCPP_ERROR(this->get_logger(), "订阅器初始化失败（未知错误）");
        }

        // 注册ROS 2退出回调，关闭订阅器
        rclcpp::on_shutdown([this]() {
            subscriber_.CloseChannel();
            RCLCPP_INFO(this->get_logger(), "订阅器已关闭");
        });
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HelloSubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}