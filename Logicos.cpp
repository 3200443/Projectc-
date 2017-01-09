#include "Logicos.h"
#include <cstdlib>

Logicos::Logicos(int difficulte)
{
    switch(difficulte){
         case 0 : _cmt = 10;
            break;
         case 1 : _cmt = 7;
            break;
         case 2 : _cmt = 5;
            break;
    }

    _difficulte = difficulte;
    _score_jeu = 0;
    _val_rand = rand()%100;
    _reussi = false;

}


void Logicos::set_reponse(int nb){
    _reponse_user = nb;
}

int Logicos::get_val_rand(){
    return _val_rand;
}

int Logicos::get_score_jeu(){
    return _score_jeu;
}

void Logicos::set_score_jeu(){
    _score_jeu = (_difficulte+1) * 2 ;  // facile = 2, normale = 4; difficile = 6;
}

int Logicos::get_cmt(){
    return _cmt;
}

void Logicos::set_cmt(int nb){
    _cmt = nb;
}

bool Logicos::get_reussi(){
    return _reussi;
}

int Logicos::compare(){

    if(_reponse_user < _val_rand){
        _cmt--;
        return 1;
    }else if(_reponse_user > _val_rand){
        _cmt--;
        return 2;
    }else{
        _reussi = true;
        _cmt = 0;
        return 0;
    }

}
