#include<iostream>
#include<vector>	//vector������֮һ 
using namespace std;

int main(void)
{
	vector <int> v(10,2);	//��v���������10���ռ䣬ÿ���ռ��ʼֵΪ2
	//�����2ȥ�����ȼ���ÿ���ռ��ʼֵΪ0 
	v.resize(11,3);
	for(auto p = v.begin();p!=v.end();p++){		//���������Զ����������Ŀռ䣬p���Կ���ָ�� 
		cout<<*p<<" ";
	}
	//v.end()������������һ���ռ䣬�������һ���ռ����һ���ռ� 
	return 0;
}
