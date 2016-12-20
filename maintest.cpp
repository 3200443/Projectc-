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



int main()
{
	srand(time(NULL)); //TODO: ENLEVER DES AUTRES FICHIERS
	std::set<Pays> monde;
	monde.insert(Federation());
	monde.insert(NFederation());
	return 0;
}