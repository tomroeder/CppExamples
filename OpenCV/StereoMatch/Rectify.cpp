#include "Rectify.h"

#include "Intrinsic.h"
#include "Extrinsic.h"
#include "CalibrationPoints.h"

#include <iostream>

using namespace std;

void Calibrate(cv::Mat & M1, cv::Mat & D1, cv::Mat & M2, cv::Mat & D2, cv::Mat & R, cv::Mat & T)
{
	const std::vector< std::vector<cv::Point2f> > imagePointsCam1 = InitImageCoordCam1();
	const std::vector< std::vector<cv::Point2f> > imagePointsCam2 = InitImageCoordCam2();
	const std::vector< std::vector<cv::Point3f> > objectPoints = InitWorld();

	const cv::Size imageSize(800, 600);

	InitIntrinsics(M1, D1, M2, D2);

	cout << "M1 = " << M1 << endl;
	cout << "D1 = " << D1 << endl;
	cout << "M2 = " << M1 << endl;
	cout << "D2 = " << D1 << endl;

	cv::Mat E, F;

	double ret = cv::stereoCalibrate(objectPoints,
			imagePointsCam1,imagePointsCam2,
			M1, D1, M2, D2,
			imageSize,
			R, T, E, F,
			cv::TermCriteria(cv::TermCriteria::COUNT+cv::TermCriteria::EPS, 30, 1e-6)
			//, cv::CALIB_SAME_FOCAL_LENGTH /*cv::CALIB_FIX_INTRINSIC*/
		);

	cout << "M1 = " << M1 << endl;
	cout << "D1 = " << D1 << endl;
	cout << "M2 = " << M1 << endl;
	cout << "D2 = " << D1 << endl;

	cout << "R = " << R << endl;
	cout << "T = " << T << endl;
	cout << "E = " << E << endl;
	cout << "F = " << F << endl;
}

void Rectify(cv::Mat & imgCam1Right, cv::Mat & imgCam2Left, bool doCalibration)
{
	cv::Mat M1, D1, M2, D2;
	cv::Mat R, T;

	if (doCalibration)
	{
		 Calibrate(M1, D1, M2, D2, R, T);
	}
	else
	{
		InitIntrinsics(M1, D1, M2, D2);

		cout << "M1 = " << M1 << endl;
		cout << "D1 = " << D1 << endl;
		cout << "M2 = " << M2 << endl;
		cout << "D2 = " << D2 << endl;

		//Rotation, Translation vector of Camera 1 vs. Camera 2 in world coordinates
		SetExtrinsics( R, T );
	}

	cv::Mat R1, P1, R2, P2;

	const cv::Size img_size = imgCam1Right.size();
	cv::Rect roi1, roi2;
	cv::Mat Q;

	cv::stereoRectify(
		// --> in
		M1, D1, M2, D2, img_size, R, T,
		// --> out
		R1, R2, P1, P2, Q, cv::CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2 );

	cv::Mat map11, map12, map21, map22;
	cv::initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
	cv::initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);

	cv::Mat img1r, img2r;
	cv::remap(imgCam1Right, img1r, map11, map12, cv::INTER_LINEAR);
	cv::remap(imgCam2Left, img2r, map21, map22, cv::INTER_LINEAR);
	//cv::remap(imgCam2Left, img1r, map11, map12, cv::INTER_LINEAR);
	//cv::remap(imgCam1Right, img2r, map21, map22, cv::INTER_LINEAR);

	imgCam1Right = img1r;
	imgCam2Left = img2r;
}

