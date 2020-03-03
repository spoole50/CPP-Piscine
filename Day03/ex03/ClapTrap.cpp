/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 19:00:03 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 19:00:05 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name)
{
    std::cout << "CL4PTrap Default Constructor called" << std::endl;
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

ClapTrap::ClapTrap(const ClapTrap & clap)
{
    std::cout << "CL4P Copy Constructor called" << std::endl;
	name = clap.name;
	hit_points = clap.hit_points;
	max_hit_points = clap.max_hit_points;
	energy_points = clap.energy_points;
	max_energy_points = clap.max_energy_points;
	level = clap.level;
	melee_attack = clap.melee_attack;
	ranged_attack = clap.ranged_attack;
	armor_reduc = clap.armor_reduc;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << std::endl << name << " level: " << level << " CL4PTrap slated for deletion, GoodBye World!" << std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &clap)
{
	std::cout << "CL4P Assign Overload called" << std::endl;
	name = clap.name;
	hit_points = clap.hit_points;
	max_hit_points = clap.max_hit_points;
	energy_points = clap.energy_points;
	max_energy_points = clap.max_energy_points;
	level = clap.level;
	melee_attack = clap.melee_attack;
	ranged_attack = clap.ranged_attack;
	armor_reduc = clap.armor_reduc;
	return *this;
}

static		std::string rangedSay[5] = {	"cannon balls",
													"flame arrows",
													"plasma lasers",
													"orbital payloads",
													"slingshots"
};

void			ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "CL4P-TP " << name << " " << rangedSay[std::rand() % 5] << " "<< target << " at range, causing " << ranged_attack << " points of damage" << std::endl;
}

static		std::string meleeSay[5] = {	"slaps",
												"stabs",
												"shanks",
												"slices",
												"pokes"
};

void			ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CL4P-TP " << name << " " << meleeSay[std::rand() % 5] << " " << target << " causing " << melee_attack << " points of damage" << std::endl;
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (armor_reduc >= (int) amount)
		amount = 0;
	else
		amount -= armor_reduc;
	
	hit_points -= amount;
	if (hit_points <= 0)
	{
		hit_points = 0;
		std::cout << name << " CL4P has perished" << std::endl;
		//delete this;
	}
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	hit_points += amount;
	if (hit_points > max_hit_points)
		hit_points = max_energy_points;
}