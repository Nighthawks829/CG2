void drawSphere(float radius, int numSlices, int numStacks)
{
    for (int i = 0; i < numStacks; ++i)
    {
        float lat0 = PI * (-0.5 + static_cast<float>(i) / numStacks);
        float z0 = radius * std::sin(lat0);
        float zr0 = radius * std::cos(lat0);

        float lat1 = PI * (-0.5 + static_cast<float>(i + 1) / numStacks);
        float z1 = radius * std::sin(lat1);
        float zr1 = radius * std::cos(lat1);

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= numSlices; ++j)
        {
            float lng = 2.0 * PI * static_cast<float>(j) / numSlices;
            float x = std::cos(lng);
            float y = std::sin(lng);

            // Calculate the surface normal
            float normalX = x * zr1;
            float normalY = y * zr1;
            float normalZ = z1;
            glNormal3f(normalX, normalY, normalZ);

            glVertex3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
    }
}