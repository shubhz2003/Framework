#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton
{
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}

protected:
	Singleton() { }
	virtual ~Singleton() { }
// Virtual destructor--if we have an inheritance chain 
// it includes all the destructors and if its not virtual only base class destructor is called.

public:
	Singleton(Singleton const&) = delete;
	Singleton& operator = (Singleton const&) = delete;
};


#endif // SINGLETON_H


