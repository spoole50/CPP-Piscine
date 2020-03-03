/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:43:16 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 17:43:17 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "SC4V Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &trap) : ClapTrap(trap)
{
	std::cout << "SC4V Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << std::endl << name << " level: " << level << " SC4VTrap slated for deletion, GoodBye World!" << std::endl;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &trap)
{
	std::cout << "SC4V Assign Overload called" << std::endl;
	name = trap.name;
	hit_points = trap.hit_points;
	max_hit_points = trap.max_hit_points;
	energy_points = trap.energy_points;
	max_energy_points = trap.max_energy_points;
	level = trap.level;
	melee_attack = trap.melee_attack;
	ranged_attack = trap.ranged_attack;
	armor_reduc = trap.armor_reduc;
	return *this;
}

int			ScavTrap::challengeNewcomer(std::string const & target)
{
	if (energy_points >= 25)
	{
		energy_points -= 25;
		std::cout << "GOGO SC4V" << std::endl;
		if (rand() % 2 == 1)
		{
			rangedAttack(target);
			return (1);
		}
		else
		{
			meleeAttack(target);
			return (0);
		}
	}
	else
	{
		std::cout << "Not enough energy points :(" << std::endl;
		return (-1);
	}
}