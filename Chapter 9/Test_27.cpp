#include<iostream>
#include<fstream>
using namespace std;

class Complex;
ostream& operator<<(ostream &out, const Complex &c);

class Complex{
	friend ostream& operator<<(ostream &out, const Complex &c);
public:
	Complex():m_real(0),m_imag(0){
		ifstream ifile;
		//读取文件
		ifile.open("Data.dat",ios::in);
		if(!ifile){
			cerr<<"Open File Fail!"<<endl;
			exit(1);
		}

		ifile>>m_real>>m_imag;

		ifile.close();
	}
	Complex(int real, int imag) : m_real(real),m_imag(imag){

	}
	~Complex(){
		ofstream ofile;
		//写文件
		ofile.open("Data.dat",ios::out);
		if(!ofile){
			cerr<<"Open File Fail!"<<endl;
			exit(1);
		}
		ofile<<m_real<<" "<<m_imag;
		ofile.close();
	}
public:
	void SetComplex(int real, int imag){
		m_real = real;
		m_imag = imag;
	}
private:
	int m_real;
	int m_imag;
};

ostream& operator<<(ostream &out, const Complex &c){
	out<<"("<<c.m_real<<","<<c.m_imag<<")";
	return out;
}

void main(){
	Complex c(1,2);
	cout<<c<<endl;
	c.SetComplex(100,200);
	cout<<c<<endl;
}