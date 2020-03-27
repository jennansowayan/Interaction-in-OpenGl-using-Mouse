#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 600
#define HEIGHT 600

using namespace std;

double arr[5000][4]; //array to store start and end vertices coordinates
int i=0; //array index
int flag=0; //detects if mouse is pressed


//initalize
void init()
{
    glClearColor( 0.0, 0.0, 0.0, 1.0);
    glMatrixMode( GL_PROJECTION);
    gluOrtho2D(0.0,WIDTH,0.0,HEIGHT);
    memset(arr,0,5000);
    glPointSize(70.0);
}

//OPENGL MAPPING
float getOpenGLX(int x)
{
    double ox = x/ (double)WIDTH*(WIDTH);
    return ox; //cursor x position
}

float getOpenGLY(int y)
{
    double oy = (1 - y/ (double) HEIGHT)*HEIGHT;
    return oy; //cursor y position
}

void drawLines()
{
    /* vertex data comes from an array */
    glEnableClientState(GL_VERTEX_ARRAY);

    /* we want to use a common color for all vertices */
    glDisableClientState(GL_COLOR_ARRAY);
    glColor3f(1.0, 0.0, 0.0);

    /* where to get the data from */
    glVertexPointer(2, GL_DOUBLE, sizeof(double)*4, arr);

    /* draw the whole thing */
    glDrawArrays(GL_LINE_STRIP, 0, i);

    /* cleanup */
    glDisableClientState(GL_VERTEX_ARRAY);
}

//store coordinates in the array

void addValue(int x,int y)
{
    arr[i][0]=getOpenGLX(x);
    arr[i++][1]=getOpenGLY(y);
}


void draw()
{
    glClear( GL_COLOR_BUFFER_BIT);
  
        drawLines();
     
    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}


void mouse(int button,int state,int x, int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) //left btn is pressed
    {
        if(!flag)
        {
            flag=1;
        }
    }
    else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP) //left btn released
    {
        if(flag)
        {
            flag=0;
        }
    }
}


void motion(int x,int y)
{
    if(flag)
    {
        addValue(x,y);
    }
}




int main( int argc, char ** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowPosition( 100, 100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow( "Testing");
    init();
    glutDisplayFunc(draw);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
  //  glutTimerFunc(100,myTimer,0);
    glutMainLoop();
    return 0;
}
