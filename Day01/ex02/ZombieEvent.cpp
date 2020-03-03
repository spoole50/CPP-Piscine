/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:10:34 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 12:10:36 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string names[10] = {"Leia", "Sadie", "Jose", "Sara", "Paul", "Sam", "Leo", "Caitlin", "Sinead", "Priya"};

void    ZombieEvent::setZombieType(std::string type)
{
    _type = type;
}

Zombie  *ZombieEvent::newZombie(std::string name)
{
    Zombie *newZombie = new Zombie(name, _type);
    return (newZombie);
}

void    ZombieEvent::randomChump()
{
    //std::cout << rand() << std::endl;
    Zombie *temp = newZombie(names[rand() % sizeof(names)/sizeof(names[0])]);
    temp->announce();
    delete temp;
}