#ifndef SIMULATION_VECTOR_HPP
#define SIMULATION_VECTOR_HPP

#include "../data/vector.h"

namespace draw
{

class Vector3f
	: public data::Vector3<float>
{
private:
	bool _dirty;
public:
	Vector3f(float x, float y, float z);

	Vector3f(float value);

	Vector3f();

	bool isDirty();

	void clean();

	virtual void xyz(float x, float y, float z) override;

	virtual void xyz(float value) override;

	virtual void x(float value) override;

	virtual void y(float value) override;

	virtual void z(float value) override;

	virtual float x() override;

	virtual float y() override;

	virtual float z() override;
};
}

#endif //SIMULATION_VECTOR_HPP
