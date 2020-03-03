# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoole <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 13:07:28 by spoole            #+#    #+#              #
#    Updated: 2020/01/13 13:07:30 by spoole           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
TARGET = phoneBook
FILES = phoneBook.cpp Contact.cpp

all: $(TARGET)

debug: cleanall
debug: CXXFLAGS += -g
debug: $(TARGET)

$(TARGET): $(TARGET).cpp
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(FILES)

clean:
	@rm $(TARGET)

cleanall: clean
	@rm -rf $(TARGET).dSYM