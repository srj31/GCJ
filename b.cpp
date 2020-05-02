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

void solve(){
	int u;
	cin >> u; // the upper bound on M
	vector<char> ans(10,'0');//this will have 10 chars
	// cout << u << endl;
	set<char> check;
	set<char> notzero;
	if(u==2){
		for(int i =0;i<1e4;i++){
			// cout << i << endl;
			int qi;string ri;
			cin >> qi >> ri;
			//so the response is for a number 1<=ni<=mi
			for(int j =0;j<ri.length();j++){
				check.insert(ri[j]);
			}
			if(qi==1){
				ans[1] = ri[0];
			}
			else if(qi==2){
				if(ans[1]=='0')
					continue;
				else{
					if(ans[1]!=ri[0])
						ans[2] = ri[0];
				}
			}
			else if(qi<10){
				int flag = 1;
				for(int j =qi-1;~j;j--){
					if(ans[j]==ri[0]){
						flag = 0;break;
					}
				}
				if(flag)ans[qi] = ri[0];
			}

			// now the one that is left
			

		}
	}

	else{
		// if the lengths are same I can possible try to fit the range for staring values;
		map<int,int> pos;
		int isno = 0;
		for(int i =0;i<10;i++){
			string qi,ri;
			cin >> qi>> ri;
			// cout << qi << endl;
			if(qi=="-1"){
				isno=1;
				// cout << "here" << endl;
			}
			
			notzero.insert(ri[0]);

			for(int j =0;j<ri.length();j++){
				check.insert(ri[j]);
			}
			if(!isno && qi.length()==ri.length()){
				char c = ri[0];
				int ub = qi[0]-'0';
				if(pos[c-'A']==0){
					pos[c-'A']=ub;
				}
				else{
					pos[c-'A'] = min(pos[c-'A'],ub);
				}
			}
		}
		if(isno){
			// cout << "here" << endl;
			int curr = 1;
			for(auto e:notzero){
				ans[curr] = e;
				curr++;
			}

			for(auto e:check){
				int tofill = 0;
				if(notzero.find(e)==notzero.end()){
					while(tofill<10 && ans[tofill]!='0')
							tofill++;
					if(tofill>=10)break;
					if(ans[tofill]=='0'){
						ans[tofill] = e;
						tofill++;
					}


				}
			}
			cout << "Case #"<<task << ": ";
			for(int i =0;i<10;i++){
				cout << ans[i];
			}cout << endl;
			task++;
			return;
		}
		for(int i =1;i<10;i++){
			for(auto e:pos){
				if(e.second==i){
					ans[i] = char(e.first+'A');
					break;
				}
			}
			// cout << endl;
		}
	}

	for(auto e:check){
			int flag = 0;
			for(int i =1;i<10;i++){
				if(ans[i]==e){
					flag = 1;break;
				}
			}
			if(!flag){
				ans[0] = e;
				break;
			}
	}

	cout << "Case #"<<task << ": ";
	for(int i =0;i<10;i++){
		cout << ans[i];
	}cout << endl;
	task++;
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