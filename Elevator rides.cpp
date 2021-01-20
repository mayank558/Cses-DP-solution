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
ll n,x;
VL v;
ll ans=0;
// you should atleast have a knowldege about generating subsets with bits (means how they are generated)
// their is also a soltuion by generating all permutations and checking them but wil cause tle
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
   //cin>>t;
   w(t)
   {
        cin>>n>>x;
        v=VL(n);
        fr(i,n) cin>>v[i];
        sort(all(v));// not necessary to sort we can do even without jus to reduce time complexity i did this
        ll cnt=0;
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]==x) cnt++,ans++;// if any weight is equal to x it will definatly need a separte rides
        }
        v.resize(n-cnt);
        if(v.size()==0)
        {
            std::cout << ans << std::endl;
            return 0;
        }
        // we ll be going through all the people who belong to a subset and then by adding them suitably to  a smaller subset which doess not conntain that value
        pair<ll,ll> ans[1<<n];//the minimum number of rides needed and the minimum weight of people who ride in the group.
        ans[0] = {1,0};
       
        for(int i=1;i<(1<<n);i++)
        {
        	// initialy assuming n+1 rides are needed
            ans[i]={n+1,0};
            // this loop gurantees that for any two subsets s1 and s2  s1 is always a subset of s2 so we can use precomputated values 
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))// genearating subsets
                {
                    auto option=ans[i^(1<<j)];//in the same subset looking for previous value of ans (remember this a subset which does not include weight j as we are taking xor)
                    if(option.sc+v[j]<=x)// checking that can this weight gets fit into previous rides wich does not contain this weight 
                    option.sc+=v[j];
                    else 
                    {
                        option.fi++;
                        option.sc=v[j];
                    }
                      ans[i]=min(ans[i],option);
                }
              
            }
        }
        // for(int i=1;i<(1<<n);i++)
        // cout<<ans[i].fi<<" ";
        cout<<ans[(1<<n)-1].fi<<" ";
   }
}
