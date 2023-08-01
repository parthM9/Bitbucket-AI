#include "stdafx.h"
#include "CppUnitTest.h"

#include "CommandProcessor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{		
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(CheckValidCommand)
		{
			CommandProcessor c;
			
			Assert::IsTrue(c.executeCommand("take"));
		}

		TEST_METHOD(CheckInValidCommand)
		{
			CommandProcessor c;

			Assert::IsFalse(c.executeCommand("jump"));
		}

		TEST_METHOD(CheckAlias)
		{
			CommandProcessor c;

			Assert::IsTrue(c.executeCommand("put"));
			Assert::IsTrue(c.executeCommand("place"));
		}



		

	};
}