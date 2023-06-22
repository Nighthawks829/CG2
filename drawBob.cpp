void drawBob()
{

    // draw head and body
    glPushMatrix();

    glColor3ub(255, 255, 0.0);
    drawSemisphere(1.2, 32, 32);
    glTranslatef(0.0, 0, 0.5);
    drawCylinder(1.2, 1.0, 32);
    glPopMatrix();

    // draw left google
    glPushMatrix();

    glTranslatef(-0.35, 1.2, 0.0);
    glRotatef(90, 1, 0, 0);
    glScaled(0.5, 0.5, 0.5);
    glColor3ub(255, 255, 255);
    drawGoogle(0.7, 0.8, 32);
    glPopMatrix();

    // // draw right google
    glPushMatrix();
    glTranslatef(0.35, 1.2, 0.0);
    glRotatef(90, 1, 0, 0);
    glScaled(0.5, 0.5, 0.5);
    glColor3ub(255, 255, 255);
    drawGoogle(0.7, 0.8, 32);
    glPopMatrix();

    // draw left eye white
    glPushMatrix();

    glColor3ub(255, 255, 255);
    glTranslatef(-0.35, 1.1, 0.0);
    glScalef(0.6, 0.6, 0.6);
    drawSphere(0.5, 32, 32);
    glPopMatrix();

    // // draw left eye black
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(-0.35, 1.4, 0.0);
    glScalef(0.25, 0.25, 0.25);
    drawSphere(0.5, 32, 32);
    glPopMatrix();

    // draw right eye white
    glPushMatrix();

    glColor3ub(255, 255, 255);
    glTranslatef(0.35, 1.1, 0.0);
    glScalef(0.6, 0.6, 0.6);
    drawSphere(0.5, 32, 32);
    glPopMatrix();

    // draw right eye black
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0.35, 1.4, 0.0);
    glScalef(0.25, 0.25, 0.25);
    drawSphere(0.5, 32, 32);
    glPopMatrix();

    // draw hair
    glPushMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0.0, 0, -1.4);
    glScalef(0.1, 0.1, 0.1);
    drawCylinder(1, 4, 32);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glRotatef(20, 0, 1, 0);
    glTranslatef(0.0, 0, -1.2);
    glScalef(0.1, 0.1, 0.1);
    drawCylinder(1, 5, 32);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glRotatef(-20, 0, 1, 0);
    glTranslatef(0.0, 0, -1.2);
    glScalef(0.1, 0.1, 0.1);
    drawCylinder(1, 5, 32);
    glPopMatrix();

    glPopMatrix(); // End draw hair

    // draw bottom body
    glPushMatrix();
    glColor3ub(80, 135, 177);
    glTranslatef(0.0, 0.0, 1.3);
    drawCylinder(1.2, 0.6, 256);
    glColor3ub(80, 135, 177);
    glTranslatef(0.0, 0.0, 0.3);
    glRotatef(180, 1.0, 0.0, 0.0);
    drawSemisphere(1.2, 256, 256);
    glPopMatrix();

    // left hand anchor point
    glPushMatrix();
    glTranslatef(-1.2, 0, 1);
    glRotatef(bobLeftHandRotateX, 1, 0, 0);
    glRotatef(bobLeftHandRotateY, 0, 1, 0);
    glRotatef(bobLeftHandRotateZ, 0, 0, 1);
    glTranslatef(1.0, 0, -1);

    // draw lef arm
    glPushMatrix();
    
    glColor3ub(255, 255, 0.0);
    glTranslatef(-1.2, 0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(0.1, 0.1, 0.1);
    drawCylinder(1, 7, 32);
    glPopMatrix();

    // draw left palm
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(-1.845, 0, 1);

    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    drawSphere(1, 32, 32);
    glPopMatrix();
    glPopMatrix();

    // draw left finger
    glPushMatrix();
    glColor3ub(0, 0, 0);
    // glRotatef(50,0,1,0);
    glTranslatef(-1.85, 0.0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(0.05, 0.05, 0.12);
    // glScalef(0.05,0.05,0.05);
    drawCylinder(1, 5, 32);
    glPopMatrix();

    // draw left second finger
    glPushMatrix();

    glColor3ub(0, 0, 0);
    glTranslatef(-2, 0, 1.0);
    glRotatef(90, 0, 1, 0);

    glPushMatrix();
    glTranslatef(0, 0, 0.15);
    glRotatef(35, 0, 1, 0);
    glTranslatef(0, 0, -0.15);
    drawCylinder(0.05, 0.3, 32);
    glPopMatrix();

    glPopMatrix();

    // Third left finger
    glPushMatrix();

    glColor3ub(0, 0, 0);
    glTranslatef(-2, 0, 1.0);
    glRotatef(90, 0, 1, 0);

    glPushMatrix();
    glTranslatef(0, 0, 0.15);
    glRotatef(-35, 0, 1, 0);
    glTranslatef(0, 0, -0.15);
    drawCylinder(0.05, 0.3, 32);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    // right hand anchor point
    glPushMatrix();
    glTranslatef(1.2, 0, 1);
    glRotatef(bobRightHandRotateX, 1, 0, 0);
    glRotatef(bobRightHandRotateY, 0, 1, 0);
    glRotatef(bobRightHandRotateZ, 0, 0, 1);
    glTranslatef(-1.0, 0, -1);

    // draw right arm
    glPushMatrix();
    glColor3ub(255, 255, 0.0);
    glTranslatef(1.2, 0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(0.1, 0.1, 0.1);
    drawCylinder(1, 7, 32);
    glPopMatrix();

    // draw right palm
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(1.845, 0, 1);

    glPushMatrix();
    glScalef(0.2, 0.2, 0.2);
    drawSphere(1, 32, 32);
    glPopMatrix();
    glPopMatrix();

    // draw right finger
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(1.85, 0.0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(0.05, 0.05, 0.12);
    drawCylinder(1, 5, 32);
    glPopMatrix();

    // draw right second finger
    glPushMatrix();

    glColor3ub(0, 0, 0);
    glTranslatef(2, 0, 1.0);
    glRotatef(90, 0, 1, 0);

    glPushMatrix();
    glTranslatef(0, 0, -0.15);
    glRotatef(35, 0, 1, 0);
    glTranslatef(0, 0, 0.15);
    drawCylinder(0.05, 0.3, 32);
    glPopMatrix();

    glPopMatrix();

    // draw right third finger
    glPushMatrix();

    glColor3ub(0, 0, 0);
    glTranslatef(2, 0, 1.0);
    glRotatef(90, 0, 1, 0);

    glPushMatrix();
    glTranslatef(0, 0, -0.15);
    glRotatef(-35, 0, 1, 0);
    glTranslatef(0, 0, 0.15);
    drawCylinder(0.05, 0.3, 32);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    // left roatet anchor point
    glPushMatrix();
    glTranslatef(-0.4, 0.0, 2.5);
    glRotatef(bobLeftLegRotateX, 1, 0, 0);
    glRotatef(bobLeftLegRotateY, 0, 1, 0);
    glRotatef(bobLeftLegRotateZ, 0, 0, 1);
    glTranslatef(0.4, 0.0, -2.5);
    // draw left leg
    glPushMatrix();
    glColor3ub(80, 135, 177);
    glTranslatef(-0.4, 0.0, 2.7);
    drawCylinder(0.2, 0.5, 32);
    glPopMatrix();

    // draw left foot
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(-0.6, -0.15, 3.2);
    drawBox(0.4, 0.4, 0.3);
    glPopMatrix();

    // draw left feet
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(-0.4, 0.25, 3.2);
    glRotatef(90, 0, 1, 0);
    glClipPlane(GL_CLIP_PLANE0, eqn);
    glEnable(GL_CLIP_PLANE0);
    glClipPlane(GL_CLIP_PLANE1, eqn2);
    glEnable(GL_CLIP_PLANE1);
    drawCylinder(0.2, 0.4, 32);
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glPopMatrix();

    // Left rotate anchor point end
    glPopMatrix();

    // Right leg rotate anchor point
    glPushMatrix();
    glTranslatef(0.4, 0.0, 2.5);
    glRotatef(bobRightLegRotateX, 1, 0, 0);
    glRotatef(bobRightLegRotateY, 0, 1, 0);
    glRotatef(bobRightLegRotateZ, 0, 0, 1);
    glTranslatef(-0.4, 0.0, -2.5);

    // draw right leg
    glPushMatrix();
    glColor3ub(80, 135, 177);
    glTranslatef(0.4, 0.0, 2.7);
    drawCylinder(0.2, 0.5, 32);
    glPopMatrix();

    // draw right foot
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0.2, -0.15, 3.2);
    drawBox(0.4, 0.4, 0.3);
    glPopMatrix();

    // draw right feet
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0.4, 0.25, 3.2);
    glRotatef(90, 0, 1, 0);
    glClipPlane(GL_CLIP_PLANE0, eqn);
    glEnable(GL_CLIP_PLANE0);
    glClipPlane(GL_CLIP_PLANE1, eqn2);
    glEnable(GL_CLIP_PLANE1);
    drawCylinder(0.2, 0.4, 32);
    glDisable(GL_CLIP_PLANE0);
    glDisable(GL_CLIP_PLANE1);
    glPopMatrix();

    glPopMatrix();
}