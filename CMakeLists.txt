cmake_minimum_required(VERSION 3.15.2)

project(motion-planning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -framework OpenGL")
set(SRC "src")
set(SRC_SIMPLEGL ${SRC}/simplegl)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Disable in-source builds
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
FATAL: In-source build is not allowed. Create a separate directory for build files.
")
endif()

# Main executable
add_executable(motion_plan ${SRC}/motion_plan.cc ${SRC}/scene.cc ${SRC}/astar.cc)

# Test simplegl executable
add_executable(simplegl_test ${SRC_SIMPLEGL}/simplegl_test.cc)
find_package(SimpleGL REQUIRED)
target_link_libraries(simplegl_test simplegl)

