#include <GL/freeglut.h>
#include <stdio.h>

GLuint fps, msec;

int main(int argc, char ** argv)
{
	void render(void);
	void reshape(int, int);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Aminacja idle + benchmark");
	glutSetCursor(GLUT_CURSOR_NONE);
	glutReshapeFunc(reshape);
	glutIdleFunc(render);
	glutDisplayFunc(render);
	fps = 0;
	msec = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();

	return 0;
}

void render(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.2f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutWireTeapot(0.50);
	glRotatef(0.1f, 1.0f, 0.0f, 0.0f);
	glRotatef(0.2f, 0.0f, 1.0f, 0.0f);
	glRotatef(0.1f, 0.0f, 0.0f, 1.0f);
	glFlush();
	glutSwapBuffers();

	if((glutGet(GLUT_ELAPSED_TIME) - msec) > 1000)
	{
		printf("frames/sec=%d , Mpixel/sec=%d\n", fps, (glutGet(GLUT_WINDOW_WIDTH) * glutGet(GLUT_WINDOW_HEIGHT) * fps ) >> 20);
		msec = glutGet(GLUT_ELAPSED_TIME);
		fps = 0;
	}
	else
	{
		fps++;
	}
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
