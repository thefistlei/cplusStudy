#pragma once

#include <iostream>

using namespace std;

#include <time.h>

namespace NRVOptimize {
	class testObj
	{
		friend testObj foo(double);
	public:
		testObj()
		{
			memset(array, 0, 10000 * sizeof(double));
		}
	public:
		double array[10000];

		inline testObj(const testObj &t)//优化代码
		{
			memcpy(this, &t, sizeof(testObj));
		}
	};

	testObj foo(double val)
	{
		testObj local;
		local.array[0] = val;
		local.array[99] = val;

		return local;
	} 

	void test()
	{
		time_t  timeVal;
		time(&timeVal);

		struct tm tVal;
		localtime_s(&tVal, &timeVal);
		cout << tVal.tm_hour << ":" << tVal.tm_min << ":" << tVal.tm_sec << endl; //start time

		for (int i = 0; i < 10000000; i++)
		{
			testObj t = foo(double(i));
		} 
  
		time_t timeNow;
		time(&timeNow); 

		struct tm tValNow;
		localtime_s(&tValNow, &timeNow);
		cout << tValNow.tm_hour << ":" << tValNow.tm_min << ":" << tValNow.tm_sec << endl; //end time 
	} 
}



