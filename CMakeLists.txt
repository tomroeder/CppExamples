cmake_minimum_required(VERSION 2.6)
project (HELLO)

# QT Support
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

# C++ 11 support einschalten:
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /opt/local/lib)

#Aktivierung von devtoolset erfordert :
#erfordert "scl enable devtoolset-2 bash" 

#OpenCV support
find_package( OpenCV REQUIRED )

add_subdirectory (C++11)
add_subdirectory (Boost)
add_subdirectory (QT)
add_subdirectory (OpenCV)
