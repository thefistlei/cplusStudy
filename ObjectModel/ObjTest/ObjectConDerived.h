#pragma once

#include <iostream>

using namespace std;
 
namespace ObjectConDerived{
	class Concrete1 {
		public:
			// ...
		protected:
			int val;
			char bit1;
	};

	class Concrete2 : public Concrete1 {
		public:
			// ...
		protected:
			char bit2;
	};

	class Concrete3 : public Concrete2 {
		public:
			// ...
		protected:
			char bit3;
	};


	void test()
	{ 
		cout << "Concrete1�ࡢConcrete2�ࡢConcrete3��Ĵ�С:" << sizeof(Concrete1) << " " << sizeof(Concrete2) << " " << sizeof(Concrete3) << endl;  
	}
}
 




