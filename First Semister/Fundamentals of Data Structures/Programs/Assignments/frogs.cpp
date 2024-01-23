#include <bits/stdc++.h>
using namespace std;
#define ll long long

void qs(ll z[], ll pos[], int l, int r)
{
    int mid = z[(l + r) / 2];
    int i = l, j = r;
    while (i < j)
    {
        while (z[i] < mid)
            i++;
        while (z[j] > mid)
            j--;
        if (i <= j)
        {
            swap(z[i], z[j]);
            swap(pos[i], pos[j]);
            i++;
            j--;
        }
    }
    if (i < r)
        qs(z, pos, i, r);
    if (j > l)
        qs(z, pos, l, j);
}

int main()
{
    long long n, k, p;
    cin >> n >> k >> p;

    long long a[n + 1];
    long long z[n + 1];
    ;
    ll q = k, st = 1;
    ll pos[n + 1];
    pos[0] = 0;
    z[0] = 0;
    ll e, f;

    for (long long i = 1; i <= n; i++)
    {
        cin >> z[i];
        pos[i] = i;
    }

    qs(z, pos, 1, n);

    //	for(int i = 1; i <= n; i++)
    //	{
    //		cout << z[i] << " ";
    //	}
    //
    //	cout << endl;
    //
    //	for(int i = 1; i <= n; i++)
    //	{
    //		cout << pos[i] << " ";
    //	}

    ll cc[n + 1];
    cc[0] = 0;

    for (int i = 1; i <= n; i++)
        cc[pos[i]] = i;

    long long b[n + 1];
    b[0] = 0;
    b[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (z[i] - z[i - 1] <= k)
        {
            b[i] = b[i - 1];
        }
        else
        {
            b[i] = b[i - 1] + 1;
        }
    }

    for (ll o = 1; o <= p; o++)
    {

        cin >> e >> f;
        ll c = cc[e], d = cc[f];
        if (c > d)
            swap(c, d);

        if (b[c] - b[d] == 0)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
}