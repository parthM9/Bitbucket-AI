#include "Messageable_Entity.h"
#include <iostream>



Messageable_Entity::Messageable_Entity()
{
	gMessageHandler.RegisterMessageableEntity(this);
	fReceivingMessages = true;
	fMessagesOnBlackboard = 0;
}

Messageable_Entity::~Messageable_Entity()
{
}

void Messageable_Entity::CreateMessage(string aReceiver, string aMessage)
{
	fMessage = Message(getName(), aReceiver, aMessage);
}

void Messageable_Entity::SendMessage()
{
	gMessageHandler.SendMessage(fMessage);
}

void Messageable_Entity::ReceiveMessage(Message aMessage)
{
	if (fReceivingMessages) {
		fMessage = aMessage;
		ProcessMessage();
	}
	else
		fMessagesOnBlackboard++;
}

void Messageable_Entity::ToggleReceiveMessages()
{
	fReceivingMessages = !fReceivingMessages;
}

bool Messageable_Entity::isReceivingMessages()
{
	return fReceivingMessages;
}

void Messageable_Entity::CheckBlackboard()
{
	while (fMessagesOnBlackboard > 0)
	{
		fMessage = gMessageHandler.GetMessagesFromBlackBoard(this);
		ProcessMessage();
		fMessagesOnBlackboard--;
	}
}

void Messageable_Entity::ProcessMessage()
{
	cout << "Sender: " << fMessage.GetSender() << endl;
	cout << "Message: " << fMessage.GetMessage() << endl;
	cout << "Receiver: " << fMessage.GetReceiver() << endl;
	cout << "This entity name: " << getName() << endl;
}

string Messageable_Entity::getName()
{
	return "null";
}
