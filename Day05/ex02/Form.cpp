/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:12 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 18:34:13 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
    _isSigned = false;
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighExcpetion();
    else if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

Form::Form(Form & form) : _name(form._name), _signGrade(form._signGrade), _execGrade(form._execGrade), _isSigned(form._isSigned) {}

Form::~Form(void) {}

Form & Form::operator = (Form & form)
{
    if (this != &form)
        _isSigned = form._isSigned;
    return *this;
}

std::ostream & operator << ( std::ostream & out, const Form & form)
{
    out << "Form: " << form.getName() << " Sign Grade: " << form.getSignGrade() << " Exec Grade: " << form.getExecGrade() << " Signed: " << form.getIsSigned() << std::endl;
    return out;
}

std::string     Form::getName(void) const
{
    return (_name);
}

bool            Form::beSigned(const Bureaucrat & bur)
{
    if (bur.getGrade() > _signGrade)
        throw GradeTooLowException();
    else if (_isSigned)
        std::cout << "Form: " << _name << " is already signed" << std::endl;
    else
        _isSigned = true;
    return (_isSigned);
}

int             Form::getSignGrade(void) const
{
    return (_signGrade);
}

int             Form::getExecGrade(void) const
{
    return (_execGrade);
}

bool            Form::getIsSigned(void) const
{
    return (_isSigned);
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowExcpetion");
}

const char *Form::GradeTooHighExcpetion::what() const throw()
{
    return ("GradeTooHighException");
}

void    Form::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() <= _execGrade)
        execAction();
    else
        throw GradeTooHighExcpetion();
}