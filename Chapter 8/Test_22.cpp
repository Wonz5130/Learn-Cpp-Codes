#include<iostream>
using namespace std;

class Base{
public:
	virtual void show(){
		cout<<"This is Base show()"<<endl;
	}
public:
	Base(){
		cout<<"Create Base"<<endl;
	}
	virtual ~Base(){
		cout<<"Free Base"<<endl;
	}
};

class D : public Base{
public:
	void show(){  //父类的show是虚函数,那么子类的show也是虚函数(函数名相同,返回值相同,参数列表相同)
		cout<<"This is D show()"<<endl;
	}
public:
	D(){
		cout<<"Create D"<<endl;
	}
	~D(){
		cout<<"Free D"<<endl;
	}
};

void main(){
	Base *pb = new D;
	delete pb;
}

/*
//一般都要同名,同参数表,同返回类型
//例外:基类中返回基类指针,派生类中返回派生类指针
class Base{
public:
	virtual Base* show(){
		cout<<"This is Base show()"<<endl;
		return this;
	}
};

class D : public Base{
public:
	D* show(){  //父类的show是虚函数,那么子类的show也是虚函数(函数名相同,返回值相同,参数列表相同)
		cout<<"This is D show()"<<endl;
		return this;
	}
};

int main(){
	D d;
	Base *pb = &d;
	pb->show();  //调用子类D的show,返回值类型不一样,但是可以执行
	return 0;
}


/*
class A{
public:
	virtual void Eat(){
		cout<<"A Eat()"<<endl;
	}
	virtual void Sleep(){
		cout<<"A Sleep()"<<endl;
	}
};

class P : public A{
public:
	void Eat(){
		cout<<"P Eat()"<<endl;
	}
	void Sleep(){
		cout<<"P Sleep()"<<endl;
	}
};

class Dog : public A{
public:
	void Eat(){
		cout<<"Dog Eat()"<<endl;
	}
	void Sleep(){
		cout<<"Dog Sleep()"<<endl;
	}
};

class Pig : public A{
public:
	void Eat(){
		cout<<"Pig Eat()"<<endl;
	}
	void Sleep(){
		cout<<"Pig Sleep()"<<endl;
	}	
};

class Bird : public A{
public:
	void Eat(){
		cout<<"Bird Eat()"<<endl;
	}
	void Sleep(){
		cout<<"Bird Sleep()"<<endl;
	}
public:  //鸟类还会飞
	void Fly(){
		cout<<"Bird Fly()"<<endl;
	}
};

class TN : public Bird{
private:  //设为private,就表示鸵鸟不会飞
	void Fly();
};

//接口
void fun(A *pa){
	pa->Eat();
	pa->Sleep();
}

void main(){
	P p;
	Dog dog;
	Pig pig;

	fun(&p);
	fun(&dog);
	fun(&pig);

	TN tn;
	//tn.Fly();  //鸵鸟不会飞
	fun(&tn);
}

/*
class Base{
public:
	virtual void show(){
		cout<<"This is Base show()"<<endl;
	}
};

/*
//virtual只用在函数声明
class Base{
public:
	virtual void show();
};

void Base::show(){
	cout<<"This is Base show()"<<endl;
}


class D : public Base{
public:
	void show(){  //父类的show是虚函数,那么子类的show也是虚函数(函数名相同,返回值相同,参数列表相同)
		cout<<"This is D show()"<<endl;
	}
	void show(int){
		cout<<"This is D show(int)"<<endl;
	}
	void print(){
		cout<<"This is D print()"<<endl;
	}
};

class C : public D{
public:
	void show(){
		cout<<"This is C show()"<<endl;
	}
	void show(int){
		cout<<"This is C show(int)"<<endl;
	}
};

void main(){
	C c;
	D *pd = &c;
	pd->show();  //调用的是C的show函数
	pd->show(0);  //调用的是父类D的show(int)
}

/*
void main(){
	D d;
	Base *pb = &d;
	pb->show();  //只能访问父类的show函数,加上virtual就能访问子类的show函数
}

/*
void main(){
	D d;

	//1:对象给对象赋值
	Base b;
	b = d;

	//2:子类的地址给父类的指针赋值
	Base *pb = &d;

	//3:子类对象初始化父类的引用
	Base &bf = d;
}
*/