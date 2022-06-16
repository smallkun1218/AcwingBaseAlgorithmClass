#include "iostream"
#include "algorithm"

using namespace std;

#define N 1000010

#define LOCAL
int q[N], tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return ;

    int mid = l + r >> 1;

    merge_sort(q, l, mid),merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];

    while(i <= mid) tmp[k++] =  q[i++];
    while(j <= r) tmp[k++] = q[j++];

    for(i = l, j=0; i <= r; i++, j++) q[i] = tmp[j];
}

int main(){
#ifdef LOCAL
//重定向输入 注释宏定义LOCAL 取消重定向

    freopen("input.txt", "r", stdin);

#endif

    int n, index;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    merge_sort(q, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", q[i]);
    }
    


    return 0;
}