//#include "triangle.h"

#include <GL/glew.h>

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xutil.h>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>

extern Bool doubleBuffer;
extern Display *display;
extern Window main_window;
GLuint vaoHandle; //Vertex Attribute Array handle

  float vertices[] = {
     -0.8f, -0.8f, 0.0f,
      0.8f, -0.8f, 0.0f,
      0.0f, 0.8f, 0.0f
     };

  float colors[] = {
      1.0f, 0.0f, 0.0f,
      0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 1.0f
     };

void makeTriangle()
{


// Step1: Create the Buffer Objects
GLuint vboHandles[2];
glGenBuffers(2, vboHandles);
GLuint vertexBufferHandle = vboHandles[0];
GLuint colorBufferHandle = vboHandles[1];

glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

//Step 2: Create and bind a Vertex Array Object and set up channels for the attribute variables
glGenVertexArrays(1, &vaoHandle);
glBindVertexArray(vaoHandle);

glEnableVertexAttribArray(0);  //Channel 0 for vertex attributes
glEnableVertexAttribArray(1); //Channel 1 for colors attributes

glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
// Attribute 0 will get its data from positionBufferHandle
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)));

glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte *)NULL + (0)));

}

void drawTriangle()
{
  glBindVertexArray(vaoHandle);
  fprintf(stderr, "In redraw()\n");
  glDrawArrays(GL_TRIANGLES, 0, 3);
//  if (doubleBuffer) glXSwapBuffers(display, main_window); else glFlush();
}
