/**
 * @author J. Santos <jamillo@gmail.com>
 * @date December 14, 2015
 **/

#ifndef VISUALIZER_IMUWINDOW_HPP
#define VISUALIZER_IMUWINDOW_HPP

#include <chrono>
#include <thread>
#include <ostream>
#include <iostream>
#include "elements/cube.h"
#include "draw/stage.h"
#include "data/imu.h"

class ImuWindow
{
private:
	bool _initialized;
	bool _running;

	data::Vector3d _offset;

	elements::Cube *_accelerometerCube;
	elements::Cube *_gyroCube;
	elements::Cube *_magnetometerCube;

	draw::Stage _stage;
	std::unique_ptr<std::thread> updateThread;
public:
	data::Imu imu;

	ImuWindow();

	virtual ~ImuWindow();

	virtual void init();

	void runUpdateTrampolin();

	void draw();

	void calibrate();

	void offset();
};

#endif // VISUALIZER_IMUWINDOW_HPP