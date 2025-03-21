#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int e[N],l[N],r[N];
int idx,m;

//初始化，导致第k个插入的元素的索引为k+1
void init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

//在下标是k的点的右边插入x,对应第k-1个插入元素右侧插入x
void add(int k,int x){
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

//删除第k个点，对应删除第k-1个插入元素
void remove(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    cin>>m;
    init(); //调用初始化！
    while(m--){
        int k,x;
        string op;
        cin>>op;
        if(op == "L"){
            cin>>x;
            add(0,x);
        }else if(op == "R"){
            cin>>x;
            add(l[1],x);
        }else if(op == "D"){
            cin>>k;
            remove(k+1);    //第 k 个插入元素对应的索引为 k + 1
        }else if(op == "IL"){
            cin>>k>>x;
            add(l[k+1],x);
        }else if(op == "IR"){
            cin>>k>>x;
            add(k+1,x);
        }
    }
    for(int i = r[0];i != 1;i = r[i]){
        cout<<e[i]<<" ";
    }
    cout<<endl;
    return 0;
}