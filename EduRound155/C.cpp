#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll long long int
#define MAXN 105
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
const int maxn = 1e5 + 10;
const int Mod = 998244353;
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
vector<ll> fp(1e6 + 1);
void SieveOfE()
{
    ll cnt = 0;
    vector<bool> prime(1e6 + 1, true);
    prime[0] = prime[1] = false;
    fp[0] = fp[1] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        if (prime[i])
        {
            for (int j = 2 * i; j <= 1e6; j += i)
            {
                prime[j] = 0;
            }
        }
    }
    for (int i = 2; i <= 1e6; i++)
    {
        if (prime[i])
        {
            fp.push_back(i);
        }
    }
}
void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0, ans = 0, comb = 1, fact = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            ans += cnt;
            comb = (comb % Mod * (cnt + 1) % Mod) % Mod;
            cnt = 0;
        }
    }
    if (cnt != 0)
    {
        ans += cnt;
        cnt++;
        comb = (comb % Mod * cnt % Mod) % Mod;
    }
    for (int i = 1; i <= ans; i++)
    {
        fact = ((fact % Mod) * (i % Mod)) % Mod;
    }
    comb = ((fact % Mod) * (comb % Mod)) % Mod;
    cout << ans << " " << comb << '\n';
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SieveOfE();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}