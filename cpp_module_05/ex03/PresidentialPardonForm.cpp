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
	(*const_cast<Bureaucrat *>(&executor)).signForm(*(const_cast<PresidentialPardonForm *>(this)));
	if (executor.getGrade() > 5)
		throw (GradeTooLowException());
	std::cout << "< " << this->getName() << " > has been pardoned by Zafod Beeblebrox." << std::endl;
}
