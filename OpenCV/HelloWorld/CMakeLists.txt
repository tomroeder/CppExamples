#include_directories (/usr/local/include/)

add_executable (cvHelloWorld
	main)


target_link_libraries(cvHelloWorld	
	m 
	opencv_core 
	opencv_highgui)