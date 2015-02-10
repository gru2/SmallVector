#ifndef __SMALL_STRING_H
#define __SMALL_STRING_H

template<unsigned N>
class SmallString
{
public:
	SmallString<N>()
	{
		size_ = 0;
		capacity = N - 1;
		data = &localStorage[0];
	}
	SmallString<N>(unsigned n)
	{
		size_ = 0;
		capacity = N - 1;
		data = &localStorage[0];
		if (n <= capacity)
		{
			size_ = n;
			return;
		}
		grow(n);
		size_ = n;
		data[size_] = 0;
	}
	SmallString<N>(const SmallString<N> &x)
	{
		capacity = N - 1;
		data = &localStorage[0];
		if (x.size_ > capacity)
		{
			size_ = 0;
			grow(x.size_);
		}
		size_ = x.size_;
		for (unsigned i = 0; i < x.size_ + 1; i++)
			data[i] = x.data[i];
	}
	SmallString<N>(const char *x)
	{
		unsigned len= 0;
		for (;;)
		{
			if (x[len] == 0)
				break;
			len++;
		}
		capacity = N - 1;
		data = &localStorage[0];
		if (len > capacity)
		{
			size_ = 0;
			grow(len);
		}
		size_ = len;
		for (unsigned i = 0; i < size_ + 1; i++)
			data[i] = x[i];
	}
	~SmallString<N>()
	{
		if (capacity >= N)
			delete [] data;
	}

	const SmallString<N> &operator=(const SmallString<N> &x)
	{
		if (capacity < x.size_)
			grow(x.size_);
		size_ = x.size_;
		for (unsigned i = 0; i < x.size_; i++)
			data[i] = x.data[i];
		return this;
	}
	const SmallString<N> &operator=(const char *x)
	{
		unsigned len= 0;
		for (;;)
		{
			if (x[len] == 0)
				break;
			len++;
		}
		if (capacity < len)
			grow(len);
		for (unsigned i = 0; i < size_ + 1; i++)
			data[i] = x[i];
		return this;
	}

	unsigned size() const { return size_; }
	char *begin() const
	{
		return data;
	}
	char *end() const
	{
		return data + size_;
	}
	void resize(unsigned n)
	{
		if (capacity < n)
			grow(n);
		size_ = n;
		data[n] = 0;
	}
	void clear()
	{
		resize(0);
	}
	void push_back(char x)
	{
		resize(size_ + 1);
		data[size_ - 1] = x;
		data[size_] = 0;
	}
	char &operator [](unsigned i)
	{
		return data[i];
	}
	void operator +=(const SmallString<N> &x)
	{
		unsigned n = size_;
		resize(n + x.size_);
		for (unsigned i = 0; i < x.size_ + 1; i++)
			data[n + i] = x.data[i];
	}
	void operator +=(const char *x)
	{
		unsigned len= 0;
		for (;;)
		{
			if (x[len] == 0)
				break;
			len++;
		}
		unsigned n = size_;
		resize(n + len);
		for (unsigned i = 0; i < len + 1; i++)
			data[n + i] = x[i];
	}
	char *str() { return data; }
	bool operator ==(const SmallString<N> &x) const
	{
		if (size_ != x.size_)
			return false;
		for (unsigned i = 0; i < size_; i++)
			if (data[i] != x.data[i])
				return false;
		return true;
	}
	bool operator ==(const char *x) const
	{
		unsigned len= 0;
		for (;;)
		{
			if (x[len] == 0)
				break;
			len++;
		}
		if (size_ != len)
			return false;
		for (unsigned i = 0; i < size_; i++)
			if (data[i] != x[i])
				return false;
		return true;
	}
	bool operator <(const SmallString<N> &x) const
	{
		unsigned n = size_;
		if (x.size_ < n)
			n = x.size_;
		for (unsigned i = 0; i < n; i++)
			if (data[i] != x.data[i])
				return data[i] < x.data[i];
		if (n < x.size_)
			return true;
		return false;
	}
	bool operator <(const char *x) const
	{
		unsigned len= 0;
		for (;;)
		{
			if (x[len] == 0)
				break;
			len++;
		}
		unsigned n = size_;
		if (len < n)
			n = len;
		for (unsigned i = 0; i < n; i++)
			if (data[i] != x[i])
				return data[i] < x[i];
		if (n < len)
			return true;
		return false;
	}

protected:
	void grow(int n);
	unsigned size_;
	unsigned capacity;
	char *data;
	char localStorage[N];
};

template<unsigned N>
void SmallString<N>::grow(int n)
{
	if (n < capacity)
		return;

	unsigned newCapacity = n;
	if ((capacity << 1) > newCapacity)
		newCapacity = capacity << 1;

	char *newData = new char[newCapacity + 1];

	for (unsigned i=0; i < size_ + 1; i++)
		newData[i] = data[i];

	if (capacity >= N)
		delete [] data;

	capacity = newCapacity;
	data = newData;
}

#endif
