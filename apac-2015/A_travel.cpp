//@author:ReVo
#include <bits/stdc++.h>

//Shortcuts
#define lli long long int
#define modulo 1000000007
#define s(n) scanf("%d",&n)
#define p(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define pl(n) printf("%lld\n",n)
#define sf(n) scanf("%f",&n)
#define pf(n) printf("%f\n",n)
#define sc(n) scanf("%c",&n);
#define pc(n) printf("%c\n",n)
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s\n",n)
// Useful constants
#define INF (int)1e9
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define foreach(v,c) for(typeof((c).begin()) v=(c).begin();v!=(c).end();++v)
#define all(a) a.begin(),a.end()
#define in(a,b) ((b).find(a)!=(b).end())
#define pb push_back
#define fill(a,v) memset(a,v,sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
// Some common useful functions
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define checkbit(n,b) ((n>>b)&1)
#define DREP(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())

using namespace std;

int main(){
	int t;
	int n,m,k;
	int x,y;
	s(t);
	while(t--){
		s(n);
		s(m);
		s(k);
		int tmp=n;
		int cost[n+1][n+1][24];
		memset(cost,0,24*n*n);
		while(tmp--){
			s(x);
			s(y);
			int buf;
			forall(i,0,24){
				s(buf);
				if(!cost[x][y][i]&&!cost[y][x][i]){
					cost[x][y][i]=buf;
					cost[y][x][i]=buf;
				}
				if(cost[x][y][i]>=buf||cost[y][x][i]>=buf){
					cost[x][y][i]=buf;
					cost[y][x][i]=buf;
				}
			}
		}
		int d,s;
		forall(i,0,k){
			cout<<"Case #"<<k<<":";
			s(d);
			s(s);
			int min_x_index=-1,min_x_val,flag;
			forall(r,s,24){
				forall(p,0,n){
					flag=1;
					min_x_val=100;
					forall(q,0,n){
						if(cost[p][q][r]==0||p==q||q==min_x_index)
							continue;
						if(min_x_val>=cost[p][q][r]){
							min_x_val=cost[p][q][r];
							min_x_index=q;
						}
						if(min_x_index==(d-1)){
							cout<<" "<<cost[p][min_x_index][r];
							flag=0;
							break;
						}
					}
					if(flag)
					cout<<" "<<cost[p][min_x_index][r];
				}
			}
			cout<<endl;
		}
	}
	return 0;
}