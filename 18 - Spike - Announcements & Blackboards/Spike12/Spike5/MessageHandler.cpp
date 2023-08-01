#include "MessageHandler.h"
#include "Messageable_Entity.h"
#include <string>

MessageHandler gMessageHandler;

MessageHandler::MessageHandler()
{
	fMessageableEntities = list<Messageable_Entity*>();
}


MessageHandler::~MessageHandler()
{
}

void MessageHandler::SendMessage(Message aMessage)
{
	//Announcement
	if (aMessage.GetSender().compare(aMessage.GetReceiver())==0)
	{
		for each (Messageable_Entity* m in fMessageableEntities)
			if (aMessage.GetReceiver().compare(aMessage.GetReceiver()) == 0)
			{
				Message lMessage = Message(aMessage.GetSender(), m->getName(), aMessage.GetMessage());

				//Create new message with correct recipient
				m->ReceiveMessage(lMessage);

				if (!m->isReceivingMessages())
					fBlackboard.push_back(lMessage);
			}
	}

	//One-to-One Message
	else
	{
		for each (Messageable_Entity* m in fMessageableEntities)
			if (aMessage.GetReceiver().compare(m->getName()) == 0)
			{
				m->ReceiveMessage(aMessage);

				if (!m->isReceivingMessages())
					fBlackboard.push_back(aMessage);
			}
	}
}

void MessageHandler::RegisterMessageableEntity(Messageable_Entity * aMessageableEntity)
{
	fMessageableEntities.push_back(aMessageableEntity);
}

Message MessageHandler::GetMessagesFromBlackBoard(Messageable_Entity * aMessageableEntity)
{
	for each (Message m in fBlackboard)
	{
		if (m.GetReceiver().compare(aMessageableEntity->getName()) == 0)
		{
			return m;
		}
	}
}
