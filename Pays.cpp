#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <cassert>

#include "Pays.hh"
#include "Parti.hh"


///////////////////////////////////////////////////////////////////////////////
std::string Pays::creer_nom()
{
	int i = 0;
    int nbLignes = 0;
    std::string ligne;
    std::string contenu;
    std::ifstream fichier("nom_pays.txt", std::ios::in);
    if(fichier)
    {
        while(std::getline(fichier, ligne)){
            nbLignes++;
        }
        //retour debut fichier
        fichier.clear();
        fichier.seekg(0,std::ios::beg);
        // Affiche nom aléatoire
        int n = rand()%nbLignes;
        while(i < n){
            std::getline(fichier, contenu);
            i++;
        }
        fichier.close();
    }else
    {
        printf("ERROR le fichier de nom n'existe pas!!!\n");
        exit(-1);
    }
    return contenu;
}
///////////////////////////////////////////////////////////////////////////////
std::map<Parti, int> Pays::creer_partis(int n)
{
    assert(n>0);
	std::map<Parti,int> partis;
	while(partis.size() < (unsigned)n)
	{
		partis.insert(std::make_pair(Parti(), 1));//TODO: TESTER SIZE POUR SAVOIR SI UN NEW EST NECESSAIRE
	}
	return partis;
}
///////////////////////////////////////////////////////////////////////////////
Pays::Pays(int n)
:_nom(creer_nom())
,_partis(creer_partis(n))
{
	_nbHab=0;
	for(const  auto& iter : _partis)
  	{
    	_nbHab+= iter.second;
  	}
}
///////////////////////////////////////////////////////////////////////////////
bool Pays::operator<(const Pays & p) const
{
	return this->_nom < p._nom;
}
///////////////////////////////////////////////////////////////////////////////
void Pays::sondage()
{

}
///////////////////////////////////////////////////////////////////////////////
std::string Pays::display()
{

}