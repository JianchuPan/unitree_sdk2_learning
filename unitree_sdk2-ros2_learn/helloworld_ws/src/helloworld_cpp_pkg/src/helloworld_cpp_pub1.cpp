#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "HelloWorldData.hpp"

#include "rclcpp/rclcpp.hpp"
#include <thread>
#include <atomic>

#define TOPIC "TopicHelloWorld_ros2"

using namespace unitree::robot;
using namespace unitree::common;

// 继承rclcpp::Node，作为标准ROS 2节点
class HelloPubNode : public rclcpp::Node
{
private:
    // Unitree SDK发布器
    ChannelPublisher<HelloWorldData::Msg> publisher_;
    bool is_initialized_ = false;

    // 发布线程和话题发布控制标志
    std::thread pub_thread_;
    std::atomic<bool> running_{true};

    // 发布内容
    std::string name_;
    std::string sentence_;

public:
    // 构造函数：初始化节点和发布器
    HelloPubNode(const std::string& node_name, const std::string& name, const std::string& sentence)
        : Node(node_name), 
          publisher_(TOPIC),  // 初始化Unitree发布器
          name_(name), 
          sentence_(sentence)
    {
        // 初始化Unitree ChannelFactory（全局一次）
        ChannelFactory::Instance()->Init(0);

        // 初始化发布通道，在构造函数中修改初始化逻辑
        try {
            publisher_.InitChannel();  // 若失败可能抛出异常
            is_initialized_ = true;
            RCLCPP_INFO(this->get_logger(), "Publisher initialized successfully");
        } catch (const std::exception& e) {
            is_initialized_ = false;
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize publisher: %s", e.what());
        } catch (...) {
            is_initialized_ = false;
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize publisher (unknown error)");
        }

        // 注册ROS 2退出回调（兼容ros2 Humble）
        rclcpp::on_shutdown([this]() {
            running_ = false;
            RCLCPP_INFO(this->get_logger(), "Node shutting down...");
        });
    }

    // 析构函数：释放资源
    ~HelloPubNode()
    {
        running_ = false;
        if (pub_thread_.joinable()) {
            pub_thread_.join();
        }
        if (is_initialized_) {
            publisher_.CloseChannel();
            RCLCPP_INFO(this->get_logger(), "Unitree publisher closed");
        }
    }

    // 启动发布线程
    void start_publishing()
    {
        if (!is_initialized_) {
            RCLCPP_ERROR(this->get_logger(), "Cannot start publishing: publisher not initialized");
            return;
        }
        pub_thread_ = std::thread(&HelloPubNode::publish_loop, this);
    }

private:
    // 发布循环（在子线程中运行）
    void publish_loop()
    {
        while (running_ && rclcpp::ok()) {
            // 创建消息
            HelloWorldData::Msg msg(
                unitree::common::GetCurrentTimeMillisecond(),
                name_,
                sentence_
            );

            // 发布消息
            publisher_.Write(msg);
            RCLCPP_INFO(this->get_logger(), "Published: %s", msg.message().c_str());

            // 休眠1秒
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

int main(int argc, char *argv[])
{
    // 初始化ROS 2
    rclcpp::init(argc, argv);

    // 创建节点实例（继承自rclcpp::Node，标准ROS 2节点）
    auto node = std::make_shared<HelloPubNode>(
        "helloworld_cpp_pub1_node",
        "pub1_unitreeSDK_cpp_ros",
        "Hello from unitree_sdk2 with HelloWorldData.hpp from HelloWorldData.idl!!!"
    );

    // 启动发布
    node->start_publishing();

    // 运行节点（进入ROS 2事件循环）
    rclcpp::spin(node);

    // 退出
    rclcpp::shutdown();
    return 0;
}
    