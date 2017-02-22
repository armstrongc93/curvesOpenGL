#include <iostream>
#include <GL/glut.h>
#include "point2D.h"
#include "curve.h"
#include <vector>
    
using namespace std;

int DIV=30.0;

Curve *C; // A pointer to curve class

/*Uncomment following line to get rid of console window
 and display only graphics window */
//#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

int width, height;

int win_id;            // each curve on each screen
int showCtrlPts=1;	   //Switch to toggle between showing ctrl pts and hiding
int showCtrlPoly = 1;	// Show/hide control polygon

void mouseButtonEvents(int, int, int, int);
void mouseMotionEvents(int, int);
void mousePassiveMotion(int, int);
void keyboard(unsigned char, int, int);
void draw(int);
void display(void);
void reshape(int, int);
void shellmessages(void);
void selectMessage(int);
void init(void);



//OpenGL initialization function. DNT.
void init(void)
{
   shellmessages();
   glClearColor(.0, .0, .0, .0);
   glShadeModel(GL_FLAT);
   glEnable(GL_POINT_SMOOTH);
   glEnable(GL_LINE_SMOOTH);
   glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);	// Make round points, not square points
   glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);		// Antialias the lines

}


void shellmessages(void)
{
	cout<<"\n* Single Left Button Click  - Adds a Point\n\n"
		<<"* <Ctrl>+Single Left Button click on an existing Point - Removes that Point\n\n"
		<<"* Right Click an existing Point and move mouse - Drags that Point\n\n"
		<<"* Middle Button Click - Menu for clearing screen, etc.\n\n";
}


void display(void)
{
	
	glClear (GL_COLOR_BUFFER_BIT);
 	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glColor3f (.0, .0, .0);
	glutSetWindow(win_id);
    
	draw(GL_RENDER);

	glutSwapBuffers();

}

Point2D deCast(float t)
{
	unsigned int j;

	for (j = 0; j < C->B.size(); j++)


}


/* This is the function that needs to be changed for drawing. */
void draw(int mode)
{
	unsigned int i;

// The following lines  draw all the points
	glBegin(GL_POINTS);
	for (i = 0; i < C->B.size(); i++)
	{
		glColor3f(0.0, 1.0, 1.0);
		glPointSize(5.0);
		glVertex2f(C->B[i].x, C->B[i].y);
	}
	glEnd();

}


// When you resize/create the window, this gets called. DNT.
void reshape(int w, int h)
{
	width  = w;
	height = h;

	glViewport(0,0,width,height) ;
    glMatrixMode(GL_PROJECTION) ;
    glLoadIdentity() ;
    glOrtho(.0, w, .0, h, -1.0, 1.0) ;

}


void selectMessage(int msg)
{
	switch (msg) {
	case 1:
		if (!C->B.empty())
			C->B.clear();
		glutPostRedisplay();
		break;
	case 2:
		glutPositionWindow(50, 50);
		glutReshapeWindow(600, 400);
		break;
	case 3:
		glutFullScreen();
		break;
	case 4:
		if (showCtrlPts == 1)
		{
			showCtrlPts = 0;
			glColor3f(0.0, 1.0, 0.0);
		}
		if (showCtrlPts != 1)
		{
			showCtrlPts = 1;
			glColor3f(0.0, 1.0, 1.0);
		}
	  break;
 /* case 5:
	  showCtrlPoly = !showCtrlPoly;
	  break;
  case 6:
	  showDeCas = !showDeCas;
	  break;
  case 7:
	  showBern = !showBern;
	  break;*/
  case 10:
	  exit(0);
	  break;
  default:
	  break;
  }
  glutPostRedisplay();
}


int main(int argc, char** argv)
{
	Curve C1;
	C = &C1;

   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize (600, 400);
   glutInitWindowPosition (50, 50);
   win_id = glutCreateWindow("MEC572 Spring 2017");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouseButtonEvents);
   glutMotionFunc(mouseMotionEvents);
   glutPassiveMotionFunc(mousePassiveMotion);

  int glut_menu = glutCreateMenu(selectMessage);
  glutAddMenuEntry("Clear Screen", 1);
  glutAddMenuEntry("Normal Window", 2);
  glutAddMenuEntry("Full Screen", 3);
  glutAddMenuEntry("Show/Hide Ctrl Points", 4);
  glutAddMenuEntry("Show/Hide Ctrl Polygon", 4);
  glutAddMenuEntry("Exit", 10);
  glutAttachMenu(GLUT_MIDDLE_BUTTON);


   glutMainLoop();

   return 0;
}

