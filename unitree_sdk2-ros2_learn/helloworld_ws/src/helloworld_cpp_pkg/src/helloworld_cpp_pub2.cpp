#include "rclcpp/rclcpp.hpp"
#include "helloworlddata_interfaces/msg/hello_world_data.hpp"  // 引入自定义消息头文件
#include <thread>
#include <atomic>
#include <unitree/common/time/time_tool.hpp>  // Unitree时间工具


class HelloPubNode : public rclcpp::Node
{
private:
    // 声明发布器，使用自定义的HelloWorldData消息类型
    rclcpp::Publisher<helloworlddata_interfaces::msg::HelloWorldData>::SharedPtr publisher_;
    std::thread pub_thread_;          // 发布线程
    std::atomic<bool> running_{true}; // 线程控制标志
    std::string name_;                // 发布者名称
    std::string message_;             // 发布内容

public:
    // 构造函数：初始化节点和发布器
    HelloPubNode(const std::string& node_name, const std::string& name, const std::string& message)
        : Node(node_name), name_(name), message_(message)
    {
        // 初始化ROS 2发布器，队列长度10
        publisher_ = this->create_publisher<helloworlddata_interfaces::msg::HelloWorldData>(TOPIC, 10);
        
        if (publisher_) {
            RCLCPP_INFO(this->get_logger(), "节点初始化成功，话题: %s", TOPIC);
        } else {
            RCLCPP_ERROR(this->get_logger(), "发布器初始化失败！");
        }

        // 注册退出回调（处理Ctrl+C）
        rclcpp::on_shutdown([this]() {
            running_ = false;
            RCLCPP_INFO(this->get_logger(), "开始关闭节点...");
        });
    }

    // 析构函数：清理线程资源
    ~HelloPubNode()
    {
        running_ = false;
        if (pub_thread_.joinable()) {
            pub_thread_.join();  // 等待发布线程结束
        }
        RCLCPP_INFO(this->get_logger(), "节点已关闭");
    }

    // 启动发布线程
    void start_publishing()
    {
        if (!publisher_) {
            RCLCPP_ERROR(this->get_logger(), "发布器未初始化，无法启动发布！");
            return;
        }
        pub_thread_ = std::thread(&HelloPubNode::publish_loop, this);
    }

private:
    // 发布循环：定时发送消息
    void publish_loop()
    {
        while (running_ && rclcpp::ok()) {
            // 创建自定义消息实例
            helloworlddata_interfaces::msg::HelloWorldData msg;
            
            // 填充消息字段（注意字段名已改为小写+下划线）
            msg.user_id = unitree::common::GetCurrentTimeMillisecond();  // 时间戳作为user_id
            msg.name = name_;
            msg.message = message_;

            // 发布消息
            publisher_->publish(msg);
            RCLCPP_INFO(this->get_logger(), "发送消息: user_id=%ld, name=%s, message=%s",
                        msg.user_id, msg.name.c_str(), msg.message.c_str());

            // 每秒发送一次
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

int main(int argc, char *argv[])
{
    // 初始化ROS 2
    rclcpp::init(argc, argv);
    
    // 创建节点实例
    auto node = std::make_shared<HelloPubNode>(
        "helloworld_cpp_pub2_node",  // 节点名
        "pub_unitree_ros2_cpp",     // 发布者名称
        "Hello from unitree_ros2 with HelloWorldData.msg!"  // 消息内容
    );
    
    // 启动发布
    node->start_publishing();
    
    // 进入ROS 2事件循环
    rclcpp::spin(node);
    
    // 关闭ROS 2
    rclcpp::shutdown();
    return 0;
}
