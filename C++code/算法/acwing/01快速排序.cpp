#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6+10;
int arr[N];
int n;

int main()
{
    cin>>n;
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
