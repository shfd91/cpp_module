#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : Form(copy)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	this->Form::operator=(copy);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	(*const_cast<Bureaucrat *>(&executor)).signForm(*(const_cast<ShrubberyCreationForm *>(this)));
	if (executor.getGrade() > 137)
		throw (GradeTooLowException());

	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName, std::ofstream::out | std::ofstream::trunc);

	std::string shrubbery = "       _-_ \n"
							"    /~~   ~~\\ \n"
							" /~~         ~~\\ \n"
							"{               } \n"
							" \\  _-     -_  / \n"
							"   ~ \\\\   // ~ \n"
							"_- -   | | _- _ \n"
							"  _ -  | |   -_ \n"
							"      // \\\\ \n";
	if (!file.good())
		throw std::ofstream::failure("fail open " + fileName);
	else
		std::cout << "create < " << fileName << " > success" << std::endl;
	file << shrubbery;
}
