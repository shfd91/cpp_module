#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		std::string _target;
		bool _sign;
		const int _sign_grade;
		const int _exe_grade;
	public:
		Form();
		Form(std::string name, std::string target, int sign_grade, int exe_grade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		virtual ~Form();

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExeGrade() const;
		std::string getTarget() const;
		void gradeException(Form &obj) const;
		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class NoSignException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif