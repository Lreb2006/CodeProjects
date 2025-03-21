#include<bits/stdc++.h>
using namespace std;

int main() {
    double n;
    cin >> n;  // 输入要求三次方根的数
    
    // 定义二分查找的左右边界
    double l = -10000, r = 10000;  
    
    // 当左右边界差距大于误差范围时继续循环
    // 1e-8 是一个很小的数，用来控制精度
    while (r - l > 1e-8) {  
        double mid = (l + r) / 2;  // 取中间值
        
        // 计算中间值的三次方
        double cube = mid * mid * mid;
        
        // 如果三次方大于目标值n，说明mid太大了
        if (cube > n) {
            r = mid;  // 将右边界缩小到mid
        } else {
            l = mid;  // 否则将左边界增大到mid
        }
    }
    
    // 输出结果，保留6位小数
    printf("%.6lf\n", l);  
    return 0;
}