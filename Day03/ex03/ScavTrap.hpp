/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:43:21 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 17:43:22 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_H
#define SCAVTRAP_H
# include "ClapTrap.hpp"

	class ScavTrap : public ClapTrap
	{
		public:
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &trap);
			~ScavTrap(void);

			ScavTrap & operator = (const ScavTrap &trap);

			int	challengeNewcomer(std::string const & target);
	};

#endif