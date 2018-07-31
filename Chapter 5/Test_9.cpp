#include<iostream>
using namespace std;

class Test{
public:
    Test(int d = 0):data(d){
        cout<<"Create Test Object:"<<this<<endl;
    }
    Test(const Test &t){
        cout<<"Copy Create Test Object:"<<this<<endl;
        data = t.data;
    }
    Test& operator=(const Test &t){
        cout<<"Assign:"<<this<<"="<<&t<<endl;
        if(this != &t){
            data = t.data;
        }
        return *this;
    }
    ~Test(){
        cout<<"Free Test Object:"<<this<<endl;
    }
public:
    int GetData()const{
        return data;
    }
private:
    int data;
};

/*
//测试1
Test fun(Test x){
    int value = x.GetData();
    Test tmp(value);
    return tmp;
}
*/

/*
//测试2
Test fun(Test x){
    int value = x.GetData();
    return Test(value);  //创建无名临时对象的语法
}
*/

/*
//测试3
Test fun(Test &x){
    int value = x.GetData();
    return Test(value);  //创建无名临时对象的语法
}
*/

/*
//测试4
Test& fun(Test &x){
    int value = x.GetData();
    return Test(value);  //创建无名临时对象的语法
}

int main(){
    Test t1(100);
    Test t2;
    t2 = fun(t1);
    return 0;
}
*/

//测试5
Test fun(Test &x){
    int value = x.GetData();
    return Test(value);  //创建无名临时对象的语法
}

int main(){
    Test t1(100);
    Test t2 = fun(t1);  //直接初始化
    return 0;
}
