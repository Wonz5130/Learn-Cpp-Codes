#include<iostream>
using namespace std;

class Base{
public:
	Base():x(0){
	}
	~Base(){
	}
public:
	void SetX(int data){
		x = data;
	}
public:
	void Show_Base(){
		cout<<"Show Base!"<<endl;
	}
protected:
	void Print_Base(){
		cout<<"Print Base!"<<endl;
	}
private:
	int x;
};


////////////////////////////////////////////////
//1:通过派生类的内部,能否访问
class D : private Base{  //子类私有继承父类
/*
//私有继承,Base不能再被D的子类使用,即相当于Base被终止继承了,不能被直接访问
//不管子类是公有继承还是私有继承父类,有两个东西一定不能继承:父类的构造函数和析构函数
//父类里原先是公有的,都变成私有了
private:
	void SetX(int data){
		x = data;
	}
	void Show_Base(){
		cout<<"Show Base!"<<endl;
	}
protected:
	void Print_Base(){
		cout<<"Print Base!"<<endl;
	}
private:
	int x;
*/
public:
	D():y(0){
	}
	~D(){
	}
public:
	void SetData(int data){
		y = data;
		//x = data;  //这里不允许,虽然继承了父类的x
		SetX(data);
	}
public:
	void Show_D(){
		cout<<"Show D!"<<endl;
		//x = 10;  //私有数据不能直接访问
		Show_Base();  //相当于访问自身的私有成员,是可以的
		Print_Base();  //相当于访问自身的保护成员,是可以的
	}
protected:
	void Print_D(){
		cout<<"Print D!"<<endl;
	}
private:
	int y;
};

class C : public D{
public:
	void Show_C(){
		//Show_Base();  //不能访问,因为Base对D来说是私有的
		//如果改成保护继承,就能访问
	}
};

////////////////////////////////////////////////
//2:通过对象的形式,能否访问
//对象永远只能访问公有方法
void main(){
	D d;
	//d.Show_Base();  //不能访问,因为在子类里变成了私有属性,对象不能直接访问
}

/*
class Base{
public:
	Base():x(0){
	}
	~Base(){
	}
public:
	void SetX(int data){
		x = data;
	}
public:
	void Show_Base(){
		cout<<"Show Base!"<<endl;
	}
protected:
	void Print_Base(){
		cout<<"Print Base!"<<endl;
	}
private:
	int x;
};


////////////////////////////////////////////////
//1:通过派生类的内部,能否访问
class D : protected Base{  //子类公有继承父类
/*
//不管子类是公有继承还是私有继承父类,有两个东西一定不能继承:父类的构造函数和析构函数
//父类里原先是公有的,都变成保护了
protected:
	void SetX(int data){
		x = data;
	}
	void Show_Base(){
		cout<<"Show Base!"<<endl;
	}
protected:
	void Print_Base(){
		cout<<"Print Base!"<<endl;
	}
private:
	int x;

public:
	D():y(0){
	}
	~D(){
	}
public:
	void SetData(int data){
		y = data;
		//x = data;  //这里不允许,虽然继承了父类的x
		SetX(data);
	}
public:
	void Show_D(){
		cout<<"Show D!"<<endl;
		//x = 10;  //私有数据不能直接访问
		Show_Base();  //相当于访问自身的保护成员,是可以的
		Print_Base();
	}
protected:
	void Print_D(){
		cout<<"Print D!"<<endl;
	}
private:
	int y;
};

////////////////////////////////////////////////
//2:通过对象的形式,能否访问
//对象永远只能访问公有方法
void main(){
	D d;
	d.Show_D();
	//d.Show_Base();  //不能访问,因为在子类里变成了保护属性,对象不能直接访问
}

/*
class Base{
public:
	Base():x(0){
	}
	~Base(){
	}
public:
	void SetX(int data){
		x = data;
	}
public:
	void Show_Base(){
		cout<<"Show Base!"<<endl;
	}
protected:
	void Print_Base(){
		cout<<"Print Base!"<<endl;
	}
private:
	int x;
};


////////////////////////////////////////////////
//1:通过派生类的内部,能否访问
class D : public Base{  //子类公有继承父类
public:
	D():y(0){
	}
	~D(){
	}
public:
	void SetData(int data){
		y = data;
		//x = data;  //这里不允许,虽然继承了父类的x
		SetX(data);
	}
public:
	void Show_D(){
		cout<<"Show D!"<<endl;
		Show_Base();
		Print_Base;  //子类里能直接访问父类的protected
	}
protected:
	void Print_D(){
		cout<<"Print D!"<<endl;
	}
private:
	int y;
};

////////////////////////////////////////////////
//2:通过对象的形式,能否访问
//不管子类是公有继承还是私有继承父类,有两个东西一定不能继承:父类的构造函数和析构函数
void main(){
	D d;
	d.Show_Base();
	d.Show_D();
	
	//通过对象,永远只能访问公有方法
	//d.Print_Base();  //不能访问
	//d.Print_D();  //不能访问
}

/*
void main(){
	Base b;
	b.Show_Base();  //对象只能访问公有
	//b.Print_Base();  //保护不可访问
	//b.x = 10;  //私有不可访问
}
*/

/*
void main(){
	cout<<sizeof(Base)<<endl;
	cout<<sizeof(D)<<endl;
}
*/