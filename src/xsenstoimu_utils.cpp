#include "xsenstoimu.h"

xsenstoimu::xsenstoimu()
{
	SubMti = node_handle.subscribe("mti",1000,&xsenstoimu::callbackmti,this);
	PubIMU = node_handle.advertise<sensor_msgs::Imu>("imu",1000);
}




void xsenstoimu::callbackmti(const xsens_slim::imuX::Ptr msg)
{
	sensor_msgs::Imu imu_msg;
	tf::Matrix3x3 rpytoqyat;
	tf::Quaternion quat;
	geometry_msgs::Quaternion imuquat;

	imu_msg.header = msg->header;
	imu_msg.angular_velocity = msg->gyro;
	imu_msg.linear_acceleration = msg->acc;
	rpytoqyat.setRPY(msg->rpy.x,msg->rpy.y,msg->rpy.z);
	rpytoqyat.getRotation(quat);
	imuquat.w = quat.getW();
	imuquat.x = quat.getX();
	imuquat.y = quat.getY();
	imuquat.z = quat.getZ();
	imu_msg.orientation = imuquat;
	PubIMU.publish(imu_msg);
}
