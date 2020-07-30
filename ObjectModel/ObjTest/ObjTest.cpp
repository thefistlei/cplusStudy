// ObjTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include "TestObj.h"
#include "point.h"
#include "zooanimal.h"
#include "bear.h"




#include <typeinfo>

typedef void(*Fun)(void);

void test_multi_inherit_rewrite()
{ 
	multiDeirve::Drive_multyBase d(3000);

	///////////////[0]
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


	/////////////[1]
	cout << "[1]Base::baseI=" << *(int*)((int *)(&d) + 1);
	cout << "\t地址：" << (int *)(&d) + 1;
	cout << endl;

	/////////////[2]
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

void test_single_inherit_noChange()
{
	Derived d(1);

	cout << "对象d的起始内存地址：\t\t" << &d << endl;

	cout << "虚函数表地址：\t\t\t" << (int*)(&d) << endl;

	cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&d) << "\t即析构函数地址" << endl;

	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&d) + 1) << "\t";

	typedef void(*Fun)(void);

	Fun pFun = (Fun)*(((int*)*(int*)(&d)) + 1);
	pFun();

	d.print();


	Fun pFun_2 = (Fun)*(((int*)*(int*)(&d)) + 2);
	pFun_2();

	cout << endl;

	cout << "虚函数表 — 第3个函数地址：\t" << ((int*)*(int*)(&d) + 2) << "【结束】\t";

	cout << endl;

	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&d) + 1) << "\t通过地址取得的值：" << *((int*)(&d) + 1) << endl;

	cout << "推测数据成员iDerived地址：\t" << ((int*)(&d) + 2) << "\t通过地址取得的值：" << *((int*)(&d) + 2) << endl;

	cout << endl;
}

void test_single_inherit_rewrite() 
{  
	Derived_Overrite d(1);

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

	cout << endl;
}


int Point::_point_count = 3;

void test_Point()
{
	Point objPt(16);

	int * vptrAdree = (int *)(&objPt);
	cout << "虚函数指针（vprt）的地址是：\t" << vptrAdree << endl;

	cout << "对象b1的起始内存地址：" << &objPt << endl;

	cout << "对象b1的内存大小：" << sizeof(objPt) << endl;

	cout << "type_info信息：" << ((int*)*(int*)(&objPt) - 1) << endl;

	RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&objPt) - 1)); 
	string classname(str.pTypeDescriptor->name);
	classname = classname.substr(4, classname.find("@@") - 4);
	cout << classname.c_str() << endl;

	cout << "虚函数表地址：\t\t\t" << (int*)(&objPt) << endl;

	cout << "虚函数表 — 第1个函数地址：\t" << (int*)*(int*)(&objPt) << "\t即析构函数地址：" << (int*)*((int*)*(int*)(&objPt)) << endl;
	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&objPt) + 1) << "\t" << (int*)*((int*)*(int*)(&objPt) + 1) << "\t";
	   
	cout << "推测数据成员iBase地址：\t\t" << ((int*)(&objPt) + 1) << "\t通过地址取值iBase的值：" << *((int*)(&objPt) + 1) << endl; 
	cout << "Base::PointCount(): " << objPt.PointCount() << endl; 
	objPt.PointCount();  

	cout << endl;
}


#include "datamemberBinding.h"
#include "defaultConstructor.h"

int main()
{
	int nInput = 0;
	cout << "Please Input number to select operate:\n" << endl;
	cout << "1:test Point Object" << endl;
	cout << "2:test ZooAnimal Object" << endl;
	cout << "3:test single inherit rewrite" << endl;
	cout << "31:test single inherit noChanged" << endl;
	cout << "40:test multi inherit" << endl;
	cout << "200:test data Member Binding" << endl;
	cout << "201:test default Constructor" << endl;
	cout << "202:test default Constructor of object order" << endl;
	while (cin >> nInput)
	{
		if (nInput == 1)
			test_Point();
		else if (nInput == 2)
		{
			test_ZooAnimal();
			test_Bear();
		}
		else if (nInput == 3)
			test_single_inherit_rewrite();
		else if (nInput == 31)
			test_single_inherit_noChange();
		else if (nInput == 40)
			test_multi_inherit_rewrite();

		else if (nInput == 200)
			dataMemberBinding::test_dataMemberBinding();

		else if (nInput == 201)
			defaultConstructor::test_defaultConstructor();

		else if (nInput == 202) {
			defaultConstructor_orderTest::test_defaultConstructor();
			defaultConstructor_orderTest::test_defaultConstructor_ObjectOrder();
			defaultConstructor_DeriveTest::test();
		}


		cout << "\nPlease Input number to select operate:\n" << endl;
	} 
}

void test_BaseObject()
{
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
	cout << "虚函数表 — 第2个函数地址：\t" << ((int*)*(int*)(&b1) + 1) << "\t" << (int*)*((int*)*(int*)(&b1) + 1) << "\t";

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
