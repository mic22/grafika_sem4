#include <GL/freeglut.h>
#include <stdio.h>

GLfloat s =60.0f;

int main ( int argc , char ** argv )
{
	void render ( void );
	void reshape ( int , int );
	void keyboard ( int , int , int );
	glutInit ( & argc , argv );
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
	glutInitWindowPosition ( 100 ,100 );
	glutInitWindowSize ( 800 ,600 );
	glutCreateWindow ( " Okno renderowania OpenGL " );
	glutSpecialFunc ( keyboard );
	glutReshapeFunc ( reshape );
	glutDisplayFunc ( render );
	glutIdleFunc ( render );
	glutMainLoop ();
	return 0;
}

/*
void render ( void )
{
	GLfloat material []={1.0f ,1.0f ,1.0f ,1.0f };
	GLfloat ambient []={0.0f ,0.1f ,0.2f ,0.0f} ,
	diffuse []={0.6f ,0.6f ,0.7f ,1.0f },
	position []={0.0f ,0.0f ,10.0f ,1.0f } ;
	glEnable ( GL_DEPTH_TEST );
	glClearColor ( 0.0f ,0.2f ,0.3f ,1.0f );
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable ( GL_LIGHTING ); glEnable ( GL_LIGHT4 );
	glLightModeli ( GL_LIGHT_MODEL_TWO_SIDE , GL_FALSE );
	glLightModelfv ( GL_LIGHT_MODEL_AMBIENT , ambient );
	glLightfv ( GL_LIGHT4 , GL_DIFFUSE , diffuse );
	glLightfv ( GL_LIGHT4 , GL_POSITION , position );
	glMaterialfv ( GL_FRONT , GL_AMBIENT_AND_DIFFUSE , material );
	glPushMatrix ();
	glLoadIdentity ();
	glutSolidSphere ( 0.5 ,35 ,35 );
	glPopMatrix ();
	glFlush ();
	glutSwapBuffers ();

}
*/

/*
void render ( void )
{
	GLfloat material []={1.0f ,1.0f ,1.0f ,1.0f };
	GLfloat ambient []={0.0f ,0.1f ,0.2f ,0.0f} ,
	diffuse []={0.6f ,0.6f ,0.7f ,1.0f },
	position []={1.0f ,0.0f ,0.0f ,1.0f} ;
	glEnable ( GL_DEPTH_TEST );
	glClearColor ( 0.0f ,0.2f ,0.3f ,1.0f );
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable ( GL_LIGHTING ); glEnable ( GL_LIGHT4 );
	glLightModeli ( GL_LIGHT_MODEL_TWO_SIDE , GL_FALSE );
	glLightModelfv ( GL_LIGHT_MODEL_AMBIENT , ambient );
	glLightfv ( GL_LIGHT4 , GL_DIFFUSE , diffuse );
	glLightfv ( GL_LIGHT4 , GL_POSITION , position );
	glMaterialfv ( GL_FRONT , GL_AMBIENT_AND_DIFFUSE , material );
	glPushMatrix ();
	glTranslatef ( -0.6f ,0.0f ,0.0f ); glutSolidSphere ( 0.25 ,35 ,35 );
	glLoadIdentity ();
	glTranslatef ( 0.6f ,0.0f ,0.0f ); glutSolidSphere ( 0.25 ,35 ,35 );
	glPopMatrix ();
	glFlush ();
	glutSwapBuffers ();
}
*/

/*
void render ( void )
{
		GLfloat material []={1.0f ,1.0f ,1.0f ,1.0f };
		GLfloat ambient []={0.0f ,0.0f ,0.4f ,1.0f} ,
		diffuse []={1.0f ,0.0f ,0.0f ,1.0f },
		specular []={1.0f ,1.0f ,0.0f ,1.0f} ,
		position []={1.0f ,1.0f ,1.0f ,1.0f };
		glEnable ( GL_DEPTH_TEST );
		glClearColor ( 0.3f ,0.3f ,0.3f ,1.0f );
		glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glEnable ( GL_LIGHTING ); glEnable ( GL_LIGHT3 );
		glLightModeli ( GL_LIGHT_MODEL_TWO_SIDE , GL_FALSE );
		glMaterialfv ( GL_FRONT , GL_AMBIENT , material );
		glMaterialfv ( GL_FRONT , GL_DIFFUSE , material );
		glMaterialfv ( GL_FRONT , GL_SPECULAR , material );
		glMaterialf ( GL_FRONT , GL_SHININESS ,s );
		glLightModelfv ( GL_LIGHT_MODEL_AMBIENT , ambient );
		glLightfv ( GL_LIGHT3 , GL_DIFFUSE , diffuse );
		glLightfv ( GL_LIGHT3 , GL_SPECULAR , specular );
		glLightfv ( GL_LIGHT3 , GL_POSITION , position );
		glutSolidSphere ( 0.25 ,50 ,50 );
		glFlush ();
	glutSwapBuffers ();
}
*/
void render ( void )
{
	GLfloat material []={1.0f ,1.0f ,1.0f ,1.0f };
	GLfloat diffuse []={1.0f ,0.0f ,0.0f ,1.0f} , position []={1.0f ,0.0f ,1.0f ,1.0f};
	GLfloat fog []={0.0f ,0.0f ,0.7f ,1.0f };
	glEnable ( GL_DEPTH_TEST ); glClearColor ( 0.0f ,0.0f ,0.2f ,1.0f );
	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glEnable ( GL_LIGHTING ); glEnable ( GL_LIGHT3 );
	glLightModeli ( GL_LIGHT_MODEL_TWO_SIDE , GL_FALSE );
	glMaterialfv ( GL_FRONT , GL_DIFFUSE , material );
	glLightfv ( GL_LIGHT3 , GL_DIFFUSE , diffuse );
	glLightfv ( GL_LIGHT3 , GL_POSITION , position );
	glFogi ( GL_FOG_MODE , GL_EXP );
	glFogfv ( GL_FOG_COLOR , fog );
	glFogf ( GL_FOG_DENSITY ,1.0f );
	glEnable ( GL_FOG );
	glPushMatrix (); glLoadIdentity ();
	glutSolidSphere ( 0.5 ,30 ,30 );
	glTranslatef ( 0.6f ,0.0f ,0.6f ); glutSolidSphere ( 0.3f ,30 ,30 );
	glPopMatrix ();
	glFlush ();
	glutSwapBuffers ();
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

/*
void keyboard ( int key , int x , int y )
{
	switch ( key )
	{
		case GLUT_KEY_HOME :
			glLoadIdentity (); break ;
		case GLUT_KEY_LEFT :
			glRotatef ( -5.0f ,0.0f ,1.0f ,0.0f); break ;
		case GLUT_KEY_RIGHT :
			glRotatef ( 5.0f ,0.0f ,1.0f ,0.0f); break ;
		case GLUT_KEY_UP :
			glRotatef ( -5.0f ,1.0f ,0.0f ,0.0f); break ;
		case GLUT_KEY_DOWN :
			glRotatef ( 5.0f ,1.0f ,0.0f ,0.0f); break ;
		case GLUT_KEY_END :
			exit (0); break ;
	}
	return ;
}
*/

void keyboard ( int key , int x , int y )
{
	switch ( key )
	{
		case GLUT_KEY_UP : if ( s <120.0f ){ s += 10.0f; } break ;
		case GLUT_KEY_DOWN : if ( s >10.0f ){ s -= 10.0f ;} break ;
		case GLUT_KEY_END : exit (0); break ;
	}
	return ;
}