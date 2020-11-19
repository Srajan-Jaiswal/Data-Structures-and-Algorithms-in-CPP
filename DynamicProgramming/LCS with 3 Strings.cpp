#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i, a, n) for (int i = a; i < n; i++)
#define fre(i, a, b) for (int i = a; i <= b; i++)
#define endl '\n'
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define mem(name, value) memset(name, value, sizeof(name))
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define case cout << "Case " << t++ << ": ";

int dp[201][201][201];
int LCS_3D(string s1,string s2,string s3,int a,int b,int c)
{
    for(int i=0;i<=a;i++){
        dp[i][0][0] = 0;
    }
    for(int j=0;j<=b;j++){
        dp[0][j][0] = 0;
    }
    for(int k=0;k<=c;k++){
        dp[0][0][k] = 0;
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                int ans = 0;
                if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1]){
                   ans = 1 + dp[i-1][j-1][k-1];
                }
                else{
                    ans =  max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                }
                dp[i][j][k] = ans; 
            }
        }
    }
    return dp[a][b][c]; 
}
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int a = s1.length();
    int b  = s2.length();
    int c = s3.length();
    cout<<LCS_3D(s1,s2,s3,a,b,c)<<endl;
}
