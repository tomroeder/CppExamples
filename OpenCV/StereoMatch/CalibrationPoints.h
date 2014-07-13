#ifndef CALIBRATIONPOINTS_H_
#define CALIBRATIONPOINTS_H_

#include <vector>
#include <opencv/cv.h>

//! \return 3D Weltkoordinaten des Referenztools  ( ein Vector pro Ebene )
std::vector< std::vector<cv::Point3f> > InitWorld();

//! \return 2D Bildkoordinaten des Referenztools ( ein Vector pro Ebene )
std::vector< std::vector<cv::Point2f> > InitImageCoordCam1();

//! \return 2D Bildkoordinaten des Referenztools ( ein Vector pro Ebene )
std::vector< std::vector<cv::Point2f> > InitImageCoordCam2();

#endif /* CALIBRATIONPOINTS_H_ */
