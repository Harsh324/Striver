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


vector<int> iter_postorder1(Node* Tree)
{
    vector<int> Res;
    if(NULL == Tree)
        return Res;

    stack<Node*> St1, St2;
    St1.push(Tree);

    while(St1.empty() != true)
    {
        Tree = St1.top();
        St1.pop();
        St2.push(Tree);

        if(Tree->left != NULL)
            St1.push(Tree->left);
        if(Tree->right != NULL)
            St1.push(Tree->right);
    }

    while(St2.empty())
    {
        Res.push_back(St2.top()->data);
        St2.pop();
    }
    return Res;
}



vector<int> iter_postorder2(Node* Tree)
{
    vector<int> Res;
    if(NULL == Tree)
        return Res;

    stack<Node*> St;
    Node* Curr = Tree;
    St.push(Tree);

    while(Curr != NULL || St.empty() != true)
    {
        if(Curr != NULL)
        {
            St.push(Curr);
            Curr = Curr->left;
        }
        else
        {
            Node* Temp = St.top()->right;
            if(Temp == NULL)
            {
                Temp = St.top();
                St.pop();
                Res.push_back(Temp->data);

                while(!St.empty() && Temp == St.top()->right)
                {
                    Temp = St.top();
                    St.pop();
                    Res.push_back(Temp->data);
                }
            }
            else
                Curr = Temp;
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


vector<int> PrePostIn(Node* Tree)
{
    stack<pair<Node*, int>> St;
    St.push({Tree, 1});
    vector<int> pre, in, post ;
    if(NULL == Tree)
        return;

    while(St.empty() != true)
    {
        auto It = St.top();
        St.pop();

        if(It.second == 1)
        {
            pre.push_back(It.first->data);
            It.second++;
            St.push(It);

            if(It.first->left != NULL)
                St.push({It.first->left, 1});
        }
        else if(It.second == 2)
        {
            in.push_back(It.first->data);
            It.second++;
            St.push(It);

            if(It.first->right != NULL)
                St.push({It.first->right, 1});
        }
        else
        {
            post.push_back(It.first->data);
        }
    }
}

int Max_Depth(Node* Tree)
{
    if(NULL == Tree)
        return 0;
    return 1 + max(Max_Depth(Tree->left), Max_Depth(Tree->right));
}

int Height(Node* Tree)
{
    if(NULL == Tree)
        return 0;

    int Left = Height(Tree->left);
    if(Left == -1)
        return -1;
    int Right = Height(Tree->right);
    if(Right = -1)
        return -1;
    if(abs(Left - Right) > 1)
        return -1;

    return 1 + max(Left, Right);
}

bool Check_balanced(Node* Tree)
{
    return Height(Tree) != -1;
}



int main()
{
    struct Node* Root = new Node(1);
    

    return 0;
}