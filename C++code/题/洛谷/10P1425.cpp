#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int min = c*60+d-(a*60+b);
    int h = min/60;
    int minl = min-h*60;
    cout<<h<<" "<<minl<<endl;
    return 0;
}