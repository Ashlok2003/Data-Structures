// SPOJ - Horrible Queries Question 
// Solution to understand Range Update Queries using Lazy Propogation on Segment Tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class SegmentTree
{
private:
    vector<T> seg;
    vector<T> vec;
    vector<T> lazy;

public:
    SegmentTree(T n, vector<T> &arr)
    {
        lazy.resize(4 * n + 1, 0);
        seg.resize(4 * n + 1, 0);
        vec = arr;

        build(0, 0, n - 1);
    }

    void build(T node, T l, T r)
    {
        if (l == r)
        {
            seg[node] = vec[l];
            return;
        }
        T mid = (l + r) >> 1;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);

        seg[node] = (seg[2 * node + 1] + seg[2 * node + 2]);
    }

    void propagate(T node, T start, T end)
    {
        seg[node] += lazy[node] * (end - start + 1);
        if (start != end)
        {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void update(T node, T start, T end, T l, T r, T val)
    {
        if (lazy[node] != 0)
            propagate(node, start, end);

        if (start > r || end < l)
            return;

        if (start >= l && end <= r)
        {
            lazy[node] = val;
            propagate(node, start, end);
            return;
        }

        T mid = (start + end) >> 1;
        update(2 * node + 1, start, mid, l, r, val);
        update(2 * node + 2, mid + 1, end, l, r, val);

        seg[node] = (seg[2 * node + 1] + seg[2 * node + 2]);
    }

    T query(T node, T start, T end, T l, T r)
    {
        if (lazy[node] != 0)
            propagate(node, start, end);

        if (end < l || r < start)
            return 0;

        if (l <= start && end <= r)
            return seg[node];

        T mid = (start + end) >> 1;
        T left = query(2 * node + 1, start, mid, l, r);
        T right = query(2 * node + 2, mid + 1, end, l, r);
        return (left + right);
    }
};

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        vector<ll> vec(n, 0);

        SegmentTree<ll> s(n, vec);
        while (q--)
        {
            ll x, l, r;
            cin >> x >> l >> r;
            if (x == 0)
            {
                ll value;
                cin >> value;
                s.update(0, 0, n - 1, l - 1, r - 1, value); 
            }
            else if (x == 1)
            {
                cout << s.query(0, 0, n - 1, l - 1, r - 1) << '\n'; 
            }
        }
    }

    return 0;
}
