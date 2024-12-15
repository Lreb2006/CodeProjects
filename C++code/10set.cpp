#include<iostream>
#include<set>	//set是集合，它里面的元素各不相同，而且元素会按照从小到大排序
using namespace std;

int main(void)
{
	set <int> s;	//跟数组的创建相似,但集合中s后面不能有（参数）
	s.insert(2);	//插入元素1,2,3, 
	s.insert(1);
	s.insert(3);
	for(auto p = s.begin();p!=s.end();p++){		//遍历集合，会自动从大到小排序 
		cout<<*p<<" ";
	} 
	
	cout<<endl;
	cout<<(s.find(2)!=s.end())<<endl;	//查找2是不是集合里的元素，<<()<<括号里整一个是bool值，如果不等于就是1，表明查找成功 
	//s.find()返回值是一个指针 
	cout<<(s.find(4)!=s.end())<<endl;	//返回0
	
	s.erase(1);		//删除元素1 
	cout<<(s.find(1)!=s.end())<<endl;
	 
	return 0;
} 
