#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>

#include "Federation.hh"
#include "Democratie.hh"


Federation::Federation()
:Pays(rand()%3+3)
,_id(rand()%5)
{}

void Federation::sondage()
{}


void Federation::display()
{
	printf("display_federation");
	
}

Federation::~Federation()
{

}