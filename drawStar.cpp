void drawStar()
{
    glBindTexture(GL_TEXTURE_2D, texture[6]);
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-10, -10, 30);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(10, -10, 30);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(10, 10, 30);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-10, 10, 30);
    glEnd();
}