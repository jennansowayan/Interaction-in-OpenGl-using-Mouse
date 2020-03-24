//
//  main.cpp
//  Interaction in OpenGl using Mouse
//
//  Created by jennan sowayan on 3/24/20.
//  Copyright © 2020 jennan sowayan. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>



int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Triangles");
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
    glutMainLoop();

}


