#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n;

int main()
{
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i<n;i++){
        bitset <N> b(arr[i]);
        cout<<b.count()<<" ";
    }
    return 0;
}