#include<iostream>
using namespace std;
#define SIZE 10

class Test{
public:
	Test(int d = 0):data(d){
		cout<<"Create Test Object!"<<endl;
	}
	~Test(){
		cout<<"Free Test Object!"<<endl;
	}
public:
	void InitObject(int d = 0){
		data = d;
		cout<<"Init Object!"<<endl;
	}
	void Destroy(){
		cout<<"Destroy Object!"<<endl;
	}
private:
	int data;
};

void main(){
	Test *pt = new Test(100);
	delete pt;

	Test *pa = new Test[10];
	delete []pa;  //一定要释放数组
}

/*
void Use_Malloc_Free(){
	Test *pt = (Test *)malloc(sizeof(Test));  //只负责对空间申请
	pt->InitObject(10);
	pt->Destroy();  //释放前要摧毁对象,防止内存泄露
	free(pt);
}

void Use_New_Delete(){
	Test *pt = new Test(10);  //先申请空间,再初始化
	delete pt;  //先摧毁对象,再释放空间
}

void main(){
	Use_Malloc_Free();
	cout<<"------------------"<<endl;
	Use_New_Delete();
}
*/

/*
void main(){
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	free(p);

	int *q = new int(10);  //new允许申请空间的时候初始化
	delete q;
}
*/

/*
void main(){
	int *p = (int*)malloc(sizeof(int) * SIZE);
	if(p == NULL)
		exit(1);
	for(int i  = 0;i < SIZE; ++i){
		p[i] = i+1;
	}
	free(p);

	int *q = new int[SIZE];
	for(int j = 0;j < SIZE; ++j){
		q[j] = j+1;
	}
	delete []q;
}
*/