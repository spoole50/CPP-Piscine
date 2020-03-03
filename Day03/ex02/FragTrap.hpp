/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:11:14 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 11:11:46 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_H
#define FRAGTRAP_H
# include "ClapTrap.hpp"

	class FragTrap : public ClapTrap
	{
		public:
			FragTrap(std::string name);
			FragTrap(const FragTrap &trap);
			~FragTrap(void);

			FragTrap & operator = (const FragTrap &trap);

			int	vaulthunter_dot_exe(std::string const & target);
	};

#endif
