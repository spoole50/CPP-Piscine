/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:01:40 by spoole            #+#    #+#             */
/*   Updated: 2020/01/15 16:01:41 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

const int Fixed::_frac = 8;

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (const Fixed &fix)
{
    std::cout << "Assignation Operator called" << std::endl;
    this->_val = fix._val;
    return *this;
}

Fixed::Fixed(void)
{
    std::cout << "Default Constructor called" << std::endl;
    _val = 0;
}

Fixed::Fixed(const Fixed &fix)
{
    std::cout << "Copy Constructor called" << std::endl;
    _val = fix._val;
}

int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits called" << std::endl;
    return _val;
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits called" << std::endl;
    _val = raw;
}
