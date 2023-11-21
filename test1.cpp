#include <bits/stdc++.h>
#define endl '\n'
#define buff ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
/*
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize(3)
*/
using namespace std;
#define ll long long
#define int ll

// 堆排序实现
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 计数排序辅助函数声明
void counting_sort_by_digit(vector<int> &arr, int exp);
// 计数排序实现
void counting_sort(vector<int> &arr)
{
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);
    vector<int> output(arr.size());
    for (int num : arr)
        count[num]++;
    for (int i = 1; i <= max_val; i++)
        count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    arr = output;
}

// 基数排序实现
void radix_sort(vector<int> &arr)
{
    int max_num = *max_element(arr.begin(), arr.end());
    int exp = 1;

    while (max_num / exp > 0)
    {
        counting_sort_by_digit(arr, exp);
        exp *= 10;
    }
}
void counting_sort_by_digit(vector<int> &arr, int exp)
{
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = output;
}

signed main()
{
    setlocale(LC_ALL, ""); // 设置本地环境，以支持宽字符

    // 测试数组
    vector<int> arr = {64, 25, 12, 22, 11};
    wcout << L"原始数据: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    // 堆排序
    vector<int> heap_sort_arr = arr;
    heap_sort(heap_sort_arr);
    wcout << L"堆排序结果: ";
    for (int num : heap_sort_arr)
        cout << num << " ";
    cout << endl;

    // 计数排序
    vector<int> counting_sort_arr = arr;
    counting_sort(counting_sort_arr);
    wcout << L"计数排序结果: ";
    for (int num : counting_sort_arr)
        cout << num << " ";
    cout << endl;

    // 基数排序
    vector<int> radix_sort_arr = arr;
    radix_sort(radix_sort_arr);
    wcout << L"基数排序结果: ";
    for (int num : radix_sort_arr)
        cout << num << " ";
    cout << endl;
}