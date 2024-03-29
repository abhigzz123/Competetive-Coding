struct Hash
{
    vector<ll> fhash, rhash, powr;
    ll p = 31, n; // >= distinct characters
    Hash(string s) 
    {
        n = (ll)s.size();
        fhash.resize(n + 1, 0);
        powr.resize(n + 1, 0);
        rhash.resize(n + 1, 0);
        powr[0] = 1, fhash[0] = s[0] - 'a' + 1; // take care of character to subtract
        rhash[n - 1] = s[n - 1] - 'a' + 1;
        for(ll i = 1; i < n; i++) 
        {
            powr[i] = (powr[i - 1] * p) % MOD;
            fhash[i] = ((fhash[i - 1] * p) % MOD + (s[i] - 'a' + 1)) % MOD;
            rhash[n - 1 - i] = ((rhash[n - i] * p) % MOD + s[n - i - 1] - 'a' + 1) % MOD;
        }
    }
    ll frontHash(ll i, ll j) 
    {
        if(i == 0) 
           return fhash[j];
        ll hashvalue = (fhash[j] - (fhash[i - 1] * powr[j - i + 1]) % MOD + MOD) % MOD;
        return hashvalue;
    }
    ll reverseHash(ll i, ll j) 
    {
        if(j == n - 1) 
            return rhash[i];
        ll hashvalue = (rhash[i] - (rhash[j + 1] * powr[j - i + 1]) % MOD + MOD) % MOD;
        return hashvalue;
     }
    bool isPalindrome(ll i, ll j) 
    {
        ll len = (j - i + 1) / 2;
        ll fhashh, rhashh;
        fhashh = frontHash(i, i + len - 1);
        if((j - i + 1) % 2) 
        {
            rhashh = reverseHash(len + 1 + i, 2 * len + i);
        } 
        else 
        {
            rhashh = reverseHash(len + i, 2 * len - 1 + i);
        }
        return fhashh == rhashh ? true : false;
    }
};