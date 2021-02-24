#include <iostream>
#include <queue>
#include <climits>
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

Node* createBT() {
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

//Time Complexity :O(n)
void printBT(Node * root) {
    if (root == NULL) {
        return;
    }

    printBT(root->left);
    cout << root->data << " ";
    printBT(root->right);
}

void inputArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) cin >> arr[i];
}

int search(int arr[], int si, int ei, int x) {
    while (si <= ei) {
        if (arr[si] == x) return si;
        ++si;
    }
    return -1;
}

int idx = 0;

//Time Complexity:O(n) 
Node * buildTree(int inOrder[], int inStart, int inEnd, int preOrder[]) {  
    if (inStart > inEnd) return NULL;

    Node * root = new Node(preOrder[idx]);   
    ++idx;

    int pos = search(inOrder, inStart, inEnd, root->data);
    root->left = buildTree(inOrder, inStart, pos - 1, preOrder);
    root->right = buildTree(inOrder, pos + 1, inEnd, preOrder);
    return root;
}

void printLevel(Node * root) {
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

Node * buildBST() {
    int x;
    Node * root = NULL;
    Node * insertBST(Node *, int);
    while (true) {
        cin >> x;
        if (x == -1) break;
        root = insertBST(root, x);
    }
    return root;
}
//Time Complexity : O(log n)
Node * insertBST(Node * root, int d) {
    if (root == NULL) {
        Node * newNode = new Node(d);
        return newNode;
    }

    if (d < root->data) {
        root->left = insertBST(root->left, d);
    }
    else {
        root->right = insertBST(root->right, d);
    }
    return root;
}

//Time Complexity : O(n) 
void printRange(Node * root, int K1, int K2) {
    if (root == NULL) return;

    if (root->data < K1) printRange(root->right, K1, K2);
    else if (root->data > K2) printRange(root->left, K1, K2);
    else {
        printRange(root->left, K1, K2);
        if (root->data >= K1 && root->data <= K2) cout << root->data << " ";
        printRange(root->right, K1, K2);
    }
}

//Time Complexity: O(n)
bool isIdentical(Node* A, Node * B) {
    if (A == NULL && B == NULL) return true;

    if (A == NULL || B == NULL) return false;

    return (A->data == B->data) && isIdentical(A->left, B->left) &&
           isIdentical(A->right, B->right);
}

//Time Complexity : O(n)
bool isBst(Node * root, int minVal, int maxVal) {
    if (root == NULL) return true;
    return (root->data >= minVal && root->data <= maxVal) &&
           isBst(root->left, minVal, root->data) &&
           isBst(root->right, root->data, maxVal);
}

//Time Complexity :O(n)
typedef pair<Node *, Node *> nn;    //head , tail
nn getSortedLL(Node * root) {
    if (root == NULL) {
        return nn(NULL, NULL);
    }

    nn left = getSortedLL(root->left);
    nn right = getSortedLL(root->right);
    nn ans (NULL, NULL);

    //setting head
    if (left.first) {
        ans.first = left.first;
        Node * tail = left.second;
        tail->right = root;
        root->left = tail;
    }
    else {
        ans.first = root;
    }

    //setting tail
    if (right.first) {
        root->right = right.first;
        right.first->left = root;
        ans.second = right.second;
    }
    else {
        ans.second = root;
    }
    return ans;
}


// int cnt = 0;

//Time Complexity : O(k) , k=kth smallest node to be searched
Node * kSmallestNode(Node * root, int &cnt,  int K) {
    //tells the kth smallest node and also sets the no. of read
    if (root == NULL) return NULL;

    Node * ans = kSmallestNode(root->left, cnt, K);
    ++cnt;

    if (ans != NULL) return ans;

    if (cnt == K) {
        return root;
    }

    return kSmallestNode(root->right, cnt, K);
}

//Time Complexity: O(log n)
Node * lcaBST(Node * root, int d1, int d2){
    if (root == NULL) return NULL;

    if (d1 > d2) swap(d1, d2);

    if (root->data >= d1 && root->data <= d2){
        return root;
    }

    if (root->data < d1) return lcaBST(root->right, d1, d2);

    return lcaBST(root->left, d1, d2);
}

//Time Complexity : O(n)
void printDLL(Node * head) {
    Node * cur =  head;
    while (cur) {
        //prev to head
        cout << "(" << (cur->left ? cur->left->data : 0) << ")";
        cout << cur->data;
        cout << "(" << (cur->right ? cur->right->data : 0) << ")";
        cout << " <--> ";
        cur = cur->right;
    }
    cout << endl;
}

int main() {
    // int inOrder[10];
    // int preOrder[10];
    // int n1, n2;
    // cin >> n1 >> n2;
    // inputArr(inOrder, n1);
    // inputArr(preOrder, n2);

    // Node * root = buildTree(inOrder, 0, n1 - 1, preOrder);

    // Node * root = buildBST();
    // printLevel(root);

    // printRange(root, 10, 20);

    Node * root = createBT();
    // Node * toor = createBT();
    // cout << isIdentical(root, toor) << endl;

    // cout << isBst(root, INT_MIN, INT_MAX);

    // nn ans = getSortedLL(root);
    // printDLL(ans.first);
    // int k; cin >> k;
    // int cnt = 0;

    // Node * ans = kSmallestNode(root, cnt, k);
    // cout << ans << " " << ans->data << endl;

    int a, b; cin >> a >> b;
    Node * ans = lcaBST(root, a, b);
    cout << ans << "  " << ans->data << endl;
}
