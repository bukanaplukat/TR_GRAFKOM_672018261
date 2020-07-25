#include<windows.h>
#include<gl/glut.h>
#include<math.h>


void init(void);
void tampil(void);
void mouse(int button, int state, int a, int b);
void myKeyboard(unsigned char key, int w, int o);
void ukuran(int, int);
void timer(int value);
void mouseMotion(int a, int b);

float arot=0.0f;
float brot=0.0f;
float adiff=0.0f;
float bdiff=0.0f;
bool mouseDown=false;
int is_depth;
int k=0; int l=0; int rot;
int a=800, b=600,o=0;
int ok=0, pk=0, c=0, qk=0;

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
    glutInitWindowSize(a,b);
	glutCreateWindow("STADE DE L'AUBE");
	gluOrtho2D(-a/2,a/2,-b/2,b/2);
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(ukuran);
    glutTimerFunc(1000, timer, 0);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void){
    glClearColor(1.0, 1.0, 4.0, 4.0);
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

void lingkaran2(int ag, int bg, int x, int z){
    float o,a,b;
    glColor4ub(k,2,l,6);
    glBegin(GL_POLYGON);
        o=6.28/z;
        for (int k=0; k<z; k++){
            a = ag+x * cos(k*o);
            b = bg+x * sin(k*o);
            glVertex2d(a,b);
        }
    glEnd();
}

void lapangan()
{
    ///lantai
    glPushMatrix ();
    glColor3f (0.50,0.50,0.50);
    glTranslatef (0 , -41.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (15 ,180 , 180);
    glutSolidCube(2);
    glPopMatrix ();

    ///rumput lapangan
    glPushMatrix ();
    glColor3f (0.0,1.0,0.0);
    glTranslatef (0 , -30, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,80 , 60);
    glutSolidCube(2);
    glPopMatrix ();

    ///tanah lapangan
    glPushMatrix ();
    glColor3f (0.7,0.5,0.0);
    glTranslatef (0 , -30, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (7.5 ,90 , 75);
    glutSolidCube(2);
    glPopMatrix ();

    ///kursi penonton bagian depan
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
    glColor3f (0.75,0.75,0.75);
    glTranslatef (0 , 10, 50);
    glRotatef (90, 0, 0, 1);
    glScalef (60 ,115 ,15);
    glutSolidCube(2);
    glPopMatrix ();

    ///kursi penonton pojok depan
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

    ///pintu akses masuk
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , -11, 50);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,10 ,16);
    glutSolidCube(2);
    glPopMatrix ();

    ///garis lapangan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (75 , -22.5, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (1 ,1 , 48.5);
    glutSolidCube(2);
    glPopMatrix ();

    ///bola
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(30,-20,-95);
    glutWireSphere(3,100,10);
    glPopMatrix();

    ///lingkaran tengah lapangan
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(0, -100, 15, 15, 100, 90);
    glPopMatrix();

    //lingkaran depan gawang kanan
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(55, -100, 10, 10, 100, 90);
    glPopMatrix();

    //rumput gawang kanan
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(73.8,-20,-76);
    glVertex3f(55.8,-20,-76);
    glVertex3f(55.8,-20,-119);
    glVertex3f(73.8,-20,-119);
    glEnd();

    //lingkaran depan gawang kiri
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(-55, -100, 10, 10, 100, 90);
    glPopMatrix();

    //rumput gawang kiri
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-73.8,-20,-76);
    glVertex3f(-55.8,-20,-76);
    glVertex3f(-55.8,-20,-119);
    glVertex3f(-73.8,-20,-119);
    glEnd();

    //corner depan kanan
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(71, -55, 4, 4, 100, 90);
    glPopMatrix();

    //corner depan kiri
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(-71, -55, 4, 4, 100, 90);
    glPopMatrix();

    //corner belakang kanan
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(71, -140, 4, 4, 100, 90);
    glPopMatrix();

    //corner belakang kiri
    glPushMatrix();
    glColor3f (4.0,4.0,4.0);
    glTranslatef(0, -21, 0);
    glRotatef(90, 1, 0, 0);
    lingkaran(-71, -140, 4, 4, 100, 90);
    glPopMatrix();

    ///garis lapangan
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

    ///gawang
    //gawang kanan
    glPushMatrix ();
    glColor3f(8.0,4.0,4.0);
    glTranslatef (-70 , -20, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (30, 10, 15);
    glutWireCube(1);
    glPopMatrix ();

    //gawang kiri
    glPushMatrix ();
    glColor3f(8.0,4.0,4.0);
    glTranslatef (70 , -20, -98);
    glRotatef (90, 0, 0, 1);
    glScalef (30, 10, 15);
    glutWireCube(1);
    glPopMatrix ();

    ///cone
    //cone 1 dari kanan
    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(50 , -25, -153);
    glRotatef(90, 0, 0, 1);
    glScalef(7, 7, 7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(50 , -25, -153);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCone(4,1,50,1);
    glPopMatrix();

    //cone 2
    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(40 , -25, -153);
    glRotatef(90, 0, 0, 1);
    glScalef(7, 7, 7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(40 , -25, -153);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCone(4,1,50,1);
    glPopMatrix();

    //cone 3
    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(30 , -25, -153);
    glRotatef(90, 0, 0, 1);
    glScalef(7, 7, 7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(30 , -25, -153);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCone(4,1,50,1);
    glPopMatrix();

    //cone 1 dari kiri
    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(-30 , -25, -153);
    glRotatef(90, 0, 0, 1);
    glScalef(7, 7, 7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(-30 , -25, -153);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCone(4,1,50,1);
    glPopMatrix();

    //cone 2
    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(-40 , -25, -153);
    glRotatef(90, 0, 0, 1);
    glScalef(7, 7, 7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(-40 , -25, -153);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCone(4,1,50,1);
    glPopMatrix();

    //cone 3
    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(-50 , -25, -153);
    glRotatef(90, 0, 0, 1);
    glScalef(7, 7, 7);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(4.0,0.6,0.0);
    glTranslatef(-50 , -25, -153);
    glRotatef(-90, 1, 0, 0);
    glScalef(1, 1, 10);
    glutSolidCone(4,1,50,1);
    glPopMatrix();


    ///tiang bendera
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

    ///kursi penonton bagian belakang
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
    glTranslatef (0 , -12.5, -231);
    glRotatef (90, 0, 0, 1);
    glScalef (25 ,90 ,7);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (0 , -9.5, -244.9);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,90 ,7);
    glutSolidCube(2);
    glPopMatrix ();

    ///lampu
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

    ///pager sponsor
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

    ///pager kursi penonton
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

    ///lantai 2
    //lantai atas kanan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (152 , 22, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,15,85);
    glutSolidCube(2);
    glPopMatrix ();

    //pager kursi kanan atas
    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (135 , 28, -85);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,2 , 100);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi kanan atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (142 , 30, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,5 , 85);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (149 , 33, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,5 , 85);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (160.5 , 37, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,7 , 85);
    glutSolidCube(2);
    glPopMatrix ();

     //lantai atas kiri
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-152 , 22, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,15,85);
    glutSolidCube(2);
    glPopMatrix ();

    //pager kursi kiri atas
    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (-135 , 28, -85);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,2 , 100);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi kiri atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-142 , 30, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,5 , 85);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-149 , 33, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,5 , 85);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (-160 , 37, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,7 , 85);
    glutSolidCube(2);
    glPopMatrix ();

    //lantai atas belakang
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 22, -234.6);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 90.8, 17.2);
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
    glTranslatef (0 , 30, -222);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,90 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 33, -232);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,90 , 7);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 37, -244.5);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,90 , 7);
    glutSolidCube(2);
    glPopMatrix ();

    //lantai atas depan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 22, 24);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 100, 17);
    glutSolidCube(2);
    glPopMatrix ();

    //pager kursi depan atas
    glPushMatrix ();
    glColor3f (2.0,2.0,2.0);
    glTranslatef (0 , 28, 5);
    glRotatef (90, 0, 0, 1);
    glScalef (10 ,140 , 2);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi depan atas
    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 28, 12);
    glRotatef (90, 0, 0, 1);
    glScalef (5 ,120 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 32, 20);
    glRotatef (90, 0, 0, 1);
    glScalef (8 ,120 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.7,0.5,2.0);
    glTranslatef (0 , 36, 30);
    glRotatef (90, 0, 0, 1);
    glScalef (12 ,120 , 5);
    glutSolidCube(2);
    glPopMatrix ();

    //lantai atas pojok kanan depan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (132 , 22, 20);
    glRotatef (45, 0, 1, 0);
    glScalef (35 ,3 ,8);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi pojok kanan depan
    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (135 , 32, 12);
    glRotatef (60, 0, 1, 0);
    glScalef (28 ,8 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (140 , 36, 12);
    glRotatef (60, 0, 1, 0);
    glScalef (40 ,12 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    //lantai atas pojok kiri depan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-132 , 22, 20);
    glRotatef (130, 0, 1, 0);
    glScalef (35 ,3 ,8);
    glutSolidCube(2);
    glPopMatrix ();

    //kursi pojok kiri depan
    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-135 , 32, 12);
    glRotatef (130, 0, 1, 0);
    glScalef (30 ,8 ,5);
    glutSolidCube(2);
    glPopMatrix ();

    glPushMatrix ();
    glColor3f (0.0,0.8,1.0);
    glTranslatef (-140 , 36, 20);
    glRotatef (130, 0, 1, 0);
    glScalef (35 ,12 ,5);
    glutSolidCube(2);
    glPopMatrix ();


    ///dinding & atap
    //dinding belakang
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-91,-50,-252);
    glVertex3f(-91,73.5,-252);
    glVertex3f(90,73.5,-252);
    glVertex3f(90,-50,-252);
    glEnd();

    //dinding kiri
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-167.5,74,6);
    glVertex3f(-167.5,-30,6);
    glVertex3f(-168,-30,-188);
    glVertex3f(-168,74,-188);
    glEnd();

    //dinding pojok kiri
    glPushMatrix ();
    glColor3f (0.75,0.75,0.75);
    glTranslatef (-136.5 , 22, 30);
    glRotatef (135, 0, 1, 0);
    glScalef (39 ,48 ,8);
    glutSolidCube(2);
    glPopMatrix ();

    //dinding kanan
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(168,74,4.5);
    glVertex3f(168,-30,4.5);
    glVertex3f(168,-30,-189.5);
    glVertex3f(168,74,-189.5);
    glEnd();

    //dinding pojok kanan
    glPushMatrix ();
    glColor3f (0.75,0.75,0.75);
    glTranslatef (136.5 , 22, 30);
    glRotatef (50, 0, 1, 0);
    glScalef (39 ,48 ,8);
    glutSolidCube(2);
    glPopMatrix ();


    //atap belakang
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 72, -220);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 92, 30);
    glutSolidCube(2);
    glPopMatrix ();

    //atap kiri
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-140 , 72, -82);
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,38,110);
    glutSolidCube(2);
    glPopMatrix ();

    //atap pojok kiri
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (-123.5 , 72, 25);
    glRotatef (150, 0, 1, 0);
    glScalef (45 ,3 ,30);
    glutSolidCube(2);
    glPopMatrix ();

    //atap kanan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (140 , 72, -82);
    glRotatef (90, 0, 0, 1);
    glScalef (3 ,38,110);
    glutSolidCube(2);
    glPopMatrix ();

    //atap pojok kanan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (123.5 , 72, 25);
    glRotatef (30, 0, 1, 0);
    glScalef (45 ,3 ,30);
    glutSolidCube(2);
    glPopMatrix ();

    //atap depan
    glPushMatrix ();
    glColor3f (1.0,1.0,1.0);
    glTranslatef (0 , 72, 39.5);
    glRotatef (90, 0, 0, 1);
    glScalef (3, 100, 34);
    glutSolidCube(2);
    glPopMatrix ();

    ///kursi
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
    glTranslatef (-158 , -9, -100);
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
    glTranslatef (157 , -9.5, -100);
    glRotatef (90, 0, 0, 1);
    glScalef (28 ,10 , 75.5);
    glutSolidCube(2);
}

void tampil()
{
    glClearColor (0.2f, 0.8f, 0.8f, 0.1f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(arot, 1, 0, 0);
    glRotatef(brot, 0, 1, 0);
    glTranslatef(0,0,-100);
    glRotatef(c,ok,pk,qk);
    glTranslatef(0,0,o);

    glPushMatrix();
    glRotatef(rot*-2, -1.0f, 6.0f, -9.0f);
    lingkaran2(-200,250,15,15);
    k+=20;
    l+=1;
    glPopMatrix();
    glEnd();

    glPushMatrix();
    lapangan();
    glPopMatrix();
    glutSwapBuffers();
}

void timer(int value){
       rot+=30;
       glutPostRedisplay();
       glutTimerFunc(1000, timer, 0);
}

void myKeyboard(unsigned char key, int w, int o){

    if (key == 'w'){
    pk=1;ok=0;qk=0;c+=-10;
    }
    else if (key == 'o'){
    pk=0;ok=0;qk=1;c+=-10;
    }
    else if (key == '1'){
    pk=0;ok=1;qk=0;c+=-10;
    }
    else if (key == '2'){
    pk=0;ok=1;qk=0;c+=10;
    }
    else if (key == '3'){
    pk=0;ok=0;qk=1;c+=10;
    }
    else if (key == '4'){
    pk=1;ok=0;qk=1;c+=10;
    }
    else if (key == '5'){
    pk=-1;ok=1;qk=0;c+=10;  //x,y,z,c.jarak putar
    }
    else if (key == '6'){
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
    tampil();
    }
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
    gluPerspective(60, lebar / tinggi, 5, 1000);
    glTranslatef(0, -80, -450);
    glMatrixMode(GL_MODELVIEW);
}
