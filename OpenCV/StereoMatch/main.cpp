////////////////////////////////////////////////////////////////////////
//
// Portation of stereo_match.py from samples folder of OpenCV source.
//
// Requires an opencv version with gtk support.
//
// Creation of disparity map from two rectified images
//
////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "Intrinsic.h"

using namespace std;

void Rectify(cv::Mat & img1, cv::Mat & img2)
{
	using namespace cv;

	Mat M1, D1;
	SetIntrinsics(6.144157, 0.008000, 0.008000, 416.735503, 299.154712, 0.021028, M1, D1);

	Mat M2, D2;
	SetIntrinsics(6.109411, 0.008000, 0.008000, 409.351082,  287.965287, 0.021380, M2, D2);

    //reading extrinsic parameters

    Mat R, T;
    Mat R1, P1, R2, P2;

    //Rotation vector world coordinates

    //Cam1
    //dblarray1 m_Txyz[3] =   448.068850  209.964202  -854.624918
    //dblarray1 m_Rxyz[3] =   0.002756  0.069707  -3.140204

    //Cam2
    //dblarray1 m_Txyz[3] =   404.649962  190.829853  -914.463886
    //dblarray1 m_Rxyz[3] =   0.022905  -0.060373  -3.139953

#if 0
    fs["R"] >> R;
    fs["T"] >> T;
#endif
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
}

int main(int argc, char *argv[])
{
	using namespace cv;

	Mat matLDownScaledL;

	//pyrDown(imread("/home/rdr/data/OpenCV/opencv-2.4.9/samples/gpu/aloeL.jpg"), matLDownScaledL);
	pyrDown(imread("/home/rdr/data/StereoTestImages/F_140630/j00097_2.png"), matLDownScaledL);

	Mat matLDownScaledR;
	//pyrDown(imread("/home/rdr/data/OpenCV/opencv-2.4.9/samples/gpu/aloeR.jpg"), matLDownScaledR);
	pyrDown(imread("/home/rdr/data/StereoTestImages/F_140630/j00097_1.png"), matLDownScaledR);

	IplImage imgL(matLDownScaledL);
	IplImage imgR(matLDownScaledR);


	// --- disparity ---

	// disparity range is tuned for 'aloe' image pair
	int window_size = 3;
	int min_disp = 16;
	int num_disp = 112-min_disp;

	StereoSGBM stereoSGBM(min_disp
			,num_disp
			,window_size
			,8*3*window_size*window_size /* P1 */,
			32*3*window_size*window_size /* P2 */,
			0 /* disp12MaxDiff */,
			0 /*preFilterCap*/,
			10 /*uniquenessRatio*/,
			100 /* speckleWindowSize*/,
			32 /*speckleRange*/,
			false /*fullDP */
			);

	//stereoSGBM.fullDP = true;

	Mat disp;
	stereoSGBM(matLDownScaledL, matLDownScaledR, disp);

	double minVal;
	double maxVal;

	cv::minMaxIdx( disp, &minVal, &maxVal);

	cout << "min/max val : " << minVal  << "/ " << maxVal << endl;

	const double offset = (maxVal - minVal)/2.0 + minVal;//Offset so , dass Mitte des Wertebereiches == 0
	const double scale = (32766.0) / (maxVal-offset); // Skalierung so, dass kompletter Wertebereich genutzt wird

	const Mat disp2Show( (disp - offset) * scale );

	// --- 3D Punktwolke ---
	const float h = imgL.height;
	const float w = imgL.width;
	const float f = 0.8*w;// guess for focal length

	// Q – 4 x 4 perspective transformation matrix that can be obtained with stereoRectify().
	// turn points 180 deg around x-axis, so that y-axis looks up
	const Matx44f Q(1, 0, 0, -0.5*w,
			0,-1, 0,  0.5*h,
			0, 0, 0,     -f,
			0, 0, 1,      0);

	//reprojectImageTo3D(InputArray disparity, OutputArray _3dImage, InputArray Q, bool handle-MissingValues=false, int ddepth=-1 )
	Mat points;
	cv::reprojectImageTo3D(disp, points, Q);

	Mat colors;
	cv::cvtColor( matLDownScaledL, colors, cv::COLOR_BGR2RGB);
    //mask = disp > disp.min()
    //out_points = points[mask]
    //out_colors = colors[mask]
    //out_fn = 'out.ply'
    //write_ply('out.ply', out_points, out_colors)

    cout << "Saved 3D point cloud." << endl;

	// ... fehlt noch :-)
	cv::minMaxIdx( disp2Show, &minVal, &maxVal);
	cout << "min/max val : " << minVal << "/ " << maxVal << endl;

	const int startX = 100;

	//Bildanzeige
	cvNamedWindow("mainWin", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("mainWin", startX, 100);
	cvShowImage("mainWin", &imgL );

	cvNamedWindow("mainWinR", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("mainWinR", startX, 100);
	cvShowImage("mainWinR", &imgR );

	cvNamedWindow("mainWin2", CV_WINDOW_AUTOSIZE);
	cvMoveWindow("mainWin2", startX+imgL.width, 100);

	IplImage dispImage( disp2Show );
	cvShowImage("mainWin2", &dispImage );


	cvWaitKey(0); // wait for a key

	return 0;

	//MeshLab
}
