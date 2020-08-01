#pragma once

#include <iostream>

using namespace std;
 
namespace ObjectVirtualDerived { 
	class Point2d {
		public:
			// has virtual functions
			virtual void print() {};
		private:
			float _x;
			float _y;
	}; 
	class Point3d : public virtual Point2d {        // virtual inheritance
		public:
			virtual void Point3dPrint() {};
		private:
			float _z;
	}; 
	class Vertex : public virtual Point2d {         // virtual inheritance
		public:
			// has virtual functions
			virtual void VertexPrint() {};
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
		cout << "Point2d�ࡢPoint3d�ࡢVertex��Vertex3d��Ĵ�С:" << sizeof(Point2d) << " " << sizeof(Point3d) << " " << sizeof(Vertex) << " " << sizeof(Vertex3d) << endl;
	}
}
 




