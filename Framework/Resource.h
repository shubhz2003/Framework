
#ifndef RESOURCE_H
#define RESOURCE_H

#include "Serializable.h"
#include "AssetController.h"

class Resource : public Serializable
{
public:
	//Constructor/Destructor
	Resource();
	virtual ~Resource();

	//Methods
	virtual void Serialize(std::ostream& _stream);
	virtual void Deserialize(std::istream& _stream);
	virtual void AssignNonDefaultValues();
	virtual void ToString();

	//Memebers
	static ObjectPool<Resource>* Pool;

protected:
	//Members
	template<class T>
	void SerializePointer(std::ostream& _stream, T* _pointer)
	{
		byte exits = 1;
		if (_pointer != nullptr)
		{
			_stream.write(reinterpret_cast<char*>(&exits), sizeof(byte));
			_pointer->Serialize(_stream);
		}
		else
		{
			byte exists = 0;
			_stream.write(reinterpret_cast<char*>(&exists), sizeof(exists));
		}
	}
	
	template<class T>
	void DeserializePointer(std::istream& _stream, T*& _pointer)
	{
		byte exists = 0;
		_stream.read(reinterpret_cast<char*>(&exists), sizeof(exists));
		if (exists == 1)
		{
			_pointer = T::Pool->GetResource();
			_pointer->Deserialize(_stream);
		}
	}

	void SerializeAsset(std::ostream& _stream, Asset* _asset);
	void DeserializeAsset(std::istream& _stream, Asset*& _asset);

private:

};
#endif // !RESOURCE_H


