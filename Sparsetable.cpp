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
 
/*
1)  For function like sum query we can use prefix sum instead of SPT
    bcz query can be answered in o(1) 
2)  We can't update sparse table
3)  Idempotent Function Like GCD , MIN , MAX , Bitwise AND , OR
    can be answered on o(1) bcz A f A = A
4)  For all other query can be answered in o(logn)
*/

//Implemented on 0 indexing
const ll N = 100001; //size of array
const ll k = 25;  //mx no of bits required to represent a query length
 
ll st[N][k+1];
ll n ;
 
ll a[N];

int logg[N+1];

 
ll combine(ll a, ll b) { return min(a,b); }
 
void build()
{
    for (ll i = 0; i < n; ++i)
        st[i][0] = a[i] ;
 
    for (ll j = 1; j <= k; ++j)
        for (ll i = 0; i + (1 << j) <= n; ++i)
            st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    //uncomment for query1
    /*
    logg[1] = 0;
    for (int i = 2; i <= N; i++)
        logg[i] = logg[i/2] + 1;
    */
    
}
 
//rmq
ll query1(ll l , ll r)
{
    int j = logg[r - l + 1];
    return combine(st[l][j], st[r - (1 << j) + 1][j]);
}
//sum
ll query2(ll l , ll r)
{
    ll ans = 0;
    for (int j = k; j >= 0; j--)
    {
        if((1<<j) <= (r-l+1))
        {
            ans += st[l][j];
            l += (1 << j);
        }
    }
    return ans;
}

void solve()
{
    cin >> n;
 
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
    build();
    ll q;
    cin >> q; 
    while(q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << query1(l, r) << "\n"; 
    }
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