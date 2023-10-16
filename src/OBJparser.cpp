/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OBJparser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:25:17 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/16 22:45:11 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OBJparser.h"
#include <fstream>
#include <sstream>

OBJparser::OBJparser(std::string filename): _file(filename)
{
    if (!_file.is_open())
        throw std::runtime_error("Could not open file");
}

Mesh OBJparser::parse()
{
   std::string line;

    while (std::getline(_file, line))
    {
        std::stringstream  ss(line); 
        std::string identifier; 
        ss >> identifier;
        if (identifier == "v")
            _vertices.push_back(parseVertexLine(ss));
        else if (identifier == "vt")
            _textureCoords.push_back(parseTextureCoordLine(ss));
        else if (identifier == "vn")
            _normals.push_back(parseNormalLine(ss));
        else if (identifier == "f")
            _faces.push_back(parseFaceLine(ss));
    }
    return (Mesh(_vertices, _textureCoords, _normals, _faces));
}

Vertex OBJparser::parseVertexLine(std::stringstream &line)
{
    Vertex vertex;
    line >> vertex.x >> vertex.y >> vertex.z;
    return (vertex);
}

TextureCoord OBJparser::parseTextureCoordLine(std::stringstream &line)
{
    TextureCoord textureCoord;
    line >> textureCoord.u >> textureCoord.v;
    return (textureCoord);
}

Normal OBJparser::parseNormalLine(std::stringstream &line)
{
    Normal normal;
    line >> normal.x >> normal.y >> normal.z;
    return (normal);
}

Face OBJparser::parseFaceLine(std::stringstream &line)
{
    Face face;
    line >> face.v[0] >> face.v[1] >> face.v[2];
    line >> face.vt[0] >> face.vt[1] >> face.vt[2];
    line >> face.vn[0] >> face.vn[1] >> face.vn[2];
    return (face);
}

OBJparser::~OBJparser()
{
    _file.close();
}
