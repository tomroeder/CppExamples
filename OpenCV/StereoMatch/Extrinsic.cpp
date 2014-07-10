#include "Extrinsic.h"

void SetExtrinsics(cv::Mat & R, cv::Mat & T)
{
	using namespace cv;

	// dblarray1 m_Rxyz[3] =   0.002756  0.069707  -3.140204
	double rCam1data[] = { -0.997570,  0.001196,  -0.069654, -0.001385, -0.999996,  0.002659, -0.069651,  0.002749,  0.997568 };
	cv::Mat RCam1 = Mat(3, 3, CV_64F, rCam1data).clone();

	// dblarray1 m_Rxyz[3] =   0.022905  -0.060373  -3.139953
	double rCam2data[] = { -0.998177, 0.003021, 0.060282, -0.001636, -0.999734, 0.023002, 0.060336, 0.022862, 0.997916 };
	cv::Mat RCam2 = Mat(3, 3, CV_64F, rCam2data).clone();

	R = RCam2 * RCam1.t();

	//float rdata[] = { 1.1, 0.1, 0.1,    0.1, 1.2, -0.1,    0.1, 0.1, 1.01 };
	//cv::Mat R = Mat(3, 3, CV_64F, rdata).clone();
	double tdata[] = { 448.068850 - 404.649962,  209.964202 - 190.829853,  -854.624918 - (-914.463886) };
	T = Mat(3, 1, CV_64F, tdata).clone();
}

