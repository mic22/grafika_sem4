#include <GL/freeglut.h>

int main ( int argc , char ** argv )
{
	void render ( void );
	void reshape ( int , int );
	void keyboard ( unsigned char , int , int );
	glutInit ( & argc , argv );
	glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGBA );
	glutInitWindowPosition ( 100 ,100 );
	glutInitWindowSize ( 500 ,300 );
	glutCreateWindow ( " Okno renderowania OpenGL " );
	glutKeyboardFunc ( keyboard );
	glutReshapeFunc ( reshape );
	glutDisplayFunc ( render );
	glutSetCursor ( GLUT_CURSOR_NONE );

	glutMainLoop ();
	return 0;
}

void render ( void )
{
	glClearColor ( 1.0f ,1.0f ,1.0f ,1.0f);
	glClear ( GL_COLOR_BUFFER_BIT );
	glColor3f ( 0.0f ,0.0f ,0.0f);
	glutWireTeapot ( 0.75 );
	glFlush ();
}

void keyboard ( unsigned char key , int x , int y )
	{
		switch ( key )
		{
			case 27: exit ( 0 ); break ;
		}
	return;
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
