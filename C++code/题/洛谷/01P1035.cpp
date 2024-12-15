#include<iostream>
using namespace std;

// int main(void)
// {
//     const int N = 1e5+5;
//     double sum[N], a[N];    //要用double
//     int k;
//     sum[0] = 0;
//     cin>>k;
//     for(int i = 1;i<N;i++){
//         a[i] = 1.0/i;       // 使用浮点数除法
//         sum[i] = sum[i-1] + a[i];
//         if(sum[i]>k){
//             cout<<i<<endl;
//             break;
//         }
//     }
//     return 0;
// }

int main(void)
{
    double sn = 0;
    int k,n = 0;
    cin>>k;
    while(sn<=k){
        n++;
        sn = sn+1.0/n;
    }
    cout<<n;
    return 0;
}