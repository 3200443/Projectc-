#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>

#include "Pays.hh"

class Democratie : virtual public Pays
{
	public:
		Democratie();
		virtual void sondage();
		virtual std::string display() const;
	private:
};