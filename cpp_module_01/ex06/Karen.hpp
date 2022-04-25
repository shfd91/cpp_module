#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	insignificant(void);
	public:
		void	complain(std::string level);
};

#endif