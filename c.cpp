#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int task =1;

void solve(){
		
	int n,d;
	cin >> n >> d;
	ll a[n];
	map<ll,int> count;
	ll maxiangle = 0;
	for(int i =0;i<n;i++){
		cin >> a[i];
		maxiangle = max(a[i],maxiangle);
		count[a[i]]++;
	}
	int maxicount = 0;
	for(auto e:count){
		if(e.second>maxicount)
			maxicount = e.second;
	}
	// ll ans = 1e9;
	if(d==2){
		int ans=10;
		if(maxicount<2){
			ans = 1;
		}
		else{
			ans = 0;
		}
		cout << "Case #" << task << ": " << ans << endl;
		task++;
		return;
	}
	else if(d==3){
		int ans = 10;
		if(maxicount<3){
			//check if a half of it is present or not;
			for(auto e:count){
				if(e.first%2==0 && count.find(e.first/2LL)!=count.end()){
					ans=1;
				}
			}
			ans=min(ans,2);
			if(maxicount==2){
				//need to find the min which has maxicount =2;
				for(auto e:count){
					if(e.second == 2){
						if(e.first < maxiangle)
							ans = 1;
					}
				}
			}

		}	
		else{
			ans =0;
		}
		cout << "Case #" << task << ": " << ans << endl;
		task++;
		return;
	}
	else{
		int ans = d-1;
		
	}

}

int main(){
	fast;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int t;cin >> t;while(t--)
		solve();
}