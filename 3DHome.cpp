#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

/*keyboard keys for rotating,translation and scaling.*/
#define ROTATE_XPLUS_KEY  'u'
#define ROTATE_XMINUS_KEY  'n'
#define ROTATE_YPLUS_KEY 'k'
#define ROTATE_YMINUS_KEY 'h'
#define ROTATE_ZPLUS_KEY  'o'
#define ROTATE_ZMINUS_KEY  'l'
#define TRANSLATE_YPLUS_KEY  'w'
#define TRANSLATE_YMINUS_KEY 'z'
#define TRANSLATE_XPLUS_KEY  'd'
#define TRANSLATE_XMINUS_KEY 'a'
#define TRANSLATE_ZPLUS_KEY  'r'
#define TRANSLATE_ZMINUS_KEY  'f'
#define SCALE_PLUS  '+'
#define SCALE_MINUS '-'

/*Angles for rotating,translation and scaling.*/
GLfloat angle_rotateX = 0.0f;
GLfloat angle_rotateY = 300.0f;
GLfloat angle_rotateZ = 0.0f;
GLfloat angle_translateX = 0.0f;
GLfloat angle_translateY = 0.0f;
GLfloat angle_translateZ =0.0f;
GLfloat angle_scaleX = 1.0f;
GLfloat angle_scaleY = 1.0f;
GLfloat angle_scaleZ = 1.0f;

/*Camera angle*/
float camera_angle = 0.0f;

