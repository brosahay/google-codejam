//@author:ReVo
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>

//Shortcuts
#define lli long long int
#define fo(i,n) for(i=0;i<n;i++)
#define fi(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define modulo 1000000007
#define gi(a) scanf("%d",&a)
#define f(n) for(i=0;i<n;i++)
#define pn printf("\n")
#define pb push_back

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("sample_D.in", "r", stdin);
	freopen("sample_D.out","w",stdout);
	#endif
	int t,case_number=1;
	cin>>t;
	while(t--)
	{
		int x,r,c;
		int grid,empty_blocks;
		char winner[20];
		cin>>x>>r>>c;
		grid=r*c;
		empty_blocks=grid-x;
		//cout<<"empty_blocks "<<empty_blocks<<" x "<<x<<endl;
		if(empty_blocks<x)
			strcpy(winner,"RICHARD");
		else if(empty_blocks%x==0)
			strcpy(winner,"GABRIEL");
		else
			strcpy(winner,"RICHARD");
		printf("Case #%d: %s\n",case_number,winner);
		case_number++;
	}
	return 0;
}