/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:30:41 by spoole            #+#    #+#             */
/*   Updated: 2020/01/20 14:30:44 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & bur) : _name(bur._name), _grade(bur._grade) {}

Bureaucrat::~Bureaucrat(void) {};

Bureaucrat & Bureaucrat::operator = (Bureaucrat const & bur)
{
	if (this != &bur)
	{
		if (bur._grade > 150)
			throw GradeTooLowException();
		else if (bur._grade < 1)
			throw GradeTooHighException();
		else
			_grade = bur._grade;
	}
	return *this;
}

std::ostream & operator << ( std::ostream & out, const Bureaucrat & bur )
{
	out << "<" << bur.getName() << ">, bureaucrat grade <" << bur.getGrade() << ">" << std::endl;
	return (out);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int			Bureaucrat::getGrade(void) const
{
	
	return (_grade);
}

void				Bureaucrat::incGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::decGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowExcpetion");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighExcpetion");
}
