#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "Parti.hh"
//#include "Pays.h"
//#include "Federation.h"
//#include "Federation.h"

#define NB_PAYS_MAX 20
#define MAX_P 5



void note(std::ostringstream & notes){
	std::cout<<"Veuillez entrer une note (une ligne)"<<std::endl;
	std::string str;
	std::cin>>str;
	notes << str;
}

void afficherNote(std::ostringstream& notes){
	std::cout<<"Voici vos notes:"<<std::endl;
	std::cout<<notes.str()<<std::endl;
}

int action(short sondages){
	char reponse_action;
	std::cout<<"Que voulez vous faire? (s:sondage | r:rien | n:note | a:afficher les notes)"<<std::endl;
	std::cout<<"Sondage restant:"<<sondages<<std::endl;
	do{
		std::cin>>reponse_action;
	}while(reponse_action!= 'r' && reponse_action != 's' && reponse_action != 'n' && reponse_action != 'a');

	if(reponse_action== 's'){
		if(sondages > -1)
			return 1;
		return action(sondages);
	}

	else if(reponse_action == 'n'){
		return 2;
	}

	else if(reponse_action == 'a'){
		return 3;
    }

	else{
		return 0;
	}
}

void mode1(const std::set<Pays> monde, float *popularite) const{
	short sondages = 2;
	//int popularite = 50;

	std::ostringstream notes;
	notes.str("");


	std::cout<<"Debut de la partie"<<std::endl;

    std::cout<<"Entrer votre nom"<<std::endl;
    std::cin >> nom_user;

    // nb_tours = nb_pays
	for(const auto& iter : monde){
//        if(popularite > 100 ) popularite = 100;
//        if(popularite < 0 ) popularite = 0;

        std::cout << " Ta popularité est de : " << popularite << " % " << std::endl;
		std::cout << iter.display() << std::endl;

    // Event
        x = rand()%10;
        if (x < 5) event(popularite, iter);


    // Action
		switch(action(sondages))
		{
			case 1:
				sondage--;
				iter.sondage(monde);
				break;

			case 2:
				note(notes);
				break;

			case 3:
				afficherNote(notes);
                break;
			default: std::cout << " Aucune action" << std::endl;
				break;
		}
	}
}

bool replay(){
	char r;
	do{
		std::cout<<"replay? (o/n)"<<std::endl;
		std::cin>>r;
	}while(r!= 'o' && r != 'n');

	if(r == 'o')    return true;
	return false;
}

void jeu(const std::set<Pays> monde)const{
	bool replay = true;
	while(replay)
	{
		mode1(monde);
		replay = replay();
	}
}

void initm(std::set<Pays>& monde /*, const std::vector<Parti>& p*/){
	int nb_pays;
	char r;

	std::cout<<"Creation du monde"<<std::endl;
	do{
		std::cout<<"Nombre de pays? (" << NB_PAYS_MAX <<" max)"<<std::endl;
		std::cin>>nb_pays;
	}while(nb_pays > NB_PAYS_MAX || nb_pays <1);

	while(monde.size() < nb_pays){
		switch(rand()%2)
		{
			case(0):
				monde.insert(Federation());
				break;
			case(1):
				monde.insert(NFederation());
				break;
			default:
				std::cout<<"Erreur création dans le monde"<<std::endl;
		}
	}

	do {
	std::cout<<"Quel difficultée ? f:Facile | n:Normale | d:difficile "<<std::endl;
	std::cin>>r;

	if(r == 'f')        popularite[] = {45,1.2,1.2,1.2,1.2};
    else if(r == 'n')   popularite[] = {30,1,1,1,1};
    else if(r == 'd')   popularite[] = {10,0.8,0.8,0.8,0.8};
    }while(r!= 'f' && r != 'n' && r != 'd');



}


int event(int *popularite, Pays iter){      // Pays iter <=> erreur possible, use template ?
    int x = rand()%10);

        if (x = 1) monde[iter].modif_parti();
        else if(x = 2) monde[iter].cataclysme();
        else if(x = 3) monde[iter].babyboom();

       // else return popularite + Discour(); // popularité + 10% !
        else {
            for(int i = 0; i < 4; i++){
                popularite[i] = popularite[i] + Discour()[i];   // ptete merde avec retour Discour()
            }

        }


        return popularite;

    }
}

float* Discour(){
    std::cout << "Il est l'heure du DididididiDiscour..." << std::endl;
    int reponse = 0;

    std::cout << " QCM " << std::endl;

    int question = rand()%10;

    if(question == 1) {

        std::cout << " Le quel de ces pays n'existe pas dans ce jeu" << std::endl;
        std::cout << " ZarbiLand (1), Zarabiland (2), Zarbilland (3) ou Zarabilland (4) ? " << std::endl;
        std::cin >> reponse;

        if(reponse = 1) return 10;
        else return -10;
    }
    else if (question == 2){


    }

    return
}



int main()
{
	srand(time(NULL)); //TODO: ENLEVER DES AUTRES FICHIERS
	std::set<Pays> monde;
	float popularite[4];

	//std::vector<Parti> partis;

	//**Creation des Partis**/
	//initp(partis);

	/**Creation du monde**/
	initm(monde, popularite);

	/** Déroulement du jeu **/
	mode1(monde, popularite);


}
