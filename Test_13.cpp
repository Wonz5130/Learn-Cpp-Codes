#include<iostream>
using namespace std;

class Test{
	friend void fun(Test &);
public:
	Test(int d = 0):data(d){
		count++;
	}
	~Test(){
		count--;
	}
public:
	//相当于void show(Test * const this)
	void show(){
		cout<<data<<endl;
		cout<<count<<endl;
	}
	/*
	//静态函数没有this指针
	static void show(){
		//cout<<data<<endl;  //不能访问普通的成员数据
		cout<<count<<endl;
	}
	*/
	void print(){
		show();  //普通方法可以调用静态方法,但是静态方法不能调用普通方法
	}
	/*
	//相当于void print(const Test * const this)  //const封锁了*this
	void print()const{
		show();  //这里不行,常方法不能调用一般方法,因为print设了不允许改变,而show是可以改变的
	}
	*/
public:
	//相当于void list(Test * const this)
	void list(){
		cout<<"This is list()"<<endl;
		data  = 0;  //没有问题
		print();  //普通方法调用普通方法,没有问题
	}
	//相当于void list(Test * const this)const
	//其实就是void list(const Test * const this)  //封锁的是*this是常量
	void list()const{  //常函数限定不能改变整个类的数据成员
		cout<<"This is list() const"<<endl;
		//data = 0;  //不能执行
	}
private:
	int data;
	static int count;  //统计对象个数,所有对象共享静态成员
};

//Init
int Test::count  = 0;

void fun(Test &t){
	cout<<"t.data = "<<t.data<<endl;  //data是不同的,所以要用t指定
	cout<<"object count = "<<Test::count<<endl;  //count是共享的,所以用Test
}

void main(){
	Test t(100);
	Test t1(200);
	fun(t);
}