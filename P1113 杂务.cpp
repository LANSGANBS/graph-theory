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
int n, l, t, ans[10005], maxans;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> i >> l;
        int tmp = 0;
        while (cin >> t && t)
            tmp = max(ans[t], tmp);
        ans[i] = tmp + l;
        maxans = max(ans[i], maxans);
    }
    cout << maxans << endl;
    // wout <<L" "<<endl;
    // cout << R"( )" << endl;
}

signed main()
{
    // setlocale(LC_ALL, "");
    buff;
    int t = 1;
    //	cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}