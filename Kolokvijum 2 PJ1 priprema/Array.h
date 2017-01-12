#pragma once
#include <exception>


template<class T,unsigned size>
class Array
{
	T* arr;
	unsigned n, curr = 0;
	void reallocate();
	friend struct iterator;
	struct iterator
	{
		friend class Array;
		T* point;
		bool operator++(int);
		void operator++();
		T& operator*();
		iterator(Array<T,size>&);
		bool operator!=(iterator&);

	};
	
public:
	iterator& begin();
	iterator& end();

	void operator+=(T x);
	void operator+();
	Array();
	~Array();
};

template<class T, unsigned size>
bool Array<T, size>::iterator::operator!=(typename Array<T, size>::iterator& other)
{
	return point != other.point;
}

template<class T, unsigned size>
void Array<T, size>::iterator::operator++()
{
	++point;
}


template<class T,unsigned size>
bool Array<T, size>::iterator::operator++(int i)
{
	try
	{
		point++;
		return true;
	}
	catch (const std::exception& ex)
	{
		return false;
	} 
	
}
template<class T, unsigned size>
inline  typename Array<T, size>::iterator& Array<T, size>::begin()
{
	iterator x(*this);
	return x;
}

template<class T, unsigned size>
inline  typename Array<T, size>::iterator& Array<T, size>::end()
{
	iterator x(*this);
	x.point = &arr[curr];
	return x;
}


template<class T,unsigned size>
T& Array<T, size>::iterator::operator*()
{
	return *point;
}

template<class T, unsigned size>
Array<T, size>::Array() :n(size)
{
	arr = new T[size];
}

template<class T, unsigned size>
Array<T, size>::~Array()
{
	delete[] arr;
}
template<class T, unsigned size>
void Array<T,size>::operator+=(T x)
{
	try
	{
		if (curr < n)
		{
			arr[curr++] = x;
		}
		else throw(std::out_of_range("Nema mjesta"));
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
		reallocate();
	}
}

template<class T, unsigned size>
inline void Array<T, size>::operator+()
{
	realloc();
}

template<class T, unsigned size>
inline void Array<T, size>::reallocate()
{
	T* temp = new T[n * 2];
	for (unsigned i = 0; i < n; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	n *= 2;
}

template<class T, unsigned size>
inline Array<T, size>::iterator::iterator(Array<T, size>& parent)
try
{
	if (parent.curr)
	{
		point = parent.arr;
	}
	else throw std::out_of_range("shit happens");
}
catch (std::exception& exc)
{
	std::cout << exc.what();
}
