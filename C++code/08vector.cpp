#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
//	string s = "hello";
//	cout<<s.length()<<endl;

	vector <int> v(10,1);
	v.resize(10);	//���������С,����µĴ�С���ڵ�ǰ��С������Ԫ�ػᱻĬ�ϳ�ʼ��Ϊ0
	
//	for(int i = 0;i<10;i++){
//		v[i] = i;
//		cout<<v[i]<<" "<<endl;
//	}
	v.push_back(2);	//��������ĩβ���һ���µ�Ԫ��
	for(int i = 0;i<11;i++){
			cout<<v[i]<<" ";
		}
	//cout<<v.size()<<endl;
	return 0;
}
