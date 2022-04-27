#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat a("a", 1);
	Intern intern;
	Form *form;

	form = intern.makeForm("ShrubberyCreationForm", "shru");
	a.executeForm(*form);
	std::cout << std::endl;

	form = intern.makeForm("RobotomyRequestForm", "robot");
	a.executeForm(*form);
	std::cout << std::endl;

	form = intern.makeForm("PresidentialPardonForm", "president");
	a.executeForm(*form);


	return (0);
}