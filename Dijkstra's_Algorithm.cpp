// Single Sources Shortest Path Problem :)
// No Doubt BFS is the best approach but when handling the case of unweighted edges 
// It fails to accomplish the approripriate solution.
// Dijkstra's_Algorithm is not as Efficient as BFS but Correct :)
/*
==================================================================================
                  It is the Three Step Algorithm
==================================================================================
          Starting with the vertex closest to the start vertex
* For Each vertex : Determine the current path as the shortest
* Optimize the length of all the paths through this vertex
* Given Nodes [1.. N] they will greedily Processed in order of how close the
    actually are.
* For Processing we optimised all the paths passing through the said node.
    Thus the Time Complexity: O(V * V)
===================================================================================
Limitation of Dijkstra's Algorithm
  -> We Greedily Process and never look back.
  -> Doesn't work with Negative edges (But can be handeled with DP :))
===================================================================================
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
const ll MOD = 1e9 + 7;
const ll INF = 1e17;
const ll MAX = 1e5 + 10;
/*=============================================================================================================*/
struct triple
{
public:
    int first, second, third;
    triple(int first_ = 0, int second_ = 0, int third_ = 0) : first(first_), second(second_), third(third_) {}
};
/*=============================================================================================================*/
/* CSES [GRAPH - SHORTEST PATH - I] Question is Solves using this Algorithm */

vector<vector<pair<int, int>>> G;
vector<ll> dist;
int n, m;

void dijkstra()
{
    dist.assign(n + 1, INF);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll d = pq.top().first;  // Current Distance
        ll u = pq.top().second; // Current Node
        pq.pop();
        // Since already the current node distance is better than the obtained
        if (dist[u] < d)
            continue;
        for (auto e : G[u])
        {
            ll v = e.first;  // Child Node
            ll c = e.second; // Child Node Distance
            if (dist[v] <= (c + d))
                continue;
            else
            {
                dist[v] = (c + d); // since we found the better distance, we are updating it :)
                // Pushing all the directed connected components in the pq.
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    G.resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
    dijkstra();
    for (int i = 1; i <= n; ++i)
        cout << dist[i] << " \n"[i == n];
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}
