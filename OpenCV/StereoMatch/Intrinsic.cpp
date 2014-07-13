#include "Intrinsic.h"

void SetIntrinsics(float f_mm,
		float m_dx, /* von m_dxy bzw. m_dpxy */
		float m_dy,/* von m_dxy bzw. m_dpxy */
		float cx_pix, //!  center x in pixel
		float cy_pix, //!  center y in pixel
		double k1, // kappa1 lens distortion
		cv::Mat & M, cv::Mat & D)
{
	using namespace cv;

	const double fx1_mm = f_mm;
	const double fy1_mm = f_mm;

	//!  focal length in pixel
	const double fx1_pix = fx1_mm / m_dx;// rough estimate, see above
	//!  focal length in pixel
	const double fy1_pix = fy1_mm / m_dy;// rough estimate, see above

	double m1data[] = {fx1_pix, 0.0, cx_pix, 0.0, fy1_pix, cy_pix, 0.0, 0.0, 1.0};

	//! 3x3 floating-point camera matrix
	M = Mat(3, 3, CV_64F, m1data).clone();


	/*!
	 * undistorted coordinates xu and yu of point with coordinates (xd, yd) are computed with the following formula
	 * xu = xd * ( 1 + k1 * r² + k2 * r⁴) + 2 * p1 * xd * yd + p2 * (r² + 2* xd²);
	 * i.e.: xu = xd wenn alle Koeffzienten == 0
	 */
	const double k2 = 0.0;
	const double p1 = 0.0;//siehe auch samples/c/intrinsics.yml
	const double p2 = 0.0;//siehe auch samples/c/intrinsics.yml
	const double k3 = 0.0;//siehe auch samples/c/intrinsics.yml
	//! rows 1, cols 5, Output vector of distortion coefficients (k1; k2; p1; p2[; k3[; k4; k5; k6]])
	double d1data[] = {k1, k2, p1, p2, k3};
	D = Mat(1, 5, CV_64F, d1data).clone();
}

void InitIntrinsics(cv::Mat & M1, cv::Mat & D1, cv::Mat & M2, cv::Mat & D2)
{
	SetIntrinsics(6.144157, 0.008000, 0.008000, 416.735503, 299.154712, 0.021028, M1, D1);
	SetIntrinsics(6.109411, 0.008000, 0.008000, 409.351082,  287.965287, 0.021380, M2, D2);
}
