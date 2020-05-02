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
int task = 1;


bool ok(int time,string s,int x,int y){
	// currently at x and y
	for(int i =0;i<time;i++){
		if(s[i]=='S'){
			y--;
		}
		if(s[i]=='N')y++;
		if(s[i]=='E')x++;
		if(s[i]=='W') x--;
	}
	// cout << time << " " << x << " " << y << endl;
	if(abs(x)+abs(y)<=time)return true;

	return false;
}

void solve(){
	int x,y;
	cin >> x >> y;
	string path;
	cin >> path;
	int ans = 1e9;
	//by binary search;
	int l =1,r=path.length();
	int flag = 0;
	while(l<=r){
		int m = l + (r-l)/2;
		if(ok(m,path,x,y)){
			 r =m-1;
			 flag = 1;
			 ans=min(ans,m);
		}
		else
			l=m+1;
	}

	if(!flag){
		cout << "Case #"<<task << ": IMPOSSIBLE"<< endl;
		task++;
		return;
	}
	cout << "Case #"<<task << ": " << ans << endl;
	task++;
}

int main(){
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	int t;cin >> t;while(t--)
		solve();
}