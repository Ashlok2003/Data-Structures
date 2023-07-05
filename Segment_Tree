#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
class SegmentTree
{
private:
    vector<T> seg;
    vector<T> vec;

public:
    SegmentTree(T n, vector<T> &arr)
    {
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

        seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
    }

    void update(T node, T l, T r, T pos, T val)
    {
        if (l == r)
        {
            vec[l] = val;
            seg[node] = val;
            return;
        }
        T mid = (l + r) >> 1;
        if (l <= pos && pos <= mid) // left Part of Tree
            update(2 * node + 1, l, mid, pos, val);
        else // Right Part of Tree.
            update(2 * node + 2, mid + 1, r, pos, val);

        seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
    }

    T query(T node, T start, T end, T l, T r)
    {
        if (end < l || r < start)
            return INT_MAX;

        if (l <= start && end <= r)
            return seg[node];

        T mid = (start + end) >> 1;
        T left = query(2 * node + 1, start, mid, l, r);
        T right = query(2 * node + 2, mid + 1, end, l, r);
        return min(left, right);
    }
};
int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> vec(n);
    for (auto &x : vec)
        cin >> x;

    SegmentTree<ll> s(n, vec);
    while (q--)
    {
        ll x, l, r;
        cin >> x >> l >> r;
        if (x == 1)
        {
            s.update(0, 0, n - 1, l - 1, r); // l-1 to convert 1-based indexing to 0-based indexing
        }
        else if (x == 2)
        {
            cout << s.query(0, 0, n - 1, l - 1, r - 1) << '\n'; // l-1 and r-1 for the same reason as above
        }
    }

    return 0;
}
