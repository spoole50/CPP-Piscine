/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameInstance.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:23:09 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 19:23:12 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameInstance.hpp"

int GameInstance::level = 1;
int GameInstance::difficulty = 1;
int GameInstance::cycle = 0;
int GameInstance::rounds = 0;

// tm    *updateTime(void)
// {
//     std::time_t t = std::time(0);
//     std::tm *now = std::localtime(&t);
//     return (now);
// }

GameInstance::GameInstance(void)
{
    max_y = 0;
    max_x = 0;
}

GameInstance::GameInstance(GameInstance & inst)
{
    max_y = inst.max_y;
    max_x = inst.max_x;
}

GameInstance::~GameInstance(void) {};

GameInstance & GameInstance::operator = (GameInstance & inst)
{
    max_y = inst.max_y;
    max_x = inst.max_x;
    return *this;
}