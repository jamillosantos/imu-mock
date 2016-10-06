/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "imuwindow.h"

ImuWindow::ImuWindow()
	: _initialized(false), _running(false)
{}

ImuWindow::~ImuWindow()
{
	if (this->_running && this->updateThread)
	{
		this->_running = false;
		this->updateThread->join();
	}
}

void ImuWindow::init()
{
	VERBOSE("Initializing...");

	this->_stage.add(this->_accelerometerCube = new elements::Cube());
	this->_accelerometerCube->colour().colour(draw::Colour::RED);
	this->_accelerometerCube->position().xyz(-0.65f, 0.0f, 0.0f);
	this->_accelerometerCube->size().xyz(0.3f, 0.5f, 0.02f);

	this->_stage.add(this->_gyroCube = new elements::Cube());
	this->_gyroCube->colour().colour(draw::Colour::GREEN);
	this->_gyroCube->position().xyz(0.0f, 0.0f, 0.0f);
	this->_gyroCube->size().xyz(0.3f, 0.5f, 0.02f);

	this->_stage.add(this->_magnetometerCube = new elements::Cube());
	this->_magnetometerCube->colour().colour(draw::Colour::BLUE);
	this->_magnetometerCube->position().xyz(0.65f, 0.0f, 0.0f);
	this->_magnetometerCube->size().xyz(0.3f, 0.5f, 0.02f);

	this->updateThread.reset(new std::thread(&ImuWindow::runUpdateTrampolin, std::ref(*this)));

	this->_initialized = true;
	VERBOSE("Initialized.");
}

void ImuWindow::runUpdateTrampolin()
{
	this->_running = true;
	data::Imu imuData;
	while (this->_running)
	{
		imuData = this->imu.retrieve();

		this->_accelerometerCube->rotate().xyz(
			imuData.accelerometer.x() + 360.0 - this->_offset.x(),
			imuData.accelerometer.y() + 360.0 - this->_offset.y(),
			imuData.accelerometer.z() + 360.0 - this->_offset.z()
		);
		this->_gyroCube->rotate().xyz(
			imuData.gyro.x() + 360.0f - this->_offset.x(),
			imuData.gyro.y() + 360.0f - this->_offset.y(),
			imuData.gyro.z() + 360.0f - this->_offset.z()
		);
		this->_magnetometerCube->rotate().xyz(
			R2D(imuData.magnetometer.x()) + 360.0f - this->_offset.x(),
			R2D(imuData.magnetometer.y()) + 360.0f - this->_offset.y(),
			R2D(imuData.magnetometer.z()) + 360.0f - this->_offset.z()
		);
	}
}

void ImuWindow::draw()
{
	VERBOSE("Accelerometer: "
				<< this->_accelerometerCube->rotate().x() << ":"
				<< this->_accelerometerCube->rotate().y() << ":"
				<< this->_accelerometerCube->rotate().z()
	);
	VERBOSE("Gyro: "
				<< this->_gyroCube->rotate().x() << ":"
				<< this->_gyroCube->rotate().y() << ":"
				<< this->_gyroCube->rotate().z()
	);
	VERBOSE("Magnetometer: "
				<< this->_magnetometerCube->rotate().x() << ":"
				<< this->_magnetometerCube->rotate().y() << ":"
				<< this->_magnetometerCube->rotate().z()
	);
	this->_stage.draw();
}

void ImuWindow::calibrate()
{
	// this->_gyro.calibrate();
}

void ImuWindow::offset()
{
	data::Imu imuData = this->imu.retrieve();
	this->_offset = imuData.magnetometer;
}
