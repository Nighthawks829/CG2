void drawBall()
{
    glPushMatrix();
    glColor3ub(255, 0, 0);
    GLUquadricObj *sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL); // Following three method calls instantiate the texturing style
    gluQuadricTexture(sphere, GL_TRUE);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    glBindTexture(GL_TEXTURE_2D, texture[0]); // choose the texture to use.
    gluSphere(sphere, 2, 100, 100);
    glPopMatrix();
}