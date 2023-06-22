#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>

void drawBox(float width, float height, float depth)
{
    // Front face
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, 1.0f);    // Normal vector for front face
    glVertex3f(0.0f, 0.0f, 0.0f);    // Bottom-left vertex
    glVertex3f(width, 0.0f, 0.0f);   // Bottom-right vertex
    glVertex3f(width, height, 0.0f); // Top-right vertex
    glVertex3f(0.0f, height, 0.0f);  // Top-left vertex
    glEnd();

    // Back face
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 0.0f, -1.0f);     // Normal vector for back face
    glVertex3f(0.0f, 0.0f, -depth);    // Bottom-left vertex
    glVertex3f(width, 0.0f, -depth);   // Bottom-right vertex
    glVertex3f(width, height, -depth); // Top-right vertex
    glVertex3f(0.0f, height, -depth);  // Top-left vertex
    glEnd();

    // Left face
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0.0f, 0.0f);    // Normal vector for left face
    glVertex3f(0.0f, 0.0f, 0.0f);     // Bottom-left vertex
    glVertex3f(0.0f, 0.0f, -depth);   // Bottom-right vertex
    glVertex3f(0.0f, height, -depth); // Top-right vertex
    glVertex3f(0.0f, height, 0.0f);   // Top-left vertex
    glEnd();

    // Right face
    glBegin(GL_QUADS);
    glNormal3f(1.0f, 0.0f, 0.0f);      // Normal vector for right face
    glVertex3f(width, 0.0f, 0.0f);     // Bottom-left vertex
    glVertex3f(width, 0.0f, -depth);   // Bottom-right vertex
    glVertex3f(width, height, -depth); // Top-right vertex
    glVertex3f(width, height, 0.0f);   // Top-left vertex
    glEnd();

    // Top face
    glBegin(GL_QUADS);
    glNormal3f(0.0f, 1.0f, 0.0f);      // Normal vector for top face
    glVertex3f(0.0f, height, 0.0f);    // Bottom-left vertex
    glVertex3f(width, height, 0.0f);   // Bottom-right vertex
    glVertex3f(width, height, -depth); // Top-right vertex
    glVertex3f(0.0f, height, -depth);  // Top-left vertex
    glEnd();

    // Bottom face
    glBegin(GL_QUADS);
    glNormal3f(0.0f, -1.0f, 0.0f);   // Normal vector for bottom face
    glVertex3f(0.0f, 0.0f, 0.0f);    // Bottom-left vertex
    glVertex3f(width, 0.0f, 0.0f);   // Bottom-right vertex
    glVertex3f(width, 0.0f, -depth); // Top-right vertex
    glVertex3f(0.0f, 0.0f, -depth);  // Top-left vertex
    glEnd();
}