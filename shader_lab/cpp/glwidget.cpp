#include "glwidget.hpp"
#include <QDebug>
#include "qt_bridge.hpp"

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    qDebug() << "OpenGL initialized";
}

void GLWidget::paintGL()
{
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    qDebug() << "Frame rendered";
}

void GLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}
