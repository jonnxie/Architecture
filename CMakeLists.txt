cmake_minimum_required(VERSION 3.22)
project(Architecture)

set(CMAKE_CXX_STANDARD 23)

add_executable(Architecture main.cpp)

target_link_libraries(Architecture FlowEngine )

set(LIBRARY_OUTPUT_PATH     ${PROJECT_SOURCE_DIR}/CMAKE)
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/CMAKE)

add_subdirectory(FlowEngine)
