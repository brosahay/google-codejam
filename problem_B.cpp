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

void special_minute(vector<int>& v,vector<int>& minute,int min_tmp)
{
	int i,max,max_index,tmp;
	max=0,max_index=-1;
	fo(i,v.size())
	{
		if(v[i]>max)
		{
			max=v[i];
			max_index=i;
		}
	}
	tmp=max+min_tmp;
	minute.pb(tmp);
	while(max>3)
	{
		if(v[max_index]%2==1)
		{
			v.pb(v[max_index]/2);
			v[max_index]=(v[max_index]/2)+1;
			min_tmp++;

		}
		else
		{
			v.pb(v[max_index]/2);
			v[max_index]=(v[max_index]/2);
			min_tmp++;
		}
		max=0,max_index=-1;
		fo(i,v.size())
		{
			if(v[i]>max)
			{
				max=v[i];
				max_index=i;
			}
		}
		tmp=max+min_tmp;
		minute.pb(tmp);
	}
	return ;
}

int main()
{
	/*#ifndef ONLINE_JUDGE
	freopen("sample_B.in", "r", stdin);
	freopen("sample_B.out","w",stdout);
	#endif*/
	int t,case_number=1;
	cin>>t;
	while(t--)
	{
		int d;
		cin>>d;
		vector<int> p;
		vector<int> minute;
		int i,input,min=1001;
		fo(i,d)
		{
			cin>>input;
			p.pb(input);
		}
		special_minute(p,minute,0);
		fo(i,minute.size())
		{
			if(minute[i]<min)
				min=minute[i];
		}
		printf("Case #%d: %d\n",case_number,min);
		case_number++;
	}
	return 0;
}
