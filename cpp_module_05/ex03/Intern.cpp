#include "Intern.hpp"

Form *Intern::makeForm(std::string form, std::string target)
{
	try
	{
		const std::string formName[] = {	"ShrubberyCreationForm",
											"RobotomyRequestForm",
											"PresidentialPardonForm" };
		int i = std::find(formName, formName + 3, form) - formName;

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
			case 3:
				throw (NotFoundException());
		}
	}
	catch (std::exception &e)
	{
		std::cout << "The specified form could not be found. Reason : " << e.what() << std::endl;
	}
	return (NULL);
}

const char* Intern::NotFoundException::what(void) const throw()
{
	return ("NotFound");
}
