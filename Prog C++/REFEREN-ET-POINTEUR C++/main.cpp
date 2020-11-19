#include <iostream>
#include <string>
#include <memory>
using namespace std;


int fonction1(int &x);// par reference
int fonction2(int *p); // par pointeur / adresse
int main()
{

    /*
    int number{0};
    std::string name;
    std::unique_ptr<int> pt{std::make_unique<int>(16)};

    std::cout << "Entrer un nombre : ";

    std::cin >> number;
    std::cout << "Nombre : " << number << std::endl;
   	std::cin.ignore();
    std::cout << "Entrer un nombre : ";
    std::getline(std::cin,name);
    std::cout << "Nombre : " << name << std::endl;
    cout << *pt << std::endl;
    */

    int a = 845;
    cout << fonction1(a) << endl; // par reference
    cout << a << endl;
    a = 845;
    cout << fonction2(&a) << endl; // par pointeur / adresse
    cout << a << endl;


    return 0;
}

int fonction2(int *p) // par pointeur / adresse
{
    return *p = *p*5;
}

int fonction1(int &x) // par reference
{
    return x = x*4;
}
