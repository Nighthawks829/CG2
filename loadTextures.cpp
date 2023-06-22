void loadTextures()
{
    // Local storage for image data.
    imageFile *image[10];

    // Load the image.

    image[0] = getBMP("Textures/ball.bmp");
    image[1] = getBMP("Textures/earth.bmp");
    image[2] = getBMP("Textures/moon.bmp");
    image[3] = getBMP("Textures/sand.bmp");
    image[4] = getBMP("Textures/sea.bmp");
    image[5] = getBMP("Textures/sky.bmp");
    image[6] = getBMP("Textures/star.bmp");

    // Create texture object texture[0].
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Create texture object texture[1].
    glBindTexture(GL_TEXTURE_2D, texture[1]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[1]->width, image[1]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[1]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Create texture object texture[2].
    glBindTexture(GL_TEXTURE_2D, texture[2]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[2]->width, image[2]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[2]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Create texture object texture[3].
    glBindTexture(GL_TEXTURE_2D, texture[3]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[3]->width, image[3]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[3]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Create texture object texture[4].
    glBindTexture(GL_TEXTURE_2D, texture[4]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[4]->width, image[4]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[4]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Create texture object texture[5].
    glBindTexture(GL_TEXTURE_2D, texture[5]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[5]->width, image[5]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[5]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Create texture object texture[6].
    glBindTexture(GL_TEXTURE_2D, texture[6]);

    // Specify image data for currently active texture object.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[6]->width, image[6]->height, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, image[6]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}