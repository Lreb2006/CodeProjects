#include<iostream>
using namespace std;

int main(void){
    int n;
    long long sum = 0;
    long long suml = 0;
    int cnt = 0;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cnt++;
        sum = sum + cnt;
        suml = suml + sum;
    }
    cout<<suml<<endl;
    return 0;
}