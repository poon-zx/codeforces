int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool isPrime(int number){
    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;
}

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vector<ll> p;                                           // compact list of primes

void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}

vector<ll> primeFactors(ll N) {                         // pre-condition, N >= 1
  vector<ll> factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) {                        // found a prime for N
      N /= p[i];                                 // remove it from N
      factors.push_back(p[i]);
    }
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

vector<bool> sieve(int n){
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

// Extended Euclidean Algorithm to compute gcd and the coefficients x and y for Bézout's identity: ax + by = gcd(a, b)
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int gcd = extended_gcd(b, a % b, y, x);
    y -= (a / b) * x;
    return gcd;
}

// Function to compute modular inverse of a modulo m
int mod_inverse(int a, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);
    if (g != 1) {
        // In our problem, this should never happen since a and m are coprime
        return -1;
    }
    // Make sure the result is positive
    x = (x % m + m) % m;
    return x;
}

// sum of all divisors of N including itself
// include sieve code
ll sumDiv(ll N) {
  ll ans = 1;                                    // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    ll multiplier = p[i], total = 1;
    while (N%p[i] == 0) {
      N /= p[i];
      total += multiplier;
      multiplier *= p[i];
    }                                            // total for
    ans *= total;                                // this prime factor
  }
  if (N != 1) ans *= (N+1);                      // N^2-1/N-1 = N+1
  return ans;
}

int mod(int a, int m) {                          // returns a (mod m)
  return ((a%m) + m) % m;                        // ensure positive answer
}

// (b^p)%m
// need mod code
int modPow(int b, int p, int m) {                // assume 0 <= b < m
  if (p == 0) return 1;
  int ans = modPow(b, p/2, m);                   // this is O(log p)
  ans = mod(ans*ans, m);                         // double it first
  if (p&1) ans = mod(ans*b, m);                  // *b if p is odd
  return ans;                                    // ans always in [0..m-1]
}

// IS PROBABLE PRIME
// multiply (a * b) % mod safely
ll mod_mul(ll a, ll b, ll mod) {
    __int128 res = a;
    res *= b;
    res %= mod;
    return (ll)res;
}

// fast exponentiation: num^b % n
ll pow_mod(ll num, ll b, ll n) {
    if (b == 0) return 1;
    if (b == 1) return num % n;
    if ((b & 1) == 0)
        return pow_mod(mod_mul(num, num, n), b >> 1, n);
    else
        return mod_mul(num, pow_mod(mod_mul(num, num, n), b >> 1, n), n);
}

// returns true if n is probably prime (with `rounds` Fermat tests)
bool IsProbablePrime(ll n, int rounds = 20) {
    if (n < 2)              return false;
    if (n < 4)              return true;     // 2 and 3 are prime
    if ((n & 1) == 0)       return false;    // even numbers >2 are composite

    // set up random engine once per call
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<ll> dist(2, n - 2);

    // Fermat's little theorem: a^(n-1) ≡ 1 mod n for prime n
    for (int i = 0; i < rounds; ++i) {
        ll a = dist(gen);
        if (pow_mod(a, n - 1, n) != 1)
            return false;  // definitely composite
    }
    return true;  // probably prime
}
/// END IS PROBABLE PRIME

//arithmetic
sn=n/2*(2*a+(n-1)*d);