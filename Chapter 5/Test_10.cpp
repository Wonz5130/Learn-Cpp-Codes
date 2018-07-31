#include<iostream>
using namespace std;

/*
class Test{
public:
    Test(int d = 0):data(d){
        cout<<"Create Test!"<<endl;
    }
    Test(const Test &t){
        //cout<<"Copy Create Test Object:"<<this<<endl;
        data = t.data;
    }
    Test& operator=(const Test &t){  //&和Test靠在一起,表示返回类型是Test的引用类型;&和t靠在一起,强调的是引用变量
        //cout<<"Assign:"<<this<<"="<<&t<<endl;
        if(this != &t){
            data = t.data;
        }
        return *this;
    }
    ~Test(){
        cout<<"Free Test!"<<endl;
    }
//其实是有6个函数的
    //对一般对象取地址符
    Test* operator&(){
        return this;
    }
    //对常对象的取址运算符的重载
    const Test* operator&()const{
        return this;
    }
private:
    int data;
};

int main(){
    Test t;
    Test t1 = t;
    Test t2;
    t2 = t1;

    Test t3;
    Test *pt = &t3;  //取t3地址,实际上是Test *pt = t3.operator&()

    const Test t4;
    //Test *pt1 = &t4;  //这是错的,因为t4是常量,不能用可变指针指向t4,而要改成const Test *pt1 = &t4;
    const Test *pt1 = &t4;
    return 0;
}
*/

/*
class Test{
public:
    Test(int d = 0):data(d){
        cout<<"Create Test!"<<endl;
    }
private:
    int data;
};

int main(){
    Test t1(100);
    Test t2 = t1;
    Test t3;
    t3 = t1;
    return 0;
}
*/

class String{
public:
    String(const char *str = ""){
        if(str == NULL){  //如果是空,就开辟一个空间
            data = (char *)malloc(sizeof(char));
            data[0] = '\0';
        }
        else{
            data = (char *)malloc(sizeof(char) * (strlen(str) + 1));  //包括了空串,即开辟一个空间
            strcpy(data,str);  //生成的data指向一个新的存储str的数组首地址,但是默认析构函数只析构掉data,动态生成的数组里的数据并没有消除,所以这里必须手动写析构函数
        }
    }
    //深拷贝函数
    String(const String &s){
        data = (char*)malloc(sizeof(char) * (strlen(s.data)+1));  //考虑'\0'长度
        strcpy(data,s.data);  //不同指针有不同指向,但是内容一样
    }
    //深赋值函数
    /*
    //这是不可取的,如果原有空间有数据,经过这个深赋值,就会有新的地址指向
    String& operator=(const String &s){
        if(this != &s){
            data = (char*)malloc(sizeof(char) * (strlen(s.data)+1));
            strcpy(data,s.data);
        }
        return *this;
    }
    */
    String& operator=(const String &s){
        if(this != &s){
            free(data);  //先释放原有空间
            data = NULL;
            data = (char*)malloc(sizeof(char) * (strlen(s.data)+1));  //有可能新申请空间不够,但是原有空间已经释放了,异常安全问题
            strcpy(data,s.data);
        }
        return *this;
    }
    //析构函数
    ~String(){
        free(data);
        data = NULL;
    }
private:
    char *data;
};

void main(){
    /*
    char *str = NULL;  //空
    String s1;
    */
    char *str = "Hello";
    String s1(str);
    String s2(s1);  //可以有多个指针指向同一个地址,但是不能多次释放,这个叫浅拷贝:只拷贝指针的指向

    String s3;
    s3 = s2;  //s3和s2指向了同一个地址,这叫浅赋值
}