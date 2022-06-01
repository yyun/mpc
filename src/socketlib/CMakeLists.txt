set(SOCKET_SOURCE_FILE ClientSocket.cpp ServerSocket.cpp Socket.cpp)
include_directories(${PROJECT_SOURCE_DIR}/socketlib)

add_library(mysocket SHARED ${SOCKET_SOURCE_FILE})

add_executable(simple_client_main simple_client_main.cpp ${SOCKET_SOURCE_FILE})
add_executable(simple_server_main simple_server_main.cpp ${SOCKET_SOURCE_FILE})