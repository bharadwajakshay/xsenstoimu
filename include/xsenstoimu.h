#include <iostream>
#include <fstream>

#include "ros/ros.h"
#include "sensor_msgs/Imu.h"
#include <cmath>
#include <math.h>
#include <xsens_slim/imuX.h>
#include <tf/LinearMath/Matrix3x3.h>
#include <geometry_msgs/Quaternion.h>

class xsenstoimu
{
private:
	ros::NodeHandle node_handle;
	ros::Subscriber SubMti;
	ros::Publisher PubIMU;

public:
	void callbackmti(const xsens_slim::imuX::Ptr msg);
	xsenstoimu();

};
