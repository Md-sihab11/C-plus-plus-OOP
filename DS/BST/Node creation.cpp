
#include<bits/stdc++.h>
using namespace std;

//node create

class Node{
    public:
    int key;
    Node* right;
    Node* left;

    //constructor
    Node(int val)
    {

        key=val;
        right=left=NULL;
    }

};

int main()
{
    Node* root = new Node(20);

     //root->key =100;

    cout<<"The value is now: "<<root->key<<endl;


}
