/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:40:18 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 19:40:19 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PLAYER_H
#define PLAYER_H
# include "GameEntity.hpp"
# include "Bullet.hpp"

class   Player : public GameEntity
{
    public:
        int score;
        tm *time;

        Player(std::string _name, char *_symbol, int _y, int _x);
		Player(Player & play);
		~Player(void);
		Player & operator = (Player & play);

        void    shoot(void);
        void    userInput(void);
        void    update(void);
};

#endif