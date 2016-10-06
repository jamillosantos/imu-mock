#include <GL/glut.h>
#include <iostream>

#include <cmath>

#include "draw/stage.h"
#include "imuwindow.h"
#include "server/server.h"

#define WIDTH 1024
#define HEIGHT 768

// The time in milliseconds between timer ticks
#define TIMERMSECS 10

ImuWindow imuWindow;

static void reshape(GLsizei w, GLsizei h)
{
	VERBOSE("Reshape ...");
	// Respond to a window resize event

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// glOrtho(-5f, 5f, -5f, 5f, 0.1f, 100.0f);
	gluPerspective(45.0f,(GLfloat)w/(GLfloat)h,0.1f,100.0f);
	gluLookAt(
		0.0f, 0.0f, 2.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void init(int w, int h)
{
	VERBOSE("Initializing ...");
	glClearColor(0.0, 0.0, 0.0, 0.0);

	reshape(w, h);

	imuWindow.init();

	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

static void animate(int value)
{
	glutTimerFunc(TIMERMSECS, animate, 0);
	glutPostRedisplay();
}

static void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	imuWindow.draw();

	glutSwapBuffers();
	glFlush();
}

static void key(unsigned char k, int x, int y)
{
	switch (k) {
		case 27:  /* Escape */
			// glutLeaveMainLoop();
			exit(0);
			// ##### INSERT YOUR OWN KEY HANDLING CODE HERE #####
		case 'c':
			imuWindow.calibrate();
			break;
		case ' ':
			imuWindow.offset();
			break;
		case 'F':
		case 'f':
			glutFullScreen();
			break;
			// ##### INSERT YOUR OWN KEY HANDLING CODE HERE #####
		default:
			return;
	}

	// Force a redraw of the screen in order to update the display
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	server::Server server(8164, imuWindow.imu);

	glutInit(&argc, argv);

	// Set up the GLUT window
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (WIDTH, HEIGHT);
	glutCreateWindow("IMU Visualizer");

	// Set up the callbacks
	init(WIDTH, HEIGHT);

	glutDisplayFunc(render);
	glutKeyboardFunc(key);
	glutReshapeFunc(reshape);
	glutPostRedisplay();

	// Start the timer
	glutTimerFunc(TIMERMSECS, animate, 0);

	// Start receiving
	server.start();

	// Start the main loop
	glutMainLoop();

	return 0;
}
