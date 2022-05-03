#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

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
	if (!this->getSign())
		throw (NoSignException());
	if (executor.getGrade() > this->getExeGrade())
		throw (GradeTooLowException());

	std::cout << "[50% chance of success.]" << std::endl;
	std::cout << "Drrrrrrr...." << std::endl;
	std::cout << "Drrrrrrr...." << std::endl;
	srand((unsigned)time(NULL));
	if ((rand() % 2) == 0)
		std::cout << "[Success] " << this->getTarget() << " is Robot" << std::endl;
	else
		std::cout << "[Fail] " << this->getTarget() << " is Human" << std::endl;
}
