#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 int128;
#define sl '\n' 

ll mult(ll a, ll b, ll mod) {
    return (int128)a * b % mod;
}
//  a^e
ll qp(ll a, ll e, ll mod) {
    ll ans = 1;
    while(e) {
        if(e & 1) ans =mult(ans, a, mod);
        a = mult(a,a,mod);
        e >>= 1;
    }
    return ans;
}
bool compositetest(ll a, ll d, ll s, ll n) {
    ll x = qp(a , d, n);
    if(x == 1 || x == n -1) return 0;
    for(ll i = 0; i < s - 1; i++) {
        x = mult(x, x, n);
        if(x == n - 1) return 0;
    }
    return 1;
}
bool esprimo(ll n) {
    if(n < 2) return 0;
    ll d = n - 1, s = 0;
    while((d&1) == 0) d >>= 1, s++;
    for(ll a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if(n == a) return 1;
        if(compositetest(a, d, s, n)) return 0;
    }
    return 1;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a,ll b){ return uniform_int_distribution<ll>(a,b)(rng); } 
ll f(ll x,ll c,ll mod){ //paso del algoritmo: x -> x^2 + c (mod n) 
    ll m = mult(x,x,mod); 
    return m + c >= mod ? m + c-mod : m + c; 
} 
ll getfactor(ll n) { //devuelve un divisor no trivial de n (on si es primo) 
    if (n % 2 == 0) return 2; 
    if (esprimo(n)) return n; 
    while (true){ //reintenta con otros y, c si falla 
        ll y = random(1,n-1); 
        ll c = random(1,n-1); 
        ll m = 64, g = 1, r = 1, q = 1; //Brent: ciclo con productos acumulados 
        ll x,ys; 
        while (g == 1){ 
            x = y; 
            for (ll i = 0;i < r;i++)y = f(y,c,n); 
            ll k = 0; 
            while (k < r && g == 1){ ys = y; ll lim = min(m,r-k); 
                for (ll i = 0; i < lim;i++) { 
                    y = f(y,c, n); 
                    ll diff = x > y ? x-y : y-x; 
                    q = mult(q,diff,n); //acumula |x-y| para hacer pocos gcd 
                } 
                g = __gcd(q,n); k += m; 
            } r <<= 1; 
        } 
        if (g == n) { //el gcd salió n: retroceder paso a paso 
            do { ys = f(ys,c,n); 
                ll diff = x > ys ? x-ys : ys-x;
                g = __gcd(diff,n); 
            } while (g == 1); 
        } 
        if (g > 1 && g < n) return g; 
    } 
} 
vector<pair<ll,ll>> fp(ll n) { //factorización completa 
    stack<ll> st; st.push(n); 
    vector<pair<ll,ll>> ans; 
    map<ll,ll> cont; 
    while (!st.empty()){ 
        ll x = st.top();st.pop(); 
        if (x == 1) continue; 
        if (esprimo(x))cont[x]++; //primo:secuenta 
        else { 
            ll f = getfactor(x); //compuesto: se parte en f y x/f 
            st.push(f),st.push(x / f); 
        } 
    } 
    for (auto [x,f] : cont) ans.push_back({x,f});
    return ans; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector <pair<ll,ll>> fact = fp(n);
        ll sz = fact.size();
        if(sz == 1 || n % 2 == 1) {
            cout << -1 << sl;
            continue;
        }
        if(sz % 2 == 0) {
            for(auto e : fact) {
                if(e.second % 2 == 1) n/= e.first;
            }
        } 
        else {
            for(int i = 0; i < sz; i++) {
                if(i == 1) continue;
                if(fact[i].second % 2 == 1) n/= fact[i].first;
            }
        }
        if(n <= 1) cout << -1;
        else cout << n;
        cout << sl;
    }   
    return 0;
}
