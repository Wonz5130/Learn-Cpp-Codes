#include<iostream>
using namespace std;

/*
class Test{
	//friend void Show();  //只在类中写出friend
	friend void Show(Test &);  //可以访问类中的私有数据
	//一般把友元函数声明写在前面,友元函数可以访问类的所有数据
public:
	Test(int d = 0):data(d){
	}
public:
	//void Fun(Test * const this)  //改写成这样
	void Fun(){  //该函数作用域属于这个类里面
		cout<<"data = "<<data<<endl;  //能访问类声明的私有部分
	}
private:
	int data;
};

void Show(Test &t){  //这里不需要加friend,也不需要加Test::  因为不属于Test  而是Test的朋友,地位一样
	cout<<"This is Friend Show()"<<endl;
	cout<<"t.data = "<<t.data<<endl;
}

void main(){
	Test t(100);
	t.Fun();  //必须要有对象t去激活
	//Show();  //不需要对象去激活
	Show(t);
}
*/

class Complex;  //对复数类进行声明
ostream& operator<<(ostream& out,const Complex &c);
istream& operator>>(istream& in,Complex &c);
Complex operator+(int i, const Complex &c);  //声明成友元方法

//#include<iostream.h>
//using namespace std;

/*
class Complex;  //对复数类进行声明
ostream& operator<<(ostream& out,const Complex &c);
Complex operator+(int i, const Complex &c);  //声明成友元方法
*/

//复数
class Complex{
	friend ostream& operator<<(ostream& out,const Complex &c);  //友元函数
	friend istream& operator>>(istream& in,Complex &c);
	friend Complex operator+(int i, const Complex &c);  //声明成友元方法
public:
	Complex():m_real(0),m_imag(0){
	}
	//10,0构造出对象
	Complex(int real,int imag = 0){
		m_real = real;
		m_imag = imag;
	}
	~Complex(){
	}
public:
	void PrintComplex()const{
		cout<<"("<<m_real<<","<<m_imag<<")"<<endl;
	}
public:
	Complex operator+(int i){  //把operator+看成一个整体,是一个函数名
		return Complex(m_real+i,m_imag);
	}
	Complex operator+(const Complex &c){  //把operator+看成一个整体,是一个函数名
		return Complex(m_real+c.m_real,m_imag+c.m_imag);
	}
	/*
public:
	ostream& operator<<(ostream& out){  //可以重载成成员函数,必须用对象进行驱动,一般重载成友元函数
		cout<<"("<<m_real<<","<<m_imag<<")";
		return out;
	}
	*/
private:
	int m_real;
	int m_imag;
};

ostream& operator<<(ostream& out,const Complex &c){
	cout<<"("<<c.m_real<<","<<c.m_imag<<")";
	return out;
}

istream& operator>>(istream& in,Complex &c){
	in>>c.m_real>>c.m_imag;
	return in;
}

Complex operator+(int i, const Complex &c){  //函数重载为友元
	return Complex(c.m_real+i,c.m_imag);
}

void main(){
	/*
	Complex c;
	Complex c1(1,2);
	Complex c2(3,4);

	c = c1 + c2;
	//c = c1 + 10;  //11,2  形如c = c1.operator+(10);

	c = 10 + c1;

	cout<<c<<endl;
	//c<<cout<<endl;  //相当于c是对象,调用c.operator<<(cout)
	*/

	/*
	int a;
	cin>>a;
	*/
	Complex c;
	cin>>c;
	cout<<c<<endl;
}