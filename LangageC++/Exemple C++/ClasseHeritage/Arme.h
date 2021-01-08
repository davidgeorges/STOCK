#ifndef DEF_ARME
#define DEF_ARME
#include <string>
#include <iostream>
using namespace std;


class Arme
{
private:
    int arme_degats;
    string arme_name;
public:
    Arme(/* args */);
    ~Arme();
    int getDegats();
    void setDegats(int);
    string getName();
};



#endif
