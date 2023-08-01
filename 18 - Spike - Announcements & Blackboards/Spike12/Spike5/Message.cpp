#include "Message.h"



Message::Message()
{
}

Message::Message(string aSender, string aReceiver, string aMessage)
{
	fSender = aSender;
	fReceiver = aReceiver;
	fMessage = aMessage;
}


Message::~Message()
{
}

string Message::GetSender()
{
	return fSender;
}

string Message::GetMessage()
{
	return fMessage;
}

string Message::GetReceiver()
{
	return fReceiver;
}
