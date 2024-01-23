// #include <stdio.h>

// int main()
// {
//     // your code goes here
//     int n, q;
//     scanf("%d", &n);
//     scanf("%d", &q);
//     short arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = 0;
//     }

//     while (q--)
//     {
//         int op = 0, lower = 0, upper = 0, count = 0;
//         scanf("%d %d %d", &op, &lower, &upper);

//         if (op == 1)
//         {
//             for (int i = lower; i <= upper; i++)
//             {
//                 if (arr[i] == 0 || arr[i] == 3)
//                 {
//                     count++;
//                 }
//             }
//             printf("%d\n", count);
//         }
//         else
//         {
//             for (int i = lower; i <= upper; i++)
//             {
//                 arr[i]++;
//                 if (arr[i] == 3)
//                 {
//                     arr[i] = 0;
//                 }
//             }
//         }
//     }
//     return 0;
// }

// //#include <ext/pb_ds/assoc_container.hpp>
// //#include <ext/pb_ds/tree_policy.hpp>
// //#include<bits/stdc++.h>
// #include <iomanip>
// #include <iostream>
// #include <algorithm>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <set>
// #include <map>
// #include <unordered_set>
// #include <unordered_map>
// #include <stack>
// #include <queue>
// #include <deque>
// #include <iterator>
// #include <bitset>
// #include <assert.h>
// #include <new>
// #include <sstream>
// #include <time.h>

// // using    namespace __gnu_pbds;
// using namespace std;

// /*** Typedef ***/
// typedef long long ll;
// typedef unsigned long long ull;

// /*** Input ***/
// #define sci1(a) scanf("%d", &a)
// #define sci2(a, b) scanf("%d %d", &a, &b)
// #define scln1(a) scanf("%lld", &a)
// #define scln2(a, b) scanf("%lld %lld", &a, &b)

// /*** Output ***/
// #define pf1(a) printf("%d\n", a)
// #define pf2(a, b) printf("%d %d\n", a, b)
// #define pfln1(a) printf("%lld\n", a)
// #define pfln2(a, b) printf("%lld %lld\n", a, b)

// /*** Loops ***/
// #define foR0(num) for (ll i = 0; i < num; i++)
// #define foR1(num) for (ll i = 1; i <= num; i++)
// #define foRev(num) for (ll i = num - 1; i >= 0; i--)
// #define rep(i, x, n) for (ll i = x, _n = (n); i < _n; ++i)
// #define forIn(arr, num)          \
//     for (ll i = 0; i < num; i++) \
//         cin >> arr[i];
// #define forIn1(arr, num)          \
//     for (ll i = 1; i <= num; i++) \
//         cin >> arr[i];

// /*** Define Values ***/

// #define ff first
// #define ss second
// #define re return
// #define MP make_pair
// #define pb push_back
// #define SZ(x) ((ll)(x).size())

// #define EPS 10E-10
// #define mxx 100005
// #define MOD 1000000007
// #define iseq(a, b) (fabs(a - b) < EPS)
// #define PI 3.141592653589793238462643
// #define HAR 0.57721566490153286060651209

// #define Ceil(a, b) (a + b - 1) / b
// #define gcd(a, b) __gcd(a, b)
// #define min3(a, b, c) min(a, min(b, c))
// #define max3(a, b, c) max(a, max(b, c))
// #define lcm(a, b) ((a) / gcd(a, b)) * (b)
// #define min4(a, b, c, d) min(d, min(a, min(b, c)))
// #define max4(a, b, c, d) max(d, max(a, max(b, c)))
// #define input freopen("input.txt", "rt", stdin)
// #define output freopen("output.txt", "wt", stdout)

// #define all(v) v.begin(), v.end()
// #define memz(u) memset(u, 0, sizeof u)
// #define memn(u) memset(u, -1, sizeof u)
// #define ps(x, y) fixed << setprecision(y) << x
// #define for2D0(n, m)           \
//     for (ll i = 0; i < n; i++) \
//         for (ll j = 0; j < m; j++)
// #define for2D1(n, m)            \
//     for (ll i = 1; i <= n; i++) \
//         for (ll j = 1; j <= m; j++)
// #define Unique(X) (X).resize(unique(all(X)) - (X).begin())
// #define get_pos(c, x) (lower_bound(c.begin(), c.end(), x) - c.begin())
// #define get_pos_up(c, x) (upper_bound(c.begin(), c.end(), x) - c.begin())
// #define IOS                           \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);

