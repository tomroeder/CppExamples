#ifndef INTRINSIC_H_
#define INTRINSIC_H_

#include <opencv/cv.h>

/*!
 * Intrinsic parameters
 *
 * rechts == 1
 * links  == 2
 *
 * M1 / M2 :
 * [ fx 0 cx ]
 * [ 0 fy cy ]
 * [ 0  0  1 ]
 *
 * You can get an initial (rough) estimate of the focal length in pixel dividing the focal length in mm by the width of a pixel of the camera CCD.
 * You get the former from the sensor's manual, or read it from the EXIF header of an image taken at full resolution.
 * Finding out the latter is a little more complicated: you may look up on the interwebs the CCD spec sheet,
 * if you know its manufacturer and model number, or you may just divide its overall width by the number of pixels on the side.
 * Absent other information, it's usually safe to assume that the pixels are square (i.e. fx == fy),
 * and that the CCD is orthogonal to the lens's focal axis
 * (i.e. that the term in the first row and second column of the camera matrix is zero).
 * Also, the pixel coordinates of the principal point (cx, cy) are usually hard to estimate accurately
 * without a carefully designed calibration rig,
 * and an as-carefully executed calibration procedure (that's because they are intrinsically confused with the camera translation
 * parallel to the image plane).
 * So it's best to just set them equal to the geometrical geometrical center of the image,
 * unless you know that the image has been cropped asymmetrically.
 *
 * Sample file : OpenCL source code: samples/c/intrinsics.yml
 */
void SetIntrinsics(float f_mm,
		float m_dx, /* von m_dxy bzw. m_dpxy */
		float m_dy,/* von m_dxy bzw. m_dpxy */
		float cx_pix, //!  center x in pixel
		float cy_pix, //!  center y in pixel
		float k1, // kappa1 lens distortion
		cv::Mat & M, cv::Mat & D);

#endif /* INTRINSIC_H_ */
