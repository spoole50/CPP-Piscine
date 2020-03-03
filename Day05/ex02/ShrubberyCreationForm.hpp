/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:28:48 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 21:28:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
# include "Form.hpp"

	class ShrubberyCreationForm : public Form
	{
		private:
			std::string		_target;
		public:
			ShrubberyCreationForm(std::string);
			ShrubberyCreationForm(ShrubberyCreationForm&);
			~ShrubberyCreationForm(void);
			ShrubberyCreationForm & operator = (ShrubberyCreationForm&);

			void	execAction(void) const;
	};

#endif