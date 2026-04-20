const int N = 1e6 + 5;
vector<int> spf(N);

void build_spf()
{
    for (int i = 1; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        { // i is prime
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> factorize(int x)
{
    vector<int> factors;
    while (x != 1)
    {
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}
