cmake_minimum_required(VERSION 3.10)
project(FaceDetection)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Add the executable
add_executable(face_detection face_detection.cpp)

# Link against OpenCV libraries
target_link_libraries(face_detection ${OpenCV_LIBS})

# Create a directory for models at build time
add_custom_command(
    TARGET face_detection POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
    ${CMAKE_CURRENT_BINARY_DIR}/models
)

# Copy the Haar Cascade file to the build directory
add_custom_command(
    TARGET face_detection POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/models/haarcascade_frontalface_default.xml
    ${CMAKE_CURRENT_BINARY_DIR}/models/haarcascade_frontalface_default.xml
)

# Installation rules
install(TARGETS face_detection DESTINATION bin)
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/models/ DESTINATION bin/models)
