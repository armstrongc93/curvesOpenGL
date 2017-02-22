#include "utility.h"

int fac(int x)
{
  if (x==0)
  return 1;
  
  else
  return (x*fac(x-1));
}


void DecodeCoords(int x, int y, int *gridx, int *gridy) {
  GLint viewport[4];
  GLdouble modelMatrix[16], projMatrix[16];
  GLdouble objx, objy, objz ;

  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
  glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);   
  gluUnProject(x, y, .0,
			modelMatrix, projMatrix, viewport,
			&objx, &objy, &objz);

  *gridx = objx ;
  *gridy = ((2.0/projMatrix[5])-objy) ;
}
