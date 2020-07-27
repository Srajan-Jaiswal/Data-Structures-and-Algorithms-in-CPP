#include<iostream>
using namespace std;
void rec_multiply(int **a, int **b,int row1,int col1,int row2,int col2, int **res)
{
	if(i>=row1)
	{
		return;
	}
	if(j<col1)
	{
		if(k<col1)
	{
	static int k=0;
	static int i=0,j=0;
  res[i][j]  += a[k][i]*b[j][k];
  k++;
  rec_multiply(a,b,row1,col1,row2,col2,res);
  k=0;
  j++;
  rec_multiply(a,b,row1,col1,row2,col2,res);
  j=0;
  i++;
  rec_multiply(a,b,row1,col1,row2,col2,res);
}
}
}
void multiply(int **a, int **b,int n,int row1,int col1,int row2,int col2, int **res)
{
  if(row1>col2)
  {
  	cout<<"OH OO... NOT POSSIBLE TO MULTIPLY :("<<endl;
  }
  res[n][n]=0;
  rec_multiply(a,b,row1,col1,row2,col2,res);
  for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col2;j++)
			{
				cout<<a[i][j]<<" ";
			}
		   cout<<endl;
		}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int row1,row2,col1,col2;
		int a[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		int b[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>b[i][j];
			}
		}
	}
	return 0;
}