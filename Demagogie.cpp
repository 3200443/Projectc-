#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cassert>

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
	notes << str+"\n";
	std::cout <<std::endl;
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

void Interaction(float resultat[5]){
    std::cout << "Il est l'heure du DididididiDiscour..." << std::endl;
    //int resultat[5] = {0,0,0,0,0};
    int reponse = -1;
    std::string tampon;
    //bool ToF = false;


    int question;
    switch(question = rand()%10)
    {
    	case 1:
	        std::cout << " Jeu general " << std::endl;
	        std::cout << " QCM " << std::endl;
	        std::cout << " Appuyez sur une touche quand vous êtes pret " << std::endl;
	    	std::cin >> tampon;

	    	std::cout << " Le quel de ces pays n'existe pas dans ce jeu" << std::endl;
	        std::cout << " ZarbiLand (1), Zarabiland (2), Zarbilland (3) ou Zarabilland (4) ? " << std::endl;
	        std::cin >> reponse;

	        if(reponse == 1) resultat[0] = 5;
	       // else resultat = -1;

	       break;


   		case 2:
	        std::cout << " Jeu pour le parti agressif " << std::endl;

	        /**
	            bouton va apparaitre aléatoirement sur la fenetre pour un temps court et une taille aléatoire,
	            si click, score++ ;
	            => avoir un score d'une certaine valeur

	        **/
	        if(reponse == 1) resultat[1] = 5;
	       break;

   		case 3:
	    	std::cout << " Jeu pour le parti peace " << std::endl;
	    	std::cout << " Appuyez sur une touche quand vous êtes pret " << std::endl;
	    	std::cin >> tampon;

	    	std::cout << " Combien de 'z' sont présents dans le mot qui va suivre " << std::endl;
	    	std::cout << " zz2z2zzzzzzzz22zzzzz2zzz222zzzz " << std::endl;

			std::cout<< "début" << std::endl;
			for(int i = 0; i < 2000000000; i++){	// environ 6 sec //TODO: BIEN PLUS LONG QUE CA CHEZ MOI
			}
			std::cout << "Réponse ? " << std::endl;
			std::cin >> reponse;
	    	if(reponse == 24) resultat[2] = 5; //TODO faire directement return 3
	    	//else resultat = -3;
	    	break;

    	case 4:
	    	std::cout << " Jeu pour le parti zinzin " << std::endl;
	    	std::cout << " Appuyez sur une touche quand vous êtes pret " << std::endl;
	    	std::cin >> tampon;//TODO: ENTRE N EST PAS UNE TOUCHE!!!!! voir si y a pas de fonction get key

	    	std::cout << " Voici une liste d'objets, vous devez en mettre 2 ensembles de la forme suivante : 45 pour les objets 4 et 5 par exemple. Vous avez 2 essais  " << std::endl;
	    	std::cout << " Pommeau de douche(1), Stylo bleu(2), Regle graduee(3), Lance-flamme(4), Flute a bec(5), Ballon de foot(6), Fourchette(7)" << std::endl;

    		std::cin >> reponse;
    		if(reponse == 12 || reponse == 21){
    			//ToF = true;
    			std::cout << "Gagne" << std::endl;
    			resultat[3] = 5;
    		}else
    		{
	    		std::cout << "Rate" << std::endl;

		    	std::cout << "C'etait simple.. fallait mettre 12 ! Tous les autres sont des objets que tu avais au collège !" << std::endl;
		    }
		    break;

    	default:
    		std::cout << "ou pas"<<std::endl;
    }
}

void event(float *popularite, Pays iter, std::set<Pays> monde){      // Pays iter <=> erreur possible, use template ?
    //int x = rand()%10;											//CHANGE EN VOID: RETOURNER POPULARITE EST INUTILE!!!!
    float resultat[5] = {0};
    Interaction(resultat);
/*
       switch (x){
                case 0 : monde.find(iter).modif_parti();	//monde[iter].modif_parti(); // Partie du pays "iter" change aléatoirement // use "monde.erase()" pour remplacer
                    break;
                case 1 : monde[iter].cataclysme();  // nb_habitant pays "iter" diminue
                    break;
                case 2 : monde[iter].babyboom();    // nb_habitant pays "iter" augmente
                    break;

                default :*/
                        for(int i = 0; i < 5; i++){  //TODO: ce 5 me perturbe
                            popularite[i] = popularite[i] + resultat[i];   // Remplis toutes les cases de la popularité
                        }
                   // break;
        //}
}

void mode1(std::set<Pays> monde, float *popularite){
	short sondages = 2;
	bool verrou = false;
	std::string nom_user;
	//int popularite = 50;

	std::ostringstream notes;
	notes.str("");


	std::cout<<"Debut de la partie"<<std::endl;

    std::cout << "Entrer votre nom"<<std::endl;
    std::cin >> nom_user;
    std::cout << std::endl<<std::endl;
    // nb_tours = nb_pays
	for(auto& iter : monde)
	{

   		// Vérifications
        for(int i = 1; i < MAX_P; i++) {
            if(popularite[i] > 1 ) popularite[i] = 1;
            if(popularite[i] < 0 ) popularite[i] = 0;

        }

    	// Affichage popularité
        std::cout << "Ta popularité est de : " << popularite[0] << " % " << std::endl;

/* // POURQUOI GETNOM_P SA GALERE SERIEUX
        for(int i = 0; i < MAX_P; i++){
            std::cout << " Ta popularité dans le partie " <<  get_nom_p[i]  << " est de : " << popularite[i+1] *100 << " % " << std::endl;
        }
*/
    	// Affichage info pays      // Partie | nb_habitants | ?
		std::cout << iter.display() << std::endl;	

    	// Event
        int x = rand()%2;
        if (x) event(popularite, iter, monde);


    	// Action
    	while(!verrou)
    	{
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
					verrou = true;
					break;
			}
		}
	}
	//TODO: FIN DE PARTIE ICI!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!       <---------------------
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

void jeu(const std::set<Pays> monde , float *popularite)
{
	do
	{
		mode1(monde,popularite);
	}while(replay());
}

void initm(std::set<Pays>& monde, float *popularite){
	int nb_pays = 5;
	char r;
	std::string test;

	std::cout<<"Creation du monde"<<std::endl;
	do{
		std::cout << "Nombre de pays? (" << NB_PAYS_MAX <<" max)"<<std::endl;
		std::cin >> nb_pays;

	}while(nb_pays > NB_PAYS_MAX || nb_pays <1);
	//std::cout <<"?"<<std::endl;
	assert(nb_pays>0);
	//std::cout <<"?"<<std::endl;
	while(monde.size() < (unsigned)nb_pays){
		switch(rand()%2)
		{
			case(0):
				monde.insert(Federation());//std::cout << 0 <<std::endl;	// Sa bloque ici :/
				break;
			case(1):
				monde.insert(NFederation());//std::cout << 1 <<std::endl;
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
	srand(time(NULL));
	std::set<Pays> monde;
	float popularite[5];

	/**Creation du monde**/
	initm(monde, popularite);

	/** Déroulement du jeu **/
	//mode1(monde, popularite);
	jeu(monde,popularite);
}
