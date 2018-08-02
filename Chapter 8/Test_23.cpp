#include<iostream>
using namespace std;

class Base{
public:
	virtual void f(){
		cout<<"This is Base f"<<endl;
	}
	virtual void g(){
		cout<<"This is Base g"<<endl;
	}
	virtual void h(){
		cout<<"This is Base h"<<endl;
	}
};

class Base1{
public:
	virtual void f(){
		cout<<"This is Base1 f"<<endl;
	}
	virtual void g(){
		cout<<"This is Base1 g"<<endl;
	}
	virtual void h(){
		cout<<"This is Base1 h"<<endl;
	}
};

class Base2{
public:
	virtual void f(){
		cout<<"This is Base2 f"<<endl;
	}
	virtual void g(){
		cout<<"This is Base2 g"<<endl;
	}
	virtual void h(){
		cout<<"This is Base2 h"<<endl;
	}
};

class D : public Base, public Base1, public Base2{
public:
	virtual void f(){
		cout<<"This is D f"<<endl;
	}
	virtual void g1(){
		cout<<"This is D g1"<<endl;
	}
	virtual void h1(){
		cout<<"This is D h1"<<endl;
	}
};

void main(){
	D d;
	Base *pb = &d;
	pb->f();

	Base1 *pb1 = &d;
	pb1->f();

	Base2 *pb2 = &d;
	pb2->f();
}

/*
class Base{
public:
	Base():x(0){

	}
	~Base(){  //这个改成虚函数,字节大小不会变,因为只有一个vfptr,只会增加4个字节

	}
public:
	virtual void show(){
		cout<<"This is Base show()"<<endl;
	}
	void show(int a){  //这两个函数构成了重载
		cout<<"This is Base show()"<<endl;
	}
	virtual void print(){
		cout<<"This is Base print()"<<endl;
	}
	void fun(){
		cout<<"This is Base fun()"<<endl;
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
	void show(){  //子类函数名和父类相同,就构成了隐藏,但是父类里面不能加virtual
		cout<<"This is D show()"<<endl;
	}
	void fun(){
		cout<<"This is D fun()"<<endl;
	}
	virtual void list(){
		cout<<"This is D list()"<<endl;
	}
private:
	int y;
};

void main(){
	D d;
	Base *pb = &d;
	pb->show();  //调用的是子类D
	pb->print();  //调用的是父类Base
	pb->fun();  //调用的是父类Base

	//pb->list();  //不能访问,通过父类的指针只能访问父类范围的所有函数
}

/*
void main(){
	cout<<sizeof(Base)<<endl;  //4个字节,如果show设为虚函数,那么就会是8个字节,因为还有一个vfptr指针
	Base b;
}
*/