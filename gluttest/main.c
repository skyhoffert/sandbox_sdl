
#include <GL/glut.h>
#include <SOIL/SOIL.h>

GLuint textureID;

void drawTriangle() {
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLES);

    glTexCoord2f(0,1); glVertex2f(1, 1);
    glTexCoord2f(0,0); glVertex2f(-1, -1);
    glTexCoord2f(1,0); glVertex2f(1, -1);

    glTexCoord2f(0,0); glVertex2f(1, 1);
    glTexCoord2f(1,1); glVertex2f(-1, 1);
    glTexCoord2f(0,1); glVertex2f(-1, -1);

    // glTexCoord2f(0,0); glVertex2f(-1, -1);
    // glTexCoord2f(1,0); glVertex2f(1, -1);
    // glTexCoord2f(0,1); glVertex2f(1, 1);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

    // glColor3f(1.0f, 1.0f, 1.0f);

    // Load and bind the texture
    textureID = SOIL_load_OGL_texture("arie.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Enable blending for transparency
    // glEnable(GL_BLEND);
    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    drawTriangle();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Triangle Portion with OpenGL");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
