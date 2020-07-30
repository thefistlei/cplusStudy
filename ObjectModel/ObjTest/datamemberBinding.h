#pragma once

#include <iostream>

using namespace std;

 
typedef float length;

namespace dataMemberBinding {
	class Point3d {
	public:
		//length被决议为global
		//_val被决议为Point3d::_val
		void mumble(length val) { _val = val; }
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

 




