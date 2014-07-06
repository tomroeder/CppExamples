////////////////////////////////////////////////////////////////////////
//
// hello-world.cpp
//
// This is a simple, introductory OpenCV program. The program reads an
// image from a file, inverts it, and displays the result.
//
// Requires an opencv version with gtk support.
//
////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <iostream>

#include <opencv/cv.h>
#include <opencv/highgui.h>


using namespace std;

/**
 * @brief makeCanvas Makes composite image from the given images
 * @param vecMat Vector of Images.
 * @param windowHeight The height of the new composite image to be formed.
 * @param nRows Number of rows of images. (Number of columns will be calculated
 *              depending on the value of total number of images).
 * @return new composite image.
 */
cv::Mat makeCanvas(std::vector<cv::Mat>& vecMat, int windowHeight, int nRows)
{
	using namespace cv;

	int N = vecMat.size();
	nRows  = nRows > N ? N : nRows;
	int edgeThickness = 10;
	int imagesPerRow = ceil(double(N) / nRows);
	int resizeHeight = floor(2.0 * ((floor(double(windowHeight - edgeThickness) / nRows)) / 2.0)) - edgeThickness;
	int maxRowLength = 0;

	std::vector<int> resizeWidth;
	for (int i = 0; i < N;) {
			int thisRowLen = 0;
			for (int k = 0; k < imagesPerRow; k++) {
					double aspectRatio = double(vecMat[i].cols) / vecMat[i].rows;
					int temp = int( ceil(resizeHeight * aspectRatio));
					resizeWidth.push_back(temp);
					thisRowLen += temp;
					if (++i == N) break;
			}
			if ((thisRowLen + edgeThickness * (imagesPerRow + 1)) > maxRowLength) {
					maxRowLength = thisRowLen + edgeThickness * (imagesPerRow + 1);
			}
	}
	int windowWidth = maxRowLength;
	cv::Mat canvasImage(windowHeight, windowWidth, CV_8UC3, Scalar(0, 0, 0));

	for (int k = 0, i = 0; i < nRows; i++) {
			int y = i * resizeHeight + (i + 1) * edgeThickness;
			int x_end = edgeThickness;
			for (int j = 0; j < imagesPerRow && k < N; k++, j++) {
					int x = x_end;
					cv::Rect roi(x, y, resizeWidth[k], resizeHeight);
					cv::Mat target_ROI = canvasImage(roi);
					cv::resize(vecMat[k], target_ROI, target_ROI.size());
					x_end += resizeWidth[k] + edgeThickness;
			}
	}
	return canvasImage;
}

int main(int argc, char *argv[])
{
	using namespace cv;

	Mat matLDownScaledL;
	pyrDown(imread("/home/rdr/data/OpenCV/opencv-2.4.9/samples/gpu/aloeL.jpg"), matLDownScaledL);

	Mat matLDownScaledR;
	pyrDown(imread("/home/rdr/data/OpenCV/opencv-2.4.9/samples/gpu/aloeR.jpg"), matLDownScaledR);

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
