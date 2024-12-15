#include<iostream>
using namespace std;
void swap(int &a,int &b)    //swap函数
{
    int t = a;
    a = b;
    b = t;
}
int main(void)
{
    int a,b;
    cin>>a>>b;
    swap(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}