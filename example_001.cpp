#include <GL/freeglut.h>
#include <stdio.h>

GLint color = -1;
GLboolean coords = GL_FALSE;

int main ( int argc , char ** argv )
{
	void render ( void );
	void reshape ( int , int );
	void keyboard ( unsigned char , int , int );
	void mouse ( int button , int state , int x , int y );
	glutInit ( & argc , argv );
	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGBA );
	glutInitWindowPosition ( 100 ,100 );
	glutInitWindowSize ( 800 ,600 );
	glutCreateWindow ( " Okno renderowania OpenGL " );
	glutKeyboardFunc ( keyboard );
	glutMouseFunc ( mouse );
	glutIdleFunc ( render );
	glutReshapeFunc ( reshape );
	glutDisplayFunc ( render );
	glutMainLoop ();

	return 0;
}

void render ( void )
{
	switch ( color )
	{
		case 1: glClearColor(0.8f ,0.1f ,0.1f ,1.0f); break ;
		case 2: glClearColor(0.1f ,0.6f ,0.1f ,1.0f); break ;
		case 3: glClearColor(0.1f ,0.1f ,0.6f ,1.0f); break ;
		default : glClearColor(0.2f ,0.2f ,0.4f ,1.0f);
	}

	if(coords) {
		glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	} else {
		glutSetCursor(GLUT_CURSOR_NONE);
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(-0.50, -0.50, -0.25, -0.25);
	glRectf(-0.25, -0.25, 0.25, 0.25);
	glRectf(0.25, 0.25, 0.50, 0.50);
	glFlush();
}

void keyboard ( unsigned char key , int x , int y )
{
	switch ( key )
	{
		case 'r': color = 1; break ;
		case 'g': color = 2; break ;
		case 'b': color = 3; break ;
		case ' ': color = 0; printf ( " space \n\r " ); break ;
		case 27: exit (0); break ;
	}
}

void mouse ( int button , int state , int x , int y )
{
	if ( state == GLUT_DOWN )
	{
		switch ( button )
		{
			case GLUT_RIGHT_BUTTON : coords = ! coords ; break ;
			case GLUT_LEFT_BUTTON :
				if ( coords ) {
					printf("[%d:%d]\n\r" , x, y);
				}
				break ;
		}
	}
}


void reshape ( int w , int h )
{
	GLdouble xo = -1.0f , x1 =1.0f , yo = -1.0f , y1 =1.0f , zo = -1.0f , z1 =1.0f;
	GLdouble q =( GLdouble )w/h;

	glViewport ( 0 ,0 ,w ,h );
	glMatrixMode ( GL_PROJECTION ); glLoadIdentity ();
	if ( w <= h ) { glOrtho ( xo ,x1 , yo /q , y1 /q ,zo , z1 ); }
	else { glOrtho ( xo *q , x1 *q ,yo ,y1 ,zo , z1 ); }
	glMatrixMode ( GL_MODELVIEW );
}
