#pragma once

#include <iostream>

using namespace std;
 
namespace ObjectMultiDerived {
	class Point2d {
		public:
			// has virtual functions
			virtual void print() {};
		private:
			float _x;
			float _y;
	};

	class Point3d : public Point2d {
		public:
			// ...
		private:
			float _z;
	};

	class Vertex {
		public:
			// has virtual functions
			virtual void print() {};
		private:
			Vertex* next;
	};

	class Vertex3d : public Point3d, public Vertex {
		public:
			// ...
		private:
			float mumble;
	}; 
	void test()
	{ 
		cout << "Point2d类、Point3d类、Vertex、Vertex3d类的大小:" << sizeof(Point2d) << " " << sizeof(Point3d) << " " << sizeof(Vertex) << " " << sizeof(Vertex3d) << endl;
	}
}
 




