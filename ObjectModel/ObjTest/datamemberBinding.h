#pragma once

#include <iostream>

using namespace std;

 
typedef float length;

namespace dataMemberBinding {
	class Point3d {
	public:
		//length被决议为global
		//_val被决议为Point3d::_val 
		length mumble() {
			cout << typeid(_val).name() << endl;
			return _val;
		}
	private:
		typedef int length;
		length _val;
	};

	void test_dataMemberBinding()
	{
		Point3d p;
		p.mumble(); //i(int)
		cout << typeid(p.mumble()).name();  //f(float) 
		cout << endl;
	}
}

namespace dataMemberGet{
	class Point3d {
		public:
			float x; 
			float y;
			static int chunkSize;
			float z;
	};

	int Point3d::chunkSize = 0;

	void test()
	{ 

		Point3d origin;
		Point3d *pt = &origin;
	 
		// 通过寻址进行存取 
		origin.x = 0.0F;        // 等价于 *(&origin + (&Point3d::x - 1)) = 0.0;
		pt->x = 0.0F;           // 等价于 *(pt + (&Point3d::x - 1)) = 0.0;

		origin.chunkSize = 1;   // 编译器会转化为Point3d::chunkSize = 1;
		pt->chunkSize = 2;      // 编译器会转化为Point3d::chunkSize = 2;
	}
}
 




