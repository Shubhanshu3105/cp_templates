#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll binExp(ll a, ll b, ll modulo)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res *= a;

        a = a * a;
        b = b >> 1;
        a = a % modulo;
        res = res % modulo;
    }
    return res;
}
ll invModulo(ll a, ll modulo)
{
    return binExp(a, modulo - 2, modulo);
}

struct Hashing
{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 1000000007,1000000013};
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a)
    {
        s = a;
        n = s.size();
        primes = hashPrimes.size();
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        for (int i = 0; i < primes; i++)
        {
            powersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1LL;
            for (int j = 1; j <= n; j++)
            {
                powersOfBase[i][j] = (powersOfBase[i][j - 1] * base) % hashPrimes[i];
            }
            inversePowersOfBase[i].resize(n + 1);
            inversePowersOfBase[i][n] = invModulo(powersOfBase[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePowersOfBase[i][j] = (inversePowersOfBase[i][j + 1] * base) % hashPrimes[i];
            }
        }

        for (int i = 0; i < primes; i++)
        {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                if (j != 0)
                    hashValues[i][j] = (hashValues[i][j] + hashValues[i][j - 1]) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r)
    {
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = (((val1 - val2 + hashPrimes[i]) % hashPrimes[i]) * inversePowersOfBase[i][l]) % hashPrimes[i];
        }
        return hash;
    }
};
