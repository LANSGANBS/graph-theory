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

void hannuota(int n, char begin, char end, char temp)
{
    if (n == 1)
    {
        cout << n << ": " << begin << " -> " << end << endl;
    }
    else
    {
        hannuota(n - 1, begin, temp, end);
        cout << n << ": " << begin << " -> " << end << endl;
        hannuota(n - 1, temp, end, begin);
    }
}

void moveHanoiTower(int num, char begin, char temp, char end)
{
    hannuota(num, begin, end, temp);
}

signed main()
{
    int num;
    char begin, temp, end;
    cin >> num >> begin >> temp >> end;
    moveHanoiTower(num, begin, temp, end);
}