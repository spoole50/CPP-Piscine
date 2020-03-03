/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:28:32 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 14:28:33 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
    _n = n;
    horde = new Zombie[n];
}

void    ZombieHorde::announce()
{
    for (int i = 0; i < _n; i++)
        horde[i].announce();
}