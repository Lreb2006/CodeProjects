#include<iostream>
using namespace std;

int main(void)
{
    int a,b,c;
    cin>>a>>b>>c;
    printf("%8d %8d %8d\n",a,b,c);    //8表示占据8个字符位，默认位右对齐
    printf("%-8d %-8d %-8d",a,b,c); //-8表示占据8个字符位，-为左对齐
    return 0;
}