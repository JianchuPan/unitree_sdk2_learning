#include "rclcpp/rclcpp.hpp"
#include <thread>  // 用于创建独立线程
#include <atomic>  // 用于线程安全的退出标志

#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/common/time/time_tool.hpp>
#include "HelloWorldData.hpp"

#define TOPIC "TopicHelloWorld_ros2"

using namespace unitree::robot;
using namespace unitree::common;

class HelloPubNode :public rclcpp::Node
{
private:
    std::string name_;
    std::string sentence_;
    std::thread pub_thread_;  // 独立线程用于发布
    std::atomic<bool> running_{true};  // 线程退出标志（原子变量保证线程安全）
public:
    HelloPubNode(const std::string &node_name,const std::string &name,const std::string &sentence)
    :Node(node_name) // 调用父类构造函数
    {
        this -> name_ = name;
        this -> sentence_ = sentence;

    }
    
    // 启动发布线程（在 main 中调用，替代直接调用 pub_unitreeSDK）
    void start_publishing()
    {
        pub_thread_ = std::thread(&HelloPubNode::pub_unitreeSDK, this);
    }

     // 等待发布线程结束（在 main 中退出前调用）
    void join_thread()
    {
        if (pub_thread_.joinable())
        {
            pub_thread_.join();
        }
    }

    // 新增：用于外部触发退出的接口
    void stop()
    {
        running_ = false;

    }
private:
    // 实际的发布逻辑（在独立线程中运行）
    void pub_unitreeSDK()
    {
        RCLCPP_INFO(this->get_logger(), "pub_unitreeSDK_cpp_ros started.");
        ChannelFactory::Instance()->Init(0);
        ChannelPublisher<HelloWorldData::Msg> publisher(TOPIC);

        publisher.InitChannel();

        // 使用 running_ 标志控制循环，而非无限循环
        while (running_ && rclcpp::ok())
        {
            HelloWorldData::Msg msg(unitree::common::GetCurrentTimeMillisecond(),this->name_, this->sentence_);
            publisher.Write(msg);
            RCLCPP_INFO(this->get_logger(), "Published message: %s", msg.message().c_str());  // 增加日志便于调试
            // sleep(1);
            std::this_thread::sleep_for(std::chrono::seconds(1));  // 更现代的睡眠方式
        }

        // 退出循环后释放资源
        publisher.CloseChannel();
        RCLCPP_INFO(this->get_logger(), "Publisher channel closed.");
    }
};

int main(int argc,char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HelloPubNode>(
        "helloworld_cpp_pub_node",
        "pub_unitreeSDK_cpp_ros", 
        "HelloWorld from unitree_sdk2!!"); //auto是类型自动推导 
    
    // 注册全局退出回调（ROS 2 Humble兼容方式）
    auto exit_callback = [node]() {
        node->stop(); // 触发发布线程停止
        node->join_thread(); // 等待线程结束
    };
    rclcpp::on_shutdown(exit_callback);

    // 启动发布线程（此时发布逻辑在子线程运行，不阻塞主线程）
    node->start_publishing();
    // 主线程进入 ROS 2 自旋，处理节点事件（如退出信号）
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}