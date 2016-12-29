#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cassert>

#include "Labyrinthe.hh"




void Labyrinthe::creer_lab(int row, Noeud* p)
{
    if(row >0)
    {
        for(int i = 0 ; i < rand()%4; i++)
            p->suivants.push_back(new Noeud);
        for(auto & iter : p->suivants)
        {
            iter->precedent = p;
            iter->isArrivee = false;
            creer_lab(row-1,iter);
        }
    }
}

void Labyrinthe::creer_lab_fin(Noeud* p)
{
    Noeud* temp;
    int i = 0;
    int lim = rand()%(p->suivants.size());
    if(p->suivants.size() > 0)
    {
        for(auto & iter: p->suivants)
        {
            if(i == lim)
                temp = iter;
            i++;
        }
    creer_lab_fin(temp);
    }else
    {
        p->isArrivee = true;
    }
}

Labyrinthe::Labyrinthe(int difficultee)
{
	_tete = new Noeud;
    _tete -> precedent = NULL;
    _tete ->isArrivee = false;
	_location = _tete;

    switch(difficultee)
    {
        case 0:
            creer_lab(4,_tete);
            break;
        case 1:
            creer_lab(8, _tete);
            break;
        case 3:
            creer_lab(12,_tete);
            break;
    }
    creer_lab_fin(_tete);
}

void Labyrinthe::detruire_lab(Noeud* p)
{
    if(p->suivants.size() > 0)
    {
        for(auto & iter: p->suivants)
        {
            detruire_lab(iter);
        }

    }else
    {
        delete p;
    }
}

Labyrinthe::~Labyrinthe()
{
    detruire_lab(_tete);
    delete _tete;
}
