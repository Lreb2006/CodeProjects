#include<iostream>
using namespace std;

int main(void)
{
    string s;
    cin>>s;
    for(int i = 0;i<s.length();i++){
        if(s[i] == 'b'){
            if(s[i+1] == 'a'){
                cout<<"False"<<endl;
                return 0;
            }
        }
    }
    cout<<"True"<<endl;
    return 0;
}