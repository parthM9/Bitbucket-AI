#pragma once

#include "Message.h"
#include <list>

class Messageable_Entity;

class MessageHandler
{

public:
	MessageHandler();
	~MessageHandler();

	void SendMessage(Message aMessage);
	void RegisterMessageableEntity(Messageable_Entity* aMessageableEntity);
	Message GetMessagesFromBlackBoard(Messageable_Entity* aMessageableEntity);

private:
	list<Messageable_Entity*>  fMessageableEntities;
	list<Message> fBlackboard;
};

extern MessageHandler gMessageHandler;