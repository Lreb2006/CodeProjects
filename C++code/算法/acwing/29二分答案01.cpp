// 题目1
// 爱吃香蕉的珂珂
// 珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉
// 警卫已经离开了，将在 h 小时后回来。
// 珂珂可以决定她吃香蕉的速度 k （单位：根/小时)
// 每个小时，她将会选择一堆香蕉，从中吃掉 k 根
// 如果这堆香蕉少于 k 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉
// 珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
// 返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int piles[N];
int n,h;

int bsearch(int n,int h){
    int sum = 0,max_pile = 0;
    for(int i = 0;i<n;i++){
        cin>>piles[i];      //输入n 堆香蕉，第 i 堆中有 piles[i] 根香蕉
        sum += piles[i];    //香蕉总根数 sum
        max_pile = max(max_pile, piles[i]); // 找到最大的香蕉堆max_pile，最快不是一次吃的根数为香蕉总和，而是一次吃最多香蕉的那堆的数量，因为如果是max_pile根每小时，那么每一堆吃的时长就已经是1小时一堆了
    }
    int l = 1,r = max_pile;  //最少1根每小时，最多max_pile根每小时
    
    while(l<r){
        int m = (l+r)/2;    //二分，每小时吃m根
        int num = 0;    //记录吃完要用多少小时

        for (int i = 0; i < n; i++) {
            num += (piles[i] + m - 1) / m; // 计算每堆需要多少小时，(a/b)结果向上取整，如果a和b都是非负数，可以写成(a+b-1)/b
        }

        if(num > h){    //吃完要用的时间大于了规定的时间h，在右边调递归
            l = m+1;
        }else{  //吃完要用的时间小于了规定的时间h，在左边调递归
            r = m;
        }
    }
    return l;   //l和r都行，最后总是l=r
}

int main()
{
    cin>>n>>h;
    cout<<bsearch(n,h)<<endl;
    return 0;
}