/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:24:44 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 19:24:45 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity(std::string _name, char *_symbol, int _y, int _x)
{
    name = _name;
    symbol =_symbol;
    speed = 1;
    y = _y;
    x = _x;
}

GameEntity::GameEntity(GameEntity & entity)
{
    name = entity.name;
    symbol = entity.symbol;
    speed = entity.speed;
    y = entity.y;
    x = entity.x;
}

GameEntity::~GameEntity(void) {};

GameEntity & GameEntity::operator = (GameEntity & entity)
{
    name = entity.name;
    symbol = entity.symbol;
    speed = entity.speed;
    y = entity.y;
    x = entity.x;
    return *this;
}

void    GameEntity::move(void)
{
    mvprintw(y, x, symbol);
}