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

Form *Intern::makeForm(std::string form, std::string target)
{
	try
	{
		const std::string formName[] = {	"shrubbery creation",
											"robotomy request",
											"presidential pardon" };
		int i = 0;
		while (i < 3 && form != formName[i])
			i++;
		switch (i)
		{
			case 0:
				std::cout << "Intern creates " << formName[i] << std::endl;
				return new ShrubberyCreationForm(target);
				break;
			case 1:
				std::cout << "Intern creates " << formName[i] << std::endl;
				return new RobotomyRequestForm(target);
				break;
			case 2:
				std::cout << "Intern creates " << formName[i] << std::endl;
				return new PresidentialPardonForm(target);
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
