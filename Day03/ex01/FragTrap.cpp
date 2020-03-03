/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:11:06 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 11:11:07 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name)
{
	std::cout << "FR4G Default Constructor called" << std::endl;
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

FragTrap::FragTrap(const FragTrap &trap)
{
	std::cout << "FR4G Copy Constructor called" << std::endl;
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

FragTrap::~FragTrap(void)
{
	std::cout << std::endl << name << " level: " << level << " FR4G slated for deletion, GoodBye World!" << std::endl;
}

FragTrap & FragTrap::operator = (const FragTrap &trap)
{
	std::cout << "FR4G Assign Overload called" << std::endl;
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

void			FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << name << " " << rangedSay[std::rand() % 5] << " "<< target << " at range, causing " << ranged_attack << " points of damage" << std::endl;
}

static		std::string meleeSay[5] = {	"slaps",
												"stabs",
												"shanks",
												"slices",
												"pokes"
};

void			FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << name << " " << meleeSay[std::rand() % 5] << " " << target << " causing " << melee_attack << " points of damage" << std::endl;
}

void			FragTrap::takeDamage(unsigned int amount)
{
	if (armor_reduc >= (int) amount)
		amount = 0;
	else
		amount -= armor_reduc;
	
	hit_points -= amount;
	if (hit_points <= 0)
	{
		hit_points = 0;
		std::cout << name << " FR4G has perished" << std::endl;
		//delete this;
	}
}

void			FragTrap::beRepaired(unsigned int amount)
{
	hit_points += amount;
	if (hit_points > max_hit_points)
		hit_points = max_energy_points;
}

static std::string	sayings[25] = { "This time it'll be awesome, I promise!",
											"Hey everybody, check out my package!",
											"Place your bets!",
											"Defragmenting!",
											"Recompiling my combat code!",
											"Running the sequencer!",
											"It's happening... it's happening!",
											"It's about to get magical!",
											"I'm pulling tricks outta my hat!",
											"You can't just program this level of excitement!",
											"What will he do next?",
											"Things are about to get awesome!",
											"Let's get this party started!",
											"Glitchy weirdness is term of endearment, right?",
											"Push this button, flip this dongle, voila! Help me!",
											"square the I, carry the 1... YES!",
											"Resequencing combat protocols!",
											"Look out everybody, things are about to get awesome!",
											"I have an IDEA!",
											"Round and around and around she goes!",
											"It's like a box of chocolates...",
											"Step right up to the sequence of Trapping!",
											"Hey everybody, check out my package!",
											"Loading combat packages!",
											"F to the R to the 4 to the G to the WHAAT!"
};

int			FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (energy_points >= 25)
	{
		energy_points -= 25;
		std::cout << sayings[rand() % 25] << std::endl;
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