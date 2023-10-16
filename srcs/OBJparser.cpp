/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OBJparser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:25:17 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/16 19:10:15 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OBJparser.h"
#include <fstream>

OBJparser::parse(std::string &filename)
{
   std::ifstream file(filename);
   std::string line;

   if (!file.is_open())
       throw std::runtime_error("Could not open file");
    while (std::getline(file, line))
    {
        std::stringstream  ss(line); 
        std::string identifier; 
        ss >> identifier;
        if (identifier == "v")
            vertices.push_back(parseVertexLine(line));
        else if (identifier == "vt")
            textureCoords.push_back(parseTextureCoordLine(line));
        else if (identifier == "vn")
            normals.push_back(parseNormalLine(line));
        else if (identifier == "f")
            faces.push_back(parseFaceLine(line)
    }
}

OBJparser::parseVertexLine(const std::string& line)
{
    std::stringstream ss(line);
    std::string v;
    float x, y, z;

    ss >> v >> x >> y >> z;
    return (Vertex(x, y, z));
}


