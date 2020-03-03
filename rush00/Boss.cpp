/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:28:26 by spoole            #+#    #+#             */
/*   Updated: 2020/01/19 19:28:27 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Boss.hpp"
#include "Bullet.hpp"

Boss *Boss::boss = NULL;
bool  Boss::isBoss = false;

Boss::Boss(int _hits) : GameEntity("BOSS", (char*)"#", (LINES/2) + 2, (COLS/2) - 5)
{
    hits = _hits;
    Boss::isBoss = true;
    cooldown = time(NULL);
}

Boss::Boss(Boss & _boss) : GameEntity(_boss)
{
    hits = _boss.hits;
    cooldown = time(NULL);
}

Boss::~Boss(void)
{
    Boss::isBoss = false;
}

Boss & Boss::operator = (Boss & _boss)
{
    hits = _boss.hits;
    cooldown = time(NULL);
    return *this;
}

void    Boss::shoot(void)
{
    for (int i = 0; i < 4; i++)
    {
        Bullet::addBullet(y + i, x - 1, -1);
    }
}

int     Boss::ckCollision(GameEntity *play)
{
    if (play->x >= x && play->x <= x + 2)
    {
        if (play->y >= y && play->y <= y + 3)
            return (1);
    }
    return (0);
}

void    Boss::update(bool change)
{
    if (change)
    {
        int mov = (rand() % 2) ? 1 : -1;
        mov *= rand() % 10;
        x += (x + mov > 0 && x + mov <= COLS) ? mov : 0;
        mov = (rand() % 2) ? 1 : -1;
        mov *= rand() % 10;
        y += (y + mov > 0 && y + mov <= LINES) ? mov : 0;
    }
    mvprintw(y, x, "#######");
    mvprintw(y + 1, x + 2, "###");
    mvprintw(y + 2, x + 2, "###");
    mvprintw(y + 3, x, "#######");
    speed = GameInstance::level/5;
    if (rand() % 7 == 0)
        shoot();
}