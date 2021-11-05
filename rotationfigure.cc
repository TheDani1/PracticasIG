#include "rotationfigure.h"
#include <cmath>

_rotationfigure::_rotationfigure(int n_i, int m_i, float Size){

    n = n_i;
    m = m_i;
    // FÓRMULA PARA SACAR LOS TRIÁNGULOS (M-1*N)*2
    // EL NUMERO POR EL QUE MULTIPLICAS PARA DIBUJAR LAS CARAS DE LA FIGURA
    // ES M ADEMÁS EL BUCLE TIENE QUE TENER N INTERACCIONES

    // CREAMOS LOS DIFERENTES PUNTOS (M) A PARTIR DE N GIROS

    Vertices.resize(4);

    // INICIALIZAMOS LOS PRIMEROS 4 PUNTOS QUE SE VAN A ROTAR

    Vertices[0] = _vertex3f(0,-Size,0);
    Vertices[3] = _vertex3f(Size,-Size,0);

    Vertices[2] = _vertex3f(Size,Size,0);
    Vertices[1] = _vertex3f(0,Size,0);

    // UNA VEZ INICIALIZADOS PROCEDEMOS A HACER LA ROTACIÓN
    // PI RADIANES = 90
    // 2PI RADIANES = 180
    // 3PI RADIANES = 270
    // 4PI RADIANES = 360
    // x = R·cos(α)
    // z = −R·sin(α)

    // float turnd = M_PI*4 / n; // angulo que gira

    // for(int i = 0, contador = 4; i < n; i++, contador+=4){
        //LOS HE CAMBIADO SIN POR COS

        // Vertices[contador] = _vertex3f(Size*cos(turnd), Vertices[0].y, -Size*sin(turnd));
//        Vertices[contador+1] = _vertex3f(Size*cos(turnd), Vertices[1].y, -Size*sin(turnd));
//        Vertices[contador+2] = _vertex3f(Size*cos(turnd), Vertices[2].y, -Size*sin(turnd));
//        Vertices[contador+3] = _vertex3f(Size*cos(turnd), Vertices[3].y, -Size*sin(turnd));

//        turnd += turnd;

        /* PROBAR CON ESTO
        var sinTheta = sin(theta);
        var cosTheta = cos(theta);
        var node = nodes[n];
        var x = node[0];
        var z = node[2];
        node[0] = x * cosTheta + z * sinTheta;
        node[2] = z * cosTheta - x * sinTheta;
        */
    // }

    // SE PUEDE SUSTITUIR VERITCES[J] POR SIZE

    float angle = (M_PI * 4) / n;
    //double vuelta_completa = M_PI * 4;

    _vertex3f verteaux;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < 4; j++){

            verteaux.x = Size * cos(angle);
            verteaux.y = Vertices[j].y;
            verteaux.z = -Size * sin(angle);
            Vertices.emplace_back(verteaux);
        }

        angle += (M_PI * 4) / n;
    }

    // CREACION TRIANGULOS o GENERACION DE CARAS

    int numero_caras = n;
    int vertex_n = Vertices.size();

    Triangles.clear();

    for(int i = 0; i < numero_caras; i++){

        // CARA PAR
        Triangles.push_back(_vertex3ui((vertex_n*i+0)+1, (vertex_n*i+0), (i+1)*vertex_n+0));
        // CARA IMPAR
        Triangles.push_back(_vertex3ui((i+1)*vertex_n+0, (i+1)*vertex_n+(0+1), (i*vertex_n+0)+1));

        // CARA PAR
        Triangles.push_back(_vertex3ui((0+1, 0, ));
        // CARA IMPAR
        Triangles.push_back(_vertex3ui((i+1)*vertex_n+0, (i+1)*vertex_n+(0+1), (i*vertex_n+0)+1));

    }



//    int numero_cas_matriz = (vertex_n-1)*n*2;

//    int aux;

//    Triangles.push_back(_vertex3ui(0, vertex_n, 1));
//    for(int i=1; i<n*2; i++){

//        int primerpunto = i*vertex_n;
//        int segundopunto1 = primerpunto+1;
//        int segundopunto2 = primerpunto+vertex_n;
//        int tercerpunto1 = 1 + vertex_n*(i-1);
//        int tercerpunto2 = tercerpunto1 + vertex_n;

//        Triangles.push_back(_vertex3ui(primerpunto, segundopunto1, tercerpunto1));
//        Triangles.push_back(_vertex3ui(primerpunto, segundopunto2, tercerpunto2));
//        aux=i;
//        aux++;
//    }

//    Triangles.push_back(_vertex3ui( (aux*vertex_n), (aux*vertex_n)+1, (1+vertex_n*(aux-1))));

//    int triangulos_a_completar = numero_cas_matriz-Triangles.size();
//    int contador=0;

//    for(int i=0 ; i < triangulos_a_completar; i++){

//        Triangles.push_back(_vertex3ui(Triangles[contador]._0+1, Triangles[contador]._1+1, Triangles[contador]._2+1));
//        contador++;
//    }

}

void _rotationfigure::draw_point(){

    glBegin(GL_POINTS);
    for (unsigned int i=0;i<Vertices.size();i++){
      glVertex3fv((GLfloat *) &Vertices[i]);
    }
    glEnd();

}

void _rotationfigure::draw_fill(){

    glBegin(GL_TRIANGLES);

    for(unsigned int i = 0; i < Triangles.size() ; i++){

        for(int j = 0; j < 3; j++){

            glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);

        }

    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnd();

}

void _rotationfigure::draw_line(){

    glBegin(GL_LINES);

    for (unsigned int i = 0; i < Vertices.size(); i++){

        glVertex3fv((GLfloat *) &Vertices[i]);

    }

    for (unsigned int i = 4; i < Vertices.size(); i+=2){

        glVertex3fv((GLfloat *) &Vertices[i]);

    }

//    glVertex3fv((GLfloat *) &Vertices[18]);
//    glVertex3fv((GLfloat *) &Vertices[6]);

//    glVertex3fv((GLfloat *) &Vertices[9]);
//    glVertex3fv((GLfloat *) &Vertices[14]);

//    glVertex3fv((GLfloat *) &Vertices[14]);
//    glVertex3fv((GLfloat *) &Vertices[17]);

//    glVertex3fv((GLfloat *) &Vertices[9]);
//    glVertex3fv((GLfloat *) &Vertices[6]);

//    glVertex3fv((GLfloat *) &Vertices[8]);
//    glVertex3fv((GLfloat *) &Vertices[7]);

//    glVertex3fv((GLfloat *) &Vertices[19]);
//    glVertex3fv((GLfloat *) &Vertices[15]);

//    glVertex3fv((GLfloat *) &Vertices[7]);
//    glVertex3fv((GLfloat *) &Vertices[19]);

//    glVertex3fv((GLfloat *) &Vertices[15]);
//    glVertex3fv((GLfloat *) &Vertices[8]);


    // 18 6 6 9 9 14 17
    // 7 8 8 15 15 19 19 7

    glEnd();

}

