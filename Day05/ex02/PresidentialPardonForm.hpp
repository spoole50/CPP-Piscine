/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:29:37 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 21:29:38 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
# include "Form.hpp"

	class PresidentialPardonForm : public Form
	{
		private:
			std::string _target;
		public:
			PresidentialPardonForm(std::string);
			PresidentialPardonForm(PresidentialPardonForm&);
			~PresidentialPardonForm(void);
			PresidentialPardonForm & operator = (PresidentialPardonForm&);

			void	execAction(void) const;
	};

#endif