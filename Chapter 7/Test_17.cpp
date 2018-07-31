#include<iostream>
using namespace std;

/*
new operator  //new操作符
operator new  //操作符new,只负责开辟空间
placement new  //定位new
*/


//返回值必须是void*  参数必须是size_t类型
void* operator new(size_t sz){  //size_t是固定不变的
	void *p = malloc(sz);
	return p;
}

void operator delete(void *p){
	free(p);
}

//数组
void* operator new[](size_t sz){
	void *p = malloc(sz);
	return p;
}

void operator delete[](void *p){
	free(p);
}



class String{
public:
	String(const char *str = ""){
		cout<<"Create String Object!"<<endl;
		if(str == NULL){
			data = new char[1];  //C++用new比malloc更加方便
			data[0] = '\0';
		}
		else{
			data = new char[strlen(str) + 1];  //+1是为了存末尾的'\0'
			strcpy(data,str);
		}
	}
	~String(){
		cout<<"Free String Object!"<<endl;
		delete []data;
		data = NULL;
	}
	/*
public:
	void* operator new(size_t sz){  //size_t是固定不变的
		void *p = malloc(sz);
		return p;
	}

	void operator delete(void *p){
		free(p);
	}

	//数组
	void* operator new[](size_t sz){
		void *p = malloc(sz);
		return p;
	}

	void operator delete[](void *p){
		free(p);
	}
	*/

private:
	char *data;
};

void* operator new(size_t sz, int *d, int pos){
	return &d[pos];  //return d+pos;
}

void main(){
	String *ps = (String *)operator new(sizeof(String));
	new(ps)String("Hello");  //构造函数,其实就是placement new
	
	ps->~String();
	operator delete(ps);
	
	//定位new的语法结构：new(p)类型(初始值)
	int ar[10];
	new(ar,3)int(10);  //ar[3] = 10;
	//printf("%d\n",ar[3]);
}

/*
void main(){
	String *ps = new String[10];
	delete []ps;
}
*/

/*
void main(){
	void *ps = new String("Hello");
	delete ps;
}
*/

/*
//new operator:先调用operator new开辟空间,再构造对象,再调用构造函数初始化对象
//delete operator:先析构对象,再释放空间
void main(){
	//String s("Hello");  //静态开辟
	String *ps = new String("Hello");
	/*
	//等价于下面两句
	String *ps = (String *)operator new(sizeof(String));  //只负责申请空间
	new(ps)String("Hello");  //构造函数,其实就是placement new
	

	delete ps;
	/*
	//等价于下面两句
	ps->~String();  //析构函数
	operator delete(ps);  //只负责释放空间
	
}
*/