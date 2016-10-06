/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#ifndef VISUALIZER_IMU_H
#define VISUALIZER_IMU_H

#include <condition_variable>
#include "vector.h"

namespace data
{
class Imu
{
private:
	std::mutex _condMutex;
	std::condition_variable _cond;
public:
	Imu();
	Imu(Imu& imu);
	Imu(Imu&& imu);

	Vector3d accelerometer;
	Vector3d gyro;
	Vector3d magnetometer;

	Imu &operator=(const Imu &imu);

	Imu &retrieve();
	void broadcastUpdate();
};
}


#endif //VISUALIZER_IMU_H
