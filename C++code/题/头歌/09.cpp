#include<iostream>
using namespace std;
const int N = 30;
int f[N];
int func(int n){
    f[0] = 0;
    f[1] = 1;
    for(int i = 2;i<=n;i++){
        f[i] = f[i-1]+f[i-2];
    }
    return f[n];
}
int main(void)
{
    int n;
    cin>>n;
    if(n == 0)  cout<<"0"<<endl;
    if(n == 1)  cout<<"1"<<endl;
    cout<<func(n)<<endl;  
    return 0;
}