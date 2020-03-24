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

int width = 600, height = 400;
int first = 0;
int xi, yi, xf, yf;

void draw(void){}

void drawLine(){
    
}

void mouse(int button, int state, int x, int y){
    
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN)
                
            break;
            
        default:
            break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Project");
    gluOrtho2D(0, width, 0, height);
    glutMainLoop();

}


