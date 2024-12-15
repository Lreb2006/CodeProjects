#include<iostream>
#include<vector>	//vector是容器之一 
using namespace std;

int main(void)
{
	vector <int> v(10,2);	//给v数组分配了10个空间，每个空间初始值为2
	//如果吧2去掉，等价于每个空间初始值为0 
	v.resize(11,3);
	for(auto p = v.begin();p!=v.end();p++){		//迭代器，自动调整遍历的空间，p可以看做指针 
		cout<<*p<<" ";
	}
	//v.end()不是数组的最后一个空间，而是最后一个空间的下一个空间 
	return 0;
}
