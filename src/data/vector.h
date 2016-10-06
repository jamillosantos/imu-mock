/**
 * @author J. Santos <jamillo@gmail.com>
 * @date October 06, 2016
 */

#ifndef VISUALIZER_VECTOR_H
#define VISUALIZER_VECTOR_H

namespace data
{
template<typename T>
class Vector3
{
private:
	T _x;
	T _y;
	T _z;
public:
	Vector3(T x, T y, T z)
		: _x(x), _y(y), _z(z)
	{ }

	Vector3(Vector3<T> &vector)
		: Vector3<T>(vector._x, vector._y, vector._z)
	{ }

	Vector3(Vector3<T> &&vector)
		: Vector3<T>(vector._x, vector._y, vector._z)
	{ }

	Vector3(T x, T y)
		: Vector3<T>(x, y, 0)
	{ }

	Vector3()
		: Vector3<T>(0, 0, 0)
	{ }

	virtual T x()
	{
		return this->_x;
	}

	virtual T y()
	{
		return this->_y;
	}

	virtual T z()
	{
		return this->_z;
	}

	virtual void xyz(T x, T y, T z)
	{
		this->_x = x;
		this->_y = y;
		this->_z = z;
	}

	virtual void xyz(T value)
	{
		this->_x = this->_y = this->_z = value;
	}

	virtual void x(T x)
	{
		this->_x = x;
	}

	virtual void y(T y)
	{
		this->_y = y;
	}

	virtual void z(T z)
	{
		this->_z = z;
	}

	Vector3<T> &operator=(const Vector3<T> &source)
	{
		this->xyz(source._x, source._y, source._z);
		return *this;
	}

	Vector3<T> &operator=(const Vector3<T> *source)
	{
		this->xyz(source->_x, source->_y, source->_z);
		return *this;
	}
};

typedef Vector3<double> Vector3d;
}

#endif //VISUALIZER_VECTOR_H
