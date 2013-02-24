#include <GL\glut.h>
#include <math.h>  
GLfloat xRotated, yRotated, zRotated;
GLdouble radius=2;
GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0}; 
GLfloat qaGreen[] = {1.0, 0.0, 0.0, 1.0}; 
GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0}; 
GLfloat qaRed[] = {1.0, 0.0, 0.0, 1.0}; 
    
GLfloat qaAmbientLight[]    = {0.1, 0.1, 0.1, 1.0};
GLfloat qaDiffuseLight[]    = {1, 1, 1, 1.0};
GLfloat qaSpecularLight[]    = {1.0, 1.0, 1.0, 1.0};
GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.01};
GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};
   
GLfloat qaLightPosition[]    = {0, 0, 0, 1};
GLfloat qaLightDirection[]    = {1, 1, 1, 0};

void display(void);
void reshape(int x, int y);
 
void idleFunc(void)
{
        if ( zRotated > 360.0 ) {
         zRotated -= 360.0*floor(zRotated/360.0);   
      }

          if ( yRotated > 360.0 ) {
         yRotated -= 360.0*floor(yRotated/360.0);  
      }
     zRotated += 0.1;
     yRotated +=0.1;
     
    display();
}
void initLighting()
{

    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

     
       glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
     glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
     glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
    


}
//void keyboard(unsigned char key, int x, int y) 
//{
    
     
 //    if (key == 'l' || key == 'L')  
   // { 
     //      glEnable(GL_LIGHTING);
    // }
    // else if (key == 'd' || key == 'D')  
    //{ 
      //  glDisable(GL_LIGHTING);
     // }
	 
void mouse(int button, int state, int x, int y) // ຝັງຊັນການຄິກເມົາເພື່ອປ່ຽນສີ ທີ່ອາຈານບອກໄຫ້ປຽນຈາກຄີບອດເປັນຢ່າງອື່ນ
{                                               // ວິທີການປຽນ ຄິກຂົ້ວ ເພືອປຽນ ຄິກຊາຍກັບເປັນສີເກົ່າ
    
     switch (button) {
case GLUT_LEFT_BUTTON:
if (state == GLUT_DOWN) 
    { 
          glEnable(GL_LIGHTING);
    }
break;
case GLUT_RIGHT_BUTTON:
if (state == GLUT_DOWN)  
    { 
        glDisable(GL_LIGHTING);
    }
break;
}
}

 
int main (int argc, char** argv)
{
    glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(350,350);
    glutCreateWindow("Thanavanh");
    initLighting(); 

    xRotated = yRotated = zRotated = 0.0;
    
    glutIdleFunc(idleFunc);
    glutDisplayFunc(display);
   // glutKeyboardFunc(keyboard); 
	glutMouseFunc(mouse);  
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
 
void display(void)
{


    glMatrixMode(GL_MODELVIEW);
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
   
    glTranslatef(0.0,0.0,-20.0);
 
   glPushMatrix();
 
     
    glTranslatef(0.0,0.0,0);
   
       glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaRed);

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaRed);

     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 1);
 
         glutSolidTeapot(radius);
     glPopMatrix();



    glPushMatrix();  
    glRotatef(yRotated,0.0,1.0,0.0);
    glTranslatef(5.0,0.0,0.0);
     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, emitLight);    
     glutSolidSphere(radius/6,25,25);
     glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Noemit);  
    glPopMatrix(); 

    glPushMatrix();  
    glRotatef(-yRotated,0.0,1.0,0.0);
    glTranslatef(5.0,0.0,0.0);
      glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    glPopMatrix(); 


    glFlush();
    glutSwapBuffers();      
   
}
 
void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,40.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  
}
