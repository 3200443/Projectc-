#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <set>
#include <ctime>
#include <cstdlib>

#include "Parti.hh"
#define NB_PARTI 4
#define THEME_PARTI 3


Parti::Parti(){

    srand(time(NULL));

		_nom = nom_p[rand()%NB_PARTI];

        switch (_id){
            case 0 : _lobby = p_agressif(rand()%THEME_PARTI);
                break;
            case 1 : _lobby = p_peace(rand()%THEME_PARTI);
                break;
            case 2 : _lobby = p_timbré(rand()%THEME_PARTI);
                break;
            case 3 : _lobby = p_cuisine(rand()%THEME_PARTI);
                break;
            default : _lobby = p_defaut(rand()%THEME_PARTI);
                break;
        }

}
bool Parti::operator<(const Parti p &)const{
	return this->_nom < p._nom;
}
std::string Parti::get_nom()const{
	return this->_nom;
}
std::set Parti::get_lobby() const{
	return *this->_lobby
}
Parti::_id 	= 0;
Parti::nom_p = {"agressif","peace","timbré","cuisine"};
Parti::p_agressif = {"AK","grenades"}{"bombe","mines"}{"lapins","chasse"};
Parti::p_peace = {"fleurs","chatons"}{"arbres","oiseaux"}{"chihuahua","soja"};
Parti::p_timbré = {"fil électrique","stylo bleu, juste le bleu"}{"tobogans","prise électrique"}{"cochons","papaille"};
Parti::p_cuisine = {"choux","carrotte"}{"artichauts","poivron"}{"Flamenkuch","pizza"};
Parti::p_defaut = {"a","A"}{"b","B"}{"c","C"};

