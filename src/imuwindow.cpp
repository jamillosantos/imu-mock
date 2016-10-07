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

		VERBOSE("Accelerometer:");
			VERBOSEB("-- x: " << imuData.accelerometer.x());
			VERBOSEB("-- y: " << imuData.accelerometer.y());
			VERBOSEB("-- z: " << imuData.accelerometer.z());
		data::Vector3d a(imuData.accelerometer);
		/*
		VERBOSE("Gyroscope:");
			VERBOSEB("-- x: " << imuData.gyro.x());
			VERBOSEB("-- y: " << imuData.gyro.y());
			VERBOSEB("-- z: " << imuData.gyro.z());
		this->_accelerometerCube->rotate().xyz(
			std::asin(a.x() / GRAVITY)
			std::asin(a.y() / GRAVITY)
			std::acos(a.z() / GRAVITY)
		);
		*/

		this->_accelerometerCube->rotate().xyz(
			(a.z() > 0 ? 1 : -1) * std::atan(a.y() / std::sqrt(a.x()*a.x() + a.z()*a.z())) + M_PI_2,
			(a.z() > 0 ? 1 : -1) * std::atan(a.x() / std::sqrt(a.y()*a.y() + a.z()*a.z())),
			0
		);
		/*
		this->_accelerometerCube->rotate().xyz(
			std::asin(a.z() / -GRAVITY),
			0,
			std::asin(a.x() / GRAVITY)
		);
		 */
	}
}

void ImuWindow::draw()
{
	VERBOSE("Accelerometer angle: "
		<< this->_accelerometerCube->rotate().x() << ":"
		<< this->_accelerometerCube->rotate().y() << ":"
		<< this->_accelerometerCube->rotate().z()
	);
	/*
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
	 */
	this->_stage.draw();
}

void ImuWindow::calibrate()
{
	// this->_gyro.calibrate();
}

void ImuWindow::offset()
{
	/*
	this->_offsetAccelerometer.x(this->_accelerometerCube->rotate().x());
	this->_offsetAccelerometer.y(this->_accelerometerCube->rotate().y());
	this->_offsetAccelerometer.z(this->_accelerometerCube->rotate().z());
	*/
}
