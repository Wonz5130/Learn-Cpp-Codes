#include<iostream>
using namespace std;

//抽象类:动物类
class A{
public:
	//int *p = NULL;
	virtual void Eat()=0;  //作用:占位置,子类必须一一实现父类
	virtual void Sleep()=0;
};

//具体类:人,具体类要完全实现父类所有的纯虚函数,这样才能定义对象,否则还是抽象类,不能实例化对象
class P : public A{
	virtual void Eat(){
		cout<<"P Eat()"<<endl;
	}
	virtual void Sleep(){
		cout<<"P Sleep()"<<endl;
	}
};

class Dog : public A{
	virtual void Eat(){
		cout<<"Dog Eat()"<<endl;
	}
	virtual void Sleep(){
		cout<<"Dog Sleep()"<<endl;
	}
};

void fun(A *pa){
	pa->Eat();
	pa->Sleep();
}

void main(){
	//A a;  //抽象类不能定义对象
	//A *a;  //这是可以的
	P p;
	Dog dog;
	//相同的接口实现了不同的方法
	fun(&p);
	fun(&dog);
}