/*
================================================================================
                  Relaxing through a Node K
================================================================================
Given two vertices I and J; Given a third Vertex K
Relaxing Through K means.
1).  Compare Dist[i,j] with Dist[i, k] + Dist[k, j]
2).  If second is better; we Optimize Dist[i, j] as Dist[i, k] + Dist[k, j].
3).  In other words, if we benfits from visiting k rather than directly going to 
      J from I - we do the same
This is called Relaxing Through Node K.
================================================================================
CSES - PROBLEM SHROTEST PATH - II
Implementing The Floyd-Warshall Algorithm [All Source Shortest Path] :)
*/
/*
    Author: Ashlok :)
    Date: 21-July-2023 (IST)
    Quote: “It is never too late to be what you might have been.” :)
*/
/*-------------------------------------------Directives------------------------------------------------------- */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order && order_by_key
/*-------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ull;
#define int long long int
/* Common bits techniques */
#define set(n, i) ((n) |= (1 << (i)))
#define unset(n, i) ((n) &= ~(1 << (i)))
#define toggle(n, i) ((n) ^= (1 << (i)))
#define check(n, i) (((n) & (1 << (i))) != 0)
#define rangeoff(n, l, r) ((n) |= (1 << ((r) + 1)) - (1 << (l)))
#define rangeon(n, l, r) ((n) &= (~((1 << ((r) + 1)) - (1 << (l)))))

template <typename T>
void print(const vector<T> &vec)
{
    for_each(vec.begin(), vec.end(), [](T x)
             { cout << x << " "; });
    cout << '\n';
}
#define range(x) (x).begin(), (x).end()
#define forn(i, x, n) for (int i = x; i < n; ++i)
/*---------------------------------------------Constants-------------------------------------------------------*/
const int INF = 1e15;
const int NINF = -1e15;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 10;
/*=============================================================================================================*/
struct triple
{
public:
    int first, second, third;
    triple(int first_ = 0, int second_ = 0, int third_ = 0) : first(first_), second(second_), third(third_) {}
};
/*=============================================================================================================*/
vector<vector<int>> G;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    G.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        G[i].resize(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            G[i][j] = G[j][i] = INF;
        }
    }
    for (int i = 0; i < m; ++i)
    {

        int u, v, c;
        cin >> u >> v >> c;
        G[u][v] = G[v][u] = min(G[u][v], c);
    }
    //  Floyd - Warshall implementation : Time Complexity: O(|V| ^ 3)
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // Comprarision has been done between (direct root_path, undirected root_path)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    for (int i = 0; i < q; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (G[u][v] == INF)
            G[u][v] = -1;
        cout << G[u][v] << '\n';
    }
}

int32_t main()
{
    //------------Ashlok(_^_^_)Here--------------//
    //-------------------------------------------//
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------------------//
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
