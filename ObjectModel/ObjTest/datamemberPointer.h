#pragma once

#include <iostream>

using namespace std;

namespace dataMemberPointer{  
	class Point3d {
	public:
		virtual ~Point3d() {}
		void print1() {
			cout << "&Point3d::x = " << &Point3d::x << endl;
			cout << "&Point3d::y = " << &Point3d::y << endl;
			cout << "&Point3d::z = " << &Point3d::z << endl;
		}
		void print2() {
			printf("&Point3d::x = %d\n", &Point3d::x);
			printf("&Point3d::y = %d\n", &Point3d::y);
			printf("&Point3d::z = %d\n", &Point3d::z);
		}
	private:
		static Point3d origin;
		float x;
		float y;
		float z;
	}; 

	void test()
	{
		Point3d p;
		p.print1();
		p.print2();
	}
}

 




