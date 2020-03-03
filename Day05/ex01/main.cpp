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
#include "Form.hpp"

int     main(void)
{
    Bureaucrat lo("WillBLo", 150);
    Bureaucrat hi("WillBHi", 1);

    std::cout << lo;
    std::cout << hi;

    Form        form1("Form 587", 5, 10);
    Form        form2("Form 239", 149, 10);

    std::cout << form1;
    std::cout << form2;

    try
    {
        Form error("Err Form", 155, 1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        lo.signForm(form2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        lo.incGrade();
        lo.signForm(form2);
        lo.signForm(form2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << form2;
    
    return (0);
}