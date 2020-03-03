/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:00:57 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 21:00:58 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NINJATRAP_H
#define NINJATRAP_H
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

	class NinjaTrap : public ClapTrap
	{
		public:
			NinjaTrap(std::string name);
			NinjaTrap(const NinjaTrap &trap);
			~NinjaTrap(void);

			NinjaTrap & operator = (const NinjaTrap &trap);

			void	ninjaShoebox(NinjaTrap & target);
			void	ninjaShoebox(ClapTrap & target);
			void	ninjaShoebox(FragTrap & target);
			void	ninjaShoebox(ScavTrap & target);
	};

#endif