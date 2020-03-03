/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:51:38 by spoole            #+#    #+#             */
/*   Updated: 2020/01/24 11:51:40 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <array>
#include <vector>
#include <set>
#include <list>
#include <deque>
#include <iostream>

template <typename T>
void easyfind(T cont, int idx)
{
    if (std::find(cont.begin(), cont.end(), idx) == cont.end())
        throw "Idx: " + std::to_string(idx) + " not found";
}

int     main(void)
{
    int init[] = {1,2,3,4,5};
    
    std::array <int, 5> arr = {{1,2,3,4,5}};
    std::vector <int> vec(std::begin(init), std::end(init));
    std::set <int> sett(std::begin(init), std::end(init));
    std::list <int> lst(std::begin(init), std::end(init));
    std::deque <int> dq(std::begin(init), std::end(init));

    for (int i = 1; i <= 6; i++)
    {
        try
        {
            easyfind(arr, i);
            easyfind(vec , i);
            easyfind(sett, i);
            easyfind(lst, i);
            easyfind(dq, i);
        }
        catch (std::string & e)
        {
            std::cout << e << std::endl;
        }
    }
    return (0);
}