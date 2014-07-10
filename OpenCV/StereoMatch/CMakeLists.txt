
add_executable (cvStereoMatch
	main
	Intrinsic.cpp
	Extrinsic.cpp)


target_link_libraries(cvStereoMatch	
	m 
	opencv_core 
	opencv_highgui
	opencv_imgproc
	opencv_calib3d)