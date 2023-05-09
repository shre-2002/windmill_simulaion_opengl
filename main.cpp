#include<GL/glut.h>
#include<string.h>
#include <math.h>
#include<stdio.h>
int flag1=0;
int flag0=0;
int flag2=0;
const double PI = 3.141592654;
int submenu;
int frameNumber = 0;
int win1;
int win3;

void init(){

    gluOrtho2D(0,100,0,100);
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}
void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}


//second page(description page)
void display1(){
	glColor3f(1.0,1.0,1.0);
    char string1[70] = "Project  Description  :  ";
    glRasterPos2f(5,90);
    int i;
    for ( i = 0; i <strlen(string1); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string1[i]);
    }
		glColor3f(1.0,1.0,1.0);
    char string2[100] = "Our project is about windmill simulation using OpenGL. Descriptions are as follows:";
    glRasterPos2f(5,80);
    
    for ( i = 0; i <strlen(string2); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string2[i]);
    }
    
    	glColor3f(1.0,1.0,1.0);
    char string3[150] = "1. Windmills are the machines that converts energy from winds into useful work by rotating.";
    glRasterPos2f(5,70);
  
    for ( i = 0; i <strlen(string3); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string3[i]);
    }
    
    	glColor3f(1.0,1.0,1.0);
    char string4[150] = "2. They are responsible for producing electricity.";
    glRasterPos2f(5,65);
  
    for ( i = 0; i <strlen(string4); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string4[i]);
    }
	
		glColor3f(1.0,1.0,1.0);
    char string5[150] = "3. These come under the category of green energy generated through natural resources.";
    glRasterPos2f(5,60);
  
    for ( i = 0; i <strlen(string5); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string5[i]);
    }
    
    	glColor3f(1.0,1.0,1.0);
    char string6[150] = "4. These are the tall structures with rotaing blades and are installed in the wind parks and require large areas.";
    glRasterPos2f(5,55);
  
    for ( i = 0; i <strlen(string6); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string6[i]);
    }
    
    	glColor3f(1.0,1.0,1.0);
    char string7[150] = "5. Smock mill, tower mill, fan mill,post mill are the four types of windmills.";
    glRasterPos2f(5,50);
  
    for ( i = 0; i <strlen(string7); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string7[i]);
    }
	
		glColor3f(1.0,1.0,1.0);
    char string8[150] = "6. Rotating blades uses aerodynamic force to produce electricity.";
    glRasterPos2f(5,45);
  
    for ( i = 0; i <strlen(string8); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string8[i]);
    }
    
    	glColor3f(1.0,1.0,1.0);
    char string9[150] = "7. Tower, blade, rotor and anemometer are the main components of windmill.";
    glRasterPos2f(5,40);
  
    for ( i = 0; i <strlen(string9); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string9[i]);
    }
    
    	glColor3f(1.0,1.0,1.0);
    char string10[150] = "8. Hence, they are pollution free and renewable source of electricity production.";
    glRasterPos2f(5,35);
  
    for ( i = 0; i <strlen(string10); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string10[i]);
    }
	
	glFlush();
}

void drawDisk(double radius) {
	int d;
	glBegin(GL_POLYGON);
	for (d = 0; d < 32; d++) {
		double angle = 2*PI/32 * d;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}
	glEnd();
}

void drawWheel() {
    int i;
	glColor3f(0,0,0);
	drawDisk(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	drawDisk(0.8);
	glColor3f(0,0,0);
	drawDisk(0.2);
	glRotatef(frameNumber*20,0,0,1);
	glBegin(GL_LINES);
	for (i = 0; i < 15; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/15), sin(i*2*PI/15));
	}
	glEnd();
}
/*void drawCart() {
	glPushMatrix();
	glTranslatef(-1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	drawWheel();
	glPopMatrix();
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-2.5f,0);
	glVertex2f(2.5f,0);
	glVertex2f(2.5f,2);
	glVertex2f(-2.5f,2);
	glEnd();
}*/
void drawSun() {
	int i;
	glColor3f(1,1,0);
	for (i = 0; i < 13; i++) { // Draw 13 rays, with different rotations.
		glRotatef( 360 / 13, 0, 0, 1 ); // Note that the rotations accumulate!
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0.75f, 0);
		glEnd();
	}
	drawDisk(0.5);
	glColor3f(0,0,0);
}
void drawWindmill0() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	if(flag0==0){
		glRotated(frameNumber * (180.0/46), 0, 0, 1);
	}
	if(flag0==-1){
		
	}
	if(flag0==1){
		glRotatef(frameNumber * (180.0/46), 0.0f, 0.0f, -1.0f);
	}
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}



void drawWindmill1() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	if(flag1==0){
		glRotated(frameNumber * (180.0/46), 0, 0, 1);
	}
	if(flag1==-1){
		
	}
	if(flag1==1){
		glRotatef(frameNumber * (180.0/46), 0.0f, 0.0f, -1.0f);
	}
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}

void drawWindmill2() {
	int i;
	glColor3f(0.8f, 0.8f, 0.9f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05f, 0);
	glVertex2f(0.05f, 0);
	glVertex2f(0.05f, 3);
	glVertex2f(-0.05f, 3);
	glEnd();
	glTranslatef(0, 3, 0);
	if(flag2==0){
		glRotated(frameNumber * (180.0/46), 0, 0, 1);
	}
	if(flag2==-1){
		
	}
	if(flag2==1){
		glRotatef(frameNumber * (180.0/46), 0.0f, 0.0f, -1.0f);
	}
	glColor3f(0.4f, 0.4f, 0.8f);
	for (i = 0; i < 3; i++) {
		glRotated(120, 0, 0, 1);  // Note: These rotations accumulate.
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0.5f, 0.1f);
		glVertex2f(1.5f,0);
		glVertex2f(0.5f, -0.1f);
		glEnd();
	}
}



void powerstation()
{
   // glClear(GL_COLOR_BUFFER_BIT);

    // Draw the building
    glColor3f(0.8f, 0.5f, 0.3f); // ochre color
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    // Draw the roof
    glColor3f(0.90f, 0.30f, 0.10f); // light brown color
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.0f, 0.8f);
      glEnd();

    // Draw the door
    //if(flag0!=-1||flag1!=-1||flag2!=-1){
    //	glColor3f(1.0f, 1.0f, 0.0f);
	//}else{
			glColor3f(0.25f, 0.25f, 0.25f);
	//}
 // dark gray color
    glBegin(GL_QUADS);
    glVertex2f(-0.15f, -0.5f);
    glVertex2f(0.15f, -0.5f);
    glVertex2f(0.15f, -0.2f);
    glVertex2f(-0.15f, -0.2f);
    glEnd();

    // Draw the windows
    if(flag0!=-1||flag1!=-1||flag2!=-1){
    	glColor3f(1.0f, 1.0f, 0.0f);
	}
	else{
			glColor3f(0.25f, 0.25f, 0.25f);
	}
     // light blue color
    glBegin(GL_QUADS);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(-0.1f, 0.2f);
    glVertex2f(-0.1f, 0.4f);
    glVertex2f(-0.35f, 0.4f);

    glVertex2f(0.1f, 0.2f);
    glVertex2f(0.35f, 0.2f);
    glVertex2f(0.35f, 0.4f);
    glVertex2f(0.1f, 0.4f);
    glEnd();

    glFlush();
}

void drawPerson(float x,float y) {
    // draw the body
    glColor3f(0.0f, 0.0f, 1.0f); // blue color
    glBegin(GL_QUADS);
    glVertex2f(x-0.1f, y);
    glVertex2f(x+0.1f, y);
    glVertex2f(x+0.1f, y+0.3f);
    glVertex2f(x-0.1f, y+0.3f);
    glEnd();

    // draw the head
    glColor3f(1.0f, 1.0f, 0.0f); // yellow color
    glPushMatrix();
    glTranslatef(x, y+0.4f, 0.0f);
    drawDisk(0.1);
    glPopMatrix();

    // draw the legs
    glColor3f(0.0f, 1.0f, 0.0f); // green color
    glBegin(GL_LINES);
    glVertex2f(x-0.1f, y);
    glVertex2f(x-0.2f, y-0.3f);
    glVertex2f(x+0.1f, y);
    glVertex2f(x+0.2f, y-0.3f);
    glEnd();

    // draw the left arm
    glColor3f(1.0f, 0.0f, 0.0f); // red color
    glBegin(GL_LINES);
    glVertex2f(x-0.1f, y+0.2f);
    glVertex2f(x-0.2f, y+0.1f);
    glEnd();

    // draw the right arm
    glColor3f(1.0f, 0.0f, 0.0f); // red color
    glBegin(GL_LINES);
    glVertex2f(x+0.1f, y+0.2f);
    glVertex2f(x+0.2f, y+0.1f);
    glEnd();
}





	
	





void powerlines2(float x,float y)
{
	if(flag2==1 || flag2==0)
	{
		glColor3f(1,0,0);
		glBegin(GL_LINES);
		glVertex2f(x,y);
		glVertex2f(5.45f, 1.0f);
		glEnd();
	
	}
	}
	void powerlines1(float x,float y){
		if(flag1==1 || flag1==0){
		glBegin(GL_LINES);
		glVertex2f(x,y);
		glVertex2f(5.45f, 1.0f);
		glEnd();
	}
	} void powerlines0(float x,float y){
		if(flag0==1 || flag0==0){
		glBegin(GL_LINES);
		glVertex2f(x,y);
		glVertex2f(5.45f, 1.0f);
		glEnd();	
		}
	}
	
	
	
	
	
/*	void wind2(int x,int y){
	//float x1=x;
//	float y1=y;
	//printf("%.2f\t\t%.2f\n",x1,y1);
	//if(x1>=722.00&&x1<=727.00&&y1>=162.00&&y1<=166.00){
		
			//powerlines2(2.7,3.9);*/
//	}


//}

void mouse(int button,int state,int x,int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN ){
//	flag2=-1;
//printf("hiiiii%d\t\t%d\n",x,y);
if(x>=720&&x<=725&&y>=162&&y<=166){
	flag2=-1;
	//	wind2(x,y);  
}
if(x>=427&&x<=432&&y>=175&&y<=179){
	flag1=-1;
	//	wind2(x,y);  
}
if(x>=141&&x<=149&&y>=175&&y<=180){
	flag0=-1;
	//	wind2(x,y);  
}
//	printf("hiiiii%d\t\t%d\n",x,y);

	}
	
	
	if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN ){
//	flag2=-1;

if(x>=720&&x<=725&&y>=162&&y<=166){
	flag2=0;
	//	printf("hiiiii%d\t\t%d\n",x,y);
	//	wind2(x,y);  
}
if(x>=427&&x<=432&&y>=175&&y<=179){
	flag1=0;
	
}
if(x>=141&&x<=149&&y>=175&&y<=180){
	flag0=0;
	  
}


	}
/*	if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN ){
//	flag2=-1;
	wind2(x,y);  
	}*/
	}

//code of windmill is written here


