#include<iostream>
#include<utility>
using namespace std;

const int N = 1e5+10;
int arr[N];
int n;

void quickSort(int l,int r){
    if(l>=r){
        return; // 只是结束函数的执行，不返回任何值
    }
    int x = arr[l];
    int a = l,b = r;
    int i = l;
    while(i <= b){
        if(arr[i] < x){
            swap(arr[a],arr[i]);
            a++;
            i++;
        }else if(arr[i] == x){
            i++;
        }else if(arr[i] > x){
            swap(arr[i],arr[b]);
            b--;
        }
    }
    int left = a,right = b;
    quickSort(l,left-1);
    quickSort(right+1,r);
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(0,n-1);
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}