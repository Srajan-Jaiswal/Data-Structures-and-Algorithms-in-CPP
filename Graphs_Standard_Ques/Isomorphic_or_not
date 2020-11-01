#include <iostream>
using namespace std;

struct BNode
{
    int data;
    BNode *left;
    BNode *right;
};

BNode *createNode(int data)
{
    BNode *temp = new BNode();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void insertNode(BNode *root, int data)
{
    queue<BNode *> nq;
    nq.push(root);

    while (!nq.empty()) {
        root = nq.front();
        nq.pop();

        if (!root->left) {
            root->left = createNode(data);
            break;
        } else {
            nq.push(root->left);
        }
        
        if (!root->right) {
            root->right = createNode(data);
            break;
        } else {
            nq.push(root->right);
        }
    }
    return;
}

bool isIsomorphic(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;

    if ((!root1 && root2) || (root1 && !root2))
        return false;

    return isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
}

int main()
{
    Node *root1 = nullptr;
    Node *root2 = nullptr;

    // Tree 1
    insertNode(root1, 100);
    insertNode(root1, 200);
    insertNode(root1, 3);
    insertNode(root1, 2);
    insertNode(root1, 7);

    // Tree 2
    insertNode(root2, 200);
    insertNode(root2, 300);
    insertNode(root2, 3);
    insertNode(root2, 2);
    insertNode(root2, 7);

    (isIsomorphic(root1, root2)) ? cout << "Are Isomorphic.." << '\n' : cout << "Not Isomorphic" << '\n';
}
