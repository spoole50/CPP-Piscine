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

int     main(void)
{
    Bureaucrat lo("WillBLo", 150);
    Bureaucrat hi("WillBHi", 1);

    std::cout << lo;
    std::cout << hi;

    try
    {
        std::cout << "Attemping to create Bureaucrat of grade 0" << std::endl;
        Bureaucrat test("Test", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting to decrement grade 150 (too low)" << std::endl;
        lo.decGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "Attempting to increrment grade 1 (too high)" << std::endl;
        hi.incGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return (0);
}