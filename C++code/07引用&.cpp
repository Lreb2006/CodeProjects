#include<iostream>
using namespace std;

void c(int &a)
{
	a = a+1;
}
void d(int b){
	b=b+1;
}
int main(void)
{
	int a = 4;
	c(a);
	int b = 4;
	d(b);
	cout<<a<<" "<<b<<endl;
	return 0;
}
