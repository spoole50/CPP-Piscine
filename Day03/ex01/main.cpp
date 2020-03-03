/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:10:40 by spoole            #+#    #+#             */
/*   Updated: 2020/01/17 11:10:44 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void        attackRound(FragTrap &frag, ScavTrap &scav, int attacker = 0)
{
    int attack;
    if (attacker == 0)
    {
        attack = frag.vaulthunter_dot_exe(scav.name);
        if (attack == 1)
            scav.takeDamage(frag.ranged_attack);
        else if (attack == 0)
            scav.takeDamage(frag.melee_attack);
    }
    else if (attacker == 1)
    {
        attack = scav.challengeNewcomer(frag.name);
        if (attack == 1)
            frag.takeDamage(scav.ranged_attack);
        else if (attack == 0)
            frag.takeDamage(scav.melee_attack);
    }
    
}

void        roundUpF(FragTrap &one)
{
    one.hit_points += 5;
    one.level += 1;
    one.energy_points += 25;
}

void        roundUpS(ScavTrap &one)
{
    one.hit_points += 5;
    one.level += 1;
    one.energy_points += 25;
}

int     main(void)
{
    std::srand(std::time(NULL));
    FragTrap clap1("Lilo");
    ScavTrap clap2("Stitch");

    while (clap1.hit_points > 0 && clap2.hit_points > 0)
    {
        attackRound(clap1, clap2);
        if (clap2.hit_points > 0)
            attackRound(clap1, clap2, 1);
        if (clap1.hit_points > 0)
            roundUpF(clap1);
        if (clap2.hit_points > 0)
            roundUpS(clap2);
    }
    return (0);
}