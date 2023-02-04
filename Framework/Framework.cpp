// Framework.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

//#include "Asset.h" //Output 1
//#include "AssetController.h"

#include "Resource.h"
#include "AssetController.h"

int main()
{ 
	////Output 1
	//AssetController::Instance().Initialize(10000000); //Alllocate 10MB
	//Asset* asset = AssetController::Instance().GetAsset("emoji.jpg");
	//cout << "Bytes used by image.bmp: " << AssetController::Stack->GetBytesUsed() << endl;

	//Output 2
	AssetController::Instance().Initialize(10000000); //Allocate 10MB
	Resource::Pool = new ObjectPool<Resource>();
	Resource* r1 = Resource::Pool->GetResource();
	r1->AssignNonDefaultValues();

	ofstream writeStream("resource.bin", ios::out | ios::binary);
	r1->Serialize(writeStream);
	writeStream.close();
	cout << "r2 values: ";
	r1->ToString();

	delete Resource::Pool;



}


