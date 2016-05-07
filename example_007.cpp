#include <GL/freeglut.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

GLfloat x=0.0f, y=0.0f, z=0.0f;

int main(int argc, char** argv)
{
	void render(void);
	srand((unsigned) time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Okno renderowania OpenGL");
	glutDisplayFunc(render);

	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutMainLoop();
	
	return 0;
}

void render(void)
{
	GLfloat x, y, z, range[2], step, size, t;
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.2f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.8f, 0.8f, 1.0f);
	glGetFloatv(GL_POINT_SIZE_RANGE, range);
	glGetFloatv(GL_POINT_SIZE_GRANULARITY, &step);
	
	for(size = range[0], t = 0.0f; size < range [1]; size += step, t +=0.1f )
	{
		x = 0.75f * cos(t); z = 0.75f * sin(t); y = 0.2f * t - 0.75f;
		glPointSize(size);
		glBegin(GL_POINTS);
		glVertex3f(x, y, z);
		glEnd();
		glFlush();
	}
}