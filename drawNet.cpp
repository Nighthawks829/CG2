void drawNet()
{
        // draw left stick
    glPushMatrix();
    glTranslatef(-2, 0, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(23, 23, 23);
    drawCylinder(0.1, 5, 32);
    glPopMatrix();

    // draw right stick
    glPushMatrix();
    glTranslatef(2, 0, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(23, 23, 23);
    drawCylinder(0.1, 5, 32);
    glPopMatrix();

    // draw net row
    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glRotatef(90, 0, 1, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 4, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glRotatef(90, 0, 1, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 4, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glRotatef(90, 0, 1, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 4, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(90, 0, 1, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 4, 32);
    glPopMatrix();

    // draw net stright
    glPushMatrix();
    glTranslatef(0, 1.2, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 1.5, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.5, 1.2, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 1.5, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1, 1.2, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 1.5, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5, 1.2, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 1.5, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.5, 1.2, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 1.5, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1, 1.2, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 1.5, 32);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5, 1.2, 0);
    glRotatef(90, 1, 0, 0);
    glColor3ub(200, 200, 200);
    drawCylinder(0.05, 1.5, 32);
    glPopMatrix();

}