#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>


#include "Democratie.hh"
#include "Tyrannie.hh"

class NFederation: public Democratie, public Tyrannie
{
	public:
		NFederation();
		virtual~NFederation();
		void display();
		void sondage();
	private:
		int init();
		char _type;
};