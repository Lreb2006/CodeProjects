#include<iostream>
#include<set>	//set�Ǽ��ϣ��������Ԫ�ظ�����ͬ������Ԫ�ػᰴ�մ�С��������
using namespace std;

int main(void)
{
	set <int> s;	//������Ĵ�������,��������s���治���У�������
	s.insert(2);	//����Ԫ��1,2,3, 
	s.insert(1);
	s.insert(3);
	for(auto p = s.begin();p!=s.end();p++){		//�������ϣ����Զ��Ӵ�С���� 
		cout<<*p<<" ";
	} 
	
	cout<<endl;
	cout<<(s.find(2)!=s.end())<<endl;	//����2�ǲ��Ǽ������Ԫ�أ�<<()<<��������һ����boolֵ����������ھ���1���������ҳɹ� 
	//s.find()����ֵ��һ��ָ�� 
	cout<<(s.find(4)!=s.end())<<endl;	//����0
	
	s.erase(1);		//ɾ��Ԫ��1 
	cout<<(s.find(1)!=s.end())<<endl;
	 
	return 0;
} 
