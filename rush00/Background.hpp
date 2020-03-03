/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 16:26:06 by spoole            #+#    #+#             */
/*   Updated: 2020/01/19 16:26:08 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BACKGROUND_H
#define BACKGROUND_H
# include "GameEntity.hpp"

	class Background : public GameEntity
	{
		public:
			static	Background *map[BACK_SIZE];
			static	int size;
			bool	collide;
			int		idx;

			Background(std::string name, char *_symbol, int _y, int _x, bool _colide, int idx);
			Background(Background & back);
			~Background(void);
			Background & operator = (Background & back);

			static void	clean(void);
			static void delIndex(int i);
			static void	addBackground(bool _collide);
			
			void	update(void);
			int		ckCollision(GameEntity *play);
			
	};

#endif