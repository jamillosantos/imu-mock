cmake_minimum_required(VERSION 2.8)
project(visualizer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(-DDEBUG=1)

# find_library(libpango NAMES pango)
# find_library(libpangoft2 NAMES pangoft2)
# find_library(libpangoxft NAMES pangoxft)
# find_library(libgosu NAMES gosu HINTS libs/gosu-0.10.3/bin/debug)

find_package(OpenGL)
if(OPENGL_FOUND)
	message("-- OPENGL FOUND")
	message("-- ${OPENGL_LIBRARIES}")
	message("")
else()
	message(ERROR "OPENGL NOT FOUND")
	set(OPENGL_gl_LIBRARY opengl32)
	set(OPENGL_glu_LIBRARY glu32)
endif(OPENGL_FOUND)

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT)
if(GLUT_FOUND)
	message("-- GLUT FOUND!")
	message("-- Include dirs: ${GLUT_INCLUDE_DIRS}")
	message("-- Library dirs: ${GLUT_LIBRARY_DIRS}")
	message("-- Definitions: ${GLUT_DEFINITIONS}")
	include_directories(${GLUT_INCLUDE_DIRS})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})
else()
	message(ERROR " GLUT not found!")
endif(GLUT_FOUND)

#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
	message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

## jsoncpp

set(jsoncpp_ROOT "$ENV{HOME}/libs/jsoncpp")
message(JSON dir: ${jsoncpp_ROOT})
include_directories(${jsoncpp_ROOT}/include)
link_directories(${jsoncpp_ROOT}/lib)
find_library(jsoncpp NAMES jsoncpp)

## Boost

set(Boost_NO_SYSTEM_PATHS ON)
set(BOOST_ROOT "$ENV{HOME}/libs/libboost_1_61_0")
set(BOOST_INCLUDEDIR "${BOOST_ROOT}/include")
set(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib")
find_package(Boost 1.59.0 REQUIRED system unit_test_framework program_options regex)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
message("Boost include dir: ${Boost_INCLUDE_DIRS}")
message("Boost library dir: ${Boost_LIBRARY_DIRS}")

set(SOURCE_FILES
	src/definitions.h

	src/main.cpp

	src/draw/drawable.cpp
	src/draw/drawable.h

	src/draw/stage.cpp
	src/draw/stage.h

	src/draw/transform.cpp
	src/draw/transform.h

	src/draw/value.cpp
	src/draw/value.h

	src/draw/vector.cpp
	src/draw/vector.h

	src/draw/colour.cpp
	src/draw/colour.h

	src/imuwindow.cpp
	src/imuwindow.h

	src/elements/cube.cpp
	src/elements/cube.h

	src/server/server.cpp
	src/server/server.h

	src/data/imu.cpp
	src/data/imu.h

	src/data/vector.cpp
	src/data/vector.h
)

add_executable(visualizer
	${SOURCE_FILES}
)

target_link_libraries(visualizer
	pthread

	dl

	${OPENGL_LIBRARIES} ${GLUT_LIBRARY}

	boost_system boost_regex
)
