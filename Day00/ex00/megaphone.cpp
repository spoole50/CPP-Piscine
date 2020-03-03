/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:52:19 by spoole            #+#    #+#             */
/*   Updated: 2020/01/13 10:52:23 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av) {
    int numArgs = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (numArgs < ac){
            std::string str = av[numArgs];
            for (int i = 0; i < (int) str.length(); i++){
                if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
            }
            std::cout << str;
            numArgs++;
        }
    }
    std::cout << std::endl;
    return 0;
}
