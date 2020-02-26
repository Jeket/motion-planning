cmake_minimum_required(VERSION 3.15.2)

project(motion-planning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Disable in-source builds
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
FATAL: In-source build is not allowed. Create a separate directory for build files.
")
endif()

# Main executable
add_executable(test_opengl test_opengl.cpp)

include_directories(include)


# Find GLEW library, and exit if not found
find_library(GLEW_LIB
	NAMES libGLEW.a
	HINTS "${CMAKE_SOURCE_DIR}/lib/GL"
	REQUIRED
)
if(NOT GLEW_LIB)
	message(FATAL_ERROR "FATAL: GLEW library not found.")
endif()
message("Found GLEW library: ${GLEW_LIB}")

# Find SDL2 library, and exit if not found
find_library(SDL2_LIB
	NAMES SDL2-2.0.0
	HINTS "${CMAKE_SOURCE_DIR}/lib/SDL2"
	REQUIRED
)
if(NOT SDL2_LIB)
	message(FATAL_ERROR "FATAL: SDL2 library not found.")
endif()
message("Found SDL2 library: ${SDL2_LIB}")

target_link_libraries(test_opengl
	${SDL2_LIB}
	${GLEW_LIB}
)

