//
//  main.cpp
//  opengltest
//
//  Created by zgm on 17/7/19.
//  Copyright © 2017年 zgm. All rights reserved.
//

#include <GLUT/GLUT.h>
#include <iostream>
#include <GLTools.h>



void display()

{
    
    glClear(GL_ENABLE_BIT);
    
    glBegin(GL_POLYGON);
    
    glVertex2f(-0.5, -0.5);
    
    glVertex2f(-0.5, 0.5);
    
    glVertex2f(0.5, 0.5);
    
    glVertex2f(0.5, -0.5);
    
    glEnd();
    
    glFlush();
    
}



int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    
    glutInitWindowSize(400, 400);
    
    glutCreateWindow("test");
    
    //检查支持扩展
//    GLint nNumExtensions;
//    glGetIntegerv(GL_VERSION, &nNumExtensions);
//    for(GLint i = 0;i < nNumExtensions;i++)
//    {
//        std::cout << (char*)glGetString(i);
//    }
    
    GLenum errorNo;
    errorNo = glGetError();
    
    std::cout << glGetString(GL_VERSION) << std::endl;
    
    glEnable(GL_DEPTH_TEST);
    auto num = glIsEnabled(GL_DEPTH_TEST);
    
    glutDisplayFunc(display);
    
    glutMainLoop();
    
    return 0;
    
}