// /*** STLs ***/
// typedef vector<ll> vll;
// typedef set<ll> sll;
// typedef multiset<ll> msll;
// typedef queue<ll> qll;
// typedef stack<ll> stll;
// typedef map<ll, ll> mll;
// typedef pair<ll, ll> pll;
// typedef vector<pair<ll, ll>> vpll;
// typedef map<string, ll> msl;
// typedef priority_queue<ll> pql;
// typedef priority_queue<ll, vector<ll>, greater<ll>> npql;

// /*** BitWise Operations
// ///int Set(int N,int pos){return N=N | (1<<pos);}
// ///int reset(int N,int pos){return N= N & ~(1<<pos);}
// ///bool check(int N,int pos){return (bool)(N & (1<<pos));}
// ***/

// /*** Grids
// ///const int fx[] = {+1,-1,+0,+0};
// ///const int fy[] = {+0,+0,+1,-1};
// ///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
// ///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
// ///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
// ///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
// ***/

// /*** Functions
// ///transform(data.begin(), data.end(), data.begin(),[](unsigned char c){ return std::tolower(c); });
// ///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// ///ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
// ///string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
// ///bool sortinrev(const pair<ll,ll> &a,const pair<ll,ll> &b)return (a.first > b.first);
// ///prime[]={2,4,2,4,6,2} //start loop from 29 to do prime factorization
// ///auto it = lower_bound(my_multiset.begin(), my_multiset.end(), 3);
// ///const auto pos = distance(my_multiset.begin(), it);
// ///priority_queue< pll ,vector<pll>,greater<pll> >p;
// ///lower_bound(all(v),r+1)-lower_bound(all(v),l);
// ///cout<<*X.find_by_order(0)<<endl;
// ///cout<<X.order_of_key(-5)<<endl;
// ///set< pair<int,int> >s;
// ///pair<int,int> p={3,2};
// ///auto lb=lower_bound(s.begin(),s.end(),p);
// ///cout<<(*lb).first<<" "<<(*lb).second<<endl;
// ***/

// /*** Some Prints ***/
// #define en cout << '\n';
// #define no cout << "NO" << '\n'
// #define yes cout << "YES" << '\n'

// struct info
// {
//     ll prop, sum[3];
// } tree[mxx * 3];

// void sw1(ll &a, ll &b, ll &c)
// {
//     ll sa = a, sb = b, sc = c;
//     a = sc;
//     b = sa;
//     c = sb;
// }

// void sw2(ll &a, ll &b, ll &c)
// {
//     ll sa = a, sb = b, sc = c;
//     c = sa;
//     a = sb;
//     b = sc;
// }

// void init(ll node, ll b, ll e)
// {
//     if (b == e)
//     {
//         tree[node].sum[0] = 1;
//         return;
//     }
//     ll Left = node * 2;
//     ll Right = node * 2 + 1;
//     ll mid = (b + e) / 2;
//     init(Left, b, mid);
//     init(Right, mid + 1, e);
//     tree[node].sum[0] = tree[Left].sum[0] + tree[Right].sum[0];
// }

// void fun(ll node, ll b, ll e)
// {
//     if (b != e)
//     {
//         tree[node * 2].prop = (tree[node * 2].prop + tree[node].prop) % 3;
//         tree[node * 2 + 1].prop = (tree[node * 2 + 1].prop + tree[node].prop) % 3;
//     }
//     if (tree[node].prop % 3 == 1)
//     {
//         sw1(tree[node].sum[0], tree[node].sum[1], tree[node].sum[2]);
//     }
//     if (tree[node].prop % 3 == 2)
//     {
//         sw2(tree[node].sum[0], tree[node].sum[1], tree[node].sum[2]);
//     }
//     tree[node].prop = 0;
//     return;
// }

// void update(ll node, ll b, ll e, ll i, ll j)
// {
//     if (tree[node].prop)
//         fun(node, b, e);
//     if (i > e || j < b)
//         return;
//     if (b >= i && e <= j)
//     {
//         if (b != e)
//         {
//             tree[node * 2].prop = (tree[node * 2].prop + 1) % 3;
//             tree[node * 2 + 1].prop = (tree[node * 2 + 1].prop + 1) % 3;
//         }
//         sw1(tree[node].sum[0], tree[node].sum[1], tree[node].sum[2]);
//         return;
//     }
//     ll Left = node * 2;
//     ll Right = (node * 2) + 1;
//     ll mid = (b + e) / 2;
//     update(Left, b, mid, i, j);
//     update(Right, mid + 1, e, i, j);
//     tree[node].sum[0] = tree[Left].sum[0] + tree[Right].sum[0];
//     tree[node].sum[1] = tree[Left].sum[1] + tree[Right].sum[1];
//     tree[node].sum[2] = tree[Left].sum[2] + tree[Right].sum[2];
// }

