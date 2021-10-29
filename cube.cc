#include "cube.h"
using namespace _colors_ne;
_cube::_cube(float Size)
{
    Vertices.resize(8);

    Vertices[0]=_vertex3f(Size/2,Size/2,-Size/2);
    Vertices[1]=_vertex3f(-Size/2,-Size/2,-Size/2);
    Vertices[2]=_vertex3f(-Size/2,Size/2,-Size/2);
    Vertices[3]=_vertex3f(Size/2,-Size/2,-Size/2);
    Vertices[4]=_vertex3f(Size/2,Size/2,Size/2);
    Vertices[5]=_vertex3f(-Size/2,-Size/2,Size/2);
    Vertices[6]=_vertex3f(Size/2,-Size/2,Size/2);
    Vertices[7]=_vertex3f(-Size/2, Size/2, Size/2);
}

void _cube::draw_point()
{
  glBegin(GL_POINTS);
  for (unsigned int i=0;i<Vertices.size();i++){
    glVertex3fv((GLfloat *) &Vertices[i]);
  }
  glEnd();
}

void _cube::draw_line(){

    glBegin(GL_LINES);

    const int NUMERO_CARAS = 6;

    GLint caras[NUMERO_CARAS][4] = {
      {1, 2, 3, 0}, {1, 5, 7, 2}, {7, 5, 6, 4},
      {0, 4, 6, 3}, {1, 3, 6, 5}, {7, 4, 0, 2}};

    for(int i = 0; i < NUMERO_CARAS ; i++){

        for(int j = 0; j < 4 ; j++){

            glVertex3fv((GLfloat *) &Vertices[caras[i][j]]);

        }

    }


    glEnd();


}

void _cube::draw_fill(){

    const int NUM_TRIANGULOS = 12;

    glBegin(GL_TRIANGLES);

    GLint triangulos[NUM_TRIANGULOS][3] ={

        {7, 5, 6}, {7, 6 ,4}, {0, 6, 3}, {0, 6, 4},
        {2, 1, 3}, {2, 3, 0}, {7, 5 ,1}, {7, 1, 2},
        {1, 5, 6}, {1, 6, 3}, {2, 7, 4}, {2, 0 ,4}};

    for(int i = 0; i < NUM_TRIANGULOS ; i++){

        for(int j = 0; j < 3; j++){

            glVertex3fv((GLfloat *) &Vertices[triangulos[i][j]]);

        }

    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnd();


}

void _cube::draw_chess(){

    const int NUM_TRIANGULOS = 12;

    glBegin(GL_TRIANGLES);

    GLint triangulos[NUM_TRIANGULOS][3] ={

        {7, 5, 6}, {7, 6 ,4}, {0, 6, 3}, {0, 6, 4},
        {2, 1, 3}, {2, 3, 0}, {7, 5 ,1}, {7, 1, 2},
        {1, 5, 6}, {1, 6, 3}, {2, 7, 4}, {2, 0 ,4}};

    for(int i = 0; i < NUM_TRIANGULOS ; i++){

        for(int j = 0; j < 3; j++){

            if(j %2 == 0){
                glColor3fv((GLfloat *) &RED);
            }else{
                glColor3fv((GLfloat *) &GREEN);
            }
            glVertex3fv((GLfloat *) &Vertices[triangulos[i][j]]);

        }

    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnd();

}


