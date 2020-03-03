/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:34:31 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 21:34:32 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Bullet.hpp"

int Enemy::size = 0;
bool Enemy::boss = false;
Enemy * Enemy::enemyList[MAX_SIZE] = {0};

Enemy::Enemy(std::string _name, char *_symbol, int _y, int _x, bool _weapon, int _idx) : GameEntity(_name, _symbol, _y, _x)
{
    weapon = _weapon;
    idx = _idx;
}

Enemy::Enemy(Enemy & enemy) : GameEntity(enemy)
{
    weapon = enemy.weapon;
    idx = enemy.idx;
}

Enemy::~Enemy(void) {};

Enemy & Enemy::operator = (Enemy & enemy)
{
    weapon = enemy.weapon;
    idx = enemy.idx;
    return *this;
}

void    Enemy::delIndex(int idx)
{
    delete Enemy::enemyList[idx];
    Enemy::enemyList[idx] = NULL;
}

void    Enemy::clean(void)
{
    Enemy *temp;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        temp = Enemy::enemyList[i];
        if (temp != NULL)
            Enemy::delIndex(i);
    }
    Enemy::size = 0;
}

void    Enemy::shoot(void)
{
    Bullet::addBullet(y, x - 1, -1);
}

void    Enemy::addEnemy(int playX)
{
    int x;
    std::ostringstream s;
    s << "Enemy#" << Enemy::size << std::endl;
    std::string name(s.str());
    x = (rand() % (COLS / 4)) + (3 * COLS/4);
    if (x == playX)
        x += 2;
    Enemy *temp = new Enemy(name, (char*)"**", (int)(rand() % LINES), x, (bool)(rand() % 2), Enemy::size);
    Enemy::enemyList[Enemy::size++] = temp;
    temp->shoot();
    if (Enemy::size == MAX_SIZE)
            Enemy::size = 0;
}

void    Enemy::update(void)
{
    if (x <= 0)
        Enemy::delIndex(idx);
    else
    {
        x -= speed;
        attron(COLOR_PAIR(2) | A_BOLD);
        move();
        attroff(COLOR_PAIR(2) | A_BOLD);
    }
}

int    Enemy::ckCollision(GameEntity *player1)
{
    if (y == player1->y && x == player1->x)
        return (1);
    else
        return (0);
}