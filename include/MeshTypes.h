/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshTypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:23:06 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/16 18:23:56 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>


struct Vertex
{
    float x;
    float y;
    float z;
};

struct TextureCoord
{
    float u;
    float v;
};

struct Normal
{
    float x;
    float y;
    float z;
};

struct Face
{
    int v[3];
    int vt[3];
    int vn[3];
};

class Mesh {
    public : 
     std::vector<Vertex> vertices;
     std::vector<TextureCoord> texCoords;
     std::vector<Normal> normals;
     std::vector<Face> faces;
}