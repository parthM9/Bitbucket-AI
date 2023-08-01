#include "Graph.h"

using namespace std;


Graph::Graph()
{
	fData = vector < list<pair<int, string> >>(25);
}


Graph::~Graph()
{
}

void Graph::addConnection(int aBeginNode, pair<int,string> aEndNode)
{
	fData[aBeginNode].push_back(aEndNode);
}

list<pair<int,string>> Graph::getConnections(int aNode)
{
	return fData[aNode];
}

void Graph::printGraph()
{
	int n = 0;
	for each (list<pair<int,string>> l in fData)
	{
		if (!l.empty()) {
			cout << n << ": ";

			for each (pair<int,string> p in l)
			{
				cout << "(" << p.first << ", " << p.second << ") ";
			}

			cout << endl;
		}
		n++;
	}
}
