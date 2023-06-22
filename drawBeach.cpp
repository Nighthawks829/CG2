void drawBeach()
{
    glBindTexture(GL_TEXTURE_2D, texture[3]);
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glTexCoord2f(0.0, 0.0);
    glVertex3f(-20, 0, -10);
    glTexCoord2f(1.0, 0.0);
    glVertex3f(20, 0, -10);
    glTexCoord2f(1.0, 1.0);
    glVertex3f(20, 0, 10);
    glTexCoord2f(0.0, 1.0);
    glVertex3f(-20, 0, 10);
    glEnd();
}
