#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double n;
    cin>>n;
    double ams = (n-int(n))*10+(int(n)%10)/10.0+((int(n)/10)%10)/100.0+(int(n)/100)/1000.0;
    printf("%.3f",ams);
    return 0;
}