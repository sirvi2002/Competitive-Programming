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

 
const ll N = 200001 ;
 
ll seg[4 * N + 1] = {0};
ll lazy[4 * N + 1] = {0};
ll a[N] = {0};
ll n, q; 
 
ll combine(ll a , ll b)
{
    return a + b; 
}
 
void build(ll si , ll ss , ll se)
{
    if(ss==se)
        seg[si] = a[ss];
    else
    {
        ll mid = (ss + se) / 2;
        build(2 * si, ss, mid);
        build(2 * si + 1, mid + 1, se);
        seg[si] = combine(seg[2 * si], seg[2 * si + 1]);
    }
}
 
ll query(ll si , ll ss , ll se , ll l , ll r)
{
    if(lazy[si]!=0) //check for pending updates
    {
        seg[si] += (lazy[si] * (se-ss+1));
        if(ss!=se)  //transfer curr lazy to its children
            lazy[2 * si] += lazy[si], lazy[2 * si + 1]+= lazy[si];
        lazy[si] = 0; //this pending update has been done
    }
 
    if(ss>r || se<l)
        return 0;
    
    if(ss>=l && se<=r)
        return seg[si];
 
    ll mid = (ss + se) / 2;
    return combine(query(2 * si, ss, mid, l, r),
                    query(2*si+1,mid+1,se,l,r));
}
 
void update(ll si , ll ss , ll se , ll l , ll r , ll x)
{
    if (lazy[si] != 0) //check for pending updates
    {
        ll dx = lazy[si]; 
        lazy[si] = 0 ; 
        seg[si] += (dx * (se - ss + 1));
        if(ss!=se)  //transfer curr lazy to its children
            lazy[2 * si] += dx, lazy[2 * si + 1]+= dx;
    }
 
    if(l>r)
        return;
    if(ss==l && se==r) //completely inside this range
    {
        ll dx = (se - ss + 1) * (x);
        seg[si] += dx;
        if(ss!=se)
            lazy[2 * si] += x, lazy[2 * si + 1] += x; 
        return;
    }
 
    ll mid = (ss + se) / 2;
    update(2*si,ss,mid,l,min(r,mid),x);
    update(2 * si + 1, mid + 1, se,max(mid+1,l),r,x);
    seg[si] = combine(seg[2 * si], seg[2 * si + 1]);
}

void solve()
{


}


int main()
{
   fast ;
   ll t = 1; 
   cin>>t;
   for(ll i = 1 ;i<=t; ++i)
   {
       //cout << "Case #"<<i<<": ";
       solve();
   }
   return 0 ; 
}