#include<iostream>
#include<map>
using namespace std;

int main(void)
{
    //map是键值对，它会自动将所有的键值对按照建从小到大排序，按照ascII码来排序，h的阿斯克码在w之前,第一个字符相同，就比较第二个
    map<string,int> m;
    m["hello"] = 4;
    m["world"] = 3;
    m["caonima"] = 5;
    m["ha"] = 2;
    //如果存在hello，就返回2，否则返回0
    cout<<"hello:"<<m["hello"]<<endl;

    for(auto p = m.begin();p != m.end();p++){
        cout<<p->first<<":"<<p->second<<endl;   //箭头指向指针，获取所有map的键值对
    }
    //获取长度
    cout<<"map's length is:"<<m.size()<<endl;
    //输出3
    return 0;
}

//map相当于一个结构体
// struct map
// {
//     string key;
//     int data;
// }