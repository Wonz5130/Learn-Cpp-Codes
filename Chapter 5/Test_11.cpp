#include<iostream>
using namespace std;

/*
//复数
class Complex{
public:
	Complex():m_real(0),m_imag(0){
	}
	Complex(int real,int imag){
		m_real = real;
		m_imag = imag;
	}
	~Complex(){
	}
public:
	void PrintComplex()const{
		cout<<"("<<m_real<<","<<m_imag<<")"<<endl;
	}
	Complex Add(Complex &c){
		Complex cmp(m_real+c.m_real,m_imag+c.m_imag);
		return cmp;
	}
public:
	Complex operator+(const Complex &c){  //把operator+看成一个整体,是一个函数名
		/*
		Complex cmp(m_real+c.m_real,m_imag+c.m_imag);
		return cmp;
		*
		//化简
		return Complex(m_real+c.m_real,m_imag+c.m_imag);
	}
private:
	int m_real;
	int m_imag;
};

void main(){
	Complex c;
	Complex c1(1,2);
	Complex c2(3,4);

	//cout << c1 <<endl;  //这个有问题
	c1.PrintComplex();

	//c = c1.Add(c2);  //调用的是公有函数Add,但是很难看出是求加法
	c = c1 + c2;  //换成这个就能执行,形如c = c1.operator+(c2);
}
*/

/*
class Int{
public:
	Int(int i = 0):m_i(i){  //默认为0,初始化
	}
public:
	Int operator+(const Int &i){
		return Int(m_i+i.m_i);
	}
public:
	Int& operator++(){  //++a,推荐使用前++
		m_i ++;
		return *this;
	}
	Int operator++(int){  //a++
		Int tmp(m_i);
		m_i ++;
		return tmp;
	}
private:
	int m_i;
};

void main(){
	Int a(5);
	Int x;
	x = a++;
	printf("%d\n",x);
	x = ++a;
	printf("%d\n",x);
}
*/

/*
void main(){
	Int x;
	Int y(1);
	Int z(2);

	x= y+z;  //不通过,因为没有写函数重载
}
*/

class Complex;  //对复数类进行声明
ostream& operator<<(ostream& out,const Complex &c);

//复数
class Complex{
	friend ostream& operator<<(ostream& out,const Complex &c);  //友元函数
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
private:
	int m_real;
	int m_imag;
};

ostream& operator<<(ostream& out,const Complex &c){
	cout<<"("<<c.m_real<<","<<c.m_imag<<")";
	return out;
}

void main(){
	Complex c;
	Complex c1(1,2);
	Complex c2(3,4);

	c = c1 + c2;
	c = c1 + 10;  //11,2  形如c = c1.operator+(10);

	//c = 10 + c1;  //这个就会报错,但是加法是有交换律的

	cout<<c<<endl;
}