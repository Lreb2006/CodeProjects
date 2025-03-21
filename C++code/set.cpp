#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    //构造
    set <int> s;
    //插入
    s.insert(3);
    s.insert(1);
    s.insert(2);
    //迭代器遍历
    for(auto p = s.begin();p != s.end();p++){
        cout<<*p<<" ";
    }
    cout<<endl;
    //删除
    s.erase(1);
    //查找
    cout<<(s.find(1) != s.end())<<endl;
    //判断元素是否存在
    cout<<s.count(1)<<endl;
    //获取长度
    cout<<s.size()<<endl;
    //清空
    s.clear();
    //判空
    cout<<s.empty()<<endl;
    return 0;
}