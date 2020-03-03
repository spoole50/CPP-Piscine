/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:10:49 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 12:10:50 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int     main(void)
{
    std::srand(time(NULL));
    ZombieEvent event;
    event.setZombieType("Face Eater");
    for (int i = 0; i < 5; i++)
        event.randomChump();
    event.setZombieType("Nice Guys");
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
        event.randomChump();
    return (0);
}