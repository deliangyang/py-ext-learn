cmake_minimum_required(VERSION 3.15)
project(py_demo C)

set(CMAKE_C_STANDARD 99)
find_package(PythonLibs REQUIRED)

add_library(py_demo library.c library.h)
include_directories('/Users/ydl/work/python/Python-3.7.0/Include')
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(py_demo ${PYTHON_LIBRARIES})
