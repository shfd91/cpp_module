#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &);
		Intern &operator=(const Intern &);
		~Intern();
		Form *makeForm(std::string form, std::string target);
		Form *newPrsident(std::string target);
		Form *newRobotomy(std::string target);
		Form *newShrubbery(std::string target);
		class NotFoundException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

#endif