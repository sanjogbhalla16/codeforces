#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MAXN 105
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
const int maxn = 1e5 + 10;
long long BinExpRecur(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = BinExpRecur(a, b / 2);
    if (b & 1)
    {
        return (a * ((res * res) % M)) % M;
    }
    else
    {
        return (res * res) % M;
    }
}
long long mod(long long x)
{
    return ((x % M + M) % M);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}
ll CountDiv(ll n)
{
    ll cnt = 0;
    // O(sqrt(n));
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++; // i is a factor
            //(n/i) is also a factor
            if (i != n / i)
                cnt++;
        }
    }
    return cnt;
}
void SieveOfE(ll n)
{
    ll cnt = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 1; i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
    cout << '\n';
}
bool isPerfectSquare(ll x)
{
    // Find floating point value of
    // square root of x.
    // if(ceil(sqrt(x)) == floor(sqrt(n))){ return true;}
    // else false;
    if (x >= 0)
    {

        long long sr = sqrt(x);

        // if product of square root
        // is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    // return 0;

    // first make the map of powers of 2
    map<ll, ll> ma, val;
    ma[0] = 1ll;
    for (ll i = 1ll; i < 30; i++)
    {
        ma[i] = ma[i - 1ll] * 2ll;
    }
    // for (auto x : ma)
    // {
    //     cout << x.first << " " << x.second << '\n';
    // }
    ll n, a, b;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a >> b;
        // cout<<n<<endl;
        // cout<<a<<b<<endl;
        if (a == 1)
        {
            val[ma[b]]++;
        }
        else
        {

            for (ll i = 30; i >= 0; i--)
            {
                if (b >= ma[i] and b != 0)
                {
                    if (val.count(ma[i]))
                    {
                        b -= min(b / ma[i], val[ma[i]]) * ma[i];
                    }
                }
            }
            if (b == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        if (i == n - 1)
            return 0;
    }
    return 0;
}