include_directories (${HELLO_SOURCE_DIR}/Asio/Timer)


add_executable (timer 
	Timer1
	Timer2
	Timer3
	main)

target_link_libraries(timer 
	boost_system-mt)