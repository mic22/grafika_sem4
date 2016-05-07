#include <GL/freeglut.h>

int main(int argc, char ** argv)
{
	void render(void);
	void reshape(int, int);
	glutInit(& argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Animacja idle");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutReshapeFunc(reshape);
	glutIdleFunc(render);
	glutDisplayFunc(render);
	glutMainLoop();

	return 0;
}

void render(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.1f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(0.05f, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
		glLoadIdentity();
		glColor3f(1.0f, 0.8f, 0.0f);
		glutSolidSphere(0.35, 25, 25);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0f, 0.4f, 0.7f);
		glTranslatef(0.8f, 0.0f, 0.0f);
		glRotatef(75.0f, 1.0f, 0.0f, 0.0f);
		glutWireSphere(0.15, 25, 25);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	GLdouble xo=-1.0f, x1=1.0f, yo=-1.0f, y1=1.0f, zo=-1.0f, z1=1.0f;
	GLdouble q=(GLdouble)w/h;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(w <= h)
	{
		glOrtho(xo, x1, yo/q, y1/q, zo, z1);
	}
	else
	{
		glOrtho(xo*q, x1*q, yo, y1, zo, z1);
	}

	glMatrixMode(GL_MODELVIEW);
}
