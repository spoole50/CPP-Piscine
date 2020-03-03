/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:26:01 by spoole            #+#    #+#             */
/*   Updated: 2020/01/19 16:26:02 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Background.hpp"

Background *Background::map[BACK_SIZE] = {0};
int     Background::size = 0;

Background::Background(std::string name, char *_symbol, int _y, int _x, bool _collide, int _idx) : GameEntity(name, _symbol, _y, _x)
{
    collide = _collide;
    idx = _idx;
}

Background::Background(Background & back) : GameEntity(back)
{
    collide = back.collide;
}

Background::~Background(void) {};

Background & Background::operator = (Background & back)
{
    collide = back.collide;
    return *this;
}

void    Background::clean(void)
{
    Background *temp;
    for (int i = 0; i < BACK_SIZE; i++)
    {
        temp = Background::map[i];
        if (temp != NULL)
            Background::delIndex(i);
    }
    Background::size = 0;
}

void    Background::delIndex(int i)
{
    delete Background::map[i];
    Background::map[i] = NULL;
}

void    Background::addBackground(bool _collide)
{
    std::ostringstream s;
    s << "Background#" << Background::size << std::endl;
    std::string name(s.str());
    Background *temp = new Background(name, (char*)".", (int)(rand() % LINES), (int)(rand() % COLS), _collide, Background::size);
    Background::map[Background::size++] = temp;
    if (Background::size == BACK_SIZE)
        Background::size = 0;
}

void    Background::update(void)
{
    if (x >= COLS || x <= 0)
        Background::delIndex(idx);
    else
    {
        x -= speed;
        attron(COLOR_PAIR(5) | A_DIM);
        move();
        attroff(COLOR_PAIR(5) | A_DIM);
    }
}

int     Background::ckCollision(GameEntity *play)
{
    if (x == play->x && y == play->y)
        return (1);
    return (0);
}