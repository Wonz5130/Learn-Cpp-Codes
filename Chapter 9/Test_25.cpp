#include<iostream.h>
#include<iomanip.h>

void main(){
	for(int i = 1; i <= 10; ++i){
		for(int j = 1; j <= 10; ++j){
			cout.flags(ios::left);
			cout<<setw(5)<<i*j;  //缺少头文件
		}
		cout<<endl;
	}
}

/*
void main(){
	int a = 123456789;
	cout<<hex<<a<<endl;  //直接输出十六进制
}
*/

/*
void main(){
	int a = 123456789;
	cout.flags(ios::showpos);  //正数输出“+”
	cout<<a<<endl;
	cout.flags(ios::hex | ios::showbase);  //ios类里面的16进制以及ios类里面的基类型,之所以用或,是因为不同功能组合
	cout<<a<<endl;
}

/*
void main(){
	for(int i = 1; i <= 10; ++i){
		for(int j = 1; j <= 10; ++j){
			cout.width(5);
			cout.flags(ios::left);  //左对齐
			cout<<i*j;
		}
		cout<<endl;
	}
}

/*
void main(){
	cerr<<"Error!";
	cout<<"Hello IO";  //缓冲区
	cout<<endl;
}
*/

/*
//CPU把数据放到缓冲区,然后做其他事去了,由缓冲区把数据显示到屏幕上
void main(){
	int a;
	cout<<"Hello IO";  //缓冲区
}
*/

/*
//输出重定向
//标准的输出,默认输出到显示器上

void main(){
	int a;
	cout<<"Hello IO"<<endl;
}
*/