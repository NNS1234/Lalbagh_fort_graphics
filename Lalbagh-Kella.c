#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include "GL/imageloader.h"
#define PI 3.1416
float _angle = -70.0f;



//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId;

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
	glEnable(GL_COLOR_MATERIAL); //Enable color

	Image* image = loadBMP("C:\\Users\\mojum\\Desktop\\water.bmp");
	_textureId = loadTexture(image);
	delete image;
}

//Called when the window is resized
void handleResize(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void Ground()
{
    int i, p, r=25;
    float x=0.0, y=-1, z=0.0, q = 0.0, radius = 20.0, Pi = 3.1412;

    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glColor3f(0, 1, 0);
    glVertex3f(x, y, z); // centre of circle
    for (i = 0; i <= 361.0; i++)
    {
        glVertex3f ((x + (radius * cos(i * Pi / r))), y, (z + (radius * sin(i * Pi / r))));
    }
    glEnd();
}


void tree()     // Drawing The Side Stands
  {

    int slices = 30;

//    float a=3.0, b=1.0, c=-3.0, alpha=0.0, x=0.0, y=-0.7, y1=0.0, z=0.0, r=0.1, height=2.5;
    float a=5, b=-2.5, c=-5, alpha=0.0, x=0.0, y=-0.7, y1=-0.48, z=5.0, r=0.1, height=1;

     ////////*****Front Left Tree*****\\\\\\\\

     //fRONT LEFT POLE
     glPushMatrix();
     glTranslatef(-10.0-a,0.1,6.5+b);

       for(int i=1; i<=1; i++)
    {
            glColor3f(1.0f, 0.5f, 0.0f);


            glBegin(GL_QUAD_STRIP);  // right cylinder
            for(int i=0; i<=slices; i++)
            {
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+y1, b+z+sin((float)i/slices*2*M_PI)*r);
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+height, b+z+sin((float)i/slices*2*M_PI)*r);
            }
            glEnd();
    }

    glPopMatrix();

    //Leaf
    glPushMatrix();

        glTranslatef(-10.0,-0.3,6.5);
        glColor3f(0,0.5,0);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.3,2,10, 20);
    glPopMatrix();

    glPushMatrix();

        glTranslatef(-10.0,-0.2,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.4,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(-10.0,-0.1,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.5,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(-10.0,0.0,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.6,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(-10.0,0.1,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.7,2,10, 20);
     glPopMatrix();


     ////////*****Front Right Tree*****\\\\\\\\

    //Front Right pole
    glPushMatrix();
    glTranslatef(10.0-a,0.1,6.5+b);

    for(int i=1; i<=1; i++)
    {
            glColor3f(1.0f, 0.5f, 0.0f);


            glBegin(GL_QUAD_STRIP);  // right cylinder
            for(int i=0; i<=slices; i++)
            {
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+y1, b+z+sin((float)i/slices*2*M_PI)*r);
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+height, b+z+sin((float)i/slices*2*M_PI)*r);
            }
            glEnd();
    }
     glPopMatrix();

     //leaf
    glPushMatrix();

        glTranslatef(10.0,-0.3,6.5);
        glColor3f(0,0.5,0);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.3,2,10, 20);
    glPopMatrix();

    glPushMatrix();

        glTranslatef(10.0,-0.2,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.4,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(10.0,-0.1,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.5,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(10.0,0.0,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.6,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(10.0,0.1,6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.7,2,10, 20);
     glPopMatrix();

      ////////*****bACK Left Tree*****\\\\\\\\

     //fRONT LEFT POLE
     glPushMatrix();
     glTranslatef(-10.0-a,0.1,-6.5+b);

       for(int i=1; i<=1; i++)
    {
            glColor3f(1.0f, 0.5f, 0.0f);


            glBegin(GL_QUAD_STRIP);  // right cylinder
            for(int i=0; i<=slices; i++)
            {
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+y1, b+z+sin((float)i/slices*2*M_PI)*r);
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+height, b+z+sin((float)i/slices*2*M_PI)*r);
            }
            glEnd();
    }

    glPopMatrix();

    //Leaf
    glPushMatrix();

        glTranslatef(-10.0,-0.3,-6.5);
        glColor3f(0,0.5,0);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.3,2,10, 20);
    glPopMatrix();

    glPushMatrix();

        glTranslatef(-10.0,-0.2,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.4,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(-10.0,-0.1,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.5,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(-10.0,0.0,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.6,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(-10.0,0.1,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.7,2,10, 20);
     glPopMatrix();


     ////////*****Back Right Tree*****\\\\\\\\

    //Front Right pole
    glPushMatrix();
    glTranslatef(10.0-a,0.1,-6.5+b);

    for(int i=1; i<=1; i++)
    {
            glColor3f(1.0f, 0.5f, 0.0f);


            glBegin(GL_QUAD_STRIP);  // right cylinder
            for(int i=0; i<=slices; i++)
            {
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+y1, b+z+sin((float)i/slices*2*M_PI)*r);
               glVertex3f(a+x+cos((float)i/slices*2*M_PI)*r, y+height, b+z+sin((float)i/slices*2*M_PI)*r);
            }
            glEnd();
    }
     glPopMatrix();

     //leaf
    glPushMatrix();

        glTranslatef(10.0,-0.3,-6.5);
        glColor3f(0,0.5,0);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.3,2,10, 20);
    glPopMatrix();

    glPushMatrix();

        glTranslatef(10.0,-0.2,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.4,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(10.0,-0.1,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.5,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(10.0,0.0,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.6,2,10, 20);
     glPopMatrix();

     glPushMatrix();

        glTranslatef(10.0,0.1,-6.5);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.7,2,10, 20);
     glPopMatrix();


    }



void Road()
{
    //Front
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glVertex3f( -6.0f,-0.9f,2.0f);
    glVertex3f( 6.0f,-0.9f,2.0f);
    glVertex3f( 6.0f,-0.9f,4.5f);
    glVertex3f( -6.0f,-0.9f,4.5f);

    glEnd();

    //Back
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glVertex3f( -6.0f,-0.9f,-2.0f);
    glVertex3f( 6.0f,-0.9f,-2.0f);
    glVertex3f( 6.0f,-0.9f,-4.5f);
    glVertex3f( -6.0f,-0.9f,-4.5f);

    glEnd();

    //Right
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glVertex3f( 4.4f,-0.9f,2.0f);
    glVertex3f( 4.4f,-0.9f,-2.0f);
    glVertex3f( 6.0f,-0.9f,-2.0f);
    glVertex3f( 6.0f,-0.9f,2.0f);

    glEnd();

    //Left
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glVertex3f( -4.4f,-0.9f,2.0f);
    glVertex3f( -4.4f,-0.9f,-2.0f);
    glVertex3f( -6.0f,-0.9f,-2.0f);
    glVertex3f( -6.0f,-0.9f,2.0f);

    glEnd();

    //Front road
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glVertex3f( 3.0f,-0.9f,4.5f);
    glVertex3f( 3.0f,-0.9f,20.0f);
    glVertex3f( -3.0f,-0.9f,20.f);
    glVertex3f( -3.0f,-0.9f,4.5f);
    glEnd();

    //Back road
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glColor3f(0.8,0.6,0.2);
    glVertex3f( 3.0f,-0.9f,-4.5f);
    glVertex3f( 3.0f,-0.9f,-20.0f);
    glVertex3f( -3.0f,-0.9f,-20.f);
    glVertex3f( -3.0f,-0.9f,-4.5f);

    glEnd();

    //Right road
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glVertex3f( 6.0f,-0.9f,1.5f);
    glVertex3f( 6.0f,-0.9f,-1.5f);
    glVertex3f( 21.5f,-0.9f,-1.5f);
    glVertex3f( 21.5f,-0.9f,1.5f);

    glEnd();

    //Left road
    glBegin(GL_QUADS);
    glColor3f(0.8,0.6,0.2);

    glVertex3f( -6.0f,-0.9f,1.5f);
    glVertex3f( -6.0f,-0.9f,-1.5f);
    glVertex3f( -21.5f,-0.9f,-1.5f);
    glVertex3f( -21.5f,-0.9f,1.5f);

    glEnd();

    //Front Water
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	  glColor3f(1.0,1.0,1.0);

	 glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 1.5f,-0.8f,6.0f);
	glTexCoord2f(0.0f, 5.0f);
    glVertex3f( 1.5f,-0.8f,16.0f);
	glTexCoord2f(5.0f, 5.0f);
	glVertex3f( -1.5f,-0.8f,16.0f);
	glTexCoord2f(10.0f, 0.0f);
    glVertex3f( -1.5f,-0.8f,6.0f);
    glEnd();

        //Back Water
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	  glColor3f(1.0,1.0,1.0);

	 glBegin(GL_QUADS);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 1.5f,-0.8f,-6.0f);
	glTexCoord2f(0.0f, 5.0f);
    glVertex3f( 1.5f,-0.8f,-16.0f);
	glTexCoord2f(5.0f, 5.0f);
	glVertex3f( -1.5f,-0.8f,-16.0f);
	glTexCoord2f(10.0f, 0.0f);
    glVertex3f( -1.5f,-0.8f,-6.0f);
    glEnd();
}

float posLight1=0.1f,posLight2=0.1f,posLight3=0.1f,R=0,G=0,B=0;
int night = 1;

void dayLight()
{
    //Add ambient light
	GLfloat ambientColor[] = {0.4f, 0.25f, 0.1f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	//Add directed light
	GLfloat lightColor1[] = {1.0f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-0.4f, 0.5f, 2.0f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	if(night==1)
        return;
}

void nightLight()
{
    //Add positioned light
	GLfloat lightColor0[] = {posLight1, posLight2, posLight3, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
}


float p=0.0,q=0.0,w=-20.0;

//Draws the 3D scene
void drawScene()
{

    float x1,y1,x2,y2;
    float angle;
    double radius;
    float z1,z2;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(R,G,B,1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(p,q,w);

    nightLight();

 //Add ambient light
    GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Add positioned light
    GLfloat lightColor0[] = {0.7f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {4.0f, 4.5f, 8.0f, -1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    //Add directed light
    GLfloat lightColor1[] = {0.5f, 0.4f, 0.5f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);


    glRotatef(_angle, 0.0f, 1.0f, 0.0f);

    /*//////////***FRONT SIDE***//////////*/

    ////////*****Front Center Wall*****\\\\\\\\

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.2f,0.1f);
    glVertex3f( -2.2f,-0.9f,2.0f);
    glVertex3f( 2.2f,-0.9f,2.0f);
    glVertex3f( 2.2f,1.8f,2.0f);
    glVertex3f( -2.2f,1.8f,2.0f);
    glEnd();

    //Center Middle wall

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f);
    glVertex3f( -1.8f,-0.9f,2.1f);
    glVertex3f( 1.8f,-0.9f,2.1f);
    glVertex3f( 1.8f,1.5f,2.1f);
    glVertex3f( -1.8f,1.5f,2.1f);
    glEnd();

    //Center Large Door

    //Center Square Door
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( -1.2f,-0.8f,2.15f);
    glVertex3f( 1.2f,-0.8f,2.15f);
    glVertex3f( 1.2f,0.8f,2.15f);
    glVertex3f( -1.2f,0.8f,2.15f);

    glEnd();

    //Center Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 1.2f,0.8f,2.15f);
    glVertex3f( -1.2f,0.8f,2.15f);
    glVertex3f( 0.0f,1.2f,2.15f);
    glEnd();

    //Center Top Left Circle
    radius=0.2f;
    x1 = -1.1f,y1=0.6f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.15);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15);
    }

    glEnd();

    //Center Top Right Circle
    radius=0.2f;
    x1 = 1.1f,y1=0.6f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.15f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15f);
    }

    glEnd();

    //Center Small Door

    //Center Square Door
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( -0.8f,-0.7f,2.18f);
    glVertex3f( 0.8f,-0.7f,2.18f);
    glVertex3f( 0.8f,0.5f,2.18f);
    glVertex3f( -0.8f,0.5f,2.18f);

    glEnd();

    //Center Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 0.8f,0.5f,2.18f);
    glVertex3f( -0.8f,0.5f,2.18f);
    glVertex3f( 0.0f,0.8f,2.18f);
    glEnd();

    //Center Top Left Circle
    radius=0.2f;
    x1 = -0.7f,y1=0.3f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.18);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.18);
    }

    glEnd();

    //Center Top Right Circle
    radius=0.2f;
    x1 = 0.7f,y1=0.3f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.18f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.18f);
    }

    glEnd();


////////*****Front Left Wall*****\\\\\\\\

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.2f,0.1f);
    glVertex3f( -4.4f,-0.9f,2.0f);
    glVertex3f( -2.2f,-0.9f,2.0f);
    glVertex3f( -2.2f,1.5f,2.0f);
    glVertex3f( -4.4f,1.5f,2.0f);
    glEnd();

    //Left Middle wall

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f);
    glVertex3f( -4.0f,-0.9f,2.1f);
    glVertex3f( -2.2f,-0.9f,2.1f);
    glVertex3f( -2.2f,1.2f,2.1f);
    glVertex3f( -4.0f,1.2f,2.1f);
    glEnd();

    //Left Large Door

    //Left Square Door
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( -3.8f,-0.8f,2.15f);
    glVertex3f( -2.4f,-0.8f,2.15f);
    glVertex3f( -2.4f,0.4f,2.15f);
    glVertex3f( -3.8f,0.4f,2.15f);

    glEnd();

    //Left Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( -3.8f,0.4f,2.15f);
    glVertex3f( -2.4f,0.4f,2.15f);
    glVertex3f( -3.1f,1.0f,2.15f);
    glEnd();

    //Left Top Left Circle
    radius=0.2f;
    x1 = -3.7f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.15);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15);
    }

    glEnd();

    //Left Top Right Circle
    radius=0.2f;
    x1 = -2.5f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.15f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15f);
    }

    glEnd();

    //Left Small Door

    //Left Square Door
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( -3.6f,-0.7f,2.18f);
    glVertex3f( -2.6f,-0.7f,2.18f);
    glVertex3f( -2.6f,0.1f,2.18f);
    glVertex3f( -3.6f,0.1f,2.18f);

    glEnd();

    //Left Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( -3.6f,0.1f,2.18f);
    glVertex3f( -2.6f,0.1f,2.18f);
    glVertex3f( -3.1f,0.6f,2.18f);
    glEnd();

    //Left Top Left Circle
    radius=0.2f;
    x1 = -3.45f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.18);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15);
    }

    glEnd();

    //Left Top Right Circle
    radius=0.2f;
    x1 = -2.75f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.18f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15f);
    }

    glEnd();



////////*****Front Right Wall*****\\\\\\\\

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.2f,0.1f);
    glVertex3f( 4.4f,-0.9f,2.0f);
    glVertex3f( 2.2f,-0.9f,2.0f);
    glVertex3f( 2.2f,1.5f,2.0f);
    glVertex3f( 4.4f,1.5f,2.0f);
    glEnd();

    //Right Middle wall

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f);
    glVertex3f( 4.0f,-0.9f,2.1f);
    glVertex3f( 2.2f,-0.9f,2.1f);
    glVertex3f( 2.2f,1.2f,2.1f);
    glVertex3f( 4.0f,1.2f,2.1f);
    glEnd();

    //Right Large Door

    //Right Square Door
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 3.8f,-0.8f,2.15f);
    glVertex3f( 2.4f,-0.8f,2.15f);
    glVertex3f( 2.4f,0.4f,2.15f);
    glVertex3f( 3.8f,0.4f,2.15f);

    glEnd();

    //Right Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 3.8f,0.4f,2.15f);
    glVertex3f( 2.4f,0.4f,2.15f);
    glVertex3f( 3.1f,1.0f,2.15f);
    glEnd();

    //Right Top Left Circle
    radius=0.2f;
    x1 = 3.7f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.15);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15);
    }

    glEnd();

    //Right Top Right Circle
    radius=0.2f;
    x1 = 2.5f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.15f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15f);
    }

    glEnd();

    //Right Small Door

    //Right Square Door
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( 3.6f,-0.7f,2.18f);
    glVertex3f( 2.6f,-0.7f,2.18f);
    glVertex3f( 2.6f,0.1f,2.18f);
    glVertex3f( 3.6f,0.1f,2.18f);

    glEnd();

    //Right Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 3.6f,0.1f,2.18f);
    glVertex3f( 2.6f,0.1f,2.18f);
    glVertex3f( 3.1f,0.6f,2.18f);
    glEnd();

    //Right Top Left Circle
    radius=0.2f;
    x1 = 2.7f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.18);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15);
    }

    glEnd();

    //Right Top Right Circle
    radius=0.2f;
    x1 = 3.45f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,2.18f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,2.15f);
    }

    glEnd();


    /*//////////***BACK SIDE***//////////*/

    ////////*****Back Center Wall*****\\\\\\\\

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.2f,0.1f);
    glVertex3f( -2.2f,-0.9f,-2.0f);
    glVertex3f( 2.2f,-0.9f,-2.0f);
    glVertex3f( 2.2f,1.8f,-2.0f);
    glVertex3f( -2.2f,1.8f,-2.0f);
    glEnd();

    //Center Middle wall

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f);
    glVertex3f( -1.8f,-0.9f,-2.1f);
    glVertex3f( 1.8f,-0.9f,-2.1f);
    glVertex3f( 1.8f,1.5f,-2.1f);
    glVertex3f( -1.8f,1.5f,-2.1f);
    glEnd();

    //Center Large Door

    //Center Square Door
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( -1.2f,-0.8f,-2.15f);
    glVertex3f( 1.2f,-0.8f,-2.15f);
    glVertex3f( 1.2f,0.8f,-2.15f);
    glVertex3f( -1.2f,0.8f,-2.15f);

    glEnd();

    //Center Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 1.2f,0.8f,-2.15f);
    glVertex3f( -1.2f,0.8f,-2.15f);
    glVertex3f( 0.0f,1.2f,-2.15f);
    glEnd();

    //Center Top Left Circle
    radius=0.2f;
    x1 = -1.1f,y1=0.6f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.15);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15);
    }

    glEnd();

    //Center Top Right Circle
    radius=0.2f;
    x1 = 1.1f,y1=0.6f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.15f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15f);
    }

    glEnd();

    //Center Small Door

    //Center Square Door
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( -0.8f,-0.7f,-2.18f);
    glVertex3f( 0.8f,-0.7f,-2.18f);
    glVertex3f( 0.8f,0.5f,-2.18f);
    glVertex3f( -0.8f,0.5f,-2.18f);

    glEnd();

    //Center Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 0.8f,0.5f,-2.18f);
    glVertex3f( -0.8f,0.5f,-2.18f);
    glVertex3f( 0.0f,0.8f,-2.18f);
    glEnd();

    //Center Top Left Circle
    radius=0.2f;
    x1 = -0.7f,y1=0.3f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.18);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.18);
    }

    glEnd();

    //Center Top Right Circle
    radius=0.2f;
    x1 = 0.7f,y1=0.3f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.18f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.18f);
    }

    glEnd();


////////*****Back Left Wall*****\\\\\\\\

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.2f,0.1f);
    glVertex3f( -4.4f,-0.9f,-2.0f);
    glVertex3f( -2.2f,-0.9f,-2.0f);
    glVertex3f( -2.2f,1.5f,-2.0f);
    glVertex3f( -4.4f,1.5f,-2.0f);
    glEnd();

    //Left Middle wall

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f);
    glVertex3f( -4.0f,-0.9f,-2.1f);
    glVertex3f( -2.2f,-0.9f,-2.1f);
    glVertex3f( -2.2f,1.2f,-2.1f);
    glVertex3f( -4.0f,1.2f,-2.1f);
    glEnd();

    //Left Large Door

    //Left Square Door
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( -3.8f,-0.8f,-2.15f);
    glVertex3f( -2.4f,-0.8f,-2.15f);
    glVertex3f( -2.4f,0.4f,-2.15f);
    glVertex3f( -3.8f,0.4f,-2.15f);

    glEnd();

    //Left Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( -3.8f,0.4f,-2.15f);
    glVertex3f( -2.4f,0.4f,-2.15f);
    glVertex3f( -3.1f,1.0f,-2.15f);
    glEnd();

    //Left Top Left Circle
    radius=0.2f;
    x1 = -3.7f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.15);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15);
    }

    glEnd();

    //Left Top Right Circle
    radius=0.2f;
    x1 = -2.5f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.15f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15f);
    }

    glEnd();

    //Left Small Door

    //Left Square Door
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( -3.6f,-0.7f,-2.18f);
    glVertex3f( -2.6f,-0.7f,-2.18f);
    glVertex3f( -2.6f,0.1f,-2.18f);
    glVertex3f( -3.6f,0.1f,-2.18f);

    glEnd();

    //Left Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( -3.6f,0.1f,-2.18f);
    glVertex3f( -2.6f,0.1f,-2.18f);
    glVertex3f( -3.1f,0.6f,-2.18f);
    glEnd();

    //Left Top Left Circle
    radius=0.2f;
    x1 = -3.45f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.18);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15);
    }

    glEnd();

    //Left Top Right Circle
    radius=0.2f;
    x1 = -2.75f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.18f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15f);
    }

    glEnd();



////////*****Back Right Wall*****\\\\\\\\

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.2f,0.1f);
    glVertex3f( 4.4f,-0.9f,-2.0f);
    glVertex3f( 2.2f,-0.9f,-2.0f);
    glVertex3f( 2.2f,1.5f,-2.0f);
    glVertex3f( 4.4f,1.5f,-2.0f);
    glEnd();

    //Right Middle wall

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.6f,0.1f);
    glVertex3f( 4.0f,-0.9f,-2.1f);
    glVertex3f( 2.2f,-0.9f,-2.1f);
    glVertex3f( 2.2f,1.2f,-2.1f);
    glVertex3f( 4.0f,1.2f,-2.1f);
    glEnd();

    //Right Large Door

    //Right Square Door
    glBegin(GL_QUADS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 3.8f,-0.8f,-2.15f);
    glVertex3f( 2.4f,-0.8f,-2.15f);
    glVertex3f( 2.4f,0.4f,-2.15f);
    glVertex3f( 3.8f,0.4f,-2.15f);

    glEnd();

    //Right Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 3.8f,0.4f,-2.15f);
    glVertex3f( 2.4f,0.4f,-2.15f);
    glVertex3f( 3.1f,1.0f,-2.15f);
    glEnd();

    //Right Top Left Circle
    radius=0.2f;
    x1 = 3.7f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.15);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15);
    }

    glEnd();

    //Right Top Right Circle
    radius=0.2f;
    x1 = 2.5f,y1=0.2f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.15f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15f);
    }

    glEnd();

    //Right Small Door

    //Right Square Door
    glBegin(GL_QUADS);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( 3.6f,-0.7f,-2.18f);
    glVertex3f( 2.6f,-0.7f,-2.18f);
    glVertex3f( 2.6f,0.1f,-2.18f);
    glVertex3f( 3.6f,0.1f,-2.18f);

    glEnd();

    //Right Triangle Top
    glBegin(GL_TRIANGLES);

    glVertex3f( 3.6f,0.1f,-2.18f);
    glVertex3f( 2.6f,0.1f,-2.18f);
    glVertex3f( 3.1f,0.6f,-2.18f);
    glEnd();

    //Right Top Left Circle
    radius=0.2f;
    x1 = 2.7f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.18);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15);
    }

    glEnd();

    //Right Top Right Circle
    radius=0.2f;
    x1 = 3.45f,y1=0.0f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x1,y1,-2.18f);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        x2 = x1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(x2,y2,-2.15f);
    }

    glEnd();

    /*//////////***RIGHT SIDE***//////////*/

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.3f,0.1f);
    glVertex3f( 4.4f,-0.9f,2.0f);
    glVertex3f( 4.4f,-0.9f,-2.0f);
    glVertex3f( 4.4f,1.5f,-2.0f);
    glVertex3f( 4.4f,1.5f,2.0f);
    glEnd();

    //Design

    glBegin(GL_QUADS);//1

    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 4.5f,-0.7f,1.6f);
    glVertex3f( 4.5f,-0.7f,0.4f);
    glVertex3f( 4.5f,-0.4f,0.4f);
    glVertex3f( 4.5f,-0.4f,1.6f);

    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( 4.5f,-0.4f,1.6f);
    glVertex3f( 4.5f,-0.4f,0.4f);
    glVertex3f( 4.5f,0.6f,0.4f);
    glVertex3f( 4.5f,0.6f,1.6f);

    glEnd();

    radius=0.5;

    z1 = 1.0,z2;
    y1=0.6;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f(4.5f,y1,z1);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        z2 = z1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(4.5f,y2,z2);
    }

    glEnd();


    glBegin(GL_QUADS);//2
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( 4.5f,-0.7f,-0.4f);
    glVertex3f( 4.5f,-0.7f,-1.6f);
    glVertex3f( 4.5f,-0.4f,-1.6f);
    glVertex3f( 4.5f,-0.4f,-0.4f);

    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( 4.5f,-0.4f,-0.4f);
    glVertex3f( 4.5f,-0.4f,-1.6f);
    glVertex3f( 4.5f,0.6f,-1.6f);
    glVertex3f( 4.5f,0.6f,-0.4f);

    glEnd();

    radius=0.5;

    z1 = -1.0,z2;
    y1=0.6;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f(4.5f,y1,z1);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        z2 = z1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(4.5f,y2,z2);
    }

    glEnd();


    /*//////////***LEFT SIDE***/////////*/

    glBegin(GL_QUADS);
    glColor3f(1.0f,0.3f,0.1f);
    glVertex3f( -4.4f,-1.0f,2.0f);
    glVertex3f( -4.4f,-1.0f,-2.0f);
    glVertex3f( -4.4f,1.5f,-2.0f);
    glVertex3f( -4.4f,1.5f,2.0f);
    glEnd();

    //Design

    glBegin(GL_QUADS);//1

    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f( -4.5f,-0.7f,1.6f);
    glVertex3f( -4.5f,-0.7f,0.4f);
    glVertex3f( -4.5f,-0.4f,0.4f);
    glVertex3f( -4.5f,-0.4f,1.6f);

    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( -4.5f,-0.4f,1.6f);
    glVertex3f( -4.5f,-0.4f,0.4f);
    glVertex3f( -4.5f,0.6f,0.4f);
    glVertex3f( -4.5f,0.6f,1.6f);

    glEnd();

    radius=0.5;

    z1 = 1.0,z2;
    y1=0.6;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f(-4.5f,y1,z1);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        z2 = z1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(-4.5f,y2,z2);
    }

    glEnd();


    glBegin(GL_QUADS);//2
    glColor3f(1,1,1);
    glVertex3f( -4.5f,-0.7f,-0.4f);
    glVertex3f( -4.5f,-0.7f,-1.6f);
    glVertex3f( -4.5f,-0.4f,-1.6f);
    glVertex3f( -4.5f,-0.4f,-0.4f);

    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f( -4.5f,-0.4f,-0.4f);
    glVertex3f( -4.5f,-0.4f,-1.6f);
    glVertex3f( -4.5f,0.6f,-1.6f);
    glVertex3f( -4.5f,0.6f,-0.4f);

    glEnd();

    radius=0.5;

    z1 = -1.0,z2;
    y1=0.6;


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.1f,0.0f,0.1f);
    glVertex3f(-4.5f,y1,z1);

    for (angle=1.0f; angle<361.0f; angle+=0.2)
    {
        z2 = z1+sin(angle)*radius;
        y2 = y1+cos(angle)*radius;
        glVertex3f(-4.5f,y2,z2);
    }

    glEnd();

    /*//////////***ROOF***//////////*/

    glBegin(GL_QUADS);//2
    glColor3f(1.0f,0.2,0.3f);
    glVertex3f( -4.5f,1.5f,-2.0f);
    glVertex3f( 4.5f,1.5f,-2.0f);
    glVertex3f( 4.5f,1.5f,2.0f);
    glVertex3f( -4.5f,1.5f,2.0f);
    glEnd();

    /*//////////***MINAR***//////////*/

    ////////*****Front Right*****\\\\\\\\

    glColor3f(1.0f, 0.5f, 0.0f);
    radius=0.5f;
    int i;

    glBegin(GL_TRIANGLE_STRIP);
    for(i=0; i<180; i++)
    {
        float x = radius * cos(i);
        float z = radius * sin(i);
        glVertex3f(4.5f+x, 1.8f, 2.5f+z);
        glVertex3f(4.5f+x, -0.9f, 2.5f+z);
    }
    glEnd();

    ////////*****Front Left*****\\\\\\\\

    glBegin(GL_TRIANGLE_STRIP);
    for(i=0; i<180; i++)
    {
        float x = radius * cos(i);
        float z = radius * sin(i);
        glVertex3f(-4.5f+x, 1.8f, 2.5f+z);
        glVertex3f(-4.5f+x, -0.9f, 2.5f+z);
    }
    glEnd();

    ////////*****Back Left*****\\\\\\\\

    glBegin(GL_TRIANGLE_STRIP);
    for(i=0; i<180; i++)
    {
        float x = radius * cos(i);
        float z = radius * sin(i);
        glVertex3f(-4.5f+x, 1.8f, -2.5f+z);
        glVertex3f(-4.5f+x, -0.9f, -2.5f+z);
    }
    glEnd();

    ////////*****Back Right*****\\\\\\\\

    glBegin(GL_TRIANGLE_STRIP);
    for(i=0; i<180; i++)
    {
        float x = radius * cos(i);
        float z = radius * sin(i);
        glVertex3f(4.5f+x, 1.8f, -2.5f+z);
        glVertex3f(4.5f+x, -0.9f, -2.5f+z);
    }
    glEnd();


    /*//////////***GOMBUZ***//////////*/

    ////////*****Front Right*****\\\\\\\\

    glPushMatrix();
    glColor3f(0.9f,0.2f,0.3f);
    glTranslatef(4.5f,1.8f,2.5f);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.6, 1.1,10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.5f,2.2f,2.5f);
    glutSolidSphere(0.5,100,200);
    glPopMatrix();

    ////////*****Front Left*****\\\\\\\\

    glPushMatrix();
    glColor3f(0.9f,0.2f,0.3f);
    glTranslatef(-4.5f,1.8f,2.5f);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.6, 1.1,10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5f,2.2f,2.5f);
    glutSolidSphere(0.5,100,200);
    glPopMatrix();

    ////////*****Back Right*****\\\\\\\\

    glPushMatrix();
    glColor3f(0.9f,0.2f,0.3f);
    glTranslatef(4.5f,1.8f,-2.5f);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.6, 1.1,10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4.5f,2.2f,-2.5f);
    glutSolidSphere(0.5,200,100);
    glPopMatrix();

    ////////*****Back Left*****\\\\\\\\

    glPushMatrix();
    glColor3f(0.9f,0.2f,0.3f);
    glTranslatef(-4.5f,1.8f,-2.5f);
    glRotatef(-90,1,0,0);
    glutSolidCone(0.6, 1.1,10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4.5f,2.2f,-2.5f);
    glutSolidSphere(0.5,200,100);
    glPopMatrix();


    ////////*****Top Center*****\\\\\\\\

    glPushMatrix();
    glColor3f(0.9f,0.2f,0.3f);
    glTranslatef(0.0f,1.8f,0.0f);
    glRotatef(-90,1,0,0);
    glutSolidCone(1.6, 1.8,10,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f,1.8f,0.0f);
    glutSolidSphere(1.5,200,100);
    glPopMatrix();


    ////Moon
    if(night==1){
        glPushMatrix();
        glTranslatef(-6.0,7.0,-0.5);
        glColor3f(1,1,1);
        glutSolidSphere(0.5,100,200);
        glPopMatrix();

            int y=5.0f, z=-0.5f;
        for(int j=0;j<5;j++)
        {

            for(int i=0;i<30;i++)
                {
                int x=-20.0f;
                glPushMatrix();
                glTranslatef(x+i,y,z);
                glutSolidSphere(0.03,12,12);
                glPopMatrix();
                }
             y++;
        }
    }
    ////Sun
     if(night==0) {
        glPushMatrix();
        glTranslatef(6.0,7.0,-0.5);
        glColor3f(1,1,0);
        glutSolidSphere(0.5,100,200);
        glPopMatrix();
    }

    /*//////////***FUNCTIONS***//////////*/

    Ground();
    Road();
    tree();
    glutSwapBuffers();

}

void update(int value)
{
    _angle += 1.5f;
    if (_angle > 360)
    {
        _angle -= 360;
    }

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void processSpecialKeys(int key, int x, int y) {

	switch(key) {

	    case GLUT_KEY_F1 : R = 0.7; G = 0.9; B = 1.0;
		     night=0;
             dayLight();
			break;

		case GLUT_KEY_F2 : R = 0.0; G = 0.0; B = 0.0;
              night = 1;
			break;

		case GLUT_KEY_F3 :
             w=w+0.2;
             glTranslatef(p, q, w);
			break;

		case GLUT_KEY_F4 :
             w=w-0.2;
             glTranslatef(p, q, w);
			break;

		case GLUT_KEY_F5 :
             p=p+0.2;
             glTranslatef(p, q, w);
			break;

		case GLUT_KEY_F6 :
             p=p-0.2;
             glTranslatef(p, q, w);
			break;

        case GLUT_KEY_F7 :
             q=q+0.2;
             glTranslatef(p, q, w);
			break;

		case GLUT_KEY_F8 :
             q=q-0.2;
             glTranslatef(p, q, w);
			break;
	}
}



int main(int argc, char** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1350, 700);
    glutInitWindowPosition(10,10);
    //Create the window
    glutCreateWindow("Lalbagh Kella");
    initRendering();

    //Set handler functions
    glutDisplayFunc(drawScene);

    glutReshapeFunc(handleResize);
    glutSpecialFunc(processSpecialKeys);
    update(0);

    glutMainLoop();
    return 0;
}











