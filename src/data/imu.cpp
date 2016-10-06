/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#include "imu.h"

data::Imu::Imu()
{ }

data::Imu::Imu(data::Imu &imu)
	: accelerometer(imu.accelerometer), gyro(imu.gyro), magnetometer(imu.magnetometer)
{ }

data::Imu::Imu(data::Imu &&imu)
	: accelerometer(imu.accelerometer), gyro(imu.gyro), magnetometer(imu.magnetometer)
{ }

data::Imu &data::Imu::operator=(const data::Imu &imu)
{
	this->accelerometer = imu.accelerometer;
	this->gyro = imu.gyro;
	this->magnetometer = imu.magnetometer;
	return *this;
}

data::Imu &data::Imu::retrieve()
{
	std::unique_lock<std::mutex> locker(this->_condMutex);
	this->_cond.wait(locker);
	return *this;
}

void data::Imu::broadcastUpdate()
{
	this->_cond.notify_all();
}
