void drawEarth()
{
    glPushMatrix();
    GLUquadricObj *sphere2 = gluNewQuadric();
    gluQuadricDrawStyle(sphere2, GLU_FILL); // Following three method calls instantiate the texturing style
    gluQuadricTexture(sphere2, GL_TRUE);
    gluQuadricNormals(sphere2, GLU_SMOOTH);
    glBindTexture(GL_TEXTURE_2D, texture[1]); // choose the texture to use.
    gluSphere(sphere2, 1.4, 100, 100);
    glPopMatrix();
}