#pragma once
#include <string>

using namespace std;

class Message
{
public:
	Message();
	Message(string aSender, string aReceiver, string aMessage);
	~Message();

	string GetSender();
	string GetMessage();
	string GetReceiver();

private:
	string fSender;
	string fReceiver;
	string fMessage;
};

