#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	ShrubberyCreationForm form1("form 1");
	RobotomyRequestForm form2("form 2");
	PresidentialPardonForm form3("form 3");
	Bureaucrat a("a", 1);
	Bureaucrat b("b", 50);
	Bureaucrat c("c", 150);

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

	// a.executeForm(form1);
	// b.executeForm(form1); // excuteForm에서 execute를 실행시키는 것. execute에 서명하는 것(signForm)도 포함되어있음

	return (0);
}