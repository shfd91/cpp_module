#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void increase(int num);
		void decrease(int num);
		void gradeException(Bureaucrat &obj);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
