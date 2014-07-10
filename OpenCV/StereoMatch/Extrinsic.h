#ifndef EXTRINSIC_H_
#define EXTRINSIC_H_

#include <opencv/cv.h>

/*!
 *
 * Extrinsic parameters
 * See cv::stereoRectify
 *
 * \param R – Rotation matrix between the coordinate systems of the first and the second cameras. rows: 3,  cols: 3
 * \param T – Translation vector between coordinate systems of the cameras. rows: 3, cols: 1
 *
 *	//http://answers.opencv.org/question/7617/extrinsicyml-meanings/
 *	//https://code.google.com/p/stereoview/source/browse/trunk/extrinsics.yml?r=20
 *	//http://answers.opencv.org/question/20805/having-trouble-with-stereorectify/
 *
 **/
void SetExtrinsics(cv::Mat & R, cv::Mat & T);

#endif /* EXTRINSIC_H_ */
