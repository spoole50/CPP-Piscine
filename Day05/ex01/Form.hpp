/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:34:20 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 18:34:22 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_H
#define FORM_H
# include "Bureaucrat.hpp"

	class Form
	{
		private:
			const std::string	_name;
			const int			_signGrade;
			const int			_execGrade;
			bool				_isSigned;
		public:
			Form(std::string, const int, const int);
			Form(Form & form);
			~Form(void);
			Form & operator = (Form & form);

			std::string		getName(void) const;
			int				getSignGrade(void) const;
			int				getExecGrade(void) const;
			bool			getIsSigned(void) const;

			bool			beSigned(const Bureaucrat & bur);

			class	GradeTooLowException : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

			class	GradeTooHighExcpetion : public std::exception
			{
				public:
					virtual const char *what() const throw();
			};

	};

	std::ostream & operator << ( std::ostream & out, const Form & form);

#endif