// INCLUDES
#include <bits/stdc++.h>
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//DEFINES
#define MAX 1000001
#define pii pair<int, int>
#define c1 __builtin_popcount
#define F first
#define S second
#define all(s) begin(s), end(s)
#define MIN3POS(a, b, c) (a) = < (b) ? ((a) = < (c) ? 1 : 3) : ((b) = < (c) ? 2 : 3)
#define MAX3POS(a, b, c) (a) >= (b) ? ((a) >= (c) ? 1 : 3) : ((b) >= (c) ? 2 : 3)
#define endl '\n'
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
//NAMESPACES
using namespace __gnu_pbds;
using namespace std;
vector<string> vec_splitter(string s)
{
    s += ',';
    vector<string> res;
    while (!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v)
{
    os << "[";
    for (auto it : v)
    {
        os << it;
        if (it != *v.rbegin())
            os << ", ";
    }
    os << "]";
    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const map<T, S> &v)
{
    for (auto it : v)
        cout << it.first << " : "
             << it.second << "\n";

    return os;
}
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v)
{
    os << "(";
    cout << v.first << ", "
         << v.second << ")";
    return os;
}

// D
int maxSubArraySum(vector<int> &a)
{
    int size = a.size();
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    FOR(i, 0, n)
        cin >> v[i];
    vector<int> odd;
    int sum = 0;
    FOR(i, 0, n) {
    if (i & 1)
        odd.push_back(v[i]-v[i-1]);
    else sum+=v[i];
    }
    int ans = maxSubArraySum(odd);
    odd.clear();
    FOR(i,0,n) if(i&1) {
        if(i+1<n) {
            odd.push_back(v[i]-v[i+1]);
        }
    }
    int ans2 = maxSubArraySum(odd);
    cout<<max({sum+ans,sum+ans2,sum})<<endl;
}
int32_t main()
{
    IOS int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
// Use emplace back in place of pushback
// Use tie function , for object destructuring