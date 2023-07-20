/*
=================================================================================================
Bellman Ford Algorithms : )
=================================================================================================
The Bellman-Ford algorithm iteratively relaxes the edges in the graph to find the shortest paths.
It guarantees finding the shortest paths even in the presence of negative cycles, and 
it can detect the existence of negative cycles reachable from the source vertex.
==================================================================================================
Conclusion: )
==================================================================================================
  * Bellman Ford Return Single Source Shortest Path (SSSP) in (vertices * No.of Edges) -> (V x E)
    operations when no negative cycles.
  * Bellman Ford resolves Negative cycles (SSSP) in (2 x V x E) operations with negative edges.
  * Thus Complexity is O(V x E)
  * -- Use BFS when no weights.
    -- Use Djikstra's algorithm when there are positive weights.
    -- Use Bellman Ford when there is negative weights and negative cycles.
==================================================================================================
Example Problem Discussed Below --> CSES HIGH SCORE - GRAPHS
*/
/*
    Author: Ashlok :)
    Date: 20-July-2023 (IST)
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
const ll INF = 1e17;
const ll NINF = -1e17;
int n, m;
vector<ll> dist;
vector<triple> edges;
void bellman_ford()
{
    //  Bellman-Ford::Propogation_Phase
    for (int i = 1; i < n; ++i) // (N - 1) times
    {
        for (auto e : edges)
        {
            int u = e.first;
            int v = e.second;
            int d = e.third;
            if (dist[u] == INF)
                continue;
            // Relaxation phase....
            dist[v] = min(dist[v], dist[u] + d);
            dist[v] = max(dist[v], NINF);
        }
    }
    // Checking the negative cycles
    for (int i = 1; i < n; ++i)
    {
        for (auto e : edges)
        {
            int u = e.first;
            int v = e.second;
            int d = e.third;
            if (dist[u] == INF)
                continue;

            dist[v] = max(dist[v], NINF);
            if ((dist[u] + d) < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    edges.resize(n + 1);
    dist.resize(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = triple(u, v, -w);
    }
    for (int i = 2; i <= n; ++i)
    {
        dist[i] = INF;
    }
    bellman_ford();
    if (dist[n] == NINF)
    {
        cout << -1 << '\n';
        return;
    }
    cout << (dist[n] * (-1)) << '\n';
}

int main()
{
    //------------Ashlok(_^_^_)Here--------------//
    //-------------------------------------------//
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //-------------------------------------------//
    ll t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
