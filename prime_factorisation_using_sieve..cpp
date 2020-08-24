#include<iostream>
#include<vector>
using namespace std;

// 	IMPLEMENTING THE PRIME SIEVE AND  MAKE THE SIEVE 
vector<int> prime_sieve(int *p_s,int num)
{
	vector<int> ans;
	for(int i=3;i<num;i+=2)
	{
		p_s[i]=1;
	}
	for(int i=3;i<num;i+=2)
	{
		if(p_s[i]==1)
		{
	       for(int j=i*i ; j<num ;j+=i)
			{
				p_s[j]=0;
			}
		}
	}

	p_s[0]=0;
	p_s[1]=0;
	p_s[2]=1;
 ans.push_back(2);
 for(int i=3;i<=num;i+=2)
 {
 	if(p_s[i]==1)
 	{
 		ans.push_back(i);
 	}
 }
 return ans;
}
// IMPLEMENTING THE FUNC. TO FIND THE PRIME FACTORS OF A NO. M 
vector<int> factorize(int m,vector<int> &primes)
{
	vector<int> fac;
	int i=0;
    int p=primes[0];
    while(p*p < m)
    {
   	if(m%p==0)
   	{
        fac.push_back(p);
   		while(m%p==0)
   		{
   			m=m/p;
   		}
   	}
    }
   i++;
   p=primes[i];
   if(m!=1)
   {
   	fac.push_back(m);
   }
  return fac;
}
int main()
{ int n=10000;
  int p_s[n]={0};
  vector<int> primes=prime_sieve(p_s,100);
   int t;
   cin>>t;
   while(t--)
   {
   	int m;
       cin>>m;
    vector<int> seive_factors=factorize(m,primes);
    for(auto it: seive_factors)
    {
       cout<<it<<" "<<endl; 
    }
   }
 return  0;
}
