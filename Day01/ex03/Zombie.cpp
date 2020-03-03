/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:10:15 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 12:10:17 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string names[16] = {"Leia", "Sadie", "Jose", "Sara", "Paul", "Sam", "Leo", "Caitlin", "Sinead", "Priya", "Milo", "Cindy", "Arron", "Will", "Chris", "Andy"};

Zombie::Zombie(void)
{
    type = "swarm";
    name = names[rand() % sizeof(names)/sizeof(names[0])];
}

void    Zombie::announce(void)
{
    std::cout << "<" << name << " (" << type << ")> Braiiinnnnsssss" << std::endl;  
}