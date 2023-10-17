/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MeshTypes.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:20:34 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/17 18:29:25 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MeshTypes.h"
#include <iostream>

void Mesh::printVertices() const
{
    std::cout << "Vertices:" << std::endl;
    for (std::vector<Vertex>::const_iterator vertex = vertices.begin(); vertex != vertices.end(); ++vertex)
        std::cout << vertex->x << " " << vertex->y << " " << vertex->z << std::endl;
}