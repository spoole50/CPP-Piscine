/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 09:59:43 by spoole            #+#    #+#             */
/*   Updated: 2020/01/23 09:59:44 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

template <typename F>
void    swap(F &one, F &two)
{
    F temp;

    temp = one;
    one = two;
    two = temp;

}

template <typename F>
F      &min(F &one, F &two)
{
    if (one < two)
        return (one);
    else
        return (two);
}

template <typename F>
F      &max(F &one, F &two)
{
    if (one > two)
        return (one);
    else
        return (two);
}

int main(void)
{
    int a = 2;
    int b = 3;

    // //std::cout << "a = " << a << " b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "min(a[3], b[2]): " << min(a, b) << std::endl;
    std::cout << "max(a[3], b[2]): " << max(a, b) << std::endl;

    std::string c = "stringC";
    std::string d = "stringD";
    // std::cout << "c = " << c << " d = " << d << std::endl;
    swap(c, d);
    std::cout << std::endl << "c = " << c << " d = " << d << std::endl;
    std::cout << "min(c, d): " << min(c, d) << std::endl;
    std::cout << "max(c, d): " << max(c, d) << std::endl;
    return (0);
}