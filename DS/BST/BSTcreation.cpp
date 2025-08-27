#include<bits/stdc++.h>
using namespace std;

class Node
{

public:

    int key;
    Node* right;
    Node* left;

    //constructor
    Node(int val)
    {
        key=val;
        right = left = NULL;
    }

};

class BST
{
public:

    Node* root;

    BST()
    {
        root = NULL;
    }

    Node* insert(Node* root, int key)
    {

        if(root==NULL) return new Node(key);

        else if(key < root->key)
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
        root= insert(root,key);
    }
    void findpresuc(Node* root, Node*& pre, Node*& suc, int key )
    {
        if(root == NULL) return;

        if (root->key ==key )
        {
            if(root->left != NULL)
            {
                Node* temp = root->left;
                while(temp->right !=NULL)
                {
                    temp = temp -> right;
                }
                 pre =temp;
            }
            if (root->right != NULL)
            {
                Node* temp = root->right;
                while(temp->left != NULL) //Null pele i off hoye jabe
                {
                    temp = temp ->left;
                }
                 suc = temp;

            }

        }

        if(key< root->key)
        {
            suc = root;
            findpresuc(root->left, pre,suc, key);

        }
        else
        {
            pre = root;
            findpresuc(root->right, pre,suc, key);
        }



    }

};

int main()
{
//    Node* root = new Node(30);
//    cout<<root->key<<endl;

    BST bst;
    bst.insert(30);
    bst.insert(60);
    bst.insert(20);

    int key = 10;
    Node* pre = NULL;
    Node* suc = NULL;

    bst.findpresuc(bst.root, pre, suc, key);


//    cout << "Root node: " << bst.root->key << endl;            // 5
//    cout << "Right child key: " << bst.root->right->key << endl;  // 60
//    cout << "Right-Left child key: " << bst.root->right->left->key << endl; // 20
    if(pre != NULL)
    {
        cout<<"Pre "<<pre->key<<endl;
    }
    else
    {
        cout<<"No pre\n" <<endl;
    }
    if(suc != NULL)
    {
        cout<<"Suc "<<suc->key<<endl;
    }
    else
    {
        cout<<"No suc \n"<<endl;
    }
}

