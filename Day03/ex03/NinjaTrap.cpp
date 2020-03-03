/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:00:51 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 21:00:53 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "Ninja Default Constructor called" << std::endl;
    hit_points = 60;
    max_hit_points = 60;
    energy_points = 120;
    max_energy_points = 120;
    melee_attack = 60;
    ranged_attack = 5;
    armor_reduc = 0;
}

NinjaTrap::NinjaTrap(const NinjaTrap &ninja) : ClapTrap(ninja)
{
	std::cout << "Ninja Copy Constructor called" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << std::endl << name << " level: " << level << " Ninja slated for death, GoodBye World!" << std::endl;
}

NinjaTrap & NinjaTrap::operator = (const NinjaTrap &trap)
{
	std::cout << "Ninja Assign Overload called" << std::endl;
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

void	NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
    std::cout << "Ninja " << name << " vs. Ninja " << target.name << " , a formidble battle" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & target)
{
    std::cout << "Ninja " << name << " slices CL4P " << target.name << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target)
{
    std::cout << "FR4G " << target.name << " takesout Ninja " << name << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target)
{
    std::cout << "Ninja " << name << " slaughters SC4V " << target.name << std::endl;
}