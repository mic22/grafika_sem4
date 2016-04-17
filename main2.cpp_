#include <GL/freeglut.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

GLfloat alpha = 1.0f;

int main(int argc, char** argv)
{
	void render(void);
	void cursor(int, int, int);
	srand((unsigned) time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Okno renderowania OpenGL");
	glutDisplayFunc(render);
	glutSpecialFunc(cursor);
	glutIdleFunc(render);

	glutMainLoop();
	
	return 0;
}

void render(void)
{
	GLfloat x, y, z, size[2];
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor4f(1.0f, 1.0f, 0.0f, alpha);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	
	glGetFloatv(GL_POINT_SIZE_RANGE, size);
	glPointSize((size[1] - size[0])/4);
	for(x = -1.0; x <=1.0; x+=0.05)
	{
		y = 0.5f * sin (2.0* M_PI * x); z=0.0f ;
		glBegin(GL_POINTS);
		glVertex3f(x, y, z);
		glEnd();
	}
	
	glFlush();
}

void cursor(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_LEFT: if(alpha > 0.1) { alpha -= 0.1f; } break ;
		case GLUT_KEY_RIGHT: if(alpha < 1.0) { alpha += 0.1f; } break ;
	}
}