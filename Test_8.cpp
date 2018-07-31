#include<iostream>
using namespace std;

class Test{
public:
    //Test t;
    Test(int d = 0):data(d){
        cout<<"Create Test Object:"<<this<<endl;
    }
    //Test t1(t),不写也没事,系统有默认的拷贝构造函数
    Test(const Test &t){  //引用
        cout<<"Copy Create Test Object:"<<this<<endl;
        data = t.data;
    }
    /*
    //系统默认的拷贝构造函数
    Test(const Test &t){  //引用
        data = t.data;  //所有数据都会初始化
    }
    */
    //赋值函数
    //t2 = t1
    //函数改写:Test& operator(Test * const this, const Test & t)
    Test& operator=(const Test &t){  //引用,这个t就是t1的别名,不会再调用构造函数,效率提高了,节省了内存
        cout<<"Assign:"<<this<<"="<<&t<<endl;
        //t.data = 20;  //如果不加const,那么就会执行这个,更改值为20
        if(this != &t){  //this代表t2
            data = t.data;
        }
        return *this;  //this代表当前地址，*this代表当前地址的元素
    }
    //~t
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

Test& fun(Test x){
    int value;
    value = x.GetData();
    Test tmp(value);
    return tmp;  //t2得到的值是随机值,因为返回的是临时对象tmp,函数执行结束,tmp会被析构掉,把一个析构掉的对象赋值,所以是随机值
}

void main(){
    Test t1(10);
    Test t2;
    t2 = fun(t1);
}

/*
void main(){
    Test t1(10);
    Test &t2 = t1;  //t2是t1的别名
    Test &t3 = t2;  //t3也是t1的别名

    t3 = t1;  //实际上是两个相同的进行赋值,自己给自己赋值
}
*/


/*
void main(){
    Test t1(10);

    //Test t2 = t1;  //初始化

    Test t2,t3;
    t2 = t1;  //赋值
    //实际上这条语句等价于下面两条语句
    //t2.operator=(t1)
    //operator=(&t2,t1);

    //t3 = t2 = t1;  //连等赋值
    //等价于
    //t2.operator=(t1)
    //t3.operator=(t2.operator=(t1));  //所以需要有返回值
}
*/