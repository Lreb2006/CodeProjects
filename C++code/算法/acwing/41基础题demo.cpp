#include<bits/stdc++.h>
using namespace std;

const int N = 6;
vector<int> v(6);
int n;

int main()
{
    cin>>n;
    for(int i = pow(10,n-1);i<=pow(10,n)-1;i++){
        int sum = 0;
        int temp = i;
        while(temp>0){
            int num = temp%10;
            sum += pow(num,n);
            temp /= 10;
        }
        if(sum == i){
            v.push_back(i);
        }
    }
    if(!v.empty()){
        for(int i = 0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    return 0;
}