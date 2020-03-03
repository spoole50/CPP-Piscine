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

void        attackRound(FragTrap &one, FragTrap &two)
{
    int attack = one.vaulthunter_dot_exe(two.name);
    if (attack == 1)
        two.takeDamage(one.ranged_attack);
    else if (attack == 0)
        two.takeDamage(one.melee_attack);
}

void        roundUp(FragTrap &one)
{
    one.hit_points += 5;
    one.level += 1;
    one.energy_points += 25;
}

int     main(void)
{
    std::srand(std::time(NULL));
    FragTrap clap1("Lilo");
    FragTrap clap2("Stitch");

    while (clap1.hit_points > 0 && clap2.hit_points > 0)
    {
        attackRound(clap1, clap2);
        if (clap2.hit_points > 0)
            attackRound(clap2, clap1);
        if (clap1.hit_points > 0)
            roundUp(clap1);
        if (clap2.hit_points > 0)
            roundUp(clap2);
    }
    return (0);
}