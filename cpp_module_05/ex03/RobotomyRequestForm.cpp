#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form()
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	this->Form::operator=(copy);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	(*const_cast<Bureaucrat *>(&executor)).signForm(*(const_cast<RobotomyRequestForm *>(this)));
	if (executor.getGrade() > 45)
		throw (GradeTooLowException());

	std::cout << "[50% chance of success.]" << std::endl;
	std::cout << "Drrrrrrr...." << std::endl;
	std::cout << "Drrrrrrr...." << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << "[Success] " << this->getName() << " is Robot" << std::endl;
	else
		std::cout << "[Fail] " << this->getName() << std::endl;
}
