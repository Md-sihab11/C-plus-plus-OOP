
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node* right;
    Node* left;

    Node(int value)
    {
        key = value;
        right = left = NULL;
    }
};

//now BST creation

class BST
{

public:
    Node* root;

    //first time setting Null int it.It has no child
    BST()
    {
        root = NULL;
    }
    //insertion part
    Node* insert(Node* root, int key)
    {
        if(root==NULL) return new Node(key); //no need to create in main fun again
        else  if(key < root->key)
        {
            root->left = insert(root->left, key);
        }
        else if(key > root->key)
        {
            root->right = insert(root->right, key);
        }
        return root;
    }
    void insert(int key)
    {
        root = insert(root, key);
    }

    void findpresuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(root ==NULL) return;

        if (root->key == key)
        {
            if(root->left != NULL)
            {
                Node* temp = root->left;
                while(temp->right != NULL)
                {
                    temp = temp -> right;
                }
                pre = temp;

            }
            if(root->right != NULL)
            {
                Node* temp = root->right;
                while(temp->left != NULL)
                {
                    temp = temp ->left;
                }
                suc = temp;
            }
           return;
        }
        if(key< root->key)
        {
            suc = root;
            findpresuc(root->left, pre, suc, key);
        }
        else{
            pre = root;
            findpresuc(root->right, pre, suc, key);
        }

    }

};

int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);

    int key=20; //set a value for finding pre & suc
    Node* pre=NULL;
    Node* suc= NULL;

    tree.findpresuc(tree.root, pre, suc, key);

     if(pre!=NULL)
     {
         cout<<"Pre "<<pre->key<<endl;
     }
     else{
        cout<<"No pre" <<endl;
     }
     if(suc!=NULL)
     {
         cout<<"Suc "<<suc->key<<endl;
     }
     else{
        cout<<"No Suc" <<endl;
     }


}
