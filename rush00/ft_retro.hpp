/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retro.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 12:00:42 by spoole            #+#    #+#             */
/*   Updated: 2020/01/19 12:00:44 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RETRO_H
#define FT_RETRO_H

# include "Player.hpp"
# include "Enemy.hpp"
# include "Background.hpp"
# include "Boss.hpp"

void    start_game();
void    get_movement(Player &player1, int max_x, int max_y);
void    moveEnemies(void);
void    makeEnemies(Player &player1);
void    checkCollisions(Player &player1);
void    continue_game(Player &player1);
void    exit_game(void);
void    dead(Player &player1);

#endif