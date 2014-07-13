#include "Extrinsic.h"

#include <iostream>

using namespace std;

void SetExtrinsics(cv::Mat & r, cv::Mat & t)
{
	double rCam1data[] = { -0.997570,  0.001196,  -0.069654, -0.001385, -0.999996,  0.002659, -0.069651,  0.002749,  0.997568 };
	const cv::Mat RCam1 = cv::Mat(3, 3, CV_64F, rCam1data).clone();

	double rCam2data[] = { -0.998177, 0.003021, 0.060282, -0.001636, -0.999734, 0.023002, 0.060336, 0.022862, 0.997916 };
	const cv::Mat RCam2 = cv::Mat(3, 3, CV_64F, rCam2data).clone();

	r = RCam2 * RCam1.t();// R = (Rc_2)(Rc_1^T)
	//r = RCam1 * RCam2.t();// R = (Rc_2)(Rc_1^T)

	cv::Mat angles_deg;

	cv::Rodrigues(RCam1, angles_deg);
	cout << "Winkel [deg] Kamera 1 = " << angles_deg << endl;

	cv::Rodrigues(RCam2, angles_deg);
	cout << "Winkel [deg] Kamera 2 = " << angles_deg << endl;

	cv::Rodrigues(r, angles_deg);
	cout << "Winkel [deg] Kamera 1 vs. Kamera 2 = " << angles_deg << endl;

	double tCam1data [] =  { 448.068850,  209.964202, -854.624918 };
	const cv::Mat tCam1 = cv::Mat(3, 1, CV_64F, tCam1data).clone();

	double tCam2data [] =  { 404.649962, 190.829853, -914.463886 };
	const cv::Mat tCam2 = cv::Mat(3, 1, CV_64F, tCam2data).clone();

	t = tCam1 - r.t() * tCam2; //T = Tc_1 - (R^T)(Tc_2),
	//t = tCam2 - r.t() * tCam1; //T = Tc_1 - (R^T)(Tc_2),

	cout << "T = " << t << endl;
}

