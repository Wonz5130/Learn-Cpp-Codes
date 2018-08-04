#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Student{

};

//列表模板
void main(){
	list<int>mylist;
	list<Student>youlist;
	for(int i = 1;i <= 10; ++i){
		mylist.push_back(i);
	}
	list<int>::iterator it = mylist.begin();
	while(it != mylist.end()){
		cout<<*it<<"-->";
		++it;
	}
	cout<<"Nul."<<endl;
}