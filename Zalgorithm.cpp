#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std ;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define DISPLAY(V)  for(auto it : V)  {   cout<<it<<" " ;} cout<<endl;
#define DISPLAY2(V)  for(auto it : V) { for (auto val : it) { cout<<val<<" ";} cout<<endl;}
#define mod 1000000007ll
#define sz(x) (ll)x.size()
#define all(x)  x.begin(),x.end()
#define see(x) cerr<<#x<<" = "; _print(x);cerr<<endl;


typedef long long ll ;
typedef long double ld; 
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;


void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
template <class T> void _print(vector <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr<<"[ ";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}


ll expo(ll x, ll y) { ll res = 1; while (y) {if (y % 2) res = (res * x % mod) % mod; x = (x * x) % mod; y /= 2; } return res;}
ll inv(ll x) {return expo(x, mod - 2);}
ll add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
ll m_div(ll a, ll b) {a = a % mod; b = b % mod; return (mul(a, inv(b)) + mod) % mod;}
inline ll myceil(ll a , ll b){ if(a%b==0) return a/b ; else return a/b+1 ; } 
inline ll lcm(ll a , ll b)  {return (a*b)/__gcd(a,b) ;}
bool isPerSquare(ll a) {if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a);}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vll zFunction(string s)
{
    ll n = sz(s);
    vll z(n,0); 
    ll l = 0, r = 0;
    for (ll i = 1; i < n; ++i) 
    {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve()
{
    
}

int main()
{
   fast ;
   ll t = 1; 
   //cin>>t;
   for(ll i = 1 ;i<=t; ++i)
   {
       //cout << "Case #"<<i<<": ";
       solve();
   }
   return 0 ; 
}