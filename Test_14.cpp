#include<iostream>
using namespace std;

class Test{
public:
	bool operator>(const Test &t){
		return true;
	}
};

//函数模板
template<typename Type>  //Type是一种类型
Type Max(Type a,Type b){
	cout<<typeid(Type).name()<<endl;
	return a > b ? a : b;  //大小如何比较通过重载进行比较
}

void main(){
	Test t1,t2;
	Max(t1,t2);
}



/*
//不同类型的比较最大值
template<typename Type1, typename Type2>  //Type是一种类型
Type1 Max(Type1 a,Type2 b){
	return a > b ? a : b;
}
*/

/*
void main(){
	cout<<Max('A','X')<<endl;  //会根据函数模板生成一个模板函数
	cout<<Max(1,2)<<endl;
	cout<<Max(1.2f,2.3f)<<endl;
	cout<<Max(3.4,2.3)<<endl;
	//Max(1,2.3);  //模板不支持隐式转换,这会报错
	//可以改成一下三种
	Max(1,(int)2.3);
	Max((double)1,2.3);
	Max<int>(1,2.3);  //给模板传递一个类型
	Max<double>(1,2.3);
}
*/