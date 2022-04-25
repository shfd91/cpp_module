#include "Form.hpp"

Form::Form() : _name("default"), _sign(false) ,_sign_grade(150), _exe_grade(150)
{

}

Form::Form(std::string name, std::string target, int sign_grade, int exe_grade) : _name(name), _target(target), _sign(false), _sign_grade(sign_grade), _exe_grade(exe_grade)
{
	if (_sign_grade > 150 || _exe_grade > 150)
		throw (GradeTooLowException());
	else if (_sign_grade < 1 || _exe_grade < 1)
		throw (GradeTooHighException());
}

Form::Form(const Form &copy) : _name(copy.getName()), _sign(copy.getSign()), _sign_grade(copy.getSignGrade()), _exe_grade(copy.getExeGrade())
{
	if (copy.getSignGrade() > 150 || copy.getExeGrade() > 150)
		throw (GradeTooLowException());
	else if (copy.getSignGrade() < 1 || copy.getExeGrade() < 1)
		throw (GradeTooHighException());
	this->_sign = copy._sign;
}

Form &Form::operator=(const Form &copy)
{
	*(const_cast<std::string *>(&this->_name)) = copy.getName();
	*(const_cast<int *>(&this->_sign_grade)) = copy.getSignGrade();
	*(const_cast<int *>(&this->_exe_grade)) = copy.getExeGrade();
	this->_sign = copy.getSign();
	if (_sign_grade > 150 || _exe_grade > 150)
		throw (GradeTooLowException());
	else if (_sign_grade < 1 || _exe_grade < 1)
		throw (GradeTooHighException());
	return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSign() const
{
	return (this->_sign);
}

int Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int Form::getExeGrade() const
{
	return (this->_exe_grade);
}

std::string Form::getTarget() const
{
	return (this->_target);
}


void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_sign_grade)
		throw Form::GradeTooLowException();
	this->_sign = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

const char *Form::NoSignException::what() const throw()
{
	return ("No Sign");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::string str;
	out << "< " << form.getName() << " > Form signGrade : < " << form.getSignGrade() << " >, exeGrade : < " << form.getExeGrade() << " >";
	return (out);
}
