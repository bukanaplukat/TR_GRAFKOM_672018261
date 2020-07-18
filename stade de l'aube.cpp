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
    glMatrixMode(GL_MODELVIEW);
}

void lapangan()
{
    //lantai
    glPushMatrix ();
    glColor3f (0.50,0.50,0.50);
    glTranslatef (0 , -41.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (17.5 ,160 , 180);
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
    glTranslatef (60 , -27.5, -20);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,30 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (58 , -24.5, -10);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,32 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (56 , -21.5, 0);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,34 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (54 , -18.5, 10);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,36 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (52 , -15.5, 20);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,38 ,5);
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
    glTranslatef (-60 , -27.5, -20);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,30 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-58 , -24.5, -10);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,32 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-56 , -21.5, 0);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,34 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-54 , -18.5, 10);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,36 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-52 , -15.5, 20);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,38 ,5);
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
    glTranslatef (0 , -9.5, 40);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,90 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    //pintu akses masuk
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , -11, 40);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,10 ,6);
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

    //lingkaran lapangan
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0,-38,-100);
    glutWireSphere(20,100,50);
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
    glTranslatef (95 , 2, -180);
    glRotatef (90, 1, 0, 0);
    glScalef (2 ,2 , 40);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (95 , 45, -180);
    glRotatef (30, 0, 1, 1);
    glScalef (2 ,10 , 10);
    glutSolidCube(2);
    glPopMatrix();

    //lampu kiri
    glPushMatrix();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-95 , 2, -180);
    glRotatef (90, 1, 0, 0);
    glScalef (2 ,2 , 40);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-95 , 45, -180);
    glRotatef (150, 0, 1, 1);
    glScalef (2 ,10 , 10);
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

    //tiang bendera
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(75 , -22.5, -150);
    glRotatef(90, 1, 0, 0);
    glScalef(1 ,1 , 15);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(75 , -16, -150);
    glRotatef(45, 0, 0, 1);
    glScalef(1, 1, 10);
    glutSolidCone(1,0.5,4,1);
    glPopMatrix();

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


    //atap
    glPushMatrix (); //kanan dinding
    glColor3f (1.0,1.0,1.0);
    glTranslatef (170 , 10, -100); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (50 ,5,75);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //kanan atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (130 , 60, -100); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,45,75);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //kiri dinding
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-170 , 10, -100); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (50 ,5,75);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //kiri atas
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-130 , 60, -100); //x,y,z
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,45,75);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //belakang dinding
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 10, -250);
    glRotatef (90, 0, 0, 1);
    glScalef (50,90 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix (); //belakang atap
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 60, -200);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 90, 30);
    glutSolidCube(2);
    glPopMatrix ();


    //kursi penonton bagian kiri
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-95 , -27.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-105 , -24, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-115 , -21, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-125 , -18, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-135 , -15, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-145 , -12, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-155 , -9, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,8 , 75.5);
    glutSolidCube(2);

    //kursi penonton bagian kanan
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (105 , -24.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (105 , -24.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (13 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (95 , -27.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (115 , -21.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (16 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (125 , -18.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (19 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (135 , -15.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (22 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (145 , -12.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,5 , 75.5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (155 , -9.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,10 , 75.5);
    glutSolidCube(2);





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
    gluPerspective(50, lebar / tinggi, 5, 500);
    glTranslatef(0, -40, -300);
    glMatrixMode(GL_MODELVIEW);
}
