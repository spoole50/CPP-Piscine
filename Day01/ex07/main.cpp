/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 12:53:36 by spoole            #+#    #+#             */
/*   Updated: 2020/01/15 12:53:37 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int     main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string toReplace = av[2];
        std::string replaceWith = av[3];
        std::ifstream inFile;
        std::ofstream outFile;

        inFile.open(filename);
        outFile.open(filename + ".replace");

        if (!inFile)
            std::cout << "Error opening input file " << filename << std::endl;
        else if (!outFile)
            std::cout << "Error creating file " << filename << ".replace" << std::endl;

        std::string line;
        size_t len = toReplace.length();
        while (std::getline(inFile, line))
        {
            while(1)
            {
                size_t pos = line.find(toReplace);
                if (pos != std::string::npos)
                    line.replace(pos, len, replaceWith);
                else
                    break;
            }
            outFile << line << std::endl;
        }  
    }
    else
        std::cout << "Usage: SIFL filename \"string to be replaced\" \"string to be inserted\"" << std::endl;
    
    return (0);
}