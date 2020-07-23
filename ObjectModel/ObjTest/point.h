#pragma once

#include <iostream>

using namespace std;

class Point
{
public:
	Point(int xval) { _x = xval; }
	virtual ~Point() {
		cout << "�������麯��~Point()"; 
	}
	int x() const {
		cout << "�������麯��Base::print()";
		return _x;
	}
	static int PointCount() {
		cout << "�������麯��Base::print()";
		return _point_count;
	}

	virtual ostream&  print(ostream &os) const {
		cout << "�������麯��Base::print()";
		return os;
	}

private:
	int _x;
	static int _point_count;
};

