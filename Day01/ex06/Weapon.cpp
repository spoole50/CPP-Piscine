/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:21:12 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 17:21:14 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

void		Weapon::setType(std::string type)
{
	_type = type;
}

const std::string&	Weapon::getType(void)
{
	const std::string& res = _type;
	return (res);
}