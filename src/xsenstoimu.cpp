#include "xsenstoimu.h"


int main(int argc, char **argv)
{
	ros::init(argc,argv,"xsenstoimu");
	xsenstoimu obj;
	ros::spin();

	return(0);
}


