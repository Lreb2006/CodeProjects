#include<iostream>
using namespace std;

int main(void)
{
    int n;
    int cnt = 0;
    cin>>n;
    for(int i = 1;i<n;i++){
        if(i%37 == 0)   cnt = cnt + i;
    }
    cout<<cnt<<endl;
    return 0;
}