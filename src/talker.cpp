#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char **argv) //聲明C语言main函数
{
	ros::init(argc, argv, "talker");//初始化 ROS 並為node命名

	ros::NodeHandle n;//node 初始化

	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);//告訴ros主機發布std_msgs::String類型的資訊topic的命名和資訊儲存量

	ros::Rate loop_rate(10);//發布速率10Hz
	int count = 0;
	while (ros::ok())//ros出現問題就結束
	{
		std_msgs::String msg;

		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();//設定要傳輸的資料

		ROS_INFO("%s", msg.data.c_str());//顯示傳出的東西

		chatter_pub.publish(msg);//發出要傳的資料

		ros::spinOnce();//寫這行才會真正的傳輸或接收資料

		loop_rate.sleep();
		++count;
	}
	return 0;
}
