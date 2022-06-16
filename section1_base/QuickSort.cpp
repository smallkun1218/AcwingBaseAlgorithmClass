#include "iostream"
#include "cstdio"
#include "cstdlib"

using namespace std;

#define N 1e5 + 10

// #define LOCAL

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;//函数结束标志

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    //划分左右边界
    while (i < j)
    {
        do i ++ ; while (q[i] < x);//寻找大于x的下标
        do j -- ; while (q[j] > x);//寻找小于x的下标
        if (i < j) swap(q[i], q[j]);//交换位置
    }
    //递归左右区间
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}


int main(){
#ifdef LOCAL
//重定向输入 注释宏定义LOCAL 取消重定向

    freopen("input.txt", "r", stdin);

#endif

    int n;
    int q[(int)N];
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }//获取输入

    quick_sort(q, 0, n-1);


    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    } //输出

    return 0;
}