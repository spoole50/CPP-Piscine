/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:35:56 by spoole            #+#    #+#             */
/*   Updated: 2020/01/14 10:35:58 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int main(void)
{
    std::cout << std::endl;
    ponyOnTheHeap();
    std::cout << std::endl;
    ponyOnTheStack();
    std::cout << "Stack pony is dead thanks to function exiting stack call :(" << std::endl;
    return (0);
}