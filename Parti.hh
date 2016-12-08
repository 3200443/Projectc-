#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include <set>

#define MAX_P 5

class Parti
{
	public:
		Parti();
		~Parti();
		std::string get_nom()const;
		std::set<std::string> get_lobby() const;
		bool operator<(const Parti &)const;
	private:
		std::string _nom;
		std::vector<std::string> _lobby;
		static short _id;

		static const std::string nom_p[MAX_P];
		static const std::string p_agressif[MAX_P][2];
		static const std::string p_peace[MAX_P][2];
		static const std::string p_timbre[MAX_P][2];
		static const std::string p_cuisine[MAX_P][2];
		static const std::string p_defaut[MAX_P][2];
};
