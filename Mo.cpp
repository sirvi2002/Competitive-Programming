#include<bits/stdc++.h>
using namespace std ;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sz(x) (ll)x.size()
#define all(x)  x.begin(),x.end()
#define mod 1000000007ll
#define DISPLAY(V)  for(auto it : V)  {   cout<<it<<" " ;} cout<<endl;
#define DISPLAY2(V)  for(auto it : V) { for (auto val : it) { cout<<val<<" ";} cout<<endl;}
 
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
 
 
int n, q;
int a[200001];
int distinct = 1;
int freq[200001]={0};    
 
int rootN = 555; 
 
struct query
{
    int l , r , block , q_no ; 
    bool operator < (query& q2)
    {
        if(block < q2.block)
            return 1;
        else if(block > q2.block)
            return 0;
        else return r < q2.r;
    }
};
 
void adjust(int &curr_l , int &curr_r , query & q)
{
    while(curr_l>q.l)
    {
        curr_l--; 
        if(!freq[a[curr_l]])
            distinct++;
        freq[a[curr_l]]++;
    }
    while(curr_r<q.r)
    {
        curr_r++;
        if(!freq[a[curr_r]])
            distinct++;
        freq[a[curr_r]]++;
    }
    while(curr_l<q.l)
    {
        freq[a[curr_l]]--;
        if(!freq[a[curr_l]])
            distinct--;
        curr_l++; 
    }
    while(curr_r>q.r)
    {
        freq[a[curr_r]]--;
        if(!freq[a[curr_r]])
            distinct--;
        curr_r--; 
    }
}
 
void solve()
{
    map<int, int> cord_comp;
    cin >> n >> q;
    int comp_no = 0;
    
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (cord_comp.find(a[i]) != cord_comp.end())
            a[i] = cord_comp[a[i]];
        else 
        {
            cord_comp[a[i]] = comp_no;
            a[i] = comp_no++;
        }
    }
 
    vector<query> que(q);
    int u, v; 
    for (int i = 0; i < q; ++i)
    {
        cin >> u >> v;
        que[i].l = u - 1, que[i].r = v - 1;
        que[i].q_no = i;
        que[i].block = (u / rootN);
    }
 
    sort(que.begin(),que.end());
 
    int l = que[0].l, r = que[0].l;
    freq[a[que[0].l]]++;
    vector<int> ans(q);
 
    for (int i = 0; i < q; ++i)
    {
        adjust(l, r, que[i]);
        ans[que[i].q_no] = distinct;
    }
 
    for(int i : ans)
        cout << i << "\n"; 
}
 
int main()
{
   fast ;
 
   solve();
   return 0;
}