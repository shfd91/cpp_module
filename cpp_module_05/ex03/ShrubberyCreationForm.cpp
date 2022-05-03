#include "ShrubberyCreationForm.hpp"
#include <fstream>

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
	if (!this->getSign())
		throw (NoSignException());
	if (executor.getGrade() > this->getExeGrade())
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
	if (!file.is_open())
		throw (fileOpenException());
	else
		std::cout << "create " << fileName << " success" << std::endl;
	file << shrubbery;
}

const char *ShrubberyCreationForm::fileOpenException::what(void) const throw()
{
	return ("file open Exception");
}
