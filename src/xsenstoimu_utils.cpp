#include "xsenstoimu.h"

xsenstoimu::xsenstoimu()
{
	SubMti = node_handle.subscribe("mti",1000,&xsenstoimu::callbackmti,this);
	PubIMU = node_handle.advertise<sensor_msgs::Imu>("imu",1000);
}




void xsenstoimu::callbackmti(const xsens_slim::imuX::Ptr msg)
{
	std::cout<<"Entered mti callback";

}
