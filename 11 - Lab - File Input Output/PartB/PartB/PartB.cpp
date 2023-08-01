// PartB.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream myFileStream("./test2.txt");
	if (!myFileStream.is_open()) {
		cout << "File unable to open" << endl;
		return 0;
	}
	string line;
	while (getline(myFileStream, line)) {
		string str = "";
		if (line.size() < 1)
			continue;
		if (line.at(0)=='#')
		{
			continue;
		}
		for (auto x : line)
		{
			
			
			if (x == ':')
			{
				cout << str << endl;
				str = "";
				continue;
			}
			str = str + x;
			if (x == line.at(line.size() - 1))
			{
				cout << str << endl;
			}
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
