#include "guerrier.h"

using namespace std;

Guerrier::Guerrier() : Personnage(),m_vie(105)
{



}

Guerrier::~Guerrier()
{


}
//-------------------------------------------------------

void Guerrier::affiche() const
{

    cout << "Ceci est un Guerrier avec  " << m_vie<< " hp " << endl;

}
