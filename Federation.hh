#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>

#include "Parti.hh"
#include "Democratie.hh"


class Federation : public Democratie
{
	public:
		Federation();
		virtual ~Federation();
		std::string display();
		void sondage();
	private:
		const int _id;
};