#include<GL/glut.h>

void display() {
	glClear(GL_COLOR_BUFFER_BIT); glColor3f(1.0, 0.0,
		0.0); glFlush();
}

void myinit()
{
	glClearColor(0.0, 0.0, 0.0,
		0.0);
	glColor3f(1.0, 0.0, 0.0); glPointSize(5.0);
	glMatrixMode(GL_PROJECTION); gluOrtho2D(0.0, 499.0, 0.0,
		499.0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |
		GLUT_RGB); glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0); glutCreateWindow("Blank Window"); glutDisplayFunc(display);
		myinit(); glutMainLoop();
}