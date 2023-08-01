// PartA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Person
{
	char age[3];
	char first[25];
	char last[25];
};

class BinaryData {
private:
	char age[3];
	char first[25];
	char last[25];
public:
	BinaryData(){}
	~BinaryData(){}
	void SetData(int age, string strFirst, string strLast)
	{
		sprintf_s(this->age, "%d", age);
		sprintf_s(this->first, "%d", strFirst.c_str());
		sprintf_s(this->last, "%d", strLast.c_str());
	}

	void Save(ofstream &of)
	{
		of.write((char*)&age, sizeof(age));
		of.write((char*)&first, sizeof(first));
		of.write((char*)&last, sizeof(last));
	}
	void WriteBinaryFile(string strFile)
	{
		ofstream fs;
		fs.open(strFile, ios::out | ios::binary | ios::app);
		if (!fs.is_open())
		{
			cout << "cannot open file" << strFile << endl;
		}
		else
		{
			this->Save(fs);
		}
		fs.close();
	}
	void ReadBinaryFile(string strFile)
	{
		Person p;
		ifstream binaryFile;
		int size = 0;
		binaryFile.open(strFile, ios::in | ios::binary);
		binaryFile.seekg(0, ios::end);
		size = (int)binaryFile.tellg();
		binaryFile.seekg(0, ios::beg);
		while (binaryFile.tellg() < size)
		{
			binaryFile.read((char*)p.age, sizeof(p.age));
			binaryFile.read((char*)p.first, sizeof(p.first));
			binaryFile.read((char*)p.last, sizeof(p.last));
			cout << p.age << "\t" << p.first << "\t" << p.last << endl;
		}
		binaryFile.close();
	}
};

int main(void)
{
	string strFirst, strLast;
	int age;
	unique_ptr<BinaryData> bd(new BinaryData());
	cout << "enter age:";
	cin >> age;
	cout << "enter first name:";
	cin >> strFirst;
	cout << "enter last name";
	cin >> strLast;
	bd->SetData(age, strFirst, strLast);
	bd->ReadBinaryFile("./test1.bin");
}
