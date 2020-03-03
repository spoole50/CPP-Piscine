/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:40:12 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 19:40:13 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "ft_retro.hpp"

Player::Player(std::string _name, char *_symbol, int _y, int _x) : GameEntity(_name, _symbol, _y, _x)
{
    score = 0;
    speed = 1;
    std::time_t t = std::time(0);
    time = std::localtime(&t);
}

Player::Player(Player & play) : GameEntity(play)
{
    score = play.score;
    speed = play.speed;
    time = play.time;
}

Player::~Player(void) {};

Player & Player::operator = (Player & play)
{
    score = play.score;
    speed = play.speed;
    time = play.time;
    return *this;
}

void    Player::shoot(void)
{
    Bullet::addBullet(y, x, 1);
}

void    Player::userInput(void)
{
    int ch;
    switch (ch = getch())
        {
            case KEY_UP:
                if (y > 2)
                    y--;
                break;
            case KEY_DOWN:
                if (y < max_y - 2)
                    y++;
                break;
            case KEY_LEFT:
                if (x > 1)
                    x -= 2;
                break;
            case KEY_RIGHT:
                if (x < max_x - 3)
                    x += 2;
                break;
            case 32:
                shoot();
                break;
            case 27:
                exit_game();
                break;
        }
}

void        Player::update(void)
{
        attron(COLOR_PAIR(1) | A_BOLD);
        mvprintw(y, x, symbol);
        attroff(COLOR_PAIR(1) | A_BOLD);
}