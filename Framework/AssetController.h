#ifndef ASSET_CONTROLLER_H
#define ASSET_CONTROLLER_H

#include "StandardIncludes.h"
#include "StackAllocator.h"
#include "Asset.h"

class AssetController : public Singleton<AssetController>
{
public:
	//Constructors/Destructors
	AssetController();
	virtual ~AssetController();

	//Accessors
	void Initialize(int _stackSize);
	Asset* GetAsset(string _guid);

	//Methods
	static StackAllocator* Stack;

private:
	//Memebers
	map<string, Asset*> m_assets;

};

#endif // ASSET_CONTROLLER_H

