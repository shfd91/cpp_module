#include "Bureaucrat.hpp"

class Form;

Bureaucrat::Bureaucrat() : _name("default"), _grade(0)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	gradeException(*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	gradeException(*this);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy.getGrade();
	*(const_cast<std::string *>(&this->_name)) = copy.getName();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::increase(int num)
{
	if ((this->_grade - num) < 1)
		throw (GradeTooHighException());
	this->_grade -= num;
	std::cout << "increase [" << this->_name << "] grade : [" << this->_grade << "]" << std::endl;
}

void Bureaucrat::decrease(int num)
{
	if ((this->_grade + num) > 150)
		throw  (GradeTooLowException());
	this->_grade += num;
	std::cout << "decrease [" << this->_name << "] grade : [" << this->_grade << "]" << std::endl;
}

void Bureaucrat::gradeException(Bureaucrat &obj)
{
	if (obj._grade > 150)
		throw (GradeTooHighException());
	if (obj._grade < 1)
		throw (GradeTooLowException());
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getTarget() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getTarget() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getTarget() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " cannot execute " << form.getTarget() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}

