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
#include <cmath>

const int Fixed::_frac = 8;

Fixed::Fixed(void)
{
    std::cout << "Default Constructor called" << std::endl;
    _val = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int Constructor called" << std::endl;
    _val = num << Fixed::_frac;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float Constructor called" << std::endl;
    _val = (int)roundf(num * (1 << Fixed::_frac));
}

Fixed::Fixed(const Fixed &fix)
{
    std::cout << "Copy Constructor called" << std::endl;
    _val = fix.getRawBits();
}

Fixed & Fixed::operator = (const Fixed &fix)
{
    std::cout << "Assignation Operator called" << std::endl;
    this->_val = fix.getRawBits();
    return *this;
}

std::ostream &operator << (std::ostream &out, const Fixed &fix)
{
    out << fix.toFloat();
    return out;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int     Fixed::toInt(void) const
{
    return _val >> Fixed::_frac;
}

float   Fixed::toFloat(void) const
{
    return _val / (float)(1 << Fixed::_frac);
}

int     Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits called" << std::endl;
    return _val;
}

void    Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits called" << std::endl;
    _val = raw;
}
