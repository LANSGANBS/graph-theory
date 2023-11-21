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

struct data
{
    int v;
    int next;
} edge[100007];

int alist[100007];
int cnt;

void add(int u, int v)
{
    edge[++cnt].v = v;
    edge[cnt].next = alist[u];
    alist[u] = cnt;
    return;
}

int n;
int m;
int res[100007];
queue<int> q;
int now;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        add(v, u);
    }
    for (int i = n; i >= 1; i--)
    {
        if (res[i] != 0)
            continue;
        q.push(i);
        while (!q.empty())
        {
            now = q.front();
            q.pop();
            res[now] = i;
            int next = alist[now];
            while (next)
            {
                int v = edge[next].v;
                if (res[v] == 0)
                {
                    q.push(v);
                }
                next = edge[next].next;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << ' ';
    }
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