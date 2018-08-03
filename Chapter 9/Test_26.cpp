#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>

//随机读取
void main(){
	//1:定义文件对象
	ifstream ifile;  //infile简写为if
	//2:打开文件并判断
	ifile.open("Test1.txt",ios::in);  //C++中,以对象打开文件名,并说明模式
	if(!ifile){
		cerr<<"Open File Fail!"<<endl;
		exit(1);  //缺少stdlib头文件
	}
	//3:用输入运算对文件进行读
	int pos;  //
	int value;
	while(1){
		cout<<"Please input the pos:";
		cin>>pos;
		ifile.seekg(pos*3,ios::beg);  //pos*3说明一个数据占2个字节,加上空格就是3个字节,beg说明相对于起始位置
		ifile>>value;  //用文件读入
		cout<<"value = "<<value<<endl;
	}
	//4:关闭文件
	ifile.close();
}

/*
//二进制文件读
void main(){
	int ar[10];
	//1:定义文件对象
	ifstream ifile;  //infile简写为if
	//2:打开文件并判断
	ifile.open("Test2.txt",ios::in | ios::binary);  //C++中,以对象打开文件名,并说明模式
	if(!ifile){
		cerr<<"Open File Fail!"<<endl;
		exit(1);  //缺少stdlib头文件
	}
	//3:用输入运算对文件进行读
	ifile.read((char*)ar,sizeof(ar));
	//4:关闭文件
	ifile.close();
}

/*
//二进制文件写
void main(){
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	//1:定义文件对象
	ofstream ofile;  //outfile简写为of
	//2:打开文件并判断
	//相当于C语言中的fopen("Test.txt","w");
	ofile.open("Test2.txt",ios::out | ios::binary);  //C++中,以对象打开文件名,并说明模式
	if(!ofile){
		cerr<<"Open File Fail!"<<endl;
		exit(1);  //缺少stdlib头文件
	}
	//3:用输出运算对文件进行写入
	ofile.write((char*)ar,sizeof(ar));  //只需知道起始位置和总共的个数即可进行输出
	//4:关闭文件
	ofile.close();
}

/*
//读文件
void main(){
	int ar[10];
	//1:定义文件对象
	ifstream ifile;  //infile简写为if
	//2:打开文件并判断
	ifile.open("Test1.txt",ios::in);  //C++中,以对象打开文件名,并说明模式
	if(!ifile){
		cerr<<"Open File Fail!"<<endl;
		exit(1);  //缺少stdlib头文件
	}
	//3:用输入运算对文件进行读
	for(int i = 0; i<sizeof(ar)/sizeof(int); ++i){
		//cin>>ar[i];
		ifile>>ar[i];
	}
	//4:关闭文件
	ifile.close();
}

/*
void main(){
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	//1:定义文件对象
	ofstream ofile("Test1.txt",ios::out);  //步骤1和2合并
	//2:打开文件并判断
	//相当于C语言中的fopen("Test.txt","w");
	//ofile.open("Test1.txt",ios::out);  //C++中,以对象打开文件名,并说明模式
	if(!ofile){
		cerr<<"Open File Fail!"<<endl;
		exit(1);  //缺少stdlib头文件
	}
	//3:用输出运算对文件进行写入
	for(int i = 0; i<sizeof(ar)/sizeof(int); ++i){
		ofile<<ar[i]<<" ";
	}
	//4:关闭文件
	ofile.close();
}

/*
void main(){
	int ar[] = {12,23,34,45,56,67,78,89,90,100};
	//1:定义文件对象
	ofstream ofile;  //outfile简写为of
	//2:打开文件并判断
	//相当于C语言中的fopen("Test.txt","w");
	ofile.open("Test1.txt",ios::out);  //C++中,以对象打开文件名,并说明模式
	if(!ofile){
		cerr<<"Open File Fail!"<<endl;
		exit(1);  //缺少stdlib头文件
	}
	//3:用输出运算对文件进行写入
	for(int i = 0; i<sizeof(ar)/sizeof(int); ++i){
		ofile<<ar[i]<<" ";
	}
	//4:关闭文件
	ofile.close();
}
*/