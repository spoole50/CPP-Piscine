/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:28:19 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 14:28:21 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int     main(void)
{
    std::srand(time(NULL));
    ZombieHorde clan(10);
    clan.announce();
    return(0);
}