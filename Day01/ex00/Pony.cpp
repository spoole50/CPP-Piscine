/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:35:37 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 10:35:38 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void    Pony::printPony(void)
{
    std::cout 
        << "Run Speed: " << runSpeed << " mph" << std::endl
        << "Tail Flip Frequency: " << tailFlipFreq << " flips/min" << std::endl
        << "Cutenss Level: " << cuteness << std::endl
        << "Carry Capacity: " << carryCapacity << " lbs" << std::endl 
        << "Races Won: " << racesWons << std::endl; 
}

void    ponyOnTheHeap(void)
{
    Pony *ponypoint = new Pony;
    std::cout << "Here is a pony on the Heap created with new keyword and members accessed with -> operator" << std::endl;
    ponypoint->runSpeed = 25;
    ponypoint->tailFlipFreq = 15;
    ponypoint->cuteness = 20;
    ponypoint->carryCapacity = 375;
    ponypoint->racesWons= 2;
    ponypoint->printPony();
    delete ponypoint;
    std::cout << "Heap pony is dead thanks to the delete keyword :/" << std::endl;
}

void    ponyOnTheStack(void)
{
    Pony stack;
    std::cout << "Here is a pony on the Stack created when function enters stack call and accessed with . operator" << std::endl;
    stack.runSpeed = 30;
    stack.tailFlipFreq = 5;
    stack.cuteness = 8;
    stack.carryCapacity = 300;
    stack.racesWons = 10;
    stack.printPony();
}