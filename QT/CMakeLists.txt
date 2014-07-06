include_directories (${HELLO_SOURCE_DIR}/QT)


SET(MY_SOURCES 
	main.cpp 
	ConcurrentMap.cpp
	MapReduce.cpp
	MapReduce2.cpp)
	
SET(QT_HEADERS 
	#ConcurrentMap.h
	)


QT4_WRAP_CPP(HEADERS_MOC ${QT_HEADERS})


add_executable (qtDemo 
	${MY_SOURCES}
	${HEADERS_MOC} )
	
target_link_libraries(qtDemo
	QtCore 
	QtGui)
