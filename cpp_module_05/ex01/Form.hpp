#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _sign;
		const int _sign_grade;
		const int _exe_grade;
	public:
		Form();
		Form(std::string name, int sign_grade, int exe_grade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();

		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExeGrade() const;

		void beSigned(const Bureaucrat &b);

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
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif