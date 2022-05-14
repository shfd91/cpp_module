#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form()
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("President", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : Form(copy)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	this->Form::operator=(copy);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSign())
		throw (NoSignException());
	if (executor.getGrade() > this->getExeGrade())
		throw (GradeTooLowException());
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
