// https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1#

class Solution{
public:	
	int countTriplet(int arr[], int n)
	{
	    
	    set<int> s;
	   for(int i=0;i<n;i++){
	       s.insert(arr[i]);
	   }
	   int cnt=0;
	   for(int i=0;i<n-1;i++)
	   {
	       for(int j=i+1;j<n;j++){
	           int sum = arr[i]+arr[j];
	           if(s.find(sum)==s.end()){
	               continue;
	           }
	           else{
	               cnt++;
	           }
	       }
	   }
	   return cnt;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}
