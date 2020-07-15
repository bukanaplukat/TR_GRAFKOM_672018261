#include<windows.h>
#include<gl/glut.h>


void init(void);
void tampil(void);
void mouse(int button, int state, int a, int b);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int a, int b);

float arot=0.0f;
float brot=0.0f;
float adiff=0.0f;
float bdiff=0.0f;
bool mouseDown=false;
int is_depth;

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("Agista Nindy Yuliarina-672018171");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void lapangan()
{
    //rumput lapangan
    glPushMatrix ();
    glColor3f (0.0,1.0,0.0);
    glTranslatef (0 , -30, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,80 , 60);
    glutSolidCube(2);
    glPopMatrix ();

    //tanah lapangan
    glPushMatrix ();
    glColor3f (0.7,0.5,0.0);
    glTranslatef (0 , -30, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (7.5 ,90 , 75);
    glutSolidCube(2);
    glPopMatrix ();

    //pager
    //pager sponsor
    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -20, -40);
    glRotatef (90, 0, 0, 1);
    glScalef (4 ,70 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -20, -150);
    glRotatef (90, 0, 0, 1);
    glScalef (4 ,70 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-80 , -20, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (4 ,1 , 45);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (80 , -20, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (4 ,1 , 45);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi penonton
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-120 , -23, -80);
    glRotatef (100, 1, 1, 1);
    glScalef (5 ,1 , 85);
    glutSolidCube(1.5);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-120 , -25, -140);
    glRotatef (110, 1, 1, 1);
    glScalef (5 ,1 , 85);
    glutSolidCube(1.5);
    glPopMatrix ();

    //kursi kiri bag kanan
    glPushMatrix ();
    glColor3f (0.7,0.5,1.0);
    glTranslatef (-95 , -27.5, -50);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,5 , 25);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-105 , -24, -51);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,5 , 26);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,1.0);
    glTranslatef (-115 , -21, -52.5);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,5 , 28);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-125 , -18, -54.5);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,5 , 30);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-135 , -15, -56.5);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,5 , 32);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-145 , -12, -58.5);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,5 , 34);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-155 , -9, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,7 , 75.5);
    glutSolidCube(2);

    //kursi belakang
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (80 , -20, -130);
    glRotatef (90, 0, 0, 1);
    glScalef (4 ,1 , 45);
    glutSolidCube(2);
    glPopMatrix ();

}

void tampil()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(arot, 1, 0, 0);
    glRotatef(brot, 0, 1, 0);

    glPushMatrix();
    lapangan();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int a, int b)
{
    switch(key)
    {
        case '5':
            if(is_depth)
            {
                is_depth=0;
                glDisable(GL_DEPTH_TEST);
            }
            else
            {
                is_depth=1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    tampil();
}

void idle(){
    if(!mouseDown){
        arot += 0.3f;
        brot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int a, int b){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        adiff = a - brot;
        bdiff = -b + arot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int a, int b){
    if(mouseDown){
        brot = a - adiff;
        arot = b + bdiff;

        glutPostRedisplay();
    }
}


void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, lebar / tinggi, 25, 800);
    glTranslatef(0, -5, -250);
    glMatrixMode(GL_MODELVIEW);
}
