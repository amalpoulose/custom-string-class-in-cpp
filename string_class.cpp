#include<iostream>
#include<cstring>
using namespace std;

class my_string
{
	char *str;
	public:

	my_string()        //default constructor
	{
		str=new char[1];
		strcpy(str,"");
	}

	my_string(const char *str) //parametrized constructor
	{
		this->str=new char[strlen(str)];
		strcpy(this->str,str);
	}

	void operator=(const char *str) // overloading of '=' operator with argument as string(eg: s="amal")
	{
		this->str=new char[strlen(str)];
		strcpy(this->str,str);
	}

	void operator=(my_string o)   //overloading of '=' operator with argument as object (eg: s1=s2)
	{
		this->str=new char[strlen(o.str)];
		strcpy(this->str,o.str);
	}

	my_string operator+(my_string &o) //overloading of '+' operator for string concatination(eg:s3=s1+s2)
	{
		my_string temp;
		temp.str=new char[strlen(this->str)+strlen(o.str)];
		strcat(temp.str,this->str);   
		strcat(temp.str,o.str); 
		return temp;
	}  
	char & operator[](int i)         //overloading of '[]' operator 
	{
		return *((this->str)+i);
	}

	bool operator>(my_string o)    //overloading of '>' operator
	{
		if(strcmp(this->str,o.str)>0)
			return true;
		else
			return false;
	} 

	bool operator<(my_string o)    //overloading of '<' operator
	{
		if(strcmp(this->str,o.str)<0)
			return true;
		else
			return false;
	} 
	bool operator<=(my_string o)  //overloading of '<=' operator
	{
		if(strcmp(this->str,o.str)<0||strcmp(this->str,o.str)==0)
			return true;
		else
			return false;
	} 
	bool operator>=(my_string o)  //overloading of '>=' operator
	{
		if(strcmp(this->str,o.str)>0||strcmp(this->str,o.str)==0)
			return true;
		else
			return false;
	} 
	bool operator==(my_string o) //overloading of '==' operator
	{
		if(strcmp(this->str,o.str)==0)
			return true;
		else
			return false;
	} 
	bool operator!=(my_string o)  //overloading of '!=' operator
	{
		if(strcmp(this->str,o.str)!=0)
			return true;
		else
			return false;
	}
	int len(void)      //function to know length of string
	{
		return strlen(this->str);
	} 
	int size(void)   //function to know length of string
	{
		return strlen(this->str);
	} 
	friend istream & operator>>(istream &stream,my_string &o); 
	friend ostream & operator<<(ostream &stream,my_string &o); 
};

ostream &operator<<(ostream &stream,my_string &o) //overloading of '<<' operator
{
	stream<<o.str;
	return stream;
}

istream &operator>>(istream &stream,my_string &o) //overloading of '>>' operator
{
	stream>>o.str;
	return stream;
}

main()
{
	my_string s1("amal"),s2=s1,s3,s4,s5,s6;
	s3=" poulose"; 
	s4=s3;
	s5=s2+s4;
	s5[0]='A';
	cin>>s6;
	cout<<s1<<endl;
	cout<<s2<<endl;
	cout<<s3<<endl;
	cout<<s4<<endl;
	cout<<s5<<endl;
	cout<<s6<<endl;
	if(s1>=s3)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	cout<<"len : "<<s6.len()<<endl;
	cout<<"size : "<<s6.size()<<endl<<"size of obj : "<<sizeof(s5)<<endl;
}