// ll query(ll node, ll b, ll e, ll i, ll j)
// {
//     if (tree[node].prop)
//         fun(node, b, e);
//     if (i > e || j < b)
//         return 0;
//     if (b >= i and e <= j)
//         return tree[node].sum[0];

//     ll Left = node << 1;
//     ll Right = (node << 1) + 1;
//     ll mid = (b + e) >> 1;

//     ll p1 = query(Left, b, mid, i, j);
//     ll p2 = query(Right, mid + 1, e, i, j);

//     return p1 + p2;
// }

// int main()
// {
//     ll tst = 1;
//     // cin>>tst;
//     for (ll tt = 1; tt <= tst; tt++)
//     {
//         // code
//         ll n, m, a, b, c;
//         scanf("%lld %lld", &n, &m);
//         init(1, 1, n);
//         while (m--)
//         {
//             scanf("%lld %lld %lld", &a, &b, &c);
//             if (a == 0)
//                 update(1, 1, n, b + 1, c + 1);
//             else
//                 printf("%lld\n", query(1, 1, n, b + 1, c + 1));
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 1;
// int st[4 * N + 3][3], lazy[4 * N + 3];
// void build(int si, int ss, int se)
// {
//     if (ss > se)
//         return;
//     if (ss == se)
//     {
//         st[si][0] = 1;
//         return;
//     }
//     int mid = (ss + se) >> 1;
//     build(si * 2 + 1, ss, mid);
//     build(si * 2 + 2, mid + 1, se);
//     st[si][0] = st[si * 2 + 1][0] + st[si * 2 + 2][0];
// }
// void rotation(int si)
// {
//     int x0 = st[si][0], x1 = st[si][1], x2 = st[si][2];
//     st[si][0] = x2;
//     st[si][1] = x0;
//     st[si][2] = x1;
// }
// void push(int si, int ss, int se)
// {
//     if (lazy[si] == 0)
//         return;
//     int t = lazy[si];
//     while (t--)
//         rotation(si);
//     if (ss != se)
//     {
//         int mid = (ss + se) >> 1;
//         (lazy[si * 2 + 1] += lazy[si]) %= 3;
//         (lazy[si * 2 + 2] += lazy[si]) %= 3;
//     }
//     lazy[si] = 0;
// }
// void update(int si, int ss, int se, int qs, int qe)
// {
//     push(si, ss, se);
//     if (qs > se || qe < ss)
//         return;

//     if (qs <= ss && qe >= se)
//     {
//         lazy[si] += 1;
//         push(si, ss, se);
//         return;
//     }
//     int mid = (ss + se) >> 1;
//     update(si * 2 + 1, ss, mid, qs, qe);
//     update(si * 2 + 2, mid + 1, se, qs, qe);
//     st[si][0] = st[si * 2 + 1][0] + st[si * 2 + 2][0];
//     st[si][1] = st[si * 2 + 1][1] + st[si * 2 + 2][1];
//     st[si][2] = st[si * 2 + 1][2] + st[si * 2 + 2][2];
// }
// int getcount(int si, int ss, int se, int qs, int qe)
// {
//     push(si, ss, se);
//     if (qs > se || qe < ss)
//         return 0;
//     if (qs <= ss && qe >= se)
//         return st[si][0];
//     int mid = (ss + se) >> 1;
//     return getcount(si * 2 + 1, ss, mid, qs, qe) + getcount(si * 2 + 2, mid + 1, se, qs, qe);
// }
// int main()
// {
//     // your code goes here
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n, m;
//     cin >> n >> m;
//     build(0, 0, n);
//     while (m--)
//     {
//         int c, u, v;
//         cin >> c >> u >> v;
//         u++, v++;
//         if (c == 0)
//         {
//             update(0, 0, n, u, v);
//         }
//         else
//             cout << getcount(0, 0, n, u, v) << '\n';
//     }

//     return 0;
// }
