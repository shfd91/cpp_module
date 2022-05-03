#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat a("a", 1);
	Form *form;
	Intern intern;

	form = intern.makeForm("empty", "empty");
	std::cout << std::endl;

	form = intern.makeForm("robotomy request", "Bender");
	a.signForm(*form);
	a.executeForm(*form);
	delete form;
	std::cout << std::endl;

	form = intern.makeForm("shrubbery creation", "shru");
	a.signForm(*form);
	a.executeForm(*form);
	delete form;
	std::cout << std::endl;

	form = intern.makeForm("presidential pardon", "president");
	a.signForm(*form);
	a.executeForm(*form);
	delete form;
	std::cout << std::endl;
	system("leaks a.out");
	return (0);
}