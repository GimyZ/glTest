//
//  triangle.cpp
//  opengltest
//
//  Created by zgm on 19/5/30.
//  Copyright © 2019年 zgm. All rights reserved.
//

#include <GLTools.h>
#include <GLShaderManager.h>
#include <GLUT/GLUT.h>

GLBatch triangleBatch;
GLShaderManager shaderManager;

GLfloat vVerts[] = {
    -0.5f,.0f,.0f,
    0.5f,.0f,.0f,
    .0f,.5f,.0f
};

void ChangeSize(int w,int h)
{
    glViewport(0, 0, w, h);
}

void SetupRC()
{
    glClearColor(.0f, .0f, .0f, .0f);
    shaderManager.InitializeStockShaders();
    
    triangleBatch.Begin(GL_TRIANGLES, 3);
    triangleBatch.CopyVertexData3f(vVerts);
    triangleBatch.End();
}

void RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_SUBTRACT);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH, GL_NICEST);
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH, GL_NICEST);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);
    
    GLfloat vRed[] = {1.0f,.0f,.0f,1.0f};
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY,vRed);
    triangleBatch.Draw();
    
    glutSwapBuffers();
    
}


/*
void RenderScene(void)
{
    glClearColor(.0f, .0f, 1.0f, .0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glClearColor(1.0f, .0f, .0f, .0f);
    glScissor(100, 100, 250, 500);
    glEnable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glClearColor(.0f, 1.0f, .0f, .0f);
    glScissor(150, 150, 200, 400);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glDisable(GL_SCISSOR_TEST);
    glutSwapBuffers();
}
*/

void SpecialKeys(int key,int x,int y)
{
    if(key == GLUT_KEY_UP)
    {
        vVerts[1] += 0.025f;
        vVerts[4] += 0.025f;
        vVerts[7] += 0.025f;
    }
    else if(key == GLUT_KEY_DOWN)
    {
        vVerts[1] -= 0.025f;
        vVerts[4] -= 0.025f;
        vVerts[7] -= 0.025f;
    }
    
    triangleBatch.CopyVertexData3f(vVerts);
    glutPostRedisplay();
}

int main(int argc,char ** argv)
{
    gltSetWorkingDirectory(argv[0]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutInitWindowSize(320, 640);
    glutCreateWindow("triagle");
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutSpecialFunc(SpecialKeys);
    
    GLenum err = glewInit();
    if(GLEW_OK != err)
    {
        fprintf(stderr,"glew error:%s\n",glewGetErrorString(err));
        return 1;
    }
    
    SetupRC();
    
    glutMainLoop();
    return 0;
}
