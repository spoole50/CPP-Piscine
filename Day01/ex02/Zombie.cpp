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

Zombie::Zombie(std::string _name, std::string _type)
{
    type = _type;
    name = _name;
}

void    Zombie::announce(void)
{
    std::cout << "<" << name << " (" << type << ")> Braiiinnnnsssss" << std::endl;  
}