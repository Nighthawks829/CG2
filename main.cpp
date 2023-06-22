#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glew.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\glut.h>
#include <math.h>
#include "getBMP.h"

#define PI 3.141592653

#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 1080
#define FPS 30
float count = -100;

float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle = 0.0;

float lastx, lasty;

static unsigned int texture[10]; // Array of texture ids.

float kevinMoveX = 0;
float kevinMoveY = 0;
float kevinMoveZ = 0;
float kevinRotateX = 0;
float kevinRotateY = 0;
float kevinRotateZ = 0;

float bobMoveX = 0;
float bobMoveY = 0;
float bobMoveZ = 0;
float bobRotateX = 0;
float bobRotateY = 0;
float bobRotateZ = 0;

float ballMoveX = 0;
float ballMoveY = 0;
float ballMoveZ = 0;
float ballRotateX = 0;
float ballRotateY = 0;
float ballRotateZ = 0;

float ballScale = 0.15;

float kevinRightHandRotateX = 0;
float kevinRightHandRotateY = 0;
float kevinRightHandRotateZ = 0;
float kevinLeftHandRotateX = 0;
float kevinLeftHandRotateY = 0;
float kevinLeftHandRotateZ = 0;
int kevinRightHandflip = 0;
int kevinLeftHandflip = 0;

float kevinRightLegRotateX = 0;
float kevinRightLegRotateY = 0;
float kevinRightLegRotateZ = 0;
float kevinLeftLegRotateX = 0;
float kevinLeftLegRotateY = 0;
float kevinLeftLegRotateZ = 0;
int kevinLeftLegFlip = 0;
int kevinRightLegFlip = 0;

float kevinScale = 0.25;
float lastKevinMoveX;
float lastKevinMoveZ;

float bobRightHandRotateX = 0;
float bobRightHandRotateY = 0;
float bobRightHandRotateZ = 0;
float bobLeftHandRotateX = 0;
float bobLeftHandRotateY = 0;
float bobLeftHandRotateZ = 0;
int bobRightHandflip = 0;
int bobLeftHandflip = 0;

float bobRightLegRotateX = 0;
float bobRightLegRotateY = 0;
float bobRightLegRotateZ = 0;
float bobLeftLegRotateX = 0;
float bobLeftLegRotateY = 0;
float bobLeftLegRotateZ = 0;
int bobLeftLegFlip = 0;
int bobRightLegFlip = 0;

float netMoveY = 0.5;
float canonMoveY = 0.5;
float projection = 0;
float ballLastMoveY = 0;

GLdouble eqn[4] = {1.0, 0.0, 0.0, 0.0};
GLdouble eqn2[4] = {0.0, 1.0, 0.0, 0.0};

#include "drawCylinder.cpp"
#include "drawBox.cpp"
#include "drawSemisphere.cpp"
#include "drawSphere.cpp"
#include "drawGoggle.cpp"
#include "loadTextures.cpp"
#include "drawSea.cpp"
#include "drawBeach.cpp"
#include "drawBall.cpp"
#include "drawSky.cpp"
#include "drawNet.cpp"
#include "drawCanon.cpp"
#include "drawBob.cpp"
#include "drawKevin.cpp"
#include "drawEarth.cpp"
#include "drawStar.cpp"
#include "drawMoon.cpp"

void drawstring(float x, float y, float z, char *string)
{
    char *c;
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_COLOR_MATERIAL);
    glRasterPos3f(x, y, z);
    glColor3ub(0, 0, 0.0);

    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();
}

void camera(void)
{
    glRotatef(xrot, 1.0, 0.0, 0.0);    // rotate our camera on the x-axis (left and right)
    glRotatef(yrot, 0.0, 1.0, 0.0);    // rotate our camera on the y-axis (up and down)
    glTranslated(-xpos, -ypos, -zpos); // translate the screen to the position of our camera
}

void cameraController()
{
    std::cout << "Camera X Position: " << xpos << "\n";
    std::cout << "Camera Y Position: " << ypos << "\n";
    std::cout << "Camera Z Position: " << zpos << "\n";
    std::cout << "Camera RotX Position: " << xrot << "\n";
    std::cout << "Camera RotY Position: " << yrot << "\n";

    if (count < 10)
    {
        xpos = -2;
        ypos = 2;
        zpos = 7;
        xrot = -5;
        canonMoveY = 10;
    }
    else if (count > 10 && count < 100)
    {
        xrot += 0.5;
        if (xrot >= 15)
        {
            xrot = 15;
        }
        std::cout << "xrot:" << xrot << "\n";
    }
    else if (count > 650 && count < 850)
    {
        xpos += 0.1;
        zpos += 0.3;
        yrot += 0.5;
        xrot -= 0.5;
        if (xpos >= 3.5)
        {
            xpos = 3.5;
        }
        if (zpos >= 12)
        {
            zpos = 12;
        }
        if (yrot >= 6)
        {
            yrot = 6;
        }
        if (xrot <= 8)
        {
            xrot = 8;
        }
    }
    else if (count > 1890 && count < 1990)
    {
        xpos = 4.5;
        ypos = 1.22;
        zpos = 1.29;
        xrot = 0;
        yrot = 293;
        count += 1;
        bobMoveX = -2.5;
        bobMoveY = 0.8;
        bobMoveZ = -3;
        bobRotateX = 90;
        // bobRotateZ=-90;
        ballMoveX = -2;
        ballMoveY = 0.5;
        ballMoveZ = -3;
        canonMoveY -= 1;
        if (canonMoveY <= 0.5)
        {
            canonMoveY = 0.5;
        }
    }
    else if (count > 2290 && count < 2390)
    {
        netMoveY = 10;
        xpos = 2.14;
        ypos = 1.22;
        zpos = 3.14;
        xrot = 0;
        yrot = 412;
        kevinRightHandRotateZ = 50;
        kevinRightHandRotateX = -60;
        kevinRightHandRotateY = 60;
        kevinLeftHandRotateZ = -50;
        kevinLeftHandRotateX = 240;
        kevinLeftHandRotateY = 60;
        ballMoveZ = 0;
        ballMoveY = 0.4;
        ballMoveX = -2;
    }
    else if (count > 2590 && count < 2640)
    {
        xpos = 2.03;
        ypos = 1.22;
        zpos = 13.14;
        xrot = 0;
        yrot = 545;
        kevinScale = 0;
        kevinMoveX = 1;
        kevinMoveY = 0;
        kevinMoveZ = 20;
        ballScale = 0;
        ballMoveX = 1;
        ballMoveY = 0;
        ballMoveZ = 20;
    }
    else if (count > 2950 && count < 3000)
    {
        bobMoveX = -2.5;
        bobMoveY = 0.8;
        bobMoveZ = -3;
        bobLeftHandRotateZ = -90;
        bobRightHandRotateZ = 90;
        bobLeftHandRotateX = 90;
        bobRightHandRotateX = 90;
        bobRotateX = 90;
        bobRotateZ = -90;
        xpos = 7.36;
        ypos = 3.45;
        zpos = -1.19;
        xrot = 22;
        yrot = -79;
    }
}

void scriptController()
{
    if (count > 100 && count < 150)
    {
        drawstring(-0.3, -0.65, -2.7, "Bob: What a perfect day at the beach, Stuart!");
    }
    else if (count > 180 && count < 230)
    {
        drawstring(-0.35, -0.65, -2.7, "Stuart: Yes Bob! The sun, the sand, it's all so relaxing.");
    }
    else if (count > 550 && count < 600)
    {
        drawstring(-0.5, -0.65, -2.7, "Stuart: How about a volleyball match, Stuart? Let's see who is the better player!");
        drawstring(-0.35, -0.7, -2.7, "The loser will be in charge of cooking dinner tonight.");
    }
    else if (count > 630 && count < 680)
    {
        drawstring(-0.25, -0.65, -2.7, "Bob: That sounds like fun, Stuart! Deal!");
    }
    else if (count > 1300 && count < 1390)
    {
        drawstring(-0.3, -0.65, -2.7, "Stuart: Bob, that was weak! Is that all you got?");
    }
    else if (count > 1400 && count < 1450)
    {

        drawstring(-0.2, -0.65, -2.7, "Bob: Oh yeah? I'll show you!");
    }
    else if (count > 1690 && count < 1790)
    {

        drawstring(-0.25, -0.65, -2.7, "Stuart: Bob, that was still too weak!");
    }
    else if (count > 1840 && count < 1890)
    {
        drawstring(-0.3, -0.65, -2.7, "Bob: Grrr! Fine, I'll show you the real power");
    }
    else if (count > 3000 && count < 3100)
    {
        drawstring(-0.3, -0.65, -2.7, "Bob: Uhhh…Stuart? Where did you go? Uh-oh.");
    }
}

