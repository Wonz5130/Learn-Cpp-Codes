#include<iostream>
using namespace std;

template<typename Type>
class List;

template<typename Type>
class ListNode{
	friend class List<Type>;  //这样就能访问私有成员数据
public:
	ListNode():data(Type()),next(NULL)  //零初始化
	{}
	ListNode(Type d,ListNode<Type> *n=NULL)
		:data(d),next(n)
	{}
	~ListNode()
	{}
private:
	Type data;  //类型是Type类型
	ListNode<Type> *next;
};

template<typename Type>  //定义类的时候,必须加上这个
class List{
public:
	List();  //如果需要放在外面实现
	bool push_back(Type x);
	void show_list()const;
private:
	ListNode<Type> *first;
	ListNode<Type> *last;
	size_t size;
};

template<typename Type>  //可以用T,习惯用Type
List<Type>::List(){  //把模板参数Type给出
	first = last = (ListNode<Type>*)malloc(sizeof(ListNode<Type>));
	last->next = NULL;
	size = 0;
}

template<typename Type>
bool List<Type>::push_back(Type x){
	ListNode<Type> *s = (ListNode<Type>*)malloc(sizeof(ListNode<Type>));
	if(s == NULL)
		return false;
	s->data = x;
	s->next = NULL;

	last->next = s;
	last = s;
	size++;
	return true;
}

template<typename Type>
void List<Type>::show_list()const{
	ListNode<Type> *p = first->next;
	while(p != NULL){
		cout<<p->data<<"-->";
		p = p->next;
	}
	cout<<"NULL"<<endl;
}

void main(){
	List<int> mylist;
	//List<char> yourlist;
	for(int i = 1;i <= 10; ++i){
		mylist.push_back(i);
	}
	mylist.show_list();

	//字符型链表
	List<char> yourlist;
	for(int j = 65;j <= 75; ++j){
		yourlist.push_back(j);
	}
	yourlist.show_list();
	return;
}