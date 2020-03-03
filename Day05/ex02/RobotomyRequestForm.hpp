/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:29:15 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 21:29:16 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
# include "Form.hpp"

	class RobotomyRequestForm : public Form
	{
		private:
			std::string	_target;
		public:
			RobotomyRequestForm(std::string);
			RobotomyRequestForm(RobotomyRequestForm&);
			~RobotomyRequestForm(void);
			RobotomyRequestForm & operator = (RobotomyRequestForm&);

			void	execAction(void) const;
	};

#endif