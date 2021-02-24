#include <iostream>
#include <queue>
using namespace std;

class Node { 
public:
    int data;
    Node * left;
    Node * right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* createBT() { //Node* return data type
    int x;
    cin >> x;
    if (x == -1){
         return NULL;
    }
    Node * root = new Node(x); //dynamic allocation  of class pointer type
    // cout << "Enter the left child of " << root->data << ": \n";
    root->left = createBT();
    // cout << "Enter the right child " << root->data << " : \n";
    root->right = createBT();
    return root;
}
// preorder traversal 
void printBT(Node * root) {     //O(N) every node is traversed once!
    if (root == NULL) {
        return;
    }

    printBT(root->left);
    cout << root->data << " ";
    printBT(root->right);
}

Node* inputLevel() {
    Node * root = NULL;
    int x;
    cin >> x;
    if (x == -1) return NULL;

    root = new Node(x);
    queue<Node*> q;
    q.push(root);
    while (q.empty() == false) {
        Node * cur = q.front();
        q.pop();

        //setting the left child
        cin >> x;
        if (x != -1) {
            cur->left = new Node(x);
            q.push(cur->left);
        }

        cin >> x;
        if (x != -1) {
            cur->right = new Node(x);
            q.push(cur->right);
        }
    }
    return root;
}


void printLevel(Node * root) {      //O(N)
    if (root == NULL) {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.empty() == false) {
        Node * cur = q.front();
        q.pop();

        if (cur == NULL) {
            cout << endl;
            if (!q.empty()) q.push(NULL);
            continue;
        }

        cout << cur->data << " ";
        if (cur->left)  q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }

}

int cnt(Node * root) {                                  //O(N) every node is traversed once
    if (root == NULL) return 0;
    return cnt(root->left) + 1 + cnt(root->right);
}


int height(Node * root) {                               //O(N)
    if (root == NULL) return 0;

    int leftHt = height(root->left);
    int rgtHt = height(root->right);
    return max(leftHt, rgtHt) + 1;
}

int diameter(Node * root) {                             //O(N^2) for every node we are calling height(left node)
    if (root == NULL) return 0;                         //height(right node) which is 2N for every node!
    int curDiameter = height(root->left) + 1 + height(root->right);
    return max(max(diameter(root->left), diameter(root->right)), curDiameter);
}

int diameterInterview(Node* root) {
    //fn declaration
    pair<int, int> diameterOpt(Node * root); //function declaration
    pair<int, int> ans = diameterOpt(root);
    return ans.second;
}


typedef pair<int, int> ii;  //ht, dia
pair<int, int> diameterOpt(Node* root) {            //O(N) for every node we are calculating height and diameter once 
    if (root == NULL) {                             // so each node is being traversed once!
        return ii(0, 0);
    }

    ii leftPair = diameterOpt(root->left);          //O(N)
    ii rightPair = diameterOpt(root->right);        //O(N)
    int curHt = max(leftPair.first, rightPair.first) + 1;
    int curDia = leftPair.first + rightPair.first + 1;

    ii ans;
    ans.first = curHt;
    ans.second = max(max(leftPair.second, rightPair.second), curDia);
    return ans;
}

bool isHtBalanced(Node * root) {                    //O(N^2) for each node height(left node) & height(right node)is called
    if (root == NULL) return true;                  // which is 2N for each node!

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    return ((abs(leftHt - rightHt) <= 1) &&
            isHtBalanced(root->left) &&
            isHtBalanced(root->right)
           );

}

typedef pair<int, bool> ib; //ht, isBalanced

ib isHtBalancedOpt(Node * root) {                           //O(N) for each node we are checking node is balanced and
    if (root == NULL) {                                     // calculating height simultaneously.So each node is traversed once
        return pair<int, bool>(0, true);
    }
    auto leftAns = isHtBalancedOpt(root->left);             //O(N)
    auto rightAns = isHtBalancedOpt(root->right);           //O(N)
    ib ans;
    ans.first = max(leftAns.first, rightAns.first) + 1;
    ans.second = (
                     leftAns.second && rightAns.second &&
                     abs(leftAns.first - rightAns.first) <= 1
                 );
}

void mirror(Node * root) {          //O(N)
    if (root == 0) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
    /*
    Node * tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    */
}

int sumTree(Node * root) {               //O(N)
    //returns sum of a tree and sets the tree accordingly
    if (root == NULL) {
        return 0;
    }

    int left = sumTree(root->left);
    int right = sumTree(root->right);
    int curSum = left + right + root->data;
    root->data = left + right;
    return curSum;
}

int bestNonAdjSum(Node * root, bool includeRoot) {      //O(N) for each node either if or else part will be executed
    if (root == NULL) return 0;

    if (includeRoot) {
        int left = bestNonAdjSum(root->left, false);
        int right = bestNonAdjSum(root->right, false);
        return max(left + right , max(left, right)) + max(root->data, 0);
    } else{
        int left = bestNonAdjSum(root->left, true);
        int right = bestNonAdjSum(root->right, true);
        return max(left + right, max(left, right));
    }
}

int bestNonAdjSum(Node* root) {
    int bestNonAdjSum(Node * , bool); //fn overloading

    int rootInc = bestNonAdjSum(root, true);
    int rootExc = bestNonAdjSum(root, false);

    return max(rootInc, rootExc);
}

void printKthLevel(Node * root, int K){     //O(2^k) this code will traverse through all the nodes untill level k
    if (root == NULL) return;               //So. no. of nodes untill level k are 2^K

    if (K == 0){
        cout << root->data << " ";
        return;
    }

    printKthLevel(root->left, K - 1);
    printKthLevel(root->right, K - 1);
}

void printPath(Node * arr[], int be, int en){       
    while(be <= en){
        cout << arr[be]->data << " ";
        ++be;
    }
    cout << endl;
}

Node * arr[100];    //array of Nodes
//void printRoot2Leaf(Node root , ArrayList<Node> a); 


void printRoot2Leaf(Node * root, int idx){      //O(h^2) where h is the height of the tree. this function traverses untill
    if(root == NULL) return;                    //every leaf node and for every leaf node it is printing no. of elements 
                                                // from root to that leaf node
    // if leaf Node
    if (root->left == NULL && root->right == NULL){
        //append
        arr[idx] = root;
        printPath(arr, 0, idx);
        return; 
    }

    arr[idx] = root;
    printRoot2Leaf(root->left, idx + 1);
    printRoot2Leaf(root->right, idx + 1);
}

int main() {
   // Node * root = createBT();
    Node * root = inputLevel();
   printBT(root);
   cout<<endl;
    // printLevel(root);

    // int cntAns = cnt(root);
    // cout << cntAns << endl;

    // cout << height(root) << endl;

    // cout << diameter(root) << endl;

    // sumTree(root);
    // printLevel(root);

    // int ans = bestNonAdjSum(root);
    // cout << ans;

    // printKthLevel(root, 2);
    printRoot2Leaf(root, 0);

}
