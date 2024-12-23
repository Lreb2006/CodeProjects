#include<iostream>
using namespace std;

int main(void)
{
    int m,t,s;
    cin>>m>>t>>s;
    //m-s/t
    if(t == 0){
        cout<<"0"<<endl;
        return 0;
    }
    if(m-s/t>=0){
        cout<<m-s/t<<endl;
    }else{
        cout<<"0"<<endl;
    }
    return 0;
}