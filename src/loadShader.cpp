/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadShader.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:03:41 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/25 17:06:53 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "glew.h"

std::string readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

GLuint loadShaders(const char *vertex_path, const char *fragment_path) {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    std::string vertShaderStr = readFile(vertex_path);
    std::string fragShaderStr = readFile(fragment_path);
    if (vertShaderStr.empty() || fragShaderStr.empty())
        throw std::runtime_error("Shader file is empty");
    const char *vertShaderSrc = vertShaderStr.c_str();
    const char *fragShaderSrc = fragShaderStr.c_str();
    GLint result = GL_FALSE;
    int logLength;

    // Compile vertex shader
    glShaderSource(vertexShader, 1, &vertShaderSrc, NULL);
    glCompileShader(vertexShader);
    // Check vertex shader
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertexShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    // Compile fragment shader
    glShaderSource(fragmentShader, 1, &fragShaderSrc, NULL);
    glCompileShader(fragmentShader);
    // Check fragment shader
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragmentShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}