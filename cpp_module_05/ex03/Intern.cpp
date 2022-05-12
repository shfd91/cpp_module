#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &)
{

}

Intern &Intern::operator=(const Intern &)
{
	return (*this);
}

Intern::~Intern()
{

}

Form *Intern::newPrsident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::newRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form *Intern::newShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}


Form *Intern::makeForm(std::string form, std::string target)
{
	try
	{
		const std::string formName[] = {	"shrubbery creation",
											"robotomy request",
											"presidential pardon" };
		Form *(Intern::*funcs[])(std::string target) =
		{
			&Intern::newShrubbery,
			&Intern::newRobotomy,
			&Intern::newPrsident,
		};
		int i = 0;
		while (i < 3 && form != formName[i])
			i++;
		switch (i)
		{
			case 0:
				std::cout << "Intern creates " << formName[i] << std::endl;
				return ((this->*funcs[i])(target));
				break;
			case 1:
				std::cout << "Intern creates " << formName[i] << std::endl;
				return ((this->*funcs[i])(target));
				break;
			case 2:
				std::cout << "Intern creates " << formName[i] << std::endl;
				return ((this->*funcs[i])(target));
				break;
			default:
				throw (NotFoundException());
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (NULL);
}

const char* Intern::NotFoundException::what(void) const throw()
{
	return ("No matching form found");
}
