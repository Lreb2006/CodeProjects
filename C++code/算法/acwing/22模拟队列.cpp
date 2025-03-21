#include<bits/stdc++.h>
using namespace std;

queue <int> q;
int m,x;
int main()
{
    cin>>m;
    string op;
    while(m--){
        cin>>op;
        if(op == "push"){
            cin>>x;
            q.push(x);
        }else if(op == "pop"){
            q.pop();
        }else if(op == "empty"){
            if(q.empty())   cout<<"YES"<<endl;
            else    cout<<"NO"<<endl;
        }else{
            cout<<q.front()<<endl;
        }
    }
    return 0;
}