/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:30:05 by spoole            #+#    #+#             */
/*   Updated: 2020/01/20 14:30:07 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int     main(void)
{
    std::srand(std::time(NULL));
    Bureaucrat lo("WillBLo", 150);
    Bureaucrat hi("WillBHi", 1);

    std::cout << lo;
    std::cout << hi;

    ShrubberyCreationForm shrub("Shrub");
    RobotomyRequestForm robo("Robo");
    PresidentialPardonForm pres("PresPardon");

    hi.executeForm(shrub);
    hi.executeForm(robo);
    hi.executeForm(pres);

    try
    {
        lo.executeForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        lo.executeForm(robo);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        lo.executeForm(pres);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    
    return (0);
}