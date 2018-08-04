#include<iostream>
using namespace std;

/*
float Div(int a, int b)throw(){
	if(b == 0){
		throw b;  //抛出异常,从右边返回,return不执行,直接跳到catch
	}
	return a/b;  //从左边返回,返回类型为float
}
*/

float Div(int a, int b){
	if(b == 0){
		throw b;  //抛出异常,从右边返回,return不执行,直接跳到catch
	}
	return a/b;  //从左边返回,返回类型为float
}

void main(){
	int a = 10;
	int b = 0;
	float result = 0.0f;
	try{
		float result = Div(a,b);
	}
	catch(int){  //针对类型进行 catch
		cout<<"Div Error, b == 0"<<endl;
	}
	catch(short){
		cout<<"Div Error, b == 0"<<endl;
	}
	catch(...){  //catch all,只能放到最后
		cout<<"Div Error, b == 0"<<endl;
	}
	cout<<"result = "<<result<<endl;
}

/*
float Div(int a, int b){
	if(b == 0){
		return 0;
	}
	return a/b;
}

void main(){
	int a = 10;
	int b = 100;
	float result = Div(a,b);
	cout<<"result = "<<result<<endl;
}
*/