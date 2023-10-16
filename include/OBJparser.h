/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OBJparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:16:55 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/16 22:44:41 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MeshTypes.h"
#include <sstream>
#include <fstream>

class OBJparser
{
    public:
        OBJparser(std::string filename);
        ~OBJparser();
        Mesh parse();
    private:
        Vertex parseVertexLine(std::stringstream& line);
        TextureCoord parseTextureCoordLine(std::stringstream& line);
        Normal parseNormalLine(std::stringstream& line);
        Face parseFaceLine(std::stringstream& line);
        std::vector<Vertex> _vertices;
        std::vector<TextureCoord> _textureCoords;
        std::vector<Normal> _normals;
        std::vector<Face> _faces;
        std::ifstream _file;
};