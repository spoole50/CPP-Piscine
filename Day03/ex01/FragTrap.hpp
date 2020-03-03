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
# include <string>
# include <iostream>
# include <random>
# include <ctime>

	class FragTrap
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

			FragTrap(std::string name);
			FragTrap(const FragTrap &trap);
			~FragTrap(void);

			FragTrap & operator = (const FragTrap &trap);

			void	rangedAttack(std::string const & target);
			void	meleeAttack(std::string const & target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
			int	vaulthunter_dot_exe(std::string const & target);
	};

#endif
