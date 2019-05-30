#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>

#include "soslab_tl_driver.h"

using namespace std;


int main(int argc, char** argv)
{
    ros::init(argc, argv, "tl_driver_node");
    ros::NodeHandle nh;
    ros::NodeHandle priv_nh("~");
    ros::Publisher tl_data_pub = nh.advertise<sensor_msgs::LaserScan>("scan", 1000);

    std::string port;
    int baud_rate;
    std::string frame_id;

    priv_nh.param("port", port, std::string("/dev/ttyUSB0"));
    priv_nh.param("baud_rate", baud_rate, 921600);
    priv_nh.param("frame_id", frame_id, std::string("laser"));

    Tl tl(port,baud_rate);

    int tl_radius[1001];
    double tl_angle[1001];
    GetTLAngle(tl_angle);

    sensor_msgs::LaserScan scan_msg;
    
    ros::Rate loop_rate(40);
    tl.tl3_normal_start();
    while(ros::ok())
    {
        loop_rate.sleep();

        scan_msg.header.stamp = ros::Time::now();
        tl.ReadPacket(tl_radius);

        scan_msg.header.frame_id = frame_id;
        scan_msg.angle_min = tl_angle[0];
        scan_msg.angle_max = tl_angle[1001-1];
        scan_msg.angle_increment = (scan_msg.angle_max - scan_msg.angle_min) / (double)(1001-1);
        scan_msg.scan_time = (ros::Time::now() - scan_msg.header.stamp).toSec();
        scan_msg.time_increment = scan_msg.scan_time / (double)(1001-1);
        scan_msg.range_min = 0.1;
        scan_msg.range_max = 5.0;
        scan_msg.ranges.resize(1001);
        for(int i=0; i<1001; i++)
        {
            scan_msg.ranges[i] = (double)tl_radius[i]/1000.0;
        }
        
        tl_data_pub.publish(scan_msg);
    }
    tl.tl3_stop();

    return -1;
}
