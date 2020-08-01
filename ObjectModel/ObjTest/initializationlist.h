#pragma once

#include <iostream>

using namespace std;

 

namespace InitializationList {
	class Shape
	{
		const int m_size; //const 常量
		int & m_ref;      // reference member

		float m_width;
		float m_height;

	public:
		Shape(int s, float w, float h) : m_size(s), m_ref(s) //只能在这初始化
		{
			//m_size =s; //在初始化将出错
			m_width = w;
			m_height = h;
		}

	}; 

	class A
	{
	public:
		A(int x);          // A 的构造函数
	};

	class B : public A
	{ 
		B(int x, int y) : A(x)   // 必须在初始化表里调用基类 A 的构造函数
		{

		};
	}; 
}



namespace InitializationList2{
	class A
	{
	public:
		A(int x);          // A 的构造函数
	};

	class B
	{
		A m_a;
		B(int x, int y) : m_a(x) // 在初始化表里调用基类 A 的构造函数
		{
			//m_a = A(x);  //赋值，并非初始化m_a
		}
	}; 
}


namespace InitializationList3{
	class X {
	public:
		int i;
		int j;
		public: X(int val) : j(val), i(j) {}
	};
}

namespace InitializationList_Order {
	class X
	{
	public:
		X(int x) :val(x) {}          // A 的构造函数
		int val;

		int getVal() {
			return val;
		}
	};

	class FooBar : public X {
		int _fVal;
	public:
		int fval() {
			return _fVal;
		}

		FooBar(int val) : _fVal(val), X(fval()) {   }
	};
	 
}

namespace InitializationList_Order2{ 
	class X {
	public:
		int i;
		int xfoo(int val) {
			return val;
		}
	public:
		X(int val) : i(xfoo(val)) //这里是正确的
		{
		}
	};
}






