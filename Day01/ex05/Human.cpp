/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:40:29 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 15:40:30 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

std::string  Human::identify(void) const
{
    return (brain.identify());
}

const Brain  &Human::getBrain(void) const
{
    return(brain);
}