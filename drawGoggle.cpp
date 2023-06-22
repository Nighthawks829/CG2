void drawGoogle(float radius, float height, int numSlices)
{
    glBegin(GL_TRIANGLE_STRIP);
    for (int i = 0; i <= numSlices; ++i)
    {
        float theta = 2.0 * PI * static_cast<float>(i) / numSlices;
        float x = radius * std::cos(theta);
        float y = radius * std::sin(theta);

        float normalX = std::cos(theta);
        float normalY = std::sin(theta);
        float normalZ = 0.0;

        glNormal3f(normalX, normalY, normalZ);
        glVertex3f(x, y, -height / 2.0);
        glVertex3f(x, y, height / 2.0);
    }
    glEnd();
}