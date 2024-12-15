#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
//	string s = "hello";
//	cout<<s.length()<<endl;

	vector <int> v(10,1);
	v.resize(10);	//设置数组大小,如果新的大小大于当前大小，则新元素会被默认初始化为0
	
//	for(int i = 0;i<10;i++){
//		v[i] = i;
//		cout<<v[i]<<" "<<endl;
//	}
	v.push_back(2);	//在向量的末尾添加一个新的元素
	for(int i = 0;i<11;i++){
			cout<<v[i]<<" ";
		}
	//cout<<v.size()<<endl;
	return 0;
}
