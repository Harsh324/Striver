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

vector<vector<int>> Level_order(Node* Tree)
{
    vector<vector<int>> Res;

    if(NULL == Tree)
        return Res;
    
    queue<Node*> Q;
    Q.push(Tree);

    while(Q.empty() != true)
    {
        int Sz = Q.size();
        vector<int> V;
        for(int i = 0; i < Sz; i++)
        {
            Node* node = Q.front();
            Q.pop();
            if(Tree->left != NULL)
                Q.push(Tree->left);
            if(Tree->right != NULL)
                Q.push(Tree->right);
            
            V.push_back(node->data);
        }
    }
    return Res;
}


vector<int> iter_preorder(Node* Tree)
{
    vector<int> Res;
    stack<Node*> St;

    
    Node* node = Tree;

    while(true)
    {
        if(NULL == node)
        {
            St.push(node);
            node = node->left;
        }
        else{
            if(St.empty() == true)
                break;
            node = St.top();
            St.pop();
            Res.push_back(node->data);
            node = node->right;
        }
    }
    return Res;
}



vector<int> iter_ineorder(Node* Tree)
{
    vector<int> Res;

    if(NULL == Tree)
        return Res;
    
    stack<Node*> St;
    St.push(Tree);

    while(St.empty() != true)
    {
        Tree = St.top();
        St.pop();
        Res.push_back(Tree->data);

        if(NULL == Tree->right)
            St.push(Tree->right);
        
        if(NULL == Tree->left)
            St.push(Tree->left);
    }
    return Res;
}



int main()
{
    struct Node* Root = new Node(1);
    

    return 0;
}