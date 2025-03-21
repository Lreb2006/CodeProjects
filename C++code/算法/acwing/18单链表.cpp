#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int e[N],ne[N];
int head,idx;

//初始化
void init(){
    head = -1;
    idx = 0;
}

//将x插到头结点
void addToHead(int x){
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}

//将x插到下标是k的点后面
void add(int k,int x){
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}

//将下标是k的点后面的点删掉
void remove(int k){
    ne[k] = ne[ne[k]];
}

int main()
{
    int m;
    cin>>m;
    init();

    while(m--){
        int k,x;
        char op;
        cin>>op;
        if(op == 'H'){
            cin>>x;
            addToHead(x);
        }else if(op == 'D'){
            cin>>k;
            if(k == 0)  head = ne[head];
            remove(k-1);
        }else if(op == 'I'){
            cin>>k>>x;
            add(k-1,x);
        }
    }

    for(int i = head;i!=-1;i = ne[i]){
        cout<<e[i]<<" ";
    }
    cout<<endl;
    return 0;
}