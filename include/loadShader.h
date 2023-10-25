/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadShader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:03:30 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/25 17:03:32 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOADSHADER_H
#define LOADSHADER_H

#include "glew.h"
#include <string>

std::string readFile(const char *filePath);
GLuint loadShaders(const char *vertex_path, const char *fragment_path);

#endif  