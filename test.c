#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535898

void display(void)
{
  GLint circle_points = 100;
  int i = 0;
  double angle;
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINE_LOOP);
  for(i = 0;i<circle_points;i++)
    {
      angle = 2*PI*i/circle_points;
      glVertex2f(cos(angle),sin(angle));
    }
  glEnd();
  glFlush();
}

void init(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1,1.0,-1,1.0,-1,1.0);
}
int main(int argc,char **agrv)
{
  glutInit(&argc,agrv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(250,250);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Look a circle!");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
