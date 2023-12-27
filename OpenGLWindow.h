#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include "Shape.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;

class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
signals:
    void shapesUpdated();
public:
    OpenGLWindow(const QColor& background, QWidget* parent);
    ~OpenGLWindow();

    void addShape(Shape inShape);

    void translate(std::vector<Point> shapePoints, int translateIndex);
    void rotate(std::vector<Point> shapePoints, int rotateIndex);
    void scale(std::vector<Point> shapePoints, int scaleIndex);
    void addClippingArea(Shape inShape);
    void clip();
    void updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors, int  flag);
    void writeStringToFile(const QString& text, const QString& filePath);
    void mouseMoveEvent(QMouseEvent* event);
    int mFlag;


protected:
    void paintGL() override;
    void initializeGL() override;

private:
    void reset();

private slots:
    void shaderWatcher();
    void updateAnimation();

    
private:
    int mflag;

    QTimer* mTimer;
    float mTimeValue;

    bool mAnimating = false;
    QOpenGLContext* mContext = nullptr;
    QOpenGLPaintDevice* mDevice = nullptr;

    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;

    QList<Shape> mShapes;
    QList<QVector3D> mNormals;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;

    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
    GLint m_scaleUniform = 0;
    GLint mTime = 0;

    QQuaternion rotationAngle;
    QPoint lastPos;

    QString readShader(QString filePath);
    QFileSystemWatcher* mShaderWatcher;

    QVector2D mScaleValue;


    Shape clippingArea;
    std::vector<Shape> shapes;
    std::vector<Shape> translatedShape;

    QVector<GLfloat> verticesOfOrignalLine;
    QVector<GLfloat> colorOfOrignalLine;
 
};
