#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

#define DefaultArraySize 10

template<typename elemType>
class Array{
	int  size;
	elemType * ia ;
public:
	explicit Array(int sz=DefaultArraySize){
		size=sz;
		ia=new elemType [size];
	}
	~ Array(){
		delete [] ia;
	}
	elemType & operator[](int ix) const{ //下标运算符[ ]重载
		if(ix<0||ix>=size){ //增加异常抛出,防止索引值越界
			string eObj="out_of_range error in Array<elemType>::operator[]()";
			throw out_of_range(eObj);
		}
		return  ia[ix];//保留原来[ ]的所有索引方式
	}
};

int main(){
	int i;
	Array<int> arr;
	try{
		for(i=0;i<=DefaultArraySize;i++){
			arr[i]=i+1; //写入ia[10]时出界
			cout<<setw(5)<<arr[i];
		}
		cout<<endl;
	}
	catch(const out_of_range & excp){
		cerr<<'\n'<<excp.what()<<'\n';//打印"out_of_range error in Array<elemType>::operator[]()"
		return -1;
	}
	return 0;
}




/*
template<typename Type>
class PushOnStackFull{
public:
	PushOnStackFull(const char *s, int val):str(s),value(val){

	}
	~PushOnStackFull(){

	}
public:
	void _What()const{
		cout<<str<<endl;
		cout<<value<<" not oush stack!"<<endl;
	}
private:
	Type value;
	string str;
};

template<typename Type>
class Stack{
public:
	Stack(int sz = STACK_SIZE){
		capacity = sz > STACK_SIZE ? sz : STACK_SIZE;
		data = new Type[capacity];
		top = 0;
	}
	~Stack(){
		delete []data;
		data = NULL;
		capacity = top = 0;
	}
public:
	bool IsFull()const{
		return top >= capacity;
	}
	bool Push(const Type &x){
		if(IsFull()){
			//cout<<"Stack is full!"<<endl;
			//return false;
			throw PushOnStackFull<Type>("Stack is full!",x);
		}
		data[top++] = x;
		return true;
	}
public:
	void Show_Stack()const{
		for(int i = top-1; i >= 0; --i){
			cout<<data[i]<<endl;
		}
	}
private:
	enum{STACK_SIZE=8};
	Type *data;
	size_t capacity;
	size_t top;
};

void main(){
	Stack<int> st;
	try{
		for(int i = 1;i <= 10; ++i){
			st.Push(i);
		}
	}
	catch(PushOnStackFull<int> &e){
		e._What();
	}
	st.Show_Stack();
}

/*
template<typename Type>
class Stack{
public:
	Stack(int sz = STACK_SIZE){
		capacity = sz > STACK_SIZE ? sz : STACK_SIZE;
		data = new Type[capacity];
		top = 0;
	}
	~Stack(){
		delete []data;
		data = NULL;
		capacity = top = 0;
	}
public:
	bool IsFull()const{
		return top >= capacity;
	}
	bool Push(const Type &x){
		if(IsFull()){
			cout<<"Stack is full!"<<endl;
			return false;
		}
		data[top++] = x;
		return true;
	}
public:
	void Show_Stack()const{
		for(int i = top-1; i >= 0; --i){
			cout<<data[i]<<endl;
		}
	}
private:
	enum{STACK_SIZE=8};
	Type *data;
	size_t capacity;
	size_t top;
};

void main(){
	Stack<int> st;
	for(int i = 1;i <= 10; ++i){  //超过了容量8
		st.Push(i);
	}
	st.Show_Stack();
}
*/