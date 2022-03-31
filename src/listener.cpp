#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)//創建接收函數
{
	ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)//主函數
{
	ros::init(argc, argv, "listener");//創建 node 並為其命名

	ros::NodeHandle n;//初始化 node 

	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);//接收訊息並執行接收函數

	ros::spin();//有他才會真正的接收

	return 0;
}
