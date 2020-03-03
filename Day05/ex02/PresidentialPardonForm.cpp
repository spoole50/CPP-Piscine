/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:29:33 by spoole            #+#    #+#             */
/*   Updated: 2020/01/21 21:29:34 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & pres) : Form(pres), _target(pres._target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm & PresidentialPardonForm::operator = (PresidentialPardonForm & pres)
{
    (void) pres;
    return *this;
}

void        PresidentialPardonForm::execAction(void) const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
