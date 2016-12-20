#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>


#include "Pays.hh"

class Tyrannie: virtual public Pays
{
	public:
		Tyrannie();
		virtual std::string display();
	private:
};