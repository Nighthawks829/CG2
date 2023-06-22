void drawMoon()
{
    glPushMatrix();
    GLUquadricObj *sphere3 = gluNewQuadric();
    gluQuadricDrawStyle(sphere3, GLU_FILL); // Following three method calls instantiate the texturing style
    gluQuadricTexture(sphere3, GL_TRUE);
    gluQuadricNormals(sphere3, GLU_SMOOTH);
    glBindTexture(GL_TEXTURE_2D, texture[2]); // choose the texture to use.
    gluSphere(sphere3, 1.4, 100, 100);
    glPopMatrix();
}