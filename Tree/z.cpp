#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int Val)
    {
        data = Val;
        left = NULL;
        right = NULL;
    }
    
};

void Preorder(Node* Tree)
{
    if(NULL == Tree)
        return;

    cout << Tree->data <<" ";
    Preorder(Tree->left);
    Preorder(Tree->right);
}


int main()
{
    struct Node* Root = new Node(1);
    

    return 0;
}