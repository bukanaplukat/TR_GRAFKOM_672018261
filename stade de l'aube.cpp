#include<windows.h>
#include<gl/glut.h>
#include<math.h>


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
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("STADE DE L'AUBE");
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
    glLineWidth(3.0);
    glMatrixMode(GL_MODELVIEW);
}


void lingkaran( float titik_x, float titik_y,
                float lebar_x, float lebar_y, float jml_sudut, float rotasi) {
    GLfloat derajat = (360/ jml_sudut) * M_PI / 180;
    glBegin(GL_LINE_STRIP);
        GLfloat sudut = 0.0 - rotasi;
        for (int _k = 0; _k < jml_sudut; ++_k)
        {
            glVertex2f(titik_x + (lebar_x * cos(sudut)), titik_y + (lebar_y * sin(sudut)));
            sudut += derajat;
        }
    glEnd();
}

void lapangan()
{
    //lantai
    glPushMatrix ();
    glColor3f (0.50,0.50,0.50);
    glTranslatef (0 , -41.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (15 ,180 , 180);
    glutSolidCube(2);
    glPopMatrix ();

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

    //kursi penonton bagian depan
    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (50 , -27.5, -20);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (50 , -24.5, -10);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (50 , -21.5, 0);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (50 , -18.5, 10);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (50 , -15.5, 20);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (50 , -12.5, 30);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-50 , -27.5, -20);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-50 , -24.5, -10);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-50 , -21.5, 0);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-50 , -18.5, 10);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-50 , -15.5, 20);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-50 , -12.5, 30);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,40 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , 10, 50);
    glRotatef (90, 0, 0, 1);
    glScalef (60 ,160 ,15);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi penonton bagian depan pojok kanan
    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (95 , -27.5, -20);
    glRotatef (60, 0, 1, 0);
    glScalef (10 ,10 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (95 , -24.5, -7);
    glRotatef (60, 0, 1, 0);
    glScalef (20 ,15 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (105 , -21.5, -3);
    glRotatef (60, 0, 1, 0);
    glScalef (30 ,20 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (110 , -18.5, 10);
    glRotatef (60, 0, 1, 0);
    glScalef (40 ,25 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (120 , -15.5, 13);
    glRotatef (60, 0, 1, 0);
    glScalef (44 ,30 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (135 , -13.5, 10);
    glRotatef (60, 0, 1, 0);
    glScalef (48 ,35 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi penonton bagian depan pojok kiri
    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-95 , -27.5, -20);
    glRotatef (120, 0, 1, 0);
    glScalef (10 ,10 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-95 , -24.5, -7);
    glRotatef (120, 0, 1, 0);
    glScalef (20 ,15 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-105 , -21.5, -3);
    glRotatef (120, 0, 1, 0);
    glScalef (30 ,20 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-110 , -18.5, 10);
    glRotatef (120, 0, 1, 0);
    glScalef (40 ,25 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-120 , -15.5, 13);
    glRotatef (120, 0, 1, 0);
    glScalef (44 ,30 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-135 , -13.5, 10);
    glRotatef (120, 0, 1, 0);
    glScalef (48 ,35 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    //pintu akses masuk
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , -11, 50);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,10 ,16);
    glutSolidCube(2);
    glPopMatrix ();

    //garis lapangan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (75 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 48.5);
    glutSolidCube(2);
    glPopMatrix ();

    //bola
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(50,-20,-95);
    glutWireSphere(3,100,10);
    glPopMatrix();

    //lingkaran
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(0, -100, 9, 12, 100, 90);
    glPopMatrix();


    //garis kecil gawang
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-55 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 21);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-65 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 8.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (65 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 8.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (55 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 21);
    glutSolidCube(2);
    glPopMatrix ();

    //garis gawang
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 47);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-75 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 47);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , -22.5, -145);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,76 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , -22.5, -50);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,76 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    //garis kecil gawang
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-64 , -22.5, -120);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,10 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-64 , -22.5, -76);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,10 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-70 , -22.5, -90);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,5 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-70 , -22.5, -105);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,5 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (64 , -22.5, -120);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,10 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (64 , -22.5, -76);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,10 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (70 , -22.5, -90);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,5 , 1);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (70 , -22.5, -105);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,5 , 1);
    glutSolidCube(2);
    glPopMatrix ();


    //gawang kanan
    glPushMatrix ();
    glColor3f(8.0,4.0,4.0);
    glTranslatef (-70 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (30, 10, 15);
    glutWireCube(1);
    glPopMatrix ();

    //gawang kiri
    glPushMatrix ();
    glColor3f(8.0,4.0,4.0);
    glTranslatef (70 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (30, 10, 15);
    glutWireCube(1);
    glPopMatrix ();

    //cone
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(65 , -25, -60);
    glRotatef(90, 0, 0, 1);
    glScalef(7, 7, 7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(65 , -25, -60);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCone(4,1,50,1);
    glPopMatrix();

    //tiang bendera  belakang kanan
    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(75 , -22.5, -150);
    glRotatef(90, 1, 0, 0);
    glScalef(1 ,1 , 15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(75 , -16, -150);
    glRotatef(45, 0, 0, 1);
    glScalef(1, 1, 10);
    glutSolidCone(1,0.5,4,1);
    glPopMatrix();

    //tiang bendera depan kanan
    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(75 , -22.5, -45);
    glRotatef(90, 1, 0, 0);
    glScalef(1 ,1 , 15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(75 , -16, -45);
    glRotatef(45, 0, 0, 1);
    glScalef(1, 1, 10);
    glutSolidCone(1,0.5,4,1);
    glPopMatrix();

    //tiang bendera belakang kiri
    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(-75 , -22.5, -150);
    glRotatef(90, 1, 0, 0);
    glScalef(1 ,1 , 15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(-75 , -16, -150);
    glRotatef(45, 0, 0, 1);
    glScalef(1, 1, 10);
    glutSolidCone(1,0.5,4,1);
    glPopMatrix();

    //tiang bendera depan kiri
    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(-75 , -22.5, -45);
    glRotatef(90, 1, 0, 0);
    glScalef(1 ,1 , 15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,4.0,3.0);
    glTranslatef(-75 , -16, -45);
    glRotatef(45, 0, 0, 1);
    glScalef(1, 1, 10);
    glutSolidCone(1,0.5,4,1);
    glPopMatrix();

    //kursi penonton bagian belakang
    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -27.5, -180);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -24.5, -190);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -21.5, -200);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -18.5, -210);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -15.5, -220);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -12.5, -230);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -9.5, -240);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    //lampu kanan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (110 , 35, -220);
    glRotatef (90, 1, 0, 0);
    glScalef (2 ,2 , 60);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (110 , 100, -220);
    glRotatef (30, 0, 1, 1);
    glScalef (2 ,10 , 15);
    glutSolidCube(2);
    glPopMatrix();

    //lampu kiri
    glPushMatrix();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-110 , 35, -220);
    glRotatef (90, 1, 0, 0);
    glScalef (2 ,2 , 60);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-110 , 100, -220);
    glRotatef (150, 0, 1, 1);
    glScalef (2 ,10 , 15);
    glutSolidCube(2);
    glPopMatrix();

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
    glTranslatef (0 , -20, -160);
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

    //pager kursi penonton bagian belakang
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-1,-10,-170);
    glRotatef(90,0,0,1);
    glScalef(1.5,88,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-1,-2,-170);
    glRotatef(90,0,0,1);
    glScalef(1.5,88,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(3.5,10,-173);
    glRotatef(90,0,0,1);
    glScalef(1.5,87,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-1,-18,-170);
    glRotatef(90,0,0,1);
    glScalef(1.5,88,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-87,-15,-170);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-84,5,-170);
    glRotatef(70,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-50,-15,-170);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-47,5,-170);
    glRotatef(70,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-5,-15,-170);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-2,5,-170);
    glRotatef(70,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(40,-15,-170);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(43,5,-170);
    glRotatef(70,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(85,-15,-170);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(87,5,-170);
    glRotatef(70,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    //pager kursi penonton bagian depan kiri
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-50,-10,-25);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-50,-2,-25);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-53,10,-24);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-50,-18,-25);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-50,-15,-25);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-52,5,-25);
    glRotatef(110,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-10,-15,-25);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-12.5,5,-25);
    glRotatef(110,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    //pager kursi penonton bagian depan kiri
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(50,-10,-25);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(50,-2,-25);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(53,10,-24);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(50,-18,-25);
    glRotatef(90,0,0,1);
    glScalef(1.5,40,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(50,-15,-25);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(52,5,-25);
    glRotatef(70,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(10,-15,-25);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(12.5,5,-25);
    glRotatef(70,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    //pager kursi penonton bagian kanan
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(90,-10,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(90,-2,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(95,10,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(90,-18,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(88,-15,-165);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(92,5,-165);
    glRotatef(60,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(88,-15,-130);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(92,5,-130);
    glRotatef(60,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(88,-15,-90);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(92,5,-90);
    glRotatef(60,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(88,-15,-50);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(92,5,-50);
    glRotatef(60,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(88,-15,-25);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(92,5,-25);
    glRotatef(65,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    //pager kursi penonton bagian kiri
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-90,-10,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-90,-2,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-95,10,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-90,-18,-94);
    glRotatef(90,1,0,0);
    glScalef(1.5,70,1);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-88,-15,-165);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-92,5,-165);
    glRotatef(125,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-88,-15,-130);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-92,5,-130);
    glRotatef(125,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-88,-15,-90);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-92,5,-90);
    glRotatef(125,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-88,-15,-50);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-92,5,-50);
    glRotatef(125,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-88,-15,-25);
    glRotatef(90,0,0,1);
    glScalef(10,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(-92,5,-25);
    glRotatef(125,0,0,1);
    glScalef(6,1,0.6);
    glutSolidCube(3);
    glPopMatrix();

    //lantai 2
    glPushMatrix (); //kanan atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (150 , 22, -100); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,15,85);
    glutSolidCube(2);
    glPopMatrix ();

    //pager kursi kanan atas
    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (135 , 28, -90);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,2 , 95);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi kanan atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (140 , 28, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (147 , 32, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (155 , 36, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (135 , 28, -90);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,2 , 95);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi kiri atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-140 , 28, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-147 , 32, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-155 , 36, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //kiri atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-150 , 22, -100); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,15,85);
    glutSolidCube(2);
    glPopMatrix ();

    //pager kursi kiri atas
    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (-135 , 28, -90);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,2 , 95);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi kiri atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-140 , 28, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-147 , 32, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-155 , 36, -70);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,5 , 115);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //belakang atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 22, -230);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 90, 15);
    glutSolidCube(2);
    glPopMatrix ();

    //pager kursi belakang atas
    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (0 , 28, -215);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,90 , 2);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi belakang atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 28, -220);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,90 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 32, -228);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,90 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 36, -235);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,90 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //belakang atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 22, -230);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 90, 15);
    glutSolidCube(2);
    glPopMatrix ();

    //pager kursi depan atas
    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (0 , 28, 5);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,135 , 2);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi depan atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 28, 10);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,140 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 32, 20);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,140 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 36, 30);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,160 , 5);
    glutSolidCube(2);
    glPopMatrix ();


    //atap
    glPushMatrix (); //kanan dinding
    glColor3f (1.0,1.0,1.0);
    glTranslatef (165 , 22, -60); //x,y,z
    glRotatef (90, 0, 0, 5);
    glScalef (50 ,5,125);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //kiri atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (138 , 72, -60); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,30,125);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //kiri dinding
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-165 , 22, -60); //x,y,z
    glRotatef (90, 0, 0, 5);
    glScalef (50 ,5,125);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //kiri atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-138 , 72, -60); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,30,125);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //belakang dinding
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 10, -245);
    glRotatef (90, 0, 0, 1);
    glScalef (60,90 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //belakang atap
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 72, -220);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 90, 30);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //depan atap
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 72, 35);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 120, 30);
    glutSolidCube(2);
    glPopMatrix ();


    //kursi penonton bagian kiri
    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (-95 , -27.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (-105 , -24, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (-115 , -21, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (-125 , -18, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (-135 , -15, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (-145 , -12, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (-155 , -9, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,8 , 75.5);
    glutSolidCube(2);

    //kursi penonton bagian kanan
    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (105 , -24.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (105 , -24.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (95 , -27.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (115 , -21.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (125 , -18.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (135 , -15.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (145 , -12.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (4.0,0.6,0.0);
    glTranslatef (155 , -9.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,10 , 75.5);
    glutSolidCube(2);
}

void tampil()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    lapangan();
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int a, int b)
{
    switch(key)
    {
    case 'w' :
    case 'W' :
        glTranslated(0.0, 0.0, 3.0);
        break;
    case 'd' :
    case 'D' :
        glTranslated(3.0, 0.0, 0.0);
        break;
    case 's' :
    case 'S' :
        glTranslated(0.0, 0.0, -3.0);
        break;
    case 'a' :
    case 'A' :
        glTranslated(-3.0, 0.0, 0.0);
        break;
    case '1' :
        glTranslated(0.0, 3.0, 0.0);
        break;
    case '2' :
        glTranslated(0.0, -3.0, 0.0);
        break;
    case '3' :
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '4' :
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6' :
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '7' :
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '8' :
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '9' :
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5' :
        if (is_depth)
        {

            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
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
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(arot, 1, 0, 0);
    glRotatef(brot, 0, 1, 0);
}


void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, lebar / tinggi, 5, 500);
    glTranslatef(0, -40, -350);
    glMatrixMode(GL_MODELVIEW);
}
