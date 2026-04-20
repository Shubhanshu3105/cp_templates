#define ll long long

const ll MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll fact[MAXN], invFact[MAXN];

// Fast exponentiation
ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void init() {
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fact[i] = fact[i-1] * i % MOD;

    invFact[MAXN-1] = power(fact[MAXN-1], MOD - 2);
    for (ll i = MAXN - 2; i >= 0; i--)
        invFact[i] = invFact[i+1] * (i+1) % MOD;
}

// nCr function
ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
}
