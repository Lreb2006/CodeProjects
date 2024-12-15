#include<iostream>
using namespace std;
// 15h/2=150 h=300/15=20
int main(void)
{
    double h = 20.00;
    double s = (15+25)*h/2.00;
    printf("%.2f",s);   //.2表示保留两位小数，前面有.
    return 0;
}