#include "stdafx.h"
#include "CppUnitTest.h"
#include "Component.h"
#include "ComponentManager.h"
#include "GameEntity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(RegisterEntityWithComponent_Component)
		{
			Component c;
			GameEntity g("test", "test");
			
			Assert::IsTrue(c.getRegisteredEntities().size() == 0);
			c.registerEntity(&g);

			Assert::IsTrue(c.getRegisteredEntities().size() == 1);
		}

		TEST_METHOD(DeregisterEntityWithComponent_Component)
		{
			Component c;
			GameEntity g("test", "test");

			Assert::IsTrue(c.getRegisteredEntities().size() == 0);
			c.registerEntity(&g);

			Assert::IsTrue(c.getRegisteredEntities().size() == 1);

			c.removeEntity(&g);
			Assert::IsTrue(c.getRegisteredEntities().size() == 0);
		}

		TEST_METHOD(RegisterEntityWithComponent_CM)
		{
			ComponentManager cm;
			GameEntity g("test", "test");

			cm.RegisterEntityWithComponent(Takeable,&g);
			Assert::IsTrue(cm.EntityHasComponent(Takeable, &g));
		}

		TEST_METHOD(RegisterEntityWithComponents_CM)
		{
			ComponentManager cm;
			GameEntity g("test", "test");
			list<string> components = { "Takeable" };


			cm.RegisterEntityWithComponents(components,&g);
			Assert::IsTrue(cm.EntityHasComponent(Takeable, &g));

		}

		

	};
}