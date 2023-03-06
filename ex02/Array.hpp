#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;
public:
	Array(void): _array(nullptr), _size(0) {}
	Array(unsigned int n): _array(new T[n]), _size(n) {}
	~Array(){ delete[] this->_array; }
	unsigned int size(void) const {return this->_size;}
	Array operator=(const Array & other)
	{
		if (this == &other)
    		return *this;
    	delete[] this->_array;
    	this->_size = other._size;
    	this->_array = new T[other._size];
    	unsigned int i = 0;
		while(i < this->_size)
		{
			_array[i] = other._array[i];
			i++;
		}
    	return *this;
	}
	Array(const Array &copy): _array(new T[copy._size]), _size(copy._size)
	{
		unsigned int i = 0;
		while(i < this->_size)
		{
			this->_array[i] = copy._array[i];
			i++;
		}
	}
	T & operator[](unsigned int i)
	{
		if (i >= this->_size)
			throw InvalidIndexException();
		return this->_array[i];
	}

	class InvalidIndexException: public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Index out of range");
		}
	};
};

#endif