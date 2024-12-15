#include<iostream>
using namespace std;

int main(void)
{
    double a,b;
    cin>>a>>b;
    double c = b/a*100;
    printf("%.3f%%",c);     //用两个连续的%%输出实际的百分号
    return 0;
}