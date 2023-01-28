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


int main()
{
    struct Node* Root = new Node(1);
    

    return 0;
}