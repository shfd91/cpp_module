#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(0)
{

}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy.getGrade();
	*(const_cast<std::string *>(&this->_name)) = copy.getName();
	if (_grade > 150)
		throw (GradeTooLowException());
	else if (_grade < 1)
		throw (GradeTooHighException());
	return *this;
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

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High Exception");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low Exception");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << "< " << b.getName() << " >, bureaucrat greade < " << b.getGrade() << " >";
	return (out);
}
