//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>

#include <iostream>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "Rectify.h"

//Todo : test findCirclesGrid

using namespace std;

void Disparity()
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
}
int main(int argc, char *argv[])
{
#if 1
	using namespace cv;

	cv::Mat img1 = imread("/home/rdr/data/StereoTestImages/F_140630/j00097_1.png");
	cv::Mat img2 = imread("/home/rdr/data/StereoTestImages/F_140630/j00097_2.png");

	Rectify(img1, img2);
#else
	Disparity();
#endif
	return 0;
	//MeshLab
}
