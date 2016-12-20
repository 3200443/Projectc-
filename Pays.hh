#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>

#include "Parti.hh"

class Pays
{
	public:
		Pays(int);
		virtual void sondage();
		bool operator<(const Pays &)const;
		virtual void display();
	private:
		std::string creer_nom();
		std::map<Parti,int>creer_partis(int n);
	protected:
		int _nbHab;
		const std::string _nom;
		std::map<Parti,int> _partis;
};