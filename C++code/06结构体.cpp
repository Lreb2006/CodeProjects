#include<iostream>
using namespace std;

struct birth{
		int year;
		int month;
		int day;
	};
	
struct stu{
	string name;
	int age;
	birth bir;
};
int main(void)
{
	stu mike;	//与C不同的是，cpp中不需要声明struct stu mike 
	mike.name = "mike";
	mike.age = 18;
	mike.bir.year = 2006;
	mike.bir.month = 03;
	mike.bir.day = 22;
	cout<<"student:"<<mike.name<<" "<<"age:"<<mike.age<<" "<<"birthday:"<<mike.bir.year<<"-"<<mike.bir.month<<"-"<<mike.bir.day<<endl; 
	return 0;
}
