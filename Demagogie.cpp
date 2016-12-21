#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "Parti.hh"
#include "Pays.hh"
#include "Federation.hh"
#include "NFederation.hh"

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

float* Interaction(){
    std::cout << "Il est l'heure du DididididiDiscour..." << std::endl;
    float resultat [5]= {0,0,0,0,0};
    int reponse;

    std::cout << " QCM " << std::endl;

    int question = rand()%10;

    if(question == 1) {

        std::cout << " Le quel de ces pays n'existe pas dans ce jeu" << std::endl;
        std::cout << " ZarbiLand (1), Zarabiland (2), Zarbilland (3) ou Zarabilland (4) ? " << std::endl;
        std::cin >> reponse;

        if(reponse == 1) resultat[0] = 5;
        else resultat[0] = -5;

        return resultat;
    }


    else if (question == 2){
        std::cout << " Jeu pour le partie agressif " << std::endl;

        /**
            bouton va apparaitre aléatoirement sur la fenetre pour un temps court et une taille aléatoire,
            si click, score++ ;
            => avoir un score d'une certaine valeur

        **/


    }

    //return
}

float* event(float *popularite, Pays iter, std::set<Pays> monde){      // Pays iter <=> erreur possible, use template ?
    int x = rand()%10;
/*
       switch (x){
                case 0 : monde.find(iter).modif_parti();	//monde[iter].modif_parti(); // Partie du pays "iter" change aléatoirement // use "monde.erase()" pour remplacer
                    break;
                case 1 : monde[iter].cataclysme();  // nb_habitant pays "iter" diminue
                    break;
                case 2 : monde[iter].babyboom();    // nb_habitant pays "iter" augmente
                    break;

                default :
                        for(int i = 0; i < 5; i++){
                            popularite[i] = popularite[i] + Interaction()[i];   // Remplis toutes les cases de la popularité
                        }
                    break;
        }
*/
        return popularite;    
}

void mode1(std::set<Pays> monde, float *popularite){
	short sondages = 2;
	std::string nom_user;
	//int popularite = 50;

	std::ostringstream notes;printf("##########");
	notes.str("");


	std::cout<<"Debut de la partie"<<std::endl;

    std::cout<<"Entrer votre nom"<<std::endl;
    std::cin >> nom_user;

    // nb_tours = nb_pays
	for(auto& iter : monde){

   		// Vérifications
        for(int i = 1; i < MAX_P; i++) {
            if(popularite[i] > 1 ) popularite[i] = 1;
            if(popularite[i] < 0 ) popularite[i] = 0;

        }

    	// Affichage popularité
        std::cout << " Ta popularité est de : " << popularite[0] << " % " << std::endl;

     /*   for(int i = 0; i < MAX_P; i++){
            std::cout << " Ta popularité dans le partie " <<  nom_p[i]  << " est de : " << popularite[i+1] *100 << " % " << std::endl;
        }
*/
    	// Affichage info pays      // Partie | nb_habitants | ?
		std::cout << iter.display() << std::endl;		// Pays = virtual //TODO: redefinir partout la fonction display avec un const!!

    	// Event
        int x = rand()%2;
        if (x) event(popularite, iter, monde);


    	// Action
		switch(action(sondages))
		{
			case 1:
				sondages--;
				//iter.sondage(monde);	// Pays = virtual TODO: redefibir la fonction sondage en consequence
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
/*
bool replay(){
	char r;
	do{
		std::cout<<"replay? (o/n)"<<std::endl;
		std::cin>>r;
	}while(r!= 'o' && r != 'n');

	if(r == 'o')    return true;
	return false;
}
*/
/*
void jeu(const std::set<Pays> monde)const{
	bool replay = true;
	while(replay)
	{
		mode1(monde);
		replay = replay();
	}
}
*/

void initm(std::set<Pays>& monde, float *popularite){
	int nb_pays;
	char r;

	std::cout<<"Creation du monde"<<std::endl;
	do{
		std::cout << "Nombre de pays? (" << NB_PAYS_MAX <<" max)"<<std::endl;
		std::cin >> nb_pays;	printf("##########");

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

		if(r == 'f'){       
			popularite[0] = 45;
			for(int i = 1; i < 5; i++)
				popularite[i] = 1.2;
		}

  		else if(r == 'n'){
			popularite[0] = 30;
			for(int i = 1; i < 5; i++)
				popularite[i] = 1;
    	}

   		else if(r == 'd'){
    		popularite[0] = 10;
			for(int i = 1; i < 5; i++)
				popularite[i] = 0.8;
   		}   

    }while(r!= 'f' && r != 'n' && r != 'd');
}






int main()
{
	srand(time(NULL)); //TODO: ENLEVER DES AUTRES FICHIERS
	std::set<Pays> monde;
	float popularite[5];

	//std::vector<Parti> partis;

	//**Creation des Partis**/
	//initp(partis);

	/**Creation du monde**/
	initm(monde, popularite);

	/** Déroulement du jeu **/
	mode1(monde, popularite);


}
