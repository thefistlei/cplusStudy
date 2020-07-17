// ObjTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include "TestObj.h"
#include <typeinfo>

typedef void(*Fun)(void);

void test_multi_inherit_rewrite()
{ 
	multiDeirve::Drive_multyBase d(3000);

	//[0]
	cout << "[0]Base::vptr";
	cout << "\t地址：" << (int *)(&d) << endl;

	//vprt[0]析构函数无法通过地址调用，故手动输出
	cout << "  [0]" << "Derive::~Derive" << endl;

	//vprt[1]
	cout << "  [1]";
	Fun fun1 = (Fun)*((int *)*((int *)(&d)) + 1);
	fun1();
	cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 1) << endl;


	//vprt[2]
	cout << "  [2]";
	Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
	fun2();
	cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 2) << endl;


	//[1]
	cout << "[1]Base::baseI=" << *(int*)((int *)(&d) + 1);
	cout << "\t地址：" << (int *)(&d) + 1;
	cout << endl;

	//[2]
	cout << "[2]Base_::vptr";
	cout << "\t地址：" << (int *)(&d) + 2 << endl;

	//vprt[0]析构函数无法通过地址调用，故手动输出
	cout << "  [0]" << "Drive_multyBase::~Derive" << endl;

	//vprt[1]
	cout << "  [1]";
	Fun fun4 = (Fun)*((int *)*((int *)(&d)) + 1);
	fun4();
	cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 1) << endl;

	//[3]
	cout << "[3]Base_2::base2I=" << *(int*)((int *)(&d) + 3);
	cout << "\t地址：" << (int *)(&d) + 3;
	cout << endl;

	//[4]
	cout << "[4]Drive_multyBase::Drive_multyBaseI=" << *(int*)((int *)(&d) + 4);
	cout << "\t地址：" << (int *)(&d) + 4;
	cout << endl;
}

void test_single_inherit_rewrite() 
{ 

	Derived_Overrite d(111111);

	cout << "对象d的起始内存地址：\t\t" << &d << endl;

	cout << "虚函数表地址：\t\t\t" << (int*)(&d) << endl;

	cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&d) << "\t即析构函数地址" << endl;

	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&d) + 1) << "\t";

	typedef void(*Fun)(void);

	Fun pFun = (Fun)*(((int*)*(int*)(&d)) + 1);

	pFun();

	d.print();

	cout << endl;

	cout << "虚函数表 — 第3个函数地址：\t" << ((int*)*(int*)(&d) + 2) << "【结束】\t";

	cout << endl;

	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&d) + 1) << "\t通过地址取得的值：" << *((int*)(&d) + 1) << endl;

	cout << "推测数据成员iDerived地址：\t" << ((int*)(&d) + 2) << "\t通过地址取得的值：" << *((int*)(&d) + 2) << endl;

}

int main()
{
	test_single_inherit_rewrite();

    std::cout << "Hello World!\n"; 

	Base b1(0);
	 
	int * vptrAdree = (int *)(&b1);
	cout << "虚函数指针（vprt）的地址是：\t" << vptrAdree << endl;

	cout << "对象b1的起始内存地址：" << &b1 << endl;

	cout << "对象b1的内存大小：" << sizeof(b1) << endl;

	cout << "type_info信息：" << ((int*)*(int*)(&b1) - 1) << endl;

	RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&b1) - 1));

	//abstract class name from RTTI

	string classname(str.pTypeDescriptor->name);

	classname = classname.substr(4, classname.find("@@") - 4);

		cout << classname.c_str() << endl;

	cout << "虚函数表地址：\t\t\t" << (int*)(&b1) << endl;

	cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&b1) << "\t即析构函数地址：" << (int*)*((int*)*(int*)(&b1)) << endl;

	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&b1) + 1) << "\t" << (int*)*((int*)*(int*)(&b1)+1) << "\t";

	typedef void(*Fun)(void);

	typedef int(*FunGet)(void);

	//FunGet pFunDelete = (FunGet)*(((int*)*(int*)(&b1))+2);
	//pFunDelete();

	Fun pFun = (Fun)*(((int*)*(int*)(&b1)) + 1);

	pFun();

	b1.print();

	

	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&b1) + 1) << "\t通过地址取值iBase的值：" << *((int*)(&b1) + 1) << endl;

	 cout << "Base::getIBase(): " << b1.getIBase() << endl;



	b1.instanceCount();

	cout << "静态函数instanceCount地址： " << b1.instanceCount << endl;
	
	cout << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
