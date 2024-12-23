#include<iostream>
using namespace std;
int isGoodArr();
int main(void)
{
    int t,n;
    cin>>t; //5
    while(t--){
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}