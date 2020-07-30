#pragma once

#include <iostream>

using namespace std;


namespace defaultConstructor {
	class Foo {
	public:
		Foo() {
			cout << "Foo Constructor" << endl;
		}

		Foo(int) {

		}
	};

	class Bar {
	public:
		Bar() {
			cout << "Bar default code" << endl;
		}
	private: 
		Foo foo; 
	};

	void test_defaultConstructor()
	{
		cout << "begin" << endl;
		Bar bar;
		cout << "end" << endl;
	}
}

namespace defaultConstructor_orderTest {
	 
	class Dopey {
		public:Dopey() {
			cout << "Dopey Constructor" << endl;
		}
	};

	class Sneezy {
		public:Sneezy() {
			cout << "Sneezy Constructor" << endl;
		}
	};

	class Bashful {
		public:Bashful() {
			cout << "Bashful Constructor" << endl;
		}
	};
	 

	class Snow_White { 
		private:
			Dopey dopey;
			Sneezy sneezy;
			Bashful bashful;
			int mumble; 
	};

	void test_defaultConstructor()
	{
		cout << "begin" << endl;
		Snow_White obj;
		cout << "end" << endl;
	} 

	class SnowWhite : public Dopey{ 
	private: 
		Sneezy sneezy; 
	};

	void test_defaultConstructor_ObjectOrder()
	{
		cout << "begin" << endl;
		SnowWhite obj;
		cout << "end" << endl;
	}
}


namespace defaultConstructor_DeriveTest {
	class X
	{
		public:
			int i;
	};

	class A: virtual public X
	{

	};

	class B: virtual public X
	{

	};

	class C: public A, public B
	{

	};

	void foo(A* pa)
	{
		pa->i = 1024; //无法在编译期间确定x的位置
	}

	void test()
	{
		foo(new A());
		foo(new C());
	}
}




