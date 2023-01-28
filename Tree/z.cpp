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


void Inorder(Node* Tree)
{
    if(NULL == Tree)
        return;
    
    Inorder(Tree->left);
    cout << Tree->data <<" ";
    Inorder(Tree->right);
}

void Postorder(Node* Tree)
{
    if(NULL == Tree)
        return;
    
    Inorder(Tree->left);
    Inorder(Tree->right);
    cout << Tree->data <<" ";
}


int main()
{
    struct Node* Root = new Node(1);
    

    return 0;
}