#include <GL/freeglut.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

GLfloat x=0.0f, y=0.0f, z=0.0f;

int main(int argc, char** argv)
{
	void reshape(int, int);
	void ifs(void);
	void clear(void);
	srand((unsigned) time(NULL));
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//przy double musi byc glutSwapBuffers po glFlush!
	
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Okno renderowania OpenGL");
	glutReshapeFunc(reshape);
	glutIdleFunc(ifs);
	glutDisplayFunc(clear);
	glutMainLoop();
	
	return 0;
}

void reshape(int w, int h)
{
	GLdouble xo = -1.0f, x1 = 1.0f, yo = 0.0f, y1 = 2.0f, zo = -1.0f, z1 = 1.0f;
	GLdouble q =(GLdouble)w/h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h) {
		glOrtho(xo, x1, yo/q, y1/q, zo, z1);
	} else {
		glOrtho(xo * q, x1 * q, yo, y1, zo, z1);
	}
	glMatrixMode(GL_MODELVIEW);
}

void clear(void)
{
	glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 1.0f, 0.0f);
	glFlush();
	glutSwapBuffers();
}

void ifs(void)
{
	GLint i;
	GLfloat r[]={0.0500f, 0.0500f, 0.6000f, 0.5000f, 0.5000f, 0.5500f}, 
	s []={0.6000f, -0.5000f, 0.5000f, 0.4500f, 0.5500f, 0.4000f},
	theta []={0.0000f, 0.0000f, 0.6980f, 0.3490f, -0.5240f, -0.6980f},
	phi []={0.0000f, 0.0000f, 0.6980f, 0.3492f, -0.5240f, -0.6980f},
	e []={0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f, 0.0000f },
	f []={0.0000f, 1.0000f, 0.6000f, 1.1000f, 1.0000f, 0.7000f };
	i = rand()%6;
	
	x = r[i] * cos(theta [i]) * x - s[i] * sin(phi [i]) * y + e[i];
	y = r[i] * sin(theta [i]) * x + s[i] * cos(phi [i]) * y +f[i];
	
	glBegin(GL_POINTS);
	glVertex3f(x, y, z);
	glEnd();
	glFlush();
	glutSwapBuffers();
}