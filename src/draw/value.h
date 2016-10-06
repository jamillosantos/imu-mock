#ifndef SIMULATION_VALUE_HPP
#define SIMULATION_VALUE_HPP

namespace draw
{
	template <typename T>
	class Value
	{
	private:
		T _value;
		bool dirty;
	public:
		Value()
			: dirty(false)
		{}

		Value(T &&value)
			: _value(value), dirty(true)
		{}

		T value()
		{
			return this->_value;
		}

		void value(T &value)
		{
			if (this->_value != value)
			{
				this->_value = value;
				this->dirty = true;
			}
		}

		bool isDirty()
		{
			return this->dirty;
		}

		void clean()
		{
			this->dirty = false;
		}

		T &operator*()
		{
			return this->_value;
		}
	};
}

#endif //SIMULATION_VALUE_HPP
