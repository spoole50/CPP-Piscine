/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameInstance.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:23:16 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 19:23:18 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAMEINSTANCE_H
#define GAMEINSTANCE_H
# include <string>
# include <sstream>
# include <iostream>
# include <ctime>
# include <random>
# include <chrono>
# include <thread>
# include <curses.h>

# define MAX_SIZE 500
# define BACK_SIZE 100

	class   GameInstance
	{
		public:
			static int	difficulty;
			static int	level;
			static int 	cycle;
			static int 	rounds;
			int			max_y;
			int			max_x;
			
			GameInstance(void);
			GameInstance(GameInstance & inst);
			~GameInstance(void);
			GameInstance & operator = (GameInstance & inst);
	};

#endif