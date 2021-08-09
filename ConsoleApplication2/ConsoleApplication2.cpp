#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define SPEED 30.0

float i = 0.0, m = 0.0, n = 0.0, o = 0.0, c = 0.0;

int light = 1, day = 1, plane = 0, comet = 0, xm = 900, train = 0;
char ch;


void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}

void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d = 1 - r, x = 0, y = r;
	while (y > x)
	{
		plotpixels(h, k, x, y);
		if (d < 0) d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}

void train_station()
{
	int l;
	if (day == 1)
	{
		//sky
		glColor3f(0.0, 0.9, 0.9);
		glBegin(GL_POLYGON);
		glVertex2f(0, 380);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 380);
		glEnd();

		//sun


		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 0.9, 0.0);
			draw_circle(100, 625, l);
		}



		//cloud1


		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(160 + m, 625, l);

		}


		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(200 + m, 625, l);
			draw_circle(225 + m, 625, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(265 + m, 625, l);
		}

		//cloud2


		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(370 + m, 615, l);
		}

		for (l = 0; l <= 35; l++)
		{

			glColor3f(1.0, 1.0, 1.0);
			draw_circle(410 + m, 615, l);
			draw_circle(435 + m, 615, l);
			draw_circle(470 + m, 615, l);
		}

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(500 + m, 615, l);
		}


		//grass
		glColor3f(0.0, 0.9, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 160);
		glVertex2f(0, 380);
		glVertex2f(1100, 380);
		glVertex2f(1100, 160);
		glEnd();

	}


	else
	{

		//sky
		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 380);
		glVertex2f(0, 700);
		glVertex2f(1100, 700);
		glVertex2f(1100, 380);
		glEnd();

		//moon
		int l;

		for (l = 0; l <= 35; l++)
		{
			glColor3f(1.0, 1.0, 1.0);
			draw_circle(100, 625, l);
		}		


		//comet
		if (comet == 1)
		{
			for (l = 0; l <= 7; l++)
			{
				glColor3f(1.0, 1.0, 1.0);
				draw_circle(300 + c, 675, l);
			}

			glColor3f(1.0, 1.0, 1.0);
			glBegin(GL_TRIANGLES);
			glVertex2f(200 + c, 675);
			glVertex2f(300 + c, 682);
			glVertex2f(300 + c, 668);
			glEnd();
		}

	

		//grass
		glColor3f(0.0, 0.3, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0, 160);
		glVertex2f(0, 380);
		glVertex2f(1100, 380);
		glVertex2f(1100, 160);
		glEnd();

	}

	//platform

	glColor3f(0.560784, 0.560784, 0.737255);
	glBegin(GL_POLYGON);
	glVertex2f(0, 160);
	glVertex2f(0, 250);
	glVertex2f(1100, 250);
	glVertex2f(1100, 160);
	glEnd();

	//table 1

	glColor3f(1.0, 0.498039, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(140, 190);
	glVertex2f(140, 210);
	glVertex2f(155, 210);
	glVertex2f(155, 190);
	glEnd();

	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex2f(130, 210);
	glVertex2f(130, 215);
	glVertex2f(225, 215);
	glVertex2f(225, 210);
	glEnd();

	glColor3f(1.0, 0.498039, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(200, 190);
	glVertex2f(200, 210);
	glVertex2f(215, 210);
	glVertex2f(215, 190);
	glEnd();

	//below track 
	glColor3f(0.623529, 0.623529, 0.372549);
	glBegin(GL_POLYGON);
	glVertex2f(0, 0);
	glVertex2f(0, 150);
	glVertex2f(1100, 150);
	glVertex2f(1100, 0);
	glEnd();
	
	//tree 1
	glColor3f(0.9, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(50, 185);
	glVertex2f(50, 255);
	glVertex2f(65, 255);
	glVertex2f(65, 185);
	glEnd();


	for (l = 0; l <= 30; l++)
	{
		glColor3f(0.31, 0.78, 0.47);
		draw_circle(40, 250, l);
		draw_circle(80, 250, l);
	}

	for (l = 0; l <= 25; l++)
	{
		glColor3f(0.31, 0.78, 0.47);
		draw_circle(50, 290, l);
		draw_circle(70, 290, l);
	}

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.31, 0.78, 0.47);
		draw_circle(60, 315, l);
	}

	//tree 2
	glColor3f(0.9, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(300, 185);
	glVertex2f(300, 255);
	glVertex2f(315, 255);
	glVertex2f(315, 185);
	glEnd();


	for (l = 0; l <= 30; l++)
	{
		glColor3f(0.31, 0.78, 0.47);
		draw_circle(290, 250, l);
		draw_circle(330, 250, l);
	}

	for (l = 0; l <= 25; l++)
	{
		glColor3f(0.31, 0.78, 0.47);
		draw_circle(300, 290, l);
		draw_circle(320, 290, l);
	}

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.31, 0.78, 0.47);
		draw_circle(310, 315, l);
	}

	//railway station 
	glColor3f(0.647, 0.164, 0.164);
	glBegin(GL_POLYGON);
	glVertex2f(400, 250);
	glVertex2f(400, 450);
	glVertex2f(950, 450);
	glVertex2f(950, 250);
	glEnd();

	//roof
	glColor3f(0.556863, 0.419608, 0.137255);
	glBegin(GL_POLYGON);
	glVertex2f(350, 450);
	glVertex2f(450, 500);
	glVertex2f(900, 500);
	glVertex2f(1000, 450);
	glEnd();
	



	//window 1
	glColor3f(0.196, 0.6, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(450, 300);
	glVertex2f(450, 375);
	glVertex2f(550, 375);
	glVertex2f(550, 300);
	glEnd();

	


	//window 2
	glColor3f(0.196, 0.6, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(800, 300);
	glVertex2f(800, 375);
	glVertex2f(900, 375);
	glVertex2f(900, 300);
	glEnd();



	//door
	glColor3f(0.329412, 0.329412, 0.329412);
	glBegin(GL_POLYGON);
	glVertex2f(625, 250);
	glVertex2f(625, 375);
	glVertex2f(725, 375);
	glVertex2f(725, 250);
	glEnd();


	//signal
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1060, 160);
	glVertex2f(1060, 350);
	glVertex2f(1070, 350);
	glVertex2f(1070, 160);
	glEnd();


	glColor3f(0.7, 0.7, 0.7);
	glBegin(GL_POLYGON);
	glVertex2f(1040, 350);
	glVertex2f(1040, 500);
	glVertex2f(1090, 500);
	glVertex2f(1090, 350);
	glEnd();

	for (l = 0; l <= 20; l++)
	{
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(1065, 475, l);
		glColor3f(1.0, 1.0, 0.0);
		draw_circle(1065, 425, l);
		glColor3f(0.0, 0.0, 0.0);
		draw_circle(1065, 375, l);
	}
	if (train == 1)
	{
		
		// train carrier 1


		glColor3f(0.26, 0.43, 0.26);
		glBegin(GL_POLYGON);
		glVertex2f(300 + i - xm, 50);
		glVertex2f(300 + i - xm, 300);
		glVertex2f(-100 + i - xm, 300);
		glVertex2f(-100 + i - xm, 50);
		glEnd();


		// carrier 1 Wheels

		for (l = 0; l < 50; l++)
		{
			glColor3f(0.35, 0.16, 0.14);
			draw_circle(-25 + i - xm, 50, l);
			draw_circle(225 + i - xm, 50, l);
		}

		//train base

		glColor3f(0.196078, 0.6, 0.8);
		glBegin(GL_POLYGON);
		glVertex2f(350 + i - xm, 50);
		glVertex2f(350 + i - xm, 125);
		glVertex2f(800 + i - xm, 125);
		glVertex2f(800 + i - xm, 50);
		glEnd();

		//train control chamber

		glColor3f(0.26, 0.43, 0.26);
		glBegin(GL_POLYGON);
		glVertex2f(360 + i - xm, 125);
		glVertex2f(360 + i - xm, 325);
		glVertex2f(560 + i - xm, 325);
		glVertex2f(560 + i - xm, 125);
		glEnd();

		

		//train engine
		glColor3f(0, 0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(560 + i - xm, 125);
		glVertex2f(560 + i - xm, 225);
		glVertex2f(755 + i - xm, 225);
		glVertex2f(755 + i - xm, 125);
		glEnd();

		//train smoke

		glColor3f(0.196078, 0.6, 0.9);
		glBegin(GL_POLYGON);
		glVertex2f(650 + i - xm, 225);
		glVertex2f(650 + i - xm, 275);
		glVertex2f(700 + i - xm, 275);
		glVertex2f(700 + i - xm, 225);
		glEnd();

		

		//train head-light

		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex2f(755 + i - xm, 225);
		glVertex2f(765 + i - xm, 225);
		glVertex2f(765 + i - xm, 185);
		glVertex2f(755 + i - xm, 185);
		glEnd();


		// train connector

		glColor3f(0.309804, 0.184314, 0.184314);
		glBegin(GL_POLYGON);
		glVertex2f(350 + i - xm, 75);
		glVertex2f(350 + i - xm, 95);
		glVertex2f(300 + i - xm, 95);
		glVertex2f(300 + i - xm, 75);
		glEnd();

		//train wheels

		for (l = 0; l < 50; l++)
		{
			glColor3f(0.35, 0.16, 0.14);
			draw_circle(425 + i - xm, 50, l);
			draw_circle(700 + i - xm, 50, l);
		}
	}
	glFlush();
}

void traffic_light()
{
	int l;
	if (light == 1)
	{
		for (l = 0; l <= 20; l++)
		{

			glColor3f(0.0, 0.0, 0.0);
			draw_circle(1065, 475, l);

			glColor3f(0.0, 0.7, 0.0);
			draw_circle(1065, 375, l);
		}
	}

	else
	{

		for (l = 0; l <= 20; l++)
		{
			glColor3f(1.0, 0.0, 0.0);
			draw_circle(1065, 475, l);

			glColor3f(0.0, 0.0, 0.0);
			draw_circle(1065, 375, l);
		}
	}
}

void idle()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);

	if (light == 0 && (i >= 0 && i <= 1150))
	{

		i += SPEED / 10;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;

	}

	if (light == 0 && (i >= 2600 && i <= 3000))
	{

		i += SPEED / 10;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;

	}

	if (light == 0)
	{
		i = i;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;

	}

	else
	{

		i += SPEED / 10;
		m += SPEED / 150;
		n -= 2;
		o += 0.2;
		c += 2;
	}
	if (i > 3500)
		i = 0.0;
	if (m > 1100)
		m = 0.0;
	if (o > 75)
	{
		plane = 0;
	}
	if (c > 500)
	{
		comet = 0;
	}
	glutPostRedisplay();

}

void mouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
		exit(0);
}

void inp_keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'g':
	case 'G':
		light = 1;
		break;

	case 'r':
	case 'R':
		light = 0;
		break;

	case 'd':
	case 'D':
		day = 1;
		break;

	case 'n':
	case 'N':
		day = 0;
		break;

	case 't':
	case 'T':
		train = 1;
		i = 0;
		break;

	};

}

void main_menu(int index)
{
	switch (index)
	{
	case 1:
		if (index == 1)
		{
			plane = 1;
			o = n = 0.0;
		}
		break;

	case 2:
		if (index == 2)
		{
			comet = 1;
			c = 0.0;
		}
		break;
	}
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1100.0, 0.0, 700.0);
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	train_station();
	traffic_light();
	glFlush();
}

int main(int argc, char** argv)
{
	int c_menu,test_lol;
	printf("   Train Station Simulator    \n\n\n");
	printf("'r' to change the signal light to red. \n\n");
	printf("'g' to change the signal light to green. \n\n");
	printf("'d' for day. \n\n");
	printf("'n' for night time  \n\n");
	printf("'t' for train To start moving\n\n");
	printf("Right Click To show contextual menu \n\n");
	printf("Left Click To end The Program \n\n\n");
	printf("Press any key and Hit ENTER.\n");
	cin >> test_lol;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1100.0, 700.0);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Train Station");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(inp_keyboard);
	glutMouseFunc(mouse);
	myinit();
	//menu operations, aeroplane(rip) and comet
	c_menu = glutCreateMenu(main_menu);
	glutAddMenuEntry("Aeroplane", 1);
	glutAddMenuEntry("Comet", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}