/*This function gets keyboard keys and changes angles for rotating,translation and scaling*/
void keyboardKeys(unsigned char key, int x, int y) {

    if(key == ROTATE_XPLUS_KEY){
        angle_rotateX += 1.0;
    }
    else if(key == ROTATE_XMINUS_KEY){
        angle_rotateX -= 1.0;
    }
    else if(key == ROTATE_YPLUS_KEY){
        angle_rotateY += 1.0;
    }
    else if(key == ROTATE_YMINUS_KEY){
        angle_rotateY -= 1.0;
    }
    else if(key == ROTATE_ZPLUS_KEY){
        angle_rotateZ += 1.0;
    }
    else if(key == ROTATE_ZMINUS_KEY){
        angle_rotateZ -= 1.0;
    }
    else if(key == TRANSLATE_XPLUS_KEY){
        angle_translateX += 0.05f;
    }
    else if(key == TRANSLATE_XMINUS_KEY){
        angle_translateX -= 0.05f;
    }
    else if(key == TRANSLATE_YPLUS_KEY){
        angle_translateY += 0.05;
    }
    else if(key == TRANSLATE_YMINUS_KEY){
        angle_translateY -= 0.05;
    }
    else if(key == TRANSLATE_ZPLUS_KEY){
       angle_translateZ += 0.05;
    }
    else if(key == TRANSLATE_ZMINUS_KEY){
       angle_translateZ -= 0.05;
    }
    else if(key == SCALE_PLUS){
        angle_scaleX += 0.05;
        angle_scaleY += 0.05;
        angle_scaleZ += 0.05;
    }
    else if(key == SCALE_MINUS){
        angle_scaleX -= 0.05;
        angle_scaleY -= 0.05;
        angle_scaleZ -= 0.05;
    }
    else if(key == 27){
        exit(0);
    }
    glutPostRedisplay();
}
/*Reshape Window function*/
void reshapeWindow(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, (double) width / (double) height, 1.0, 300.0);
}
/*This function for setting matrix mode,camera angle and other features*/
void setFeatures(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(camera_angle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, -1.5f, -2.0f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    
}
/*Constructing Home*/
void constructHome() {

    setFeatures();
    /*Translation,rotation and scaling operations.*/
    glTranslatef(angle_translateX,angle_translateY,angle_translateZ);
    glRotatef(angle_rotateZ, 0.0f, 0.0f, 1.0f);
    glRotatef(angle_rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(angle_rotateY, 0.0f, 1.0f, 0.0f);
    glScalef(angle_scaleX, angle_scaleY, angle_scaleZ);
  

    /* Right (according to us) rectangle*/  
    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.11, .68);
    glVertex3f (0, 0, 0.0);
    glVertex3f (0.5, 0, 0.0);
    glVertex3f (0.5, 0.5, 0.0);
    glVertex3f (0.0, 0.5, 0.0);
    glEnd();
    
    /* Left (according to us) rectangle*/
    glBegin(GL_POLYGON);
    glColor3f (1.0, 0.11, .68);
    glVertex3f (0, 0, 0.5);
    glVertex3f (0.5, 0.0, 0.5);
    glVertex3f (0.5, 0.5, 0.5);
    glVertex3f (0, 0.5, 0.5);
    glEnd();

    /* Front rectangle */
    glBegin(GL_POLYGON);
    glColor3f (0.73, 0.16, .96);
    glVertex3f (0.5, 0, 0.5);
    glVertex3f (0.5, 0, 0.0);
    glVertex3f (0.5, 0.5, 0.0);
    glVertex3f (0.5, 0.5, 0.5);
    glEnd();

    /* Back rectangle */
    glBegin(GL_POLYGON);
    glColor3f (0.73, 0.16, .96);
    glVertex3f (0, 0, 0.5);
    glVertex3f (0, 0, 0.0);
    glVertex3f (0, 0.5, 0.0);
    glVertex3f (0, 0.5, 0.5);
    glEnd();
 
    /* Bottom rectangle */
    glBegin(GL_POLYGON);
    glColor3f (0.73, 0.16, .96);
    glVertex3f (0, 0, 0.0);
    glVertex3f (0, 0, 0.5);
    glVertex3f (0.5, 0, 0.5);
    glVertex3f (0.5, 0, 0.0);
    glEnd();

    /* Front triangle roof*/
    glBegin(GL_TRIANGLES);
    glColor3f (.55, 0.2, .2);
    glVertex3f (0.5, 0.5, 0.0);
    glVertex3f (0.5, 0.5, 0.5);
    glVertex3f (0.5, 0.8, 0.25);
    glEnd();

    /* Back triangle roof */
    glBegin(GL_TRIANGLES);
    glColor3f (.55, 0.2, .2);
    glVertex3f (0, 0.5, 0.0);
    glVertex3f (0, 0.5, 0.5);
    glVertex3f (0, 0.8, 0.25);
    glEnd();

    /* Right (according to us) roof*/
    glBegin(GL_POLYGON);
    glColor3f (.45, 0.2, .2);
    glVertex3f (0, 0.5, 0.0);
    glVertex3f (0.5, 0.5, 0.0);
    glVertex3f (0.5, 0.8, 0.25);
    glVertex3f (0, 0.8, 0.25);
    glEnd();

    /* Left(according to us) roof*/
    glBegin(GL_POLYGON);
    glColor3f (.45, 0.2, .2);
    glVertex3f (0, 0.5, 0.5);
    glVertex3f (0.5, 0.5, 0.5);
    glVertex3f (0.5, 0.8, 0.25);
    glVertex3f (0, 0.8, 0.25);
    glEnd();

    /* Left(according to us) window*/
    glBegin(GL_POLYGON);
    glColor3f (.15, 0.5, .5);
    glVertex3f (0.51, 0.33, 0.45);
    glVertex3f (0.51, 0.33, 0.32);
    glVertex3f (0.51, 0.48, 0.32);
    glVertex3f (0.51, 0.48, 0.45);
    glEnd();

    /* Right (according to us) window*/
    glBegin(GL_POLYGON);
    glColor3f (.15, 0.5, .5);
    glVertex3f (0.51, 0.33, 0.05);
    glVertex3f (0.51, 0.33, 0.18);
    glVertex3f (0.51, 0.48, 0.18);
    glVertex3f (0.51, 0.48, 0.05);
    glEnd();
    
    
    /* Door */
    glBegin(GL_POLYGON);
    glColor3f (.4, 0.2, .1);
    glVertex3f (0.51, 0, 0.18);
    glVertex3f (0.51, 0, 0.32);
    glVertex3f (0.51, 0.3, 0.32);
    glVertex3f (0.51, 0.3, 0.18);
    glEnd();


    glFlush ();
    glPopMatrix();
    glutSwapBuffers();
    
}
/*Main function*/
int main(int argc, char * * argv) {

    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(20,20);
    glutCreateWindow("3D Home");
    glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
  
    glutDisplayFunc(constructHome);
    glutKeyboardFunc(keyboardKeys);
    glutReshapeFunc(reshapeWindow);

    glutMainLoop();
    return 0;
}
