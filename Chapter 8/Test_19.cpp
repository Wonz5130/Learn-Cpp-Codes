#include<iostream>
using namespace std;

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

/*
//代表公有继承Base1,私有继承Base2,Base3
class D : public Base1,Base2,Base3{

};
*/


class D : public Base2,public Base1,public Base3{  //父类的构造顺序按照这里的顺序
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
class Base1{
public:
	Base1(int x):m_x(x){  //参数列表的初始化进行初始化
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
	Base2(int y):m_y(y){
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
	Base3(int z):m_z(z){
		cout<<"Create Base3!"<<endl;
	}
	~Base3(){
		cout<<"Free Base3!"<<endl;
	}
private:
	int m_z;
};

/*
//代表公有继承Base1,私有继承Base2,Base3
class D : public Base1,Base2,Base3{

};


class D : public Base2,public Base1,public Base3{  //父类的构造顺序按照这里的顺序
public:
	D(int data):Base1(data),Base2(data),Base3(data),b1(data),b2(data),b3(data){
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
class Base{
public:
	Base(){
		cout<<"Create Base!"<<endl;
	}
	~Base(){
		cout<<"Free Base!"<<endl;
	}
private:
	int x;
};

class D : public Base{
public:
	D(){
		cout<<"Create D!"<<endl;
	}
	~D(){
		cout<<"Free D!"<<endl;
	}
private:
	int y;
};

void main(){
	D d;
}
*/