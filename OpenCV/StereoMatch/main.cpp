#include <iostream>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "Rectify.h"
#include "Disparity.h"

//Todo : test findCirclesGrid

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
	cv::Mat img1 = imread("/home/rdr/data/StereoTestImages/F_140630/j00097_1.png");//rechts
	cv::Mat img2 = imread("/home/rdr/data/StereoTestImages/F_140630/j00097_2.png");//links

	Rectify(img1, img2);
	Disparity(img1, img2);

	cvWaitKey(0); // wait for a key

	return 0;
}
