#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    //构造
    vector <int> arr(10,1);
    vector <vector<int>> mat(10,vector<int> (10,1));
    //插入
    arr.push_back(1);
    //删除
    arr.pop_back();
    //迭代器遍历
    for(auto p = arr.begin();p != arr.end();p++){
        cout<<*p<<" ";
    }
    cout<<endl;
    //普通遍历
    for(int i = 0;i < 10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //清空
    arr.clear();
    //判空
    cout<<arr.empty()<<endl;
    //改变长度
    arr.resize(11);
    //获取长度
    cout<<arr.size()<<endl;
    return 0;
}