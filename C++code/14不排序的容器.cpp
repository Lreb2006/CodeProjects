#include<iostream>
#include<unordered_map>     //不排序的map（键值对）
#include<unordered_set>     //不排序的set（集合）
using namespace std;

int main(void)
{
    //unordered_map和unordered_set这两个其实就是不会排序的map和set，它们省去了排序的过程，如果刷题的时候超时了，可以使用这两个
    unordered_map <string,int> m;
    unordered_set <int> s;
    s.insert(5);
    s.insert(6);
    s.insert(7);
    m["hello"] = 1;
    m["world"] = 2;
    m["caonima"] = 3;
    //实际上是按照哈希表顺序输出的
    for(auto p = s.begin();p!=s.end();p++){
        cout<<*p<<endl;
    }
    for(auto p = m.begin();p!=m.end();p++){
        cout<<p->first<<" "<<p->second<<endl;
    }
    return 0;
}