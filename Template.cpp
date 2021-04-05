#include<bits/stdc++.h>
using namespace std ;
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define DISPLAY(V)  for(auto it : V)  {   cout<<it<<" " ;} cout<<endl;
#define DISPLAY2(V)  for(auto it : V) { for (auto val : it) { cout<<val<<" ";} cout<<endl;}
#define MOD 1000000007ll
#define sz(x) (ll)x.size()
#define all(x)  x.begin(),x.end()
#define see(x) cerr<<#x<<" = "; _print(x);cerr<<endl;


typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
template <class T> void _print(vector <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(set <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[ ";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr<<"[ ";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}


inline ll add(ll a,ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
inline ll mul(ll a,ll b){return (a*1ll*b)%MOD;}
inline ll power(ll a,ll b){ll rt=1;while(b>0){if(b&1)rt=mul(rt,a);a=mul(a,a);b>>=1;}return rt;}
inline ll myceil(ll a , ll b){ if(a%b==0) return a/b ; else return a/b+1 ; } 
inline ll lcm(ll a , ll b)  {return (a*b)/__gcd(a,b) ;}
bool isPerSquare(ll a) {if(a<0) return false; ll sr = sqrt(a); return (sr*sr == a);}


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
