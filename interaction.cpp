#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "interaction.h"
#include "utility.h"
#include "point2D.h"
#include "curve.h"
#include <vector>

using namespace std;

// All the following extern vars are defined in main.cpp
//They are just being declared here 

extern int width, height;
//extern vector<Point2D> B;
extern Curve *C;

int WhichPointErase = -1;
int WhichPointMove = -1; 


void mouseButtonEvents(int button, int state, int x, int y) 
{

double Px, Py;
int i, X, Y;

	Point2D P2D;
	P2D .x = x;
	P2D.y = height-y;

	switch( button )
     {
        case GLUT_LEFT_BUTTON:
      
           switch( state )
           {
              case GLUT_DOWN:
				  
			      if (glutGetModifiers() & GLUT_ACTIVE_CTRL)
				  {
					  WhichPointErase = -1;
					  DecodeCoords(x,y,&X,&Y);
					  
					  for (i = 0; i < C->B.size(); i++) 
						{
						  	Px = C->B[i].x;
							Py = C->B[i].y;
							
							if (abs((int) (Px - X)) <= 3 && abs((int) (Py - Y)) <= 3) 
							{
							WhichPointErase = i;
							//cout<<"which="<<WhichPointErase;
							break;
							}
						} //for (i=0..
					  if (WhichPointErase>=0)
						  C->B.erase(C->B.begin()+WhichPointErase); //erase the point

				  } //if
				  else
				  {
					  //glutSetCursor(GLUT_CURSOR_SPRAY);
					  C->B.push_back(P2D); //Add a Point
				  }


			      break;
				
              case GLUT_UP:
				m_LButtonDown = FALSE;
				
                break;
           }
           break;

		case GLUT_RIGHT_BUTTON:
			 switch( state )
			 {
              case GLUT_DOWN:
				m_RButtonDown = TRUE;
				m_RDownPos.x = x;
				m_RDownPos.y = y;

				WhichPointMove = -1;
				DecodeCoords(x,y,&X,&Y) ;

			
				for (i = 0; i < C->B.size(); i++) 
					{
					Px = C->B[i].x;
					Py = C->B[i].y;

					if (abs((int) (Px - X)) <= 3 && abs((int) (Py - Y)) <= 3) 
					{
					WhichPointMove = i;
					//cout<<"which="<<WhichPointMove;
					return;
					}
					continue;
					} //for (i=0..
			
              break;

			  case GLUT_UP:
				  m_RButtonDown = FALSE;
				  WhichPointMove = -1;
				  break;
			 }

		case GLUT_MIDDLE_BUTTON:
			switch (state)
			
		default:
			break;

     } //End of switch

	glutPostRedisplay();
}

void mouseMotionEvents(int x, int y) 
{
int X, Y;

	if (m_RButtonDown)
	{
		if (WhichPointMove < 0)
		return;
	
		DecodeCoords(x,y,&X,&Y) ;
		C->B[WhichPointMove].x = X;
		C->B[WhichPointMove].y = Y;
					
	}

	glutPostRedisplay();
}

void mousePassiveMotion(int x, int y)
{
	static char title[64];

	sprintf(title, "(%d,%d)", x, y);
	glutSetWindowTitle(title);

}

void keyboard(unsigned char Key, int x, int y)
{
  switch(Key)
  {
  case 27: 
  case 'q':
    exit(0);
    break;
  };
  
  glutPostRedisplay();

}