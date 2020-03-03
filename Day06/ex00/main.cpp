/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 09:55:36 by spoole            #+#    #+#             */
/*   Updated: 2020/01/22 09:55:38 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

int     main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cout << "Usage: ./convert <string> ..." << std::endl;
    }
    else
    {
        char    chr;
        int     it;
        float   flt;
        double  dbl;

        for (int i = 1; i < ac; i++)
        {
            //Detect Precision
            std::string search = av[i];
            int dec = 0;
            int src = search.find(".");
            if (src == -1)
                dec = 1;
            else
            {
                for (unsigned long i = src + 1; i < search.length(); i++)
                {
                    if (search[i] >= '0' && search[i] < '9')
                        dec++;
                }
            }

            //Char
            try
            {   std::cout << "char: ";
                chr = static_cast <char> (std::stoi(av[i]));
                if (chr < 32 || chr > 126)
                    std::cout << " Non-Displayable" << std::endl;
                else
                    std::cout << chr << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "impossible" << std::endl;
            }

            //Int
            try
            {
                std::cout << "int: ";
                it = static_cast <int> (std::stoi(av[i]));
                std::cout << it << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "impossible" << std::endl;
            }

            //Float
            try
            {
                std::cout << "float: ";
                flt = static_cast <float> (std::stof(av[i]));
                std::cout << std::fixed << std::setprecision(dec) << flt << "f" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "impossible" << std::endl;
            }

            //Double
            try
            {
                std::cout << "double: ";
                dbl = (std::stod(av[i]));
                std::cout << dbl << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "impossible" << std::endl;
            }
            if (ac > 2)
                std::cout << std::endl;
        }
    }
    return (0);
}