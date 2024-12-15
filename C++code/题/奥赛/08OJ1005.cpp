#include<iostream>
using namespace std;
//110*90
//90*210
//R G
//R+90G=110*90
//R+210G=90*210
//G=(90*210-110*90)/(210-90)
//z*1<=G
//z = (y*b-x*a)/(b-a)
int main(void)
{
    double x,y,a,b;
    cin>>x>>a>>y>>b;
    double z = (y*b-x*a)/(b-a);
    printf("%.2f",z);
    return 0;
}