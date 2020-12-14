#include <iostream>
#include <vector>

using namespace std;

void addInv(int x,vector<int>& invv);
int delInv(int x);

int main()
{

    vector<int> inv;
    addInv(15,inv);
    cout << inv[0];

}

void addInv(int x,vector<int> &invv)
{

            invv.push_back(x);

}

int delInv(int x)
{

}
