#include_directories (${HELLO_SOURCE_DIR}/Asio/Timer)

add_executable (serialization
	main)

target_link_libraries(serialization	boost_serialization-mt)