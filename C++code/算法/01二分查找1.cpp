#include<bits/stdc++.h>
using namespace std;
//在有序数组中确定num存在还是不存在
bool exist(vector<int> arr, int num) {      //返回布尔值要用bool声明
    if (arr.empty()) {
        return false;
    }
    int l = 0, r = arr.size() - 1, m = 0;   //l和r是下标，所以r需要-1
    while (l <= r) {
        m = (l + r) / 2;
        if (arr[m] == num) {
            return true;
        } else if (arr[m] > num) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return false;
}
int main(void)
{
    vector<int> arr = {1,12,25,33,38,46,51,64,74,85,95};
    sort(arr.begin(),arr.end());
    cout<<(exist(arr,95)!=0)<<endl;

    return 0;
}
