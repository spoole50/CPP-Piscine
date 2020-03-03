/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:30:48 by spoole            #+#    #+#             */
/*   Updated: 2020/01/20 14:30:50 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include <stdexcept>

	class Bureaucrat
	{
		private:
			const std::string 	_name;
			int					_grade;
		public:
			Bureaucrat(std::string, int);
			Bureaucrat(const Bureaucrat & bur);
			~Bureaucrat(void);
			Bureaucrat & operator = (Bureaucrat const & bur);

			std::string			getName(void) const;
			int					getGrade(void) const;
			void				incGrade(void);
			void				decGrade(void);

			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char	*what() const throw();
			};

			class GradeTooHighException : public std::exception
			{
				public:
					virtual const char	*what() const throw();
			};
	};

	std::ostream & operator << ( std::ostream & out, const Bureaucrat & bur );

#endif