#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Parti.hh"


#define NB_PARTI 4
#define NB_LOBBY 2


Parti::Parti(){
    int j = rand()%(THEME_PARTI);
    switch (rand()%NB_PARTI)
    {
        case 0 :
            _nom = nom_p[0];
            for(int i = 0; i < NB_LOBBY; i++)
                _lobby.push_back(p_agressif[j][i]);
                break;

        case 1 : 
            _nom = nom_p[1];
            for(int i = 0; i < NB_LOBBY; i++)
                _lobby.push_back(p_peace[j][i]);
            break;

         case 2 : 
            _nom = nom_p[2];
            for(int i = 0; i < NB_LOBBY; i++)
                _lobby.push_back(p_timbre[j][i]);
            break;

        case 3 : 
            _nom = nom_p[3];
            for(int i = 0; i < NB_LOBBY; i++)
                _lobby.push_back(p_cuisine[j][i]);
                break;

        default : 
            _nom = nom_p[4];
            for(int i = 0; i < NB_LOBBY; i++)
                _lobby.push_back(p_maths[j][i]);
            break;
        }

}
bool Parti::operator<(const Parti & p)const{
	return this->_nom < p._nom;
}
std::string Parti::get_nom()const{
	return this->_nom;
}
std::vector<std::string> Parti::get_lobby() const{
	return this->_lobby;
}
// ======== Ajout perso ==========
/*std::string Parti::get_nom_p() const{
    return this->nom_p;
}
*/

//short Parti::_id 	= 0;

const std::string Parti::nom_p[MAX_P] = {"agressif","peace","timbré","cuisine","Matheux"};

const std::string Parti::p_agressif[THEME_PARTI][NB_LOBBY] =    {{"AK","grenades"},
                                                                {"bombe","mines"},
                                                                {"lapins","chasse"}};
const std::string Parti::p_peace[THEME_PARTI][NB_LOBBY] =       {{"fleurs","chatons"},
                                                                {"arbres","oiseaux"},
                                                                {"chihuahua","soja"}};
const std::string Parti::p_timbre[THEME_PARTI][NB_LOBBY] =      {{"fil électrique","stylo bleu, juste le bleu"},
                                                                {"tobogans","prise électrique"},
                                                                {"cochons","papaille"}};
const std::string Parti::p_cuisine[THEME_PARTI][NB_LOBBY] =     {{"choux","carrotte"},
                                                                {"artichauts","poivron"},
                                                                {"Flamenkuch","pizza"}};
const std::string Parti::p_maths[THEME_PARTI][NB_LOBBY] =      {{"Des chiffres"," Et des chiffres"},
                                                                {"2 + x = 12","Triiigonométriiiie"},
                                                                {"Thales","Pour ton chien"}};   // Ok j'avoue c'est nul mdrrr

Parti::~Parti()
{
    
}