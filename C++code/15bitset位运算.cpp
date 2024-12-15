#include<iostream>
#include<bitset>
using namespace std;

int main(void)
{
    //bitset类似一个字符数组，但是它是从二进制的低位到高位依次为b[0],b[1]...，所以按照b[i]的方式输出和直接输出b的结果相反
    bitset <5> a;       //5表示5个二进制位，初始化为0
    bitset <5> b(19);   //19的二进制是10011，所以b[0]=1,b[1]=1,b[2]=0,b[3]=0,b[4]=1
    cout<<b<<endl;
    for(int i = 0;i<5;i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    
    bitset <6> c("111");      //111为字符串，字符串只能是0或1，输出结果是000111，不做进制转换 

    cout<<a<<endl;
    cout<<c<<endl;
    
    cout<<"是否存在1:"<<b.any()<<endl;      //判断是否存在1，有返回1，没有返回0
    cout<<"是否不存在1:"<<b.none()<<endl;   //判断是否不存在1，不存在返回1，存在返回0
    cout<<"1的个数为:"<<b.count()<<endl;
    cout<<"元素个数为:"<<b.size()<<endl;
    cout<<"下标为i的元素是不是1:"<<b.test(0)<<endl;
    
    cout<<"把下标为i的元素变为1:"<<b.set(2)<<endl;      //10111
    cout<<"第i位归零"<<b.reset(2)<<endl;        //10011
    cout<<"所有位归零:"<<b.reset()<<endl;   //00000
    cout<<"第i位取反:"<<b.flip(2)<<endl;        //00100
    cout<<"所有位取反:"<<b.flip()<<endl;        //11011
    
    bitset <5> e(19);
    unsigned long d = e.to_ulong();
    cout<<d<<endl;
    return 0;
}