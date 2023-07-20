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
/*---------------------------------------------Constants-------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const int MAX = 3e5 + 5;
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};
/*=============================================================================================================*/
struct triple
{
public:
    int first, second, third;
    triple(int first_ = 0, int second_ = 0, int third_ = 0) : first(first_), second(second_), third(third_) {}
};
/*=============================================================================================================*/
/* Sparse Table - Range Minumum Queries :)

Time Complexity : O(N * Log(N) + Q(1)) Queries
Space Complexity:

    Storing the minimum in the ranges of(lengths 2 ^ K)

Arr[] =  {1,2,3,5,6,7,1,3,5}
len(1) : [1,2,3,5,6,7,1,3,5] minimum in length 1
len(2) : [1,2,3,5,7,1,1,3,x]
len(4) : [1,2,3,1,1,1,x,x,x]
len(8) : [1,1,1,x,x,x,x,x,x]

Matrix[N][Log2(N)] -- > Matrix[i][j] = Minima of range [(i) --> to --> (2^j - 1)]


*/
const int N = 1e5 + 9;
int table[N][18];
void build(int n, const vector<ll> &vec)
{
    for (int i = 1; i <= n; ++i)
        table[i][0] = vec[i];

    for (int k = 1; k < 18; ++k)
        for (int i = 1; (i + (1 << k) - 1) <= n; ++i)
            table[i][k] = min(table[i][k - 1], table[i + (1 << (k - 1))][k - 1]);
}
int query(int l, int r)
{
    int k = 31 - __builtin_clz(r - l + 1);
    return min(table[l][k], table[r - (1 << k) + 1][k]);
}
/*=============================================================================================================*/
void solve()
{
    ll n, q;
    cin >> n;
    vector<ll> vec(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> vec[i];
    build(n, vec);
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        cout << (query(x + 1, y + 1)) << '\n';
    }
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
