#include "Form.hpp"

Form::Form() : _name("default"), _sign(false) ,_sign_grade(150), _exe_grade(150)
{

}

Form::Form(std::string name, int sign_grade, int exe_grade) : _name(name), _sign(false), _sign_grade(sign_grade), _exe_grade(exe_grade)
{
	gradeException(*this);
}

Form::Form(const Form &copy) : _name(copy.getName()), _sign(copy.getSign()), _sign_grade(copy.getSignGrade()), _exe_grade(copy.getExeGrade())
{

}

Form &Form::operator=(const Form &copy)
{
	*(const_cast<std::string *>(&this->_name)) = copy.getName();
	*(const_cast<int *>(&this->_sign_grade)) = copy.getSignGrade();
	*(const_cast<int *>(&this->_exe_grade)) = copy.getExeGrade();
	this->_sign = copy.getSign();
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

void Form::gradeException(Form &obj) const
{
	if (obj._sign_grade > 150 || obj._exe_grade > 150)
		throw (GradeTooLowException());
	else if (obj._sign_grade < 1 || obj._exe_grade < 1)
		throw (GradeTooHighException());
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_sign_grade)
		throw (GradeTooLowException());
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

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << " Form sign : " << form.getSign() << ", signGrade : " << form.getSignGrade() << ", exeGrade : " << form.getExeGrade();
	return (out);
}
