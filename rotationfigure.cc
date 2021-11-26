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

    int n_caras = n;
    //double vuelta_completa = M_PI * 4;

    _vertex3f verteaux;

    _vertex3f aux;
    //calculo el angle inicial (angle de partida)
    float angle_ini = (2*M_PI)/n_caras;
    //calculo el nuevo angle (angle de referencia a sumar)
    float angle_modi = (2*M_PI)/n_caras;
    int tam = Vertices.size(), cont_c=0;
    for(int i=0; i<n_caras*tam; ++i){

        ++cont_c;
        Vertices.push_back(_vertex3f(Vertices[i%tam].x*cos(angle_ini),
                                    Vertices[i%tam].y,
                                    Vertices[i%tam].x*sin(angle_ini)));

        Vertices[tam+i]=_vertex3f(Vertices[i%tam].x*cos(angle_ini),
                                Vertices[i%tam].y,
                                Vertices[i%tam].x*sin(angle_ini));

        if(cont_c==tam){
            angle_ini+=angle_modi;
            cont_c=0;
        }
    }

    // CREACION TRIANGULOS o GENERACION DE CARAS

//    int numero_caras = n;
//    int vertex_n = Vertices.size();

//    Triangles.clear();

//    for(int i = 0; i < numero_caras; i++){

//        // CARA PARs
//        Triangles.push_back(_vertex3ui((vertex_n*i+0)+1, (vertex_n*i+0), (i+1)*vertex_n+0));
//        // CARA IMPAR
//        Triangles.push_back(_vertex3ui((i+1)*vertex_n+0, (i+1)*vertex_n+(0+1), (i*vertex_n+0)+1));

//    }

//    _vertex3ui vertaux;

//    // TAPA SUPERIOR

//    for(unsigned int i=0; i<Vertices.size(); i+=2){

//        vertaux._0= Vertices.size()-1;
//        vertaux._1= i;
//        vertaux._2= (i+2)%(Vertices.size()-1);
//        Triangles.push_back(vertaux);

//    }

//    // TAPA INFERIOR

//    for(unsigned int i=1; i<Vertices.size(); i+=2){

//        vertaux._0= Vertices.size()-1;
//        vertaux._1= (i+2)%(Vertices.size()-2);
//        vertaux._2= i;
//        Triangles.push_back(vertaux);

//    }

    int j=0,cara=0, mod=(n_caras+1)*tam;
    //int indice=0, pos_t=0;
    int tope = mod*2;
    Triangles.resize(tope);
    for(int i=0;i<mod;++i){
        if(cara<n_caras){
            ++cara;
        }else{
            cara=0;
            ++j;
        }
            if(cara%2){
                //creamos la tapa inferior y sus caras (superior)
                Triangles[i*2]=_vertex3ui(((i*tam)+j)%mod,(((i+1)*tam)+j)%mod,((i*tam)+j+1)%mod);
                //creamos la tapa superior y sus caras (inferior)
                Triangles[(2*i)+1]=_vertex3ui((((i+1)*tam)+j)%mod,(((i+1)*tam)+j+1)%mod,((i*tam)+j+1)%mod);
            }else{
                //creamos la tapa inferior y sus caras (superior)
                Triangles[(2*i)+1]=_vertex3ui(((i*tam)+j)%mod,(((i+1)*tam)+j)%mod,((i*tam)+j+1)%mod);
                //creamos la tapa superior y sus caras (inferior)
                Triangles[i*2]=_vertex3ui((((i+1)*tam)+j)%mod,(((i+1)*tam)+j+1)%mod,((i*tam)+j+1)%mod);
            }
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

    for(unsigned int i = 0; i < Triangles.size() ; i++){

        for(int j = 0; j < 3; j++){

            glVertex3fv((GLfloat *) &Vertices[Triangles[i][j]]);

        }

    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
    glEnd();


}

