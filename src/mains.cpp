/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mains.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:04:59 by ydumaine          #+#    #+#             */
/*   Updated: 2023/10/17 19:05:50 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "OBJparser.h"
#include "glfw3.h"

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
    GLFWwindow* window = glfwCreateWindow(800, 600, "Ma Fenêtre GLFW", nullptr, nullptr);
    if (!window) {
        std::cerr << "Error during GLFW window creation" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
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
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
        if (std::cin.get() == '\n')
            break;
    }
    glfwTerminate();
}