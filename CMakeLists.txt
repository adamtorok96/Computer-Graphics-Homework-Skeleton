cmake_minimum_required(VERSION 3.6)
project(OpenGl_test)

set(CMAKE_CXX_STANDARD 11)

include(FindOpenGL)
message(STATUS "OPENGLV_FOUND = ${OPENGL_FOUND}")
message(STATUS "OPENGL_GLU_FOUND = ${OPENGL_GLU_FOUND}")

include(FindGLEW)
message(STATUS "Glew_FOUND = ${GLEW_FOUND}")

include(FindGLUT)
message(STATUS "GLUT_FOUND = ${GLUT_FOUND}")

include_directories({$OPENGL_INCLUDE_DIRS})
include_directories({$GLEW_INCLUDE_DIRS})
include_directories({$GLUT_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp)
add_executable(OpenGl_test ${SOURCE_FILES})

target_link_libraries(OpenGl_test ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} GL)