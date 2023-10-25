/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:04:59 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/25 17:06:33 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "OBJparser.h"
#include "glew.h"
#include <glfw3.h>
#include "loadShader.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        exit(1);
    }
    if (!glfwInit()) {
        std::cerr << "Error during GLFW initialization" << std::endl;
        return -1;
    }
    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Ma Fenêtre GLFW", nullptr, nullptr);
    if (!window) {
        std::cerr << "Error during GLFW window creation" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Make the window's context current
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        std::cerr << "Error during GLEW initialization" << std::endl;
        return -1;
    }
    GLuint shaderProgram = loadShaders("./shader/vertex_shader.vs", "./shader/fragment_shader.fs");
    try {
        OBJparser parser(argv[1]);
        Mesh mesh = parser.parse();
        mesh.printVertices();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    std::cout << "Press enter to exit..." << std::endl;
    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // Swap front and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        if (std::cin.get() == '\n')
            break;
    }
    glfwTerminate();
}