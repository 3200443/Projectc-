#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "NFederation.hh"
#include "Pays.hh"



int NFederation::init()
{
	switch(rand()%2)
	{
		case 0:
			_type = 'T';
			return 0;
		case 1:
			_type = 'D';
			return 4;
	}
	return 4;
}
NFederation::NFederation()
:Pays(1+init())
{}


void NFederation::sondage()
{}


void NFederation::display()
{
	printf("display_Nfederation");	
}