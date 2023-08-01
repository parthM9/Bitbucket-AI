#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Graph
{
public:
	Graph();
	~Graph();

	void addConnection(int aBeginNode, pair<int,string> aEndNode);

	list<pair<int,string>> getConnections(int aNode);

	void printGraph();

private:
	vector<list<pair<int,string>>> fData;
};

