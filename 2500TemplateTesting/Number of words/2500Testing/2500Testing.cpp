#include "pch.h"
#include "CppUnitTest.h"
#include "header.h"
#include "Main.cpp"

namespace MVC = Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2500Testing
{
	TEST_CLASS(My2500Testing)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a{ 1 };
		}
	};
}
