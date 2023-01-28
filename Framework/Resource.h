
#ifndef RESOURCE_H
#define RESOURCE_H

#include "Serializable.h"
#include "ObjectPool.h"

class Resource
{
public:
	//Constructor/Destructor
	Resource();
	virtual ~Resource();

	//Methods
	virtual void Serialize(std::ostream& _stream);
	virtual void Deserialize(std::istream& _stream);
	void AssignNonDefaultValues();
	void ToString();

	//Memebers
	static ObjectPool<Resource>* Pool;

protected:
	void SerializePointer(std::ostream& _stream, Resource* _pointer);
	void DeserializePointer(std::istream& _stream, Resource*& _pointer);

private:
	int m_val1;
	double m_val2;
	char m_val3;
	Resource* m_subResource;
};
#endif // !RESOURCE_H


