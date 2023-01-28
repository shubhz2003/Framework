#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "StandardIncludes.h"

class Serializable
{
	//Abstract class since it contains pure virtual methods
public:
	//Constructor/Destructor
	Serializable() {}
	virtual ~Serializable() {}

	//Methods
	virtual void Serialize(std::ostream& _stream) = 0;
	virtual void Deserialize(std::istream& _stream) = 0;

};
#endif // !SERIALIZABLE_H

