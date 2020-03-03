/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:29:10 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 21:29:11 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & robo) : Form(robo), _target(robo._target)
{}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm & RobotomyRequestForm::operator = (RobotomyRequestForm & robo)
{
    (void) robo;
    return *this;
}

void    RobotomyRequestForm::execAction(void) const
{
    std::cout << "*DRILLING NOISES*" << std::endl;
    std::string result;
    if (rand() % 2)
        result = " has been robotomized";
    else
        result = " failed to be robotomoized";
    std::cout << _target << result << std::endl;
}