#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n;

void sortArr(int arr[],int n){
    int even = 0,odd = 1,x = n-1;   //x一直在n-1位置，对even和odd发货
    while(even<n&&odd<n){
        if(arr[x]%2 == 0){
            swap(arr[even],arr[x]);
            even += 2;
        }else if(arr[x]%2 == 1){
            swap(arr[odd],arr[x]);
            odd += 2;
        }
    }
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    sortArr(arr,n);
    return 0;
}