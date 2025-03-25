#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001; 
int arr[MAXN]; 
int n; // 数组实际长度

// 交换数组中两个元素的值
void swap(int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}


// 向上调整大根堆
// i 需要调整的元素下标
// 从i位置开始，不断与其父节点比较，若较大则交换，直到根节点或父节点更大
void heapInsert(int i) {
    while (arr[i] > arr[(i - 1) / 2]) { // 当当前节点大于父节点时继续
        swap(i, (i - 1) / 2); // 交换当前节点与父节点
        i = (i - 1) / 2; // 更新当前节点位置为父节点位置
    }
}


// 向下调整大根堆
// i 需要调整的节点下标
// size 堆当前的大小
// 从i位置开始，与其较大的子节点比较，若子节点更大则交换，直到叶子节点或无需调整
void heapify(int i, int size) {
    int l = i * 2 + 1; // 左子节点下标
    while (l < size) { // 当左子节点存在时循环
        // 选择较大的子节点（若右子节点存在且更大则选右）
        int best = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;
        best = arr[best] > arr[i] ? best : i; // 比较当前节点与较大子节点
        if (best == i) break; // 若当前节点已经是最大，停止调整
        swap(best, i); // 否则交换当前节点与较大子节点
        i = best; // 更新当前节点位置
        l = i * 2 + 1; // 更新左子节点下标
    }
}


// 堆排序方法1（自顶向下建堆）
// 时间复杂度：O(n logn)
// 1. 依次插入元素，建立大根堆（O(n logn)）
// 2. 依次弹出堆顶最大值并调整堆（O(n logn)）
void heapSort1() {
    // 建立堆（逐个插入）
    for (int i = 0; i < n; i++) {
        heapInsert(i);
    }
    int size = n;
    // 依次弹出堆顶元素到数组末尾
    while (size > 1) {
        swap(0, --size); // 将堆顶元素与末尾元素交换，堆大小减一
        heapify(0, size); // 调整堆顶元素
    }
}

// 堆排序方法2（自底向上建堆）
// 时间复杂度：O(n logn)
// 1. 从最后一个非叶子节点开始调整，建立大根堆（O(n)）
// 2. 依次弹出堆顶最大值并调整堆（O(n logn)）
void heapSort2() {
    // 建立堆（从最后一个非叶子节点开始调整）
    for (int i = n - 1; i >= 0; i--) {
        heapify(i, n);
    }
    int size = n;
    // 依次弹出堆顶元素到数组末尾
    while (size > 1) {
        swap(0, --size); // 将堆顶元素与末尾元素交换，堆大小减一
        heapify(0, size); // 调整堆顶元素
    }
}

int main() {
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    // 选择排序方法（这里使用heapSort2作为示例）
    // heapSort1();
    heapSort2();
    
    for (int i = 0; i < n - 1; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1]<<endl;   // 最后一个不打印空格
    return 0;
}