#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	ShrubberyCreationForm form1("shru");
	RobotomyRequestForm form2("robo");
	PresidentialPardonForm form3("pres");
	Bureaucrat a("a", 1);
	Bureaucrat b("b", 50);
	Bureaucrat c("c", 150);

	a.executeForm(form1);
	b.executeForm(form1);
	c.executeForm(form1);
	std::cout << std::endl;

	a.signForm(form1);
	a.signForm(form2);
	a.signForm(form3);
	std::cout << std::endl;

	a.executeForm(form1);
	b.executeForm(form1);
	c.executeForm(form1);
	std::cout << std::endl;

	a.executeForm(form2);
	b.executeForm(form2);
	c.executeForm(form2);
	std::cout << std::endl;

	a.executeForm(form3);
	b.executeForm(form3);
	c.executeForm(form3);

	return (0);
}