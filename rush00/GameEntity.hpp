/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:24:48 by spoole            #+#    #+#             */
/*   Updated: 2020/01/18 19:24:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAMEENTITY_H
#define GAMEENTITY_H
# include "GameInstance.hpp"

	class   GameEntity : public virtual GameInstance
	{
		public:
			std::string 		name;
			int					speed;
			char				*symbol;
			int					y;
			int					x;

			GameEntity(std::string _name, char *_symbol, int _y, int _x);
			GameEntity(GameEntity & entity);
			~GameEntity(void);
			GameEntity & operator = (GameEntity & entity);

			void	move(void);
			//collisions?
	};

#endif