
#include<bits/stdc++.h>
using namespace std;
class my
{
public:

    //creates constructors
    int a;
    string b;

    my(int x, string y)
    {
        a=x;
        b=y;
    }
    void display()
    {
        cout<<a<<endl<<b<<endl;
        //cout<<b;

    }
};
int main()
{
    my s1(20,"Shkib");
    s1.display();

}
