#include "Logicos.h"
#include <cstdlib>

Logicos::Logicos(int difficulte)
{
   //Init
    _cmt = (difficulte+1) * 2 ;
    _score_jeu = (difficulte+1) * 2 ;  // facile = 2, normale = 4; difficile = 6;
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