void bobController()
{
    if (count < 10)
    {
        bobMoveX = -3;
        bobMoveY = 0.05;
        bobMoveZ = 1;
        // bobRotateY = 90;
    }
    else if (count > 350 && count < 450)
    {
        bobRotateX += 3;
        bobMoveY += 0.03;
        if (bobRotateX >= 90)
        {
            bobRotateX = 90;
        }
        if (bobMoveY >= 0.8)
        {
            bobMoveY = 0.8;
        }
    }
    else if (count > 450 && count < 550)
    {
        bobRotateZ -= 3;
        bobLeftHandRotateZ -= 3;
        bobLeftHandRotateX += 3;

        bobRightHandRotateZ += 3;
        bobRightHandRotateX += 3;
        if (bobRotateZ <= -90)
        {
            bobRotateZ = -90;
        }
        if (bobLeftHandRotateZ <= -90)
        {
            bobLeftHandRotateZ = -90;
        }
        if (bobRightHandRotateZ >= 90)
        {
            bobRightHandRotateZ = 90;
        }
        if (bobRightHandRotateX >= 90)
        {
            bobRightHandRotateX = 90;
        }
        if (bobLeftHandRotateX >= 90)
        {
            bobLeftHandRotateX = 90;
        }
    }
    else if (count > 700 && count < 750)
    {
        bobLeftHandRotateZ = -90;
        bobRightHandRotateZ = 90;
        bobLeftHandRotateX = 0;
        bobRightHandRotateX = 0;
    }
    else if (count > 750 && count < 920)
    {
        bobMoveX += 0.1;
        bobMoveZ = -0.3;
        if (bobMoveX >= 4)
        {
            bobMoveX = 4;
        }
        if (bobLeftLegFlip == 1)
        {
            bobLeftLegRotateX += 5;
            if (bobLeftLegRotateX >= 30)
            {
                bobLeftLegRotateX = 30;
                bobLeftLegFlip = 0;
            }
        }
        else if (bobLeftLegFlip == 0)
        {
            bobLeftLegRotateX -= 5;
            if (bobLeftLegRotateX <= -30)
            {
                bobLeftLegRotateX = -30;
                bobLeftLegFlip = 1;
            }
        }

        if (bobRightLegFlip == 0)
        {
            bobRightLegRotateX += 5;
            if (bobRightLegRotateX >= 30)
            {
                bobRightLegRotateX = 30;
                bobRightLegFlip = 1;
            }
        }
        else if (bobRightLegFlip == 1)
        {
            bobRightLegRotateX -= 5;
            if (bobRightLegRotateX <= -30)
            {
                bobRightLegRotateX = -30;
                bobRightLegFlip = 0;
            }
        }
    }
    else if (count > 1020 && count < 1120)
    {
        bobLeftHandRotateX -= 3;
        if (bobLeftHandRotateX <= -90)
        {
            bobLeftHandRotateX = -90;
        }
    }
    else if (count > 1120 && count < 1170)
    {
        bobLeftHandRotateX += 20;
        if (bobLeftHandRotateX >= 90)
        {
            bobLeftHandRotateX = 90;
        }
    }
    else if (count > 1460 && count < 1560)
    {
        bobLeftHandRotateX -= 3;
        if (bobLeftHandRotateX <= -90)
        {
            bobLeftHandRotateX = -90;
        }
    }
    else if (count > 1560 && count < 1610)
    {
        bobLeftHandRotateX += 20;
        if (bobLeftHandRotateX >= 90)
        {
            bobLeftHandRotateX = 90;
        }
    }
    else if (count > 1990 && count < 2090)
    {
        bobRotateZ += 3;
        if (bobRotateZ >= 0)
        {
            bobRotateZ = 0;
        }
    }
    else if (count > 2090 && count < 2190)
    {
        bobMoveZ += 0.1;
        if (bobMoveZ >= -1.9)
        {
            bobMoveZ = -1.9;
        }
    }
    else if (count > 3000 && count < 3100)
    {
        bobRotateY += 0.3;
        bobRightLegRotateX += 0.55;
        bobLeftLegRotateX += 0.55;
    }
}

