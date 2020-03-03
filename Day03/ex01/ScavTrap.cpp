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

ScavTrap::ScavTrap(std::string _name)
{
	std::cout << "SC4V Default Constructor called" << std::endl;
	name = _name;
	hit_points = 100;
	max_hit_points = 100;
	energy_points = 100;
	max_energy_points = 100;
	level = 1;
	melee_attack = 30;
	ranged_attack = 20;
	armor_reduc = 5;
}

ScavTrap::ScavTrap(const ScavTrap &trap)
{
	std::cout << "SC4V Copy Constructor called" << std::endl;
	name = trap.name;
	hit_points = trap.hit_points;
	max_hit_points = trap.max_hit_points;
	energy_points = trap.energy_points;
	max_energy_points = trap.max_energy_points;
	level = trap.level;
	melee_attack = trap.melee_attack;
	ranged_attack = trap.ranged_attack;
	armor_reduc = trap.armor_reduc;
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

static		std::string rangedSay[5] = {	"cannon balls",
													"flame arrows",
													"plasma lasers",
													"orbital payloads",
													"slingshots"
};

void			ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << name << " " << rangedSay[std::rand() % 5] << " "<< target << " at range, causing " << ranged_attack << " points of damage" << std::endl;
}

static		std::string meleeSay[5] = {	"slaps",
												"stabs",
												"shanks",
												"slices",
												"pokes"
};

void			ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP " << name << " " << meleeSay[std::rand() % 5] << " " << target << " causing " << melee_attack << " points of damage" << std::endl;
}

void			ScavTrap::takeDamage(unsigned int amount)
{
	if (armor_reduc >= (int) amount)
		amount = 0;
	else
		amount -= armor_reduc;
	
	hit_points -= amount;
	if (hit_points <= 0)
	{
		hit_points = 0;
		std::cout << name << " SC4V has perished" << std::endl;
		//delete this;
	}
}

void			ScavTrap::beRepaired(unsigned int amount)
{
	hit_points += amount;
	if (hit_points > max_hit_points)
		hit_points = max_energy_points;
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