#include<iostream>
using namespace std;

class Base{
public:
	Base():x(0){

	}
	~Base(){

	}
public:
	virtual void show(){
		cout<<"This is Base show()"<<endl;
	}
	void show(int){
		cout<<"This is Base show(int)"<<endl;
	}
private:
	int x;
};

class D : public Base{
public:
	D():y(0){

	}
	~D(){

	}
public:
	void print(){
		cout<<"This is D print()"<<endl;
	}
	void show(){  //子类的函数名和父类函数名一样,就会把父类的所有同名函数隐藏掉,即不能使用
		cout<<"This is D show()"<<endl;
	}
public:
	void list(){
		cout<<"This is D list()"<<endl;
	}
private:
	int y;
};

void main(){
	D d;
	
	Base b = d;
	//用对象,只能访问父类
	b.show();
	b.show(0);
	//b.list();  //不能访问

	Base *pb = &d;
	pb->show();  //这个调用的是父类,如果父类里面用virtual,那么这里调用的就是子类

    Base &bf = d;
    bf.show();  //加上virtual之后,这里调用的也是子类
}

/*
void main(){
	Base b;
	D d;

	//1:子类给父类赋值
	b = d;

	//2:只能访问从父类那里继承的
	Base *pb;
	pb = &d;
	pb->show();  //可以访问父类的show
	pb->show(0);  //可以访问父类的show(int)

	//3:派生类对象可以初始化基类的引用
	Base &bf = d;
	bf.show();
	bf.show(0);
	//bf.list();  //不能访问
}
*/

/*
void main(){
	D d;
	d.print();
	d.show();  //调用的是子类的show
	//d.show(0);  //编译不通过
	d.Base::show(0);
}
*/