void drawSemisphere(float radius, int numSlices, int numStacks)
{
    for (int i = 0; i < numStacks / 2; ++i)
    {
        float lat0 = PI * (-0.5 + static_cast<float>(i) / numStacks);
        float lat1 = PI * (-0.5 + static_cast<float>(i + 1) / numStacks);
        float z0 = radius * std::sin(lat0);
        float z1 = radius * std::sin(lat1);
        float r0 = radius * std::cos(lat0);
        float r1 = radius * std::cos(lat1);

        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= numSlices; ++j)
        {
            float lng = 2.0 * PI * static_cast<float>(j) / numSlices;
            float x = std::cos(lng);
            float y = std::sin(lng);

            // Calculate the surface normal
            float normalX = x * r1;
            float normalY = y * r1;
            float normalZ = z1;
            glNormal3f(normalX, normalY, normalZ);

            glVertex3f(x * r0, y * r0, z0);
            glVertex3f(x * r1, y * r1, z1);
        }
        glEnd();
    }
}