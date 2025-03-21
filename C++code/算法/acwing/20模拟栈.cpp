#include<bits/stdc++.h>
using namespace std;

stack <int> s;
int m,x;

int main()
{
    cin>>m;
    while(m--){
        string op;
        cin>>op;
        if(op == "push"){
            cin>>x;
            s.push(x);
        }else if(op == "pop"){
            s.pop();
        }else if(op == "empty"){
            if(s.empty() == 1)   cout<<"YES"<<endl;
            else    cout<<"NO"<<endl;
        }else if(op == "query"){
            cout<<s.top()<<endl;
        }
    }
    return 0;
}