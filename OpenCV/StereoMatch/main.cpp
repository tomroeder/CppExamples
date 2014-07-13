#include <iostream>

#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "Rectify.h"
#include "Disparity.h"

using namespace std;
using namespace cv;

//computeCorrespondEpilines
int main(int argc, char *argv[])
{
	try
	{
		cv::Mat imgCam1Right = imread("/home/rdr/data/StereoTestImages/F_140630/j00691_1.png");//WNT Stereo 1 = rechts
		cv::Mat imgCam2Left = imread("/home/rdr/data/StereoTestImages/F_140630/j00691_2.png");//WNT Stereo 2 = links

		//cv::Mat imgCam1Right = imread("/home/rdr/data/StereoTestImages/F_140630/j00229_1.png");//WNT Stereo 1 = rechts
		//cv::Mat imgCam2Left = imread("/home/rdr/data/StereoTestImages/F_140630/j00229_2.png");//WNT Stereo 2 = links

		//cv::Mat imgCam1Right = imread("/home/rdr/data/StereoTestImages/F_140630/j00097_1.png");//WNT Stereo 1 = rechts
		//cv::Mat imgCam2Left = imread("/home/rdr/data/StereoTestImages/F_140630/j00097_2.png");//WNT Stereo 2 = links
#if 0
		cv::Mat imgHg1Right = imread("/home/rdr/data/StereoTestImages/F_140630/HG_IMAGES/SKHG_020_1.png");//WNT Stereo 1 = rechts
		cv::Mat imgHg2Left = imread("/home/rdr/data/StereoTestImages/F_140630/HG_IMAGES/SKHG_020_2.png");//WNT Stereo 2 = links
		if ( imgHg1Right.empty() || imgHg2Left.empty() )
		{
			throw std::exception();
		}

		imgCam1Right = imgCam1Right - imgHg1Right;
		imgCam2Left = imgCam2Left - imgHg2Left;
#endif

		if ( imgCam1Right.empty() || imgCam2Left.empty() )
		{
			throw std::exception();
		}

		Rectify(imgCam1Right, imgCam2Left, true /* doCalibration */);

		imwrite("/tmp/rect_1_right.png", imgCam1Right);
		imwrite("/tmp/rect_2_left.png", imgCam2Left);

		Disparity(imgCam1Right, imgCam2Left);

		cvWaitKey(0); // wait for a key

		return 0;
	}
	catch(const std::exception & e)
	{
		cerr << "Fehler : " << e.what() << endl;
	}
}
