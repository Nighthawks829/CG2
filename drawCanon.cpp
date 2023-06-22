void drawCanon()
{
    // draw tayar
    glPushMatrix();
    glColor3ub(133, 81, 40);
    drawCylinder(1.5, 1, 32);
    glPopMatrix();

    // draw tayar
    glPushMatrix();
    glColor3ub(133, 81, 40);
    glTranslatef(0, 0, 3);
    drawCylinder(1.5, 1, 32);
    glPopMatrix();

    // draw bomb
    glPushMatrix();

    glTranslatef(0, 0, 1.5);
    glRotatef(-20, 0, 0, 1);

    glPushMatrix();
    glColor3ub(77, 77, 77);
    glTranslatef(-1.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    drawCylinder(1, 8, 32);
    glPopMatrix();

    glPopMatrix();
}