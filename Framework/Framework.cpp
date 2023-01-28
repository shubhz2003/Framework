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

#include "FileController.h"
#include "StackAllocator.h"
#include "ObjectPool.h"
#include "Resource.h"

int main()
{ 
  //Output1 & output2
  //  FileController* fc = &FileController::Instance();
  //  cout << fc->GetCurDirectory() << endl;
  //  int fs = fc->GetFileSize("FileController.cpp");
  //  unsigned char* buffer = new unsigned char[fs];
  ///*  if (fc->ReadFile("FileController.cpp", buffer, fs))
  //  {
  //      cout << "File read operation successful." << endl;
  //  }*/

  //  //output2
  //  fc->ReadFileAsync("FileController.cpp", buffer, fs);
  //  while (!fc->GetFileReadDone())
  //  {
  //      cout << "Thread Running..." << std::endl;
  //  }
  //  if (fc->GetFileReadSuccess())
  //  {
  //      cout << "File read operation unsuccessful." << endl;
  //  }

  //  delete[] buffer;

	////Output3
	//FileController* fc = &FileController::Instance();
	//StackAllocator* sa = new StackAllocator();
	//sa->AllocateStack(100); //Allocate 100 bytes on the heap

	//int fs1 = fc->GetFileSize("File1.txt");
	//unsigned char* file1 = sa->GetMemory(fs1);
	//fc->ReadFile("File1.txt", file1, fs1);
	//cout << file1 << endl;

	//int fs2 = fc->GetFileSize("File2.txt");
	//unsigned char* file2 = sa->GetMemory(fs2);
	//fc->ReadFile("File2.txt", file2, fs2);
	//sa->Mark();
	//cout << file2 << endl;

	//int fs3 = fc->GetFileSize("File3.txt");
	//unsigned char* file3 = sa->GetMemory(fs3);
	//fc->ReadFile("File3.txt", file3, fs3);
	//cout << file3 << endl;

	//cout << "Bytes used: " << sa->GetBytesUsed() << " Content: " << file1 << endl;
	//sa->FreeToMarker();
	//cout << file1 << endl;
	//cout << "Bytes used: " << sa->GetBytesUsed() << " Content: " << file1 << endl;
	//delete sa;

	//Output4
	ObjectPool<Resource>* objP = new ObjectPool<Resource>();
	Resource* r1 = objP->GetResource();
	r1->AssignNonDefaultValues();

	ofstream writeStream("resource.bin", ios::out | ios::binary);
	r1->Serialize(writeStream);
	writeStream.close();
	cout << "r1 values: ";
	r1->ToString();

	Resource* r2= objP->GetResource();
	ifstream readStream("resource.bin", ios::out | ios::binary);
	r2->Deserialize(readStream);
	readStream.close();
	cout << "r2 values: ";
	r2->ToString();

	delete objP;
}


