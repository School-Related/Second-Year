#include <bits/stdc++.h>

#define rep(i, n, m) for (int i = n; i < m; i++)
#define repr(i, n, m) for (int i = n; i >= m; i--)
#define ll long long
#define pb push_back
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define mx *max_element
#define mn *min_element
#define x4          \
    {               \
        1, -1, 0, 0 \
    }
#define y4          \
    {               \
        0, 0, 1, -1 \
    }
#define x8                        \
    {                             \
        1, 1, 1, -1, -1, -1, 0, 0 \
    }
#define y8                        \
    {                             \
        0, 1, -1, 0, 1, -1, 1, -1 \
    }
#define dirmap map<pair<int, int>, char> dmap = {{{0, 1}, 'R'}, {{0, -1}, 'L'}, {{-1, 0}, 'U'}, {{1, 0}, 'D'}};
#define allin(t) \
    long long t; \
    cin >> t;    \
    while (t--)
#define if_out_range(i, j, m, n) if (i < 0 or j < 0 or i >= m or j >= n)
#define if_in_range(i, j, m, n) if (i >= 0 && j >= 0 && i < m && j < n)
#define read  \
    int t;    \
    cin >> t; \
    while (t--)
#define mod 1000000007
using namespace std;
#define N 301
int a[N][N][10];
int count(int xx, int yy, int x, int y)
{
    xx--;
    yy--;
    x--;
    y--;

    int ans = 0;
    rep(k, 0, 10)
    {
        int temp = a[x][y][k];

        if (xx - 1 >= 0)
            temp -= a[xx - 1][y][k];
        if (yy - 1 >= 0)
            temp -= a[x][yy - 1][k];

        if (xx - 1 >= 0 and yy - 1 >= 0)
            temp += a[xx - 1][yy - 1][k];

        ans += (temp > 0);
    }

    return ans;
}
int main()
{

    int n;
    cin >> n;

    rep(i, 0, n)
        rep(j, 0, n)
    {
        int x;
        cin >> x;
        a[i][j][x - 1] = 1;
    }

    rep(k, 0, 10)
        rep(i, 0, n)
            rep(j, 0, n)
    {
        if (i - 1 >= 0)
            a[i][j][k] += a[i - 1][j][k];

        if (j - 1 >= 0)
            a[i][j][k] += a[i][j - 1][k];

        if (i - 1 >= 0 and j - 1 >= 0)
            a[i][j][k] -= a[i - 1][j - 1][k];
    }

    int q;
    cin >> q;
    rep(i, 0, q)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << count(x1, y1, x2, y2) << endl;
    }
    return 0;
}