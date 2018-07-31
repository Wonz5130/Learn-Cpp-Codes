#include<iostream>
using namespace std;

//钻石继承
//虚拟继承
//虚基类

class B0{
public:
	B0():m(0){
	}
public:
	int m;
};

class B1 : virtual public B0{
public:
	B1():n(0){
	}
public:
	int n;
};
	
class B2 : virtual public B0{
public:
	B2():n(0){
	}
public:
	int n;
};

class Base1{
public:
	Base1(int x = 0):m_x(x){  //参数列表的初始化进行初始化
		cout<<"Create Base1!"<<endl;
	}
	~Base1(){
		cout<<"Free Base1!"<<endl;
	}
private:
	int m_x;
};
	
class Base2{
public:
	Base2(int y = 0):m_y(y){
		cout<<"Create Base2!"<<endl;
	}
	~Base2(){
		cout<<"Free Base2!"<<endl;
	}
private:
	int m_y;
};

class Base3{
public:
	Base3(int z = 0):m_z(z){
		cout<<"Create Base3!"<<endl;
	}
	~Base3(){
		cout<<"Free Base3!"<<endl;
	}
private:
	int m_z;
};

class D : public Base2,virtual public Base1,public Base3{  //父类的构造顺序按照这里的顺序
public:
	D(int data)//:Base1(data),Base2(data),Base3(data),b1(data),b2(data),b3(data)
	{
		cout<<"Create D!"<<endl;
	}
	~D(){
		cout<<"Free D!"<<endl;
	}
private:  //按照顺序构造
	Base3 b3;
	Base1 b1;
	Base2 b2;
};

void main(){
	D d(10);
}

/*
class B0{
public:
	B0():m(0){
	}
public:
	int m;
};

class B1 : virtual public B0{
public:
	B1():n(0){
	}
public:
	int n;
};
	
class B2 : virtual public B0{
public:
	B2():n(0){
	}
public:
	int n;
};

class D : public B1,public B2{
public:
	D():x(0){
	}
private:
	int x;
};

void main(){
	D d;
	//d.n = 10;  //这里有二义性
	d.B1::n = 10;
	d.B2::n = 20;

	//d.m = 100;  //这里有二义性
	/*
	//但是实际上m是只有一个,所以这个方法不符合实际
	d.B1::m = 100;
	d.B2::m = 200;
	
	d.m = 100;		
}

/*
class B1{
public:
	B1():n(0){
	}
public:
	int n;
};
	
class B2{
public:
	B2():n(0){
	}
public:
	int n;
};

class D : public B1,public B2{
public:
	D():x(0){
	}
private:
	int x;
};

void main(){
	D d;
	//d.n = 10;  //这里有二义性
	d.B1::n = 10;
}
*/