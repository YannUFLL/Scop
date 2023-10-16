/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OBJparser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:16:55 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/16 18:45:35 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MeshTypes.h"

class OBJparser
{
    public:
        OBJparser(std::string &filename);
        ~OBJparser();
        Mesh parse();
    private:
        Vertex parseVertexLine(const std::string& line);
        TextureCoord parseTextureCoordLine(const std::string& line);
        Normal parseNormalLine(const std::string& line);
        Face parseFaceLine(const std::string& line);
}