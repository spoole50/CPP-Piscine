/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:00:10 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 19:00:11 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H
#define CLAPTRAP_H
# include <string>
# include <iostream>
# include <random>
# include <ctime>

	class ClapTrap
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

			ClapTrap(std::string _name);
			ClapTrap(const ClapTrap & clap);
			~ClapTrap(void);

			ClapTrap & operator = (const ClapTrap & clap);

			void	rangedAttack(std::string const & target);
			void	meleeAttack(std::string const & target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
	};

#endif