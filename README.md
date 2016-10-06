# IMU Mock

The IMU sensor is a fundamental component on a dynamic walking gait. The sensor can be used to add important
capabilities to the whole system, from damage prevention (when falling disable the torque from motors, or turning
the neck to the other side) until a better push-recovery mechanism.

This component uses the IMU from your cellphone in order to provide data for testing the the library Mote IMU library,
which fetches data from an IMU (with a driver).

## Android app

For capturing the IMU data, the app [Sensor fusion and IMU](https://play.google.com/store/apps/details?id=imu3.imu5.app)
from the [Department of Automatic Control, Lund University](http://www.control.lth.se/) is used.
 
The app is very intuitive and provide all the needed data and uses a nice, and easy, method of sending the data: a human
formatted string through UDP packets. The format of the string is:

```
TIMESTAMP <COORDS>
```

Where `<COORDS>` are sequence of float numbers, separated by a `<space>`.

For our application we are going to use data from two sensors: accelerometer and gyroscope. However, we are going to get
the magnetometer data for testing purposes (the use of the magnetometer area ).

Then, we have the following string pattern:

```
TIMESTAMP accelerometerX accelerometerY accelerometerZ gyroX gyroY gyroZ magnetometerX magnetometerY magnetometerZ
```

A dump of the retrieved information:

```
39913661192788 3.492003011703491 -11.232936334609985 2.1742963981628414 0.23595607709139585 0.05251753693446517 -0.03792341435328126 -0.5400000214576721 -0.36000001430511475 -14.460000038146973
```