void kevinController()
{
    if (count < 10)
    {
        kevinMoveX = -1;
        kevinMoveY = 0.05;
        kevinMoveZ = 1;
    }
    else if (count > 350 && count < 450)
    {
        kevinRotateX += 3;
        kevinMoveY += 0.03;
        if (kevinRotateX >= 90)
        {
            kevinRotateX = 90;
        }
        if (kevinMoveY >= 0.8)
        {
            kevinMoveY = 0.8;
        }
    }

    else if (count > 450 && count < 550)
    {
        kevinRotateZ += 3;
        kevinLeftHandRotateZ -= 3;
        kevinLeftHandRotateX += 3;

        kevinRightHandRotateZ += 3;
        kevinRightHandRotateX += 3;

        if (kevinRotateZ >= 90)
        {
            kevinRotateZ = 90;
        }
        if (kevinRotateZ <= -90)
        {
            kevinRotateZ = -90;
        }
        if (kevinLeftHandRotateZ <= -90)
        {
            kevinLeftHandRotateZ = -90;
        }
        if (kevinRightHandRotateZ >= 90)
        {
            kevinRightHandRotateZ = 90;
        }
        if (kevinRightHandRotateX >= 90)
        {
            kevinRightHandRotateX = 90;
        }
        if (bobLeftHandRotateX >= 90)
        {
            kevinLeftHandRotateX = 90;
        }
    }
    else if (count > 550 && count < 650)
    {
        kevinRotateZ -= 3;
        kevinRightHandRotateZ -= 3;
        kevinRightHandRotateX -= 3;
        if (kevinRotateZ <= 0)
        {
            kevinRotateZ = 0;
        }
        if (kevinRightHandRotateZ <= 0)
        {
            kevinRightHandRotateZ = 0;
        }
        if (kevinRightHandRotateX <= 0)
        {
            kevinRightHandRotateX = 0;
        }
    }
    else if (count > 700 && count < 750)
    {
        kevinRotateZ = -90;
        kevinRightHandRotateZ = 90;
        kevinLeftHandRotateZ = -90;
        kevinRightHandRotateX = 130;
        kevinLeftHandRotateX = 60;
    }
    else if (count > 750 && count < 920)
    {
        kevinMoveX += 0.1;
        kevinMoveZ = -0.3;
        if (kevinLeftHandflip == 1)
        {
            kevinLeftHandRotateX += 5;
            if (kevinLeftHandRotateX >= 130)
            {
                kevinLeftHandRotateX = 130;
                kevinLeftHandflip = 0;
            }
        }
        else if (kevinLeftHandflip == 0)
        {
            kevinLeftHandRotateX -= 5;
            if (kevinLeftHandRotateX <= 60)
            {
                kevinLeftHandRotateX = 60;
                kevinLeftHandflip = 1;
            }
        }

        if (kevinRightHandflip == 0)
        {
            kevinRightHandRotateX += 5;
            if (kevinRightHandRotateX >= 130)
            {
                kevinRightHandRotateX = 130;
                kevinRightHandflip = 1;
            }
        }
        else if (kevinRightHandflip == 1)
        {
            kevinRightHandRotateX -= 5;
            if (kevinRightHandRotateX <= 60)
            {
                kevinRightHandRotateX = 60;
                kevinRightHandflip = 0;
            }
        }

        if (kevinLeftLegFlip == 1)
        {
            kevinLeftLegRotateX += 5;
            if (kevinLeftLegRotateX >= 30)
            {
                kevinLeftLegRotateX = 30;
                kevinLeftLegFlip = 0;
            }
        }
        else if (kevinLeftLegFlip == 0)
        {
            kevinLeftLegRotateX -= 5;
            if (kevinLeftLegRotateX <= -30)
            {
                kevinLeftLegRotateX = -30;
                kevinLeftLegFlip = 1;
            }
        }

        if (kevinRightLegFlip == 0)
        {
            kevinRightLegRotateX += 5;
            if (kevinRightLegRotateX >= 30)
            {
                kevinRightLegRotateX = 30;
                kevinRightLegFlip = 1;
            }
        }
        else if (kevinRightLegFlip == 1)
        {
            kevinRightLegRotateX -= 5;
            if (kevinRightLegRotateX <= -30)
            {
                kevinRightLegRotateX = -30;
                kevinRightLegFlip = 0;
            }
        }
        if (kevinMoveX >= 6.8)
        {
            kevinMoveX = 6.8;
        }
    }
    else if (count >= 920 && count < 1020)
    {
        kevinLeftHandRotateX = 90;
        kevinRightHandRotateX = 90;
        kevinRightLegRotateX = 0;
        kevinLeftLegRotateX = 0;
        kevinRotateZ += 4;
        if (kevinRotateZ >= 80)
        {
            kevinRotateZ = 80;
        }
    }
    else if (count > 1260 && count < 1360)
    {
        kevinRightHandRotateX -= 5;
        if (kevinRightHandRotateX <= 0)
        {
            kevinRightHandRotateX = 0;
        }
    }
    else if (count > 1360 && count < 1460)
    {
        kevinRightHandRotateX += 5;
        if (kevinRightHandRotateX >= 90)
        {
            kevinRightHandRotateX = 90;
        }
    }
    else if (count > 1690 && count < 1790)
    {
        kevinRightHandRotateX -= 5;
        if (kevinRightHandRotateX <= 0)
        {
            kevinRightHandRotateX = 0;
        }
    }
    else if (count > 1790 && count < 1890)
    {
        kevinRightHandRotateZ += 5;
        if (kevinRightHandRotateZ >= 90)
        {
            kevinRightHandRotateZ = 90;
        }
    }
    else if (count > 2405 && count < 2590)
    {
        kevinMoveX += 1;
    }
    else if (count > 2640 && count < 2760)
    {
        kevinRotateX += 3;
        kevinRotateY += 3;
        kevinRotateZ = 3;
        kevinMoveX += 0.01;
        kevinMoveZ -= 0.01;
        kevinMoveY += 0.01;
        kevinScale += 0.001;
    }
    else if (count > 2760 && count < 2960)
    {
        kevinRotateX += 0.3;
        kevinRotateY += 0.3;
        kevinRotateZ += 0.3;
        kevinMoveX += 0.001;
        kevinMoveZ -= 0.001;
        kevinMoveY += 0.001;
        kevinScale += 0.0001;
    }
}

void ballController()
{
    if (count < 10)
    {
        ballMoveX = -10;
        ballMoveY = 0.3;
        ballMoveZ = 0;
    }
    else if (count > 100 & count < 300)
    {
        ballMoveX += 0.08;
        ballRotateZ -= 10;
        ballMoveY = pow(sin(count / 10 + 20), 2);
    }
    else if (count > 700 && count < 750)
    {
        ballMoveX = -2.5;
        ballMoveY = 0.4;
        ballMoveZ = 1;
    }
    else if (count > 750 && count < 920)
    {
        ballMoveZ = -0.3;
        ballMoveX += 0.1;
        if (ballMoveX >= 4.5)
        {
            ballMoveX = 4.5;
        }
    }
    else if (count > 1130 && count < 1190)
    {
        if (ballMoveX <= 5.8)
        {
            ballMoveX += 0.05;
            ballMoveY = 0.4 + sin(projection / 3);
            projection += 0.1;
            ballLastMoveY = ballMoveY;
            ballRotateZ -= 10;
        }
    }
    else if (count > 1190 && count < 1290)
    {
        bobLeftHandRotateX -= 10;
        if (bobLeftHandRotateX <= 0)
        {
            bobLeftHandRotateX = 0;
        }
        if (ballMoveX > 4.5)
        {
            ballMoveX -= 0.05;
            ballMoveY = abs(0.4 + sin(projection / 3));
            projection -= 0.1;
            ballRotateZ += 10;
        }
        else
        {
            ballMoveY = 0.4;
            ballMoveX = 4.5;
            projection = 0;
        }
    }
    else if (count > 1570 && count < 1600)
    {
        if (ballMoveX <= 5.8)
        {
            ballMoveX += 0.1;
            ballMoveY = 0.4 + sin(projection / 3);
            projection += 0.2;
            ballLastMoveY = ballMoveY;
            ballRotateZ -= 10;
        }
    }
    else if (count > 1600 && count < 1690)
    {
        bobLeftHandRotateX -= 10;
        if (bobLeftHandRotateX <= 0)
        {
            bobLeftHandRotateX = 0;
        }
        if (ballMoveX > 4.5)
        {
            ballMoveX -= 0.05;
            ballMoveY = abs(0.4 + sin(projection / 3));
            projection -= 0.2;
            ballRotateZ += 10;
        }
        else
        {
            ballMoveY = 0.4;
            ballMoveX = 4.5;
            projection = 90;
        }
    }
    else if (count > 1990 && count < 2090)
    {
        projection -= 0.07;
        if (projection <= 88)
        {
            projection = 88;
        }
        ballMoveX = -2.5 + 0.5 * sin(projection);
        ballMoveZ = -3 + 0.5 * cos(projection);
    }
    else if (count > 2090 && count < 2290)
    {
        ballMoveZ += 0.1;
        if (ballMoveZ > -1.5)
        {
            ballMoveX = -1.4;
            ballMoveY = 1.1;
            ballMoveZ = -1.5;
        }
    }
    else if (count > 2390 && count < 2490)
    {
        ballMoveX += 1;
        // if (ballMoveX > 5)
        // {
        //     ballMoveX = 5;
        // }
    }
    else if (count > 2640 && count < 2790)
    {
        ballRotateX += 5;
        ballRotateY += 5;
        ballRotateZ += 5;
        ballMoveX += 0.01;
        ballMoveZ -= 0.1;
        ballMoveY += 0.1;
        ballScale += 0.005;
    }
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glLoadIdentity();
    camera();

    // draw sea, beach and sky scene
    glPushMatrix();
    drawBeach();
    glTranslatef(0, 0, -20);
    drawSea();
    drawSky();
    glPopMatrix();

    // draw left scene
    glPushMatrix();
    glTranslatef(-10.0, 0, -10);
    glRotatef(90, 0, 1, 0);
    drawSky();
    glPopMatrix();

    // draw right scene
    glPushMatrix();
    glTranslatef(10.0, 0, -10);
    glRotatef(-90, 0, 1, 0);
    drawSky();
    glPopMatrix();

    // draw star
    glPushMatrix();
    glTranslatef(0, 0, 5);
    drawStar();
    glPopMatrix();

    // draw earth
    glPushMatrix();
    glTranslatef(0, 0, 25);
    glRotatef(130, 0, 1, 0);
    drawEarth();
    glPopMatrix();

    // draw moon
    glPushMatrix();
    glTranslatef(2, 0, 30);
    glScalef(0.3, 0.3, 0.3);
    drawMoon();
    glPopMatrix();

    // drawBob
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslatef(bobMoveX, bobMoveY, bobMoveZ);
    glRotatef(bobRotateX, 1, 0, 0);
    glRotatef(bobRotateY, 0, 1, 0);
    glRotatef(bobRotateZ, 0, 0, 1);
    glScalef(0.25, 0.25, 0.25);
    drawBob();
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

    // drawKevin
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslatef(kevinMoveX, kevinMoveY, kevinMoveZ);
    glRotatef(kevinRotateX, 1, 0, 0);
    glRotatef(kevinRotateY, 0, 1, 0);
    glRotatef(kevinRotateZ, 0, 0, 1);
    glScalef(kevinScale, kevinScale, kevinScale);
    drawKevin();
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

    // draw ball()
    glPushMatrix();
    glTranslatef(ballMoveX, ballMoveY, ballMoveZ);
    glRotatef(ballRotateX, 1, 0, 0);
    glRotatef(ballRotateY, 0, 1, 0);
    glRotatef(ballRotateZ, 0, 0, 1);
    glScalef(ballScale, ballScale, ballScale);
    drawBall();
    glPopMatrix();

    // draw net
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslatef(6, netMoveY, 0);
    glRotatef(90, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    drawNet();
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

    // draw canon
    glPushMatrix();
    glDisable(GL_TEXTURE_2D);
    glTranslatef(-3, canonMoveY, -1);
    glRotatef(180, 0, 1, 0);
    glScalef(0.3, 0.3, 0.3);
    drawCanon();
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

    // glPushMatrix();
    // glTranslatef(0, 0.8, 0);
    // glRotatef(90, 1, 0, 0);
    // glScalef(0.25, 0.25, 0.25);
    // // drawBob();
    // drawKevin();
    // glPopMatrix();

    glPopMatrix();

    kevinController();
    bobController();
    ballController();
    cameraController();
    scriptController();
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // set the viewport to the current window specifications
    glMatrixMode(GL_PROJECTION);              // set the matrix to projection
    glLoadIdentity();
    // gluPerspective(60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); // set the perspective (angle of sight, width, height, depth)
    gluPerspective(30.0, 1.0, 0.0001, 1000.0);
    glMatrixMode(GL_MODELVIEW); // set the matrix back to model
}

void keyInput(unsigned char key, int x, int y)
{
    if (key == 'q')
    {
        xrot += 1;
        if (xrot > 360)
            xrot -= 360;
    }

    if (key == 'z')
    {
        xrot -= 1;
        if (xrot < -360)
            xrot += 360;
    }

    if (key == 'w')
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f);
        xpos += float(sin(yrotrad));
        zpos -= float(cos(yrotrad));
        ypos -= float(sin(xrotrad));
    }

    if (key == 's')
    {
        float xrotrad, yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xrotrad = (xrot / 180 * 3.141592654f);
        xpos -= float(sin(yrotrad));
        zpos += float(cos(yrotrad));
        ypos += float(sin(xrotrad));
    }

    if (key == 'd')
    {
        float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xpos += float(cos(yrotrad)) * 0.2;
        zpos += float(sin(yrotrad)) * 0.2;
    }

    if (key == 'a')
    {
        float yrotrad;
        yrotrad = (yrot / 180 * 3.141592654f);
        xpos -= float(cos(yrotrad)) * 0.2;
        zpos -= float(sin(yrotrad)) * 0.2;
    }

    if (key == 27)
    {
        exit(0);
    }
    glutPostRedisplay();
}

void specialKeys(int key, int xx, int yy)
{

    float fraction = 0.1f;

    switch (key)
    {
    case GLUT_KEY_LEFT:
        yrot -= 1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        yrot += 1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        xrot -= 1;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        xrot += 1;
        glutPostRedisplay();
        break;
    }
}

void idle()
{
    DWORD start = GetTickCount();
    while (GetTickCount() - start < 1000 / FPS)
        ;
    count += 2;
    std::cout << count << "\n";

    glutPostRedisplay();
}

void initGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(10.0);
    glLineWidth(5.0);

    // camera setup
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // //	glOrtho(-5, 5, -5, 5, 0.0001, 1000.0);
    // gluPerspective(30.0, 1.0, 0.0001, 1000.0);
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // gluLookAt(0.0, 3.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    // gluLookAt(cameraX, cameraY, cameraZ, lookX, lookY, lookZ, 0.0, 1.0, 0.0);

    // lights
    glEnable(GL_COLOR_MATERIAL); // cheat!!!!

    GLfloat lightAmbient[] = {0.2, 0.2, 0.2, 1.0};  // Ambient light color (adjust as needed)
    GLfloat lightDiffuse[] = {0.3, 0.3, 0.3, 1.0};  // Diffuse light color (adjust as needed)
    GLfloat lightSpecular[] = {0.0, 0.0, 0.0, 1.0}; // Specular light color (adjust as needed)
    GLfloat lightPosition[] = {0.0, 0.0, 1.0, 0.0}; // Light position (adjust as needed)

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Reduce light intensity
    GLfloat lightIntensity = 0.2; // Adjust the value between 0.0 and 1.0

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, lightIntensity);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glShadeModel(GL_SMOOTH);
    // depth buffer
    glEnable(GL_DEPTH_TEST);

    glGenTextures(10, texture);

    // Load external texture.
    loadTextures();

    // Specify how texture values combine with current surface color values.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    // Turn on OpenGL texturing.
    glEnable(GL_TEXTURE_2D);
}

int main(int argc, char **argv)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Main");
    initGL();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyInput);
    glewExperimental = GL_TRUE;
    glewInit();

    glutMainLoop();
}