void display2(){
	glClear(GL_COLOR_BUFFER_BIT); // Fills the scene with blue.
	glLoadIdentity();

	/* Draw three green triangles to form a ridge of hills in the background */

	glColor3f(0, 0.6f, 0.2f);
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(1.5f,1.65f);
	glVertex2f(5,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(3,2.1f);
	glVertex2f(7,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,-1);
	glVertex2f(6,1.2f);
	glVertex2f(20,-1);
	glEnd();

	/* Draw a bluish-gray rectangle to represent the road. */

	glColor3f(0.4f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0,-0.4f);
	glVertex2f(7,-0.4f);
	glVertex2f(7,0.4f);
	glVertex2f(0,0.4f);
	glEnd();

	/* Draw a white line to represent the stripe down the middle
	 * of the road. */

	glLineWidth(6);  // Set the line width to be 6 pixels.
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(7,0);
	glEnd();
	glLineWidth(1);  // Reset the line width to be 1 pixel.

	/* Draw the sun.  The drawSun method draws the sun centered at (0,0).  A 2D translation
	 * is applied to move the center of the sun to (5,3.3).   A rotation makes it rotate*/

	glPushMatrix();
	glTranslated(5.8,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawSun();
	glPopMatrix();

	/* Draw three windmills.  The drawWindmill method draws the windmill with its base
	 * at (0,0), and the top of the pole at (0,3).  Each windmill is first scaled to change
	 * its size and then translated to move its base to a different paint.  In the animation,
	 * the vanes of the windmill rotate.  That rotation is done with a transform inside the
	 * drawWindmill method. */

	glPushMatrix();
	glTranslated(0.75,1,0);
	glScaled(0.6,0.6,1);
	drawWindmill0();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.2,1.6,0);
	glScaled(0.4,0.4,1);
	drawWindmill1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3.7,0.8,0);
	glScaled(0.7,0.7,1);
	drawWindmill2();
	glPopMatrix();
/*	glPushMatrix();
	glTranslated(-3 + 13*(frameNumber % 300) / 300.0, 0, 0);
	glScaled(0.3,0.3,1);
//	drawCart();
	glPopMatrix();*/
	
	glPushMatrix();
	glTranslated(5.8,0.75,0);
	glScaled(0.7,0.7,0);
	powerstation();
	glPopMatrix();

	glPushMatrix();
	glScaled(0.5,0.5,0);
    drawPerson(1.0,1.0);
    drawPerson(7.0,0.4);
    glPopMatrix();


    //powerlines
    
   glPushMatrix();
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(2.0f);
    powerlines2(3.7,2.9);
    powerlines1(2.2,2.81);
    powerlines0(0.75,2.8);
    glPopMatrix();

 glutMouseFunc(mouse);
	glutSwapBuffers();



}
void init2(){
glClearColor(0.5f, 0.5f, 1, 1);
		// The next three lines set up the coordinates system.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}
/*void menu(int n){
if (n == 0)
{
	glutDestroyWindow(win3);
	exit(0);
}

else
{
	value = n;
}
glutPostRedisplay();
}*/
/*void createMenu(void){
glutCreateMenu();
glutAddMenuEntry("Red", 11);
glutAddMenuEntry("White", 12);
glutAddMenuEntry("Yellow", 13);
glutAddMenuEntry("Green", 14);
glutAddMenuEntry("Blue", 15);
}*/
void secmenu(int id)
{
     switch(id)
     {
               case 4:
               	//glRotated(frameNumber * (180.0/46), 0, 0, 1);
               	//glRotatef(frameNumber * (180.0/46),0.0f,0.0f,1.0f);
               	// glRotatef(frameNumber * (180.0/46), 0.0f, 0.0f, -1.0f);
               	 //glRotatef(frameNumber * (180.0/46), 0, 0, 1 );
               	 flag0=1;
               	  flag1=1;
               	   flag2=1;
               	 //drawwindmill();
               break;
               case 5:
               	flag0=0;
               	 flag1=0;
               	   flag2=0;
               	//drawwindmill();
                    break;
                case 6:
                	flag0=-1;
                	 flag1=-1;
               	   flag2=-1;
                	break;
               }

}

void key2(unsigned char c, int x, int y){
	if(c=1){
	 glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    win3=glutCreateWindow("Windmill simulation");
    init2();
    glutDisplayFunc(display2);
   
    glutTimerFunc(200,doFrame,0);
    
  submenu=glutCreateMenu(secmenu);
   glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutAddMenuEntry("rotate clockwise",4);
    glutAddMenuEntry("rotate anticlocwise",5);
     glutAddMenuEntry("stop rotating",6);
    glutSetWindow(win3);
    
	}

}


void key(unsigned char c, int x, int y){
if(c=1){

    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    int win2=glutCreateWindow("Project description page");
    init();
    glutDisplayFunc(display1);
    glutSetWindow(win2);

	glutKeyboardFunc(key2);
}
}


void display(){
	//displaying title
    glColor3f(1.0,1.0,1.0);
    char string1[70] = "Project  title  :  WINDMILL  SIMULATION  USING  OPENGL";
    glRasterPos2f(25,75);
    int i;
    for ( i = 0; i <strlen(string1); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string1[i]);
    }
    //displaing team members names
    glColor3f(1.0,1.0,1.0);
    char string2[50] = "Team members : ";
    glRasterPos2f(25,65);
    for ( i = 0; i <strlen(string2); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string2[i]);
    }
    glColor3f(1.0,1.0,1.0);
    char string3[50] = "Name1";
    glRasterPos2f(30,60);
    for ( i = 0; i <strlen(string3); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string3[i]);
    }
    glColor3f(1.0,1.0,1.0);
    char string4[50] = "Name2";
    glRasterPos2f(30,55);
    for ( i = 0; i <strlen(string4); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string4[i]);
    }
    glColor3f(1.0,1.0,1.0);
    char string5[50] = "Section : D";
    glRasterPos2f(25,45);
    for ( i = 0; i <strlen(string5); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string5[i]);
    }
    glColor3f(1.0,1.0,1.0);
    char string6[50] = "Guided by : Faculty name";
    glRasterPos2f(25,35);
    for ( i = 0; i <strlen(string6); i++) {
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string6[i]);
    }


    glFlush();

}




int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(0,0);
    win1=glutCreateWindow("Project front page");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    //glutKeyboardFunc(key2);
    glutMainLoop();
    return 0;
}
