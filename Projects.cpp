#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
#define fi first
#define sc second 
#define w(n) while(n--)
#define f(i,n) for(ll i=1;i<=n;i++)
#define fr(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
bool sortbysec(const pair<pair<ll,ll>,ll>&a,const pair<pair<ll,ll>,ll>&b)
{
    if(a.fi.sc==b.fi.sc)
    return a.sc>b.sc;
    return a.fi.sc<b.fi.sc;
}
// just sort them by ending time and now you have two choices left either to include a nth value or not 
// if not taking the nth val then dp[i]=dp[i-1]
// else dp[i]=max(dp[i-1],price[i]+val);
// here val is lower bound of starting time of this val on the ending time of all previous values
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
   //cin>>t;
   w(t)
   {
       ll n;
       cin>>n;
        VL dp(n+1,0);
        vector<pair<pair<ll,ll>,ll>>vpp;
        fr(i,n)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            vpp.pb({{x,y},z});
        }
        sort(all(vpp),sortbysec);
        dp[0]=vpp[0].sc;
        multiset<ll>ms;
        ms.insert(vpp[0].fi.sc);
        map<ll,ll>m;
        m[vpp[0].fi.sc]=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=dp[i-1];
            auto it=ms.lower_bound(vpp[i].fi.fi);
            if(it==ms.begin())
            {
                dp[i]=max(dp[i],vpp[i].sc);
            }
            else 
            {
                it--;
                dp[i]=max(dp[i],vpp[i].sc+dp[m[*it]]);
            }
            
             ms.insert(vpp[i].fi.sc);
             m[vpp[i].fi.sc]=i;
        }
        std::cout << dp[n-1] << std::endl;
   }
}
