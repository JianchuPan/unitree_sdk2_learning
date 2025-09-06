#include "rclcpp/rclcpp.hpp"
#include "helloworlddata_interfaces/msg/hello_world_data.hpp"  // 引入自定义消息头文件

#define TOPIC "TopicHelloWorld_ros2"  // 保持原话题名

// 订阅者节点类，继承自rclcpp::Node
class HelloSubNode : public rclcpp::Node
{
private:
    // 声明订阅者对象，类型为自定义的HelloWorldData消息
    rclcpp::Subscription<helloworlddata_interfaces::msg::HelloWorldData>::SharedPtr subscriber_;

public:
    // 构造函数：初始化节点名称
    HelloSubNode() : Node("helloworld_cpp_sub_node")
    {
        // 创建订阅者，订阅指定话题
        subscriber_ = this->create_subscription<helloworlddata_interfaces::msg::HelloWorldData>(
            TOPIC,  // 要订阅的话题名（与发布者一致）
            10,                      // 消息队列长度
            std::bind(&HelloSubNode::topic_callback, this, std::placeholders::_1)  // 回调函数
        );
        
        RCLCPP_INFO(this->get_logger(), "订阅者节点已启动，正在等待消息...");
    }

private:
    // 消息回调函数：当收到消息时执行
    void topic_callback(const helloworlddata_interfaces::msg::HelloWorldData::SharedPtr msg) const
    {
        // 打印收到的消息内容（注意使用%ld匹配long int类型）
        RCLCPP_INFO(this->get_logger(), "收到消息:");
        RCLCPP_INFO(this->get_logger(), "  user_id: %ld", msg->user_id);
        RCLCPP_INFO(this->get_logger(), "  name: %s", msg->name.c_str());
        RCLCPP_INFO(this->get_logger(), "  message: %s", msg->message.c_str());
        RCLCPP_INFO(this->get_logger(), "------------------------");
    }
};

int main(int argc, char *argv[])
{
    // 初始化ROS 2
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<HelloSubNode>();
    // 创建订阅者节点并运行
    rclcpp::spin(node);
    
    // 关闭ROS 2
    rclcpp::shutdown();
    return 0;
}
    