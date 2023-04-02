#include <GL/glut.h>
#include <stdio.h>

GLint LARGURA = 600,
      ALTURA = 600;

bool cinza = false;
bool preto = false;
bool branco = false;

void initGlut(int *argc, char **argv){
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(LARGURA, ALTURA);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Casinha");
}

void inicializacao(GLvoid){
    // Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
                //esquerda, direita, baixo, cima
    gluOrtho2D(0, LARGURA, ALTURA, 0);
}

void desenharBase(GLvoid){
    glLineWidth(5.0);

    // DESENHA A BASE AZUL
    glBegin(GL_QUADS);
        
        glColor3f(0.69f, 0.86f, 0.78f);
        glVertex2i(50, 550);
        glVertex2i(50, 350);
        glVertex2i(550, 350);
        glVertex2i(550, 550);
    glEnd();

    // DESENHA A PORTA BRANCA
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2i(275, 550);
        glVertex2i(325, 550);
        glVertex2i(325, 430);
        glVertex2i(275, 430);
    glEnd();

    // DESENHA PORTA GARAGEM
    glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2i(410, 550);
        glVertex2i(540, 550);
        glVertex2i(540, 400);
        glVertex2i(410, 400);
    glEnd();

    // DESENHA JANELA
    glBegin(GL_QUADS);
        glColor3f(0.36f, 0.59f, 0.73f);
        glVertex2i(75, 485);
        glVertex2i(175, 485);
        glVertex2i(175, 415);
        glVertex2i(75, 415);
    glEnd();
}

void desenharTelhado(GLvoid){

    //PARTE DO MEIO DO TELHADO
    glLineWidth(5.0);
    glBegin(GL_QUADS);
        glColor3f(0.31f, 0.33f, 0.34f);
        glVertex2i(125, 350);
        glVertex2i(125, 250);
        glVertex2i(475, 250);
        glVertex2i(475, 350);
    glEnd();

    //TRIANGULO ESQUERDO DO TELHADO
    glBegin(GL_TRIANGLES);
        glColor3f(0.31f, 0.33f, 0.34f);
        glVertex2i(125, 350);
        glVertex2i(30, 350);
        glVertex2i(125, 250);
    glEnd();

    //TRIANGULO DIREITO DO TELHADO
    glBegin(GL_TRIANGLES);
        glColor3f(0.31f, 0.33f, 0.34f);
        glVertex2i(475, 350);
        glVertex2i(570, 350);
        glVertex2i(475, 250);
    glEnd();

    //TRIANGULO INTERNO ESQUERDO
    glBegin(GL_TRIANGLES);
        glColor3f(0.69f, 0.86f, 0.78f);
        glVertex2i(50, 350);
        glVertex2i(125, 270);
        glVertex2i(200, 350);
    glEnd();

    //TRIANGULO INTERNO DIREITO
    glBegin(GL_TRIANGLES);
        glColor3f(0.69f, 0.86f, 0.78f);
        glVertex2i(400, 350);
        glVertex2i(475, 270);
        glVertex2i(550, 350);
    glEnd();

    //JANELA ESQUERDA

    glBegin(GL_QUADS);
        glColor3f(0.36f, 0.59f, 0.73f);
        glVertex2i(110, 334);
        glVertex2i(140, 334);
        glVertex2i(140, 304);
        glVertex2i(110, 304);
    glEnd();

    //JANELA DIREITA

    glBegin(GL_QUADS);
        glColor3f(0.36f, 0.59f, 0.73f);
        glVertex2i(460, 334);
        glVertex2i(490, 334);
        glVertex2i(490, 304);
        glVertex2i(460, 304);
    glEnd();

    //DETALHES JANELA ESQUERDA
    
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(124, 334);
        glVertex2i(126, 334);
        glVertex2i(126, 304);
        glVertex2i(124, 304);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(110, 320);
        glVertex2i(110, 318);
        glVertex2i(140, 318);
        glVertex2i(140, 320);
    glEnd();

    //DETALHE JANELA DIREITA

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(474, 334);
        glVertex2i(476, 334);
        glVertex2i(476, 304);
        glVertex2i(474, 304);
        
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(460, 320);
        glVertex2i(460, 318);
        glVertex2i(490, 318);
        glVertex2i(490, 320);
    glEnd();
        
    
}

void desenharBordaTelhado(GLvoid){
    glLineWidth(3.0);

    //BORDA DE FORA
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(30, 350);
        glVertex2i(50, 350);
        glVertex2i(125,270);
        glVertex2i(200,350);
        glVertex2i(400,350);
        glVertex2i(475,270);
        glVertex2i(550, 350);
        glVertex2i(570, 350);
        glVertex2i(475, 250);
        glVertex2i(125, 250);
        glVertex2i(30, 350);
        
    glEnd();

    //BORDA DE DENTRO LADO ESQUERDO
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(125, 250);
        glVertex2i(220, 350);
    glEnd();

    //BORDA DE DENTRO LADO DIREITO
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(380, 350);
        glVertex2i(475, 250);
    glEnd();

    //MAIS BORDA SO QUE ESQUERDA
     glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(50, 350);
        glVertex2i(200, 350);
    glEnd();

    //MAIS BORDA DA DIREITA
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(400, 350);
        glVertex2i(550, 350);
    glEnd();

    glLineWidth(2.0);
    //BORDA JANELA ESQUERDA;
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(110, 334);
        glVertex2i(110, 304);
        glVertex2i(140, 304);
        glVertex2i(140, 334);
    glEnd();

    //BORDA JANELA DIREITA;
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(460, 334);
        glVertex2i(460, 304);
        glVertex2i(490, 304);
        glVertex2i(490, 334);
    glEnd();

}

void desenharBordaBase(GLvoid){
    glLineWidth(3.0);

    //BORDA DE FORA
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(50, 550);
        glVertex2i(50, 350);
        glVertex2i(550, 350);
        glVertex2i(550, 550);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(200, 350);
        glVertex2i(200, 550);
        glVertex2i(400, 550);
        glVertex2i(400, 350);
    glEnd();

    //DESENHA BORDA JANELA
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(75, 485);
        glVertex2i(175, 485);
        glVertex2i(175, 415);
        glVertex2i(75, 415);
    glEnd();

    //BORDA INTERNA VERTICAL
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(123, 485);
        glVertex2i(127, 485);
        glVertex2i(127, 415);
        glVertex2i(123, 415);
    glEnd();

    //BORDA INTERNA HORIZONTAL
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(75, 448);
        glVertex2i(175, 448);
        glVertex2i(175, 452);
        glVertex2i(75, 452);
    glEnd();

    //BORDA PORTA
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(275, 550);
        glVertex2i(325, 550);
        glVertex2i(325, 430);
        glVertex2i(275, 430);
    glEnd();

    //BORDA PORTA GARAGEM
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2i(410, 550);
        glVertex2i(540, 550);
        glVertex2i(540, 400);
        glVertex2i(410, 400);
    glEnd();

    //BORDA INTERNA PORTA
    glBegin(GL_LINE_LOOP);
        glColor3f(0.7f, 0.74f, 0.72f);
        glVertex2i(285, 540);
        glVertex2i(315, 540);
        glVertex2i(315, 495);
        glVertex2i(285, 495);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.73f, 0.74f, 0.72f);
        glVertex2i(285, 445);
        glVertex2i(315, 445);
        glVertex2i(315, 485);
        glVertex2i(285, 485);
    glEnd();

    //BORDA INTERNA GARAGEM
    
    glBegin(GL_LINE_LOOP);
        glColor3f(0.73f, 0.74f, 0.72f);
        glVertex2i(420, 540);
        glVertex2i(420, 410);
        glVertex2i(530, 410);
        glVertex2i(530, 540);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.73f, 0.74f, 0.72f);
        glVertex2i(420, 435);
        glVertex2i(530, 435);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.73f, 0.74f, 0.72f);
        glVertex2i(420, 456);
        glVertex2i(530, 456);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.73f, 0.74f, 0.72f);
        glVertex2i(420, 477);
        glVertex2i(530, 477);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.73f, 0.74f, 0.72f);
        glVertex2i(420, 498);
        glVertex2i(530, 498);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(0.73f, 0.74f, 0.72f);
        glVertex2i(420, 519);
        glVertex2i(530, 519);
    glEnd();

    
}

void evento1(GLint button, GLint x, GLint y){
    if(button == GLUT_KEY_F1 && cinza == false)
    {
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        cinza = true;
        preto = false;
        branco = false;
    }
    glutPostRedisplay();
}

void evento2e3(char unsigned button, GLint x, GLint y)
{
    if (button == 0 && glutGetModifiers() == GLUT_ACTIVE_CTRL && branco)
    {
        if (branco || cinza)
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            branco = false;
            cinza = false;
            glutPostRedisplay();
        }
    }
    else
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        branco = true;
        cinza = false;
        glutPostRedisplay();
    }
}



void desenha(GLvoid){
    glClear(GL_COLOR_BUFFER_BIT);
    desenharBase();
    desenharTelhado();
    desenharBordaTelhado();
    desenharBordaBase();
    glutSpecialFunc(evento1);
    glutKeyboardFunc(evento2e3);  
    glFlush();
}


int main(int argc, char *argv[])
{   
    initGlut(&argc, argv);
    inicializacao();
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;
}
