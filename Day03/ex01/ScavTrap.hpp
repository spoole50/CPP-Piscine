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
# include <string>
# include <iostream>
# include <random>
# include <ctime>

	class ScavTrap
	{
		public:
			std::string		name;
			int				hit_points;
			int				max_hit_points;
			int				energy_points;
			int				max_energy_points;
			int				level;
			int				melee_attack;
			int				ranged_attack;
			int				armor_reduc;

			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &trap);
			~ScavTrap(void);

			ScavTrap & operator = (const ScavTrap &trap);

			void	rangedAttack(std::string const & target);
			void	meleeAttack(std::string const & target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
			int	challengeNewcomer(std::string const & target);
	};

#endif