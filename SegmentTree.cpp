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


ll n, q;

struct node
{
    ll data; 
};

class sg
{
    ll n ; 
    public :
        vector<node> seg;    
        sg(ll s)
        {
            n = s;
            seg.resize(4 * n + 1);
        }

        //write combine function
        node combine(node a , node b)
        {
            node temp;
            return temp;
        }

        void build(ll par , ll l , ll r)
        {
            if(l==r)
            {
                //for a node initialize 
            }
            else
            {
                ll mid = (l + r) / 2;
                build(2 * par, l, mid);
                build(2 * par + 1, mid + 1, r);
                seg[par] = combine(seg[par * 2] , seg[2 * par + 1]);
            }
        }

        void update(ll par , ll l , ll r , ll pos , ll nval)
        {
            if(l==r)
            {
                //for a node initialize 
            }
            else
            {
                ll mid = (l+r)/2 ; 
                if(pos<=mid)    update(par*2,l,mid,pos,nval) ; 
                else
                    update(par*2+1,mid+1,r,pos,nval) ; 
                seg[par] = combine(seg[par*2] , seg[par*2+1]) ; 
            }
        }

        node query(ll par , ll orgl , ll orgr , ll l , ll r)
        {
            if(l>r) 
            {
                //invalid condi... return invalid node ;
                node temp;
                return temp;
            }
            if(l==orgl and r==orgr)
                return seg[par] ; 
            
            ll mid = (orgl+orgr)/2 ; 

            node temp1 = query(2*par,orgl,mid,l,min(r,mid));
            node temp2 = query(2*par+1,mid+1,orgr,max(mid+1,l),r);
 
            return combine(temp1,temp2);
        }
};

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