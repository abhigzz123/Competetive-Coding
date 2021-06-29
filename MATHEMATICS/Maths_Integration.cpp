      //Abhigyan's Code:
             
      //You DON'T DARE TO COPY :) 

      #include<bits/stdc++.h>
      using namespace std;
      typedef long long int ll;
      typedef unsigned long long int ull;
      #define checker cout<<"CHECKED" 
      #define modulo 1000000007
  	

  	bool primeCheck(long long int  n)
    {   
      	if (n == 2 || n == 3 || n == 5) return true;
      	if (n % 2 == 0 || n % 3 == 0 || n ==1) return false; 
  
   	 	for (int i = 5; i * i <= n; i += 6) 
        	if (n % i == 0 || n % (i + 2) == 0) 
           	return false;

    	return true; 
	}

	vector<ll> sieve(ll n)
	{
		vector<ll> v;  
		bool a[n+1];
		ll cnt=0;
		memset(a,true,sizeof(a));
		a[0]=false;
		a[1]=false;
		for(ll i=2;i*i<=n;i++)
		{
			if(a[i]==true)
			{
				for(int j=i*i;j<=n;j+=i)
				{
					a[j]=false;
				}
			}
		}
		for(ll i=0;i<=n;i++)
		{
			if(a[i])
			v.pb(i);
		}
		return v;
	}
	ll digits(ll n)
	{
		ll c=0;
		for(ll temp=n;temp!=0;temp/=10)
		{
			 c++;
		}
	 
		return c;
	}
	 