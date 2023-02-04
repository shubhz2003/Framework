#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include "StandardIncludes.h"

template<class T>
class ObjectPool
{
public:
	//Constructors/Destructors
	ObjectPool() { }
	~ObjectPool()
	{
		for (unsigned int count = 0; count < m_all.size(); count++)
		{
			cout << "Deleting pool object" << endl;
			delete m_all[count];
		}
		m_all.clear();
		m_available.clear();
	}

	//Methods
	T* GetResource()
	{
		if (m_available.empty())
		{
			cout << "Creating new pool object." << endl;
			T* resource = new T();
			m_all.push_back(resource);
			return resource;
		}
		else
		{
			cout << "Reusing existing pool object." << endl;
			T* resource = m_available[0];
			m_available.erase(m_available.begin());
			return resource;
		}
	}

	void ReleaseResource(T* _object)
	{
		//_object->Reset();
		m_available.push_back(_object);
	}

private:
	//Memebers
	vector<T*> m_available;
	vector<T*> m_all;
};
#endif // OBJECTPOOL_H

