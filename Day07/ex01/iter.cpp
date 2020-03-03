/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:40:49 by spoole            #+#    #+#             */
/*   Updated: 2020/01/23 10:40:51 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename F>
void        iter(F *arr, int len, void (*func)(F const & x))
{
    for (int i = 0; i < len; i++)
    {
        (func)(arr[i]);
        if (i < len - 1)
            std::cout << ", ";
    }
}

template <typename F>
void    printIt(F const & x)
{
    std::cout << x;
}

int     main(void)
{
    int intArr[5] = {1,2,3,4,5};
    float fltArr[5] = {1,2,3,4,5};
    double dblArr[5] = {1,2,3,4,5};
    std::string strArr[5] = {"1", "2", "3", "4", "5"};

    std::cout << "Int Array: ";
    iter (intArr, 5, printIt);
    std::cout << std::endl;

    std::cout << "Float Array: ";
    iter (fltArr, 5, printIt);
    std::cout << std::endl;

    std::cout << "Double Array: ";
    iter (dblArr, 5, printIt);
    std::cout << std::endl;

    std::cout << "String Array: ";
    iter (strArr, 5, printIt);
    std::cout << std::endl;
    return (0);
}