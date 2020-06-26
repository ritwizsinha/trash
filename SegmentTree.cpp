#include<bits/stdc++.h> 
using namespace std;
class Seg_tree
{

public:
    int n;
    vector<int> l, r, val, delta;
    Seg_tree(int size)
    {
        n = size;
        l.resize(4 * n + 2);
        r.resize(4 * n + 2);
        val.resize(4 * n + 2);
        delta.resize(4 * n + 2);
    }
    void init(int node, int a, int b)
    {
        l[node] = a;
        r[node] = b;
        if (a == b)
            return;
        int mid = (a + b) >> 1;
        init(2 * node, a, mid);
        init(2 * node + 1, mid + 1, b);
    }
    void change(int a, int b, int val)
    {
        ic(1, a, b, val);
    }
    int query(int a, int b)
    {
        return q(1, a, b);
    }
    int search(int node, int value)
    {
        if (l[node] == r[node])
            return l[node];
        prop(node);
        debug(node,l[node],r[node],val[node],val[2*node],val[2*node+1],value);
        if (val[2 * node] + delta[2*node]>= value)
            return search(2 * node, value);
        return search(2 * node+1, value);

    }

private:
    int inside(int l1, int r1, int l2, int r2)
    {
        if (l2 <= l1 && r1 <= r2)
            return 1;
        return 0;
    }
    int intersect(int l1, int r1, int l2, int r2)
    {
        if (r1 < l2 || l1 > r2)
            return 0;
        return 1;
    }
    // This function will change
    void prop(int node)
    {
        delta[2 * node] += delta[node];
        delta[2 * node + 1] += delta[node];
        delta[node] = 0;
    }
    // This function will change
    void update(int node)
    {
        val[node] = max(val[2 * node] + delta[2 * node], val[2 * node + 1] + delta[2 * node + 1]);
    }
    void ic(int node, int a, int b, int val)
    {
        if (!intersect(l[node], r[node], a, b))
            return;
        if (inside(l[node], r[node], a, b))
        {
            // Change this
            delta[node] += val;
            return;
        }
        prop(node);
        ic(2 * node, a, b, val);
        ic(2 * node + 1, a, b, val);
        update(node);
    }
    int q(int node, int a, int b)
    {
        // Change this according to function
        if (!intersect(l[node], r[node], a, b))
            return 0;
        if (inside(l[node], r[node], a, b))
        {
            // Change Here
            return val[node] + delta[node];
        }
        prop(node);
        int valLeft = q(2 * node, a, b);
        int valRight = q(2 * node + 1, a, b);
        debug(node, l[node], r[node], a, b, valLeft, valRight);
        update(node);
        //Change this according to the function
        return max(valLeft, valRight);
    }
};
int main() {
int arr[10] = {1,3,2,6,3,9,121,323,22,32};
int n = 10;
Seg_tree sgt = Seg_tree(n);
sgt.init(1,0,9);

}