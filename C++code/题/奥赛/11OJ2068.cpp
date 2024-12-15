#include<iostream>
using namespace std;
//z x-z
//2z+4(x-z)=y
//2z+4x-4z=y
//(4x-y)/2=z
int main(void)
{
    int x,y;
    cin>>x>>y;
    int z = (4*x-y)/2;
    cout<<z<<" "<<x-z<<endl;
    return 0;
}