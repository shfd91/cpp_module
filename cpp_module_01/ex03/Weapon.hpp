#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string str);
		void setType(std::string str);
		const std::string &getType();
};

#endif