/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:32:58 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 15:32:59 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int     main(void)
{
    std::string str = "HI THIS IS BRAIN";

    std::string *point = &str;
    std::string &ref = str;

    std::cout << "Printing String Straight Up: " << str << std::endl;
    std::cout << "Printing String with pointer: " << *point << std::endl;
    std::cout << "Printing String with Reference: " << ref << std::endl;
    return (0);
}