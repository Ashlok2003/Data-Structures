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

void solve()
{
   
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
