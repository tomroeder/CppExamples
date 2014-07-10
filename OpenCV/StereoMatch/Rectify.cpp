#include "Rectify.h"

#include "Intrinsic.h"
#include "Extrinsic.h"

#include <iostream>

using namespace std;

void Rectify(cv::Mat & img1, cv::Mat & img2)
{
	using namespace cv;

	cout << "images size = " << img1.size() << " "<< img2.size() << endl;

	Mat M1, D1;
	SetIntrinsics(6.144157, 0.008000, 0.008000, 416.735503, 299.154712, 0.021028, M1, D1);
	cout << "M1 = " << M1 << endl;
	cout << "D1 = " << D1 << endl;

	Mat M2, D2;
	SetIntrinsics(6.109411, 0.008000, 0.008000, 409.351082,  287.965287, 0.021380, M2, D2);
	cout << "M2 = " << M2 << endl;
	cout << "D2 = " << D2 << endl;

	//Rotation, Translation vector of Camera 1 vs. Camera 2 in world coordinates
	cv::Mat R, T;
	SetExtrinsics( R, T );

	Mat R1, P1, R2, P2;

	const Size img_size = img1.size();
    Rect roi1, roi2;
    Mat Q;

	cv::stereoRectify(
			// --> in
			M1, D1, M2, D2, img_size, R, T,
			// --> out
			R1, R2, P1, P2, Q, CALIB_ZERO_DISPARITY, -1, img_size, &roi1, &roi2 );

	Mat map11, map12, map21, map22;
	cv::initUndistortRectifyMap(M1, D1, R1, P1, img_size, CV_16SC2, map11, map12);
	cv::initUndistortRectifyMap(M2, D2, R2, P2, img_size, CV_16SC2, map21, map22);

	Mat img1r, img2r;
	cv::remap(img1, img1r, map11, map12, INTER_LINEAR);
	cv::remap(img2, img2r, map21, map22, INTER_LINEAR);

	img1 = img1r;
	img2 = img2r;
#if 0
	//Bildanzeige
  IplImage iplImage1(img1);
	cvNamedWindow("mainWin1", CV_WINDOW_AUTOSIZE);
	cvShowImage("mainWin1", &iplImage1 );

  IplImage iplImage2(img2);
	cvNamedWindow("mainWin2", CV_WINDOW_AUTOSIZE);
	cvShowImage("mainWin2", &iplImage2 );

	cvWaitKey(0); // wait for a key
#endif
}

