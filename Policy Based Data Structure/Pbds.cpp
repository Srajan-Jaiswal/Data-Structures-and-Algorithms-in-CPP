#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main(){
	
	pbds A;
	
   A.insert(11);
	 A.insert(1);
   A.insert(5);
	 A.insert(3);
	 A.insert(7);
	 A.insert(9);
	int k = 3;
	cout << k << "rd smallest: " << *A.find_by_order(k-1) << endl;
	
	k = 5;
	cout << k << "th smallest: " << *A.find_by_order(k-1) << endl;
	int X = 9;
	
	cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
    cout << "Deleted 3" << endl;
    A.erase(3);
	
    cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
 
    X = 8;
    
    cout << "Next greater element than " << X << " is " << *A.upper_bound(X) << endl;
    
	
	return 0;
}
