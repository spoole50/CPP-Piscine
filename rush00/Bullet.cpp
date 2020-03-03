/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:57:56 by spoole            #+#    #+#             */
/*   Updated: 2020/01/19 12:57:57 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

int Bullet::size = 0;
Bullet * Bullet::BulletList[MAX_SIZE] = {0};

Bullet::Bullet(std::string name, char *_symbol, int _y, int _x, int _direction, int _idx) : GameEntity(name, _symbol, _y, _x)
{
    direction = _direction;
    idx = _idx;
}

Bullet::Bullet(Bullet & bull) : GameEntity(bull)
{
    direction = bull.direction;
    idx = bull.idx;
}

Bullet::~Bullet(void) {};

Bullet & Bullet::operator = (Bullet & bull)
{
    direction = bull.direction;
    idx = bull.idx;
    return *this;
}

void    Bullet::clean(void)
{
    Bullet *temp;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        temp = Bullet::BulletList[i];
        if (temp != NULL)
            Bullet::delIndex(i);
    }
    Bullet::size = 0;
}

void    Bullet::delIndex(int i)
{
    delete Bullet::BulletList[i];
    Bullet::BulletList[i] = NULL;
}

void    Bullet::addBullet(int _y, int _x, int _direction)
{
    std::ostringstream s;
    s << "Bullet#" << Bullet::size << std::endl;
    std::string name(s.str());
    Bullet *temp = new Bullet(name, (char*)"-", _y, _x + _direction, _direction, Bullet::size);
    if (_direction == -1)
        temp->speed = 2;
    Bullet::BulletList[Bullet::size++] = temp;
    if (Bullet::size == MAX_SIZE)
        Bullet::size = 0;
}

void    Bullet::update(void)
{
    if (x >= COLS || x <= 0)
        Bullet::delIndex(idx);
    else
    {
        attron(A_BOLD);
        x += (speed * direction);
        if (direction == -1)
        {
            attron(COLOR_PAIR(4));
            move();
            attroff(COLOR_PAIR(4));
        }
        else
        {
            attron(COLOR_PAIR(3));
            move();
            attroff(COLOR_PAIR(3));
        }
        attroff(A_BOLD);
    }
}

int     Bullet::ckCollision(GameEntity *play)
{
    for (int i = 0; i <= speed; i++)
    {
        if (x + (direction * i) == play->x && y == play->y)
            return (1);
    }
    return (0);
}