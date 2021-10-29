/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{

    glBegin(GL_LINES);

    for(unsigned int i=0; i<Vertices.size() ; i++ ){

        glVertex3fv((GLfloat *) &Vertices[1]);
        glVertex3fv((GLfloat *) &Vertices[i]);

    }

    for(unsigned int i=0; i<Vertices.size() ; i++ ){

        glVertex3fv((GLfloat *) &Vertices[2]);
        glVertex3fv((GLfloat *) &Vertices[i]);
    }

    for(unsigned int i=0; i<Vertices.size() ; i++ ){

        glVertex3fv((GLfloat *) &Vertices[3]);
        glVertex3fv((GLfloat *) &Vertices[i]);

    }

    glEnd();

}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++)
        glVertex3fv((GLfloat *) &Vertices[Triangles[0][i]]);

    for (int i = 0; i < 3; i++)
        glVertex3fv((GLfloat *) &Vertices[Triangles[1][i]]);

    for (int i = 0; i < 3; i++)
        glVertex3fv((GLfloat *) &Vertices[Triangles[2][i]]);

    for (int i = 0; i < 3; i++)
        glVertex3fv((GLfloat *) &Vertices[Triangles[3][i]]);

    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnd();

}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++){
        glColor3fv((GLfloat *) &RED);
        glVertex3fv((GLfloat *) &Vertices[Triangles[0][i]]);
    }

    for (int i = 0; i < 3; i++){
        glColor3fv((GLfloat *) &RED);
        glVertex3fv((GLfloat *) &Vertices[Triangles[1][i]]);
    }

    for (int i = 0; i < 3; i++){
        glColor3fv((GLfloat *) &GREEN);
        glVertex3fv((GLfloat *) &Vertices[Triangles[2][i]]);
    }

    for (int i = 0; i < 3; i++){
        glColor3fv((GLfloat *) &GREEN);
        glVertex3fv((GLfloat *) &Vertices[Triangles[3][i]]);
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnd();
  
}
