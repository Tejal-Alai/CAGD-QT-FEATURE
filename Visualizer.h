#pragma once


#include <QtWidgets/QMainWindow>
#include "Point.h"
#include <QPushButton>
#include <QSpinBox>
#include <vector>
#include "OpenGLWindow.h"

using namespace std;

class OpenGLWindow;
class ShapeContainer;

class Visualizer : public QMainWindow
{
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private slots:
    void addShape();
    void clippingArea();
    void clip();
    void addPoint();
    void translateShape();
    void rotateShape();
    void scaleShape();
    void drawBezierCurve();
    void drawHermiteCurve();
    void colorPicker();

public:
    vector <float> mVerticess;
    vector <float>  mColorss;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;



private:
    void setupUi();


private:

QWidget* mCentralWidget;
QWidget* mGridLayoutWidget;
QGridLayout* mGridLayout;
QPushButton* mAddShapeButton;
QPushButton* mAddClippingArea;
QPushButton* mClip;
QDoubleSpinBox* mShapeX;
QDoubleSpinBox* mShapeY;
QPushButton* mAddPoint;

QListWidget* mShapeListWidget;
OpenGLWindow* mRenderer;

QTabWidget* mTabWidget;
QWidget* mTranslateTab;
QDoubleSpinBox* mTranslateX;
QDoubleSpinBox* mTranslateY;
QPushButton* mTranslateButton;
QSpinBox* mShapeIndex;

QWidget* mRotateTab;
QDoubleSpinBox* mRotationAngle;
QPushButton* mRotateButton;
QSpinBox* mRotateShapeIndex;


QWidget* mScaleTab;
QDoubleSpinBox* mScaleFactor;
QPushButton* mScaleButton;
QSpinBox* mScaleShapeIndex;

QDoubleSpinBox* mX0;
QDoubleSpinBox* mY0;
QDoubleSpinBox* mX1;
QDoubleSpinBox* mY1;
QDoubleSpinBox* mX2;
QDoubleSpinBox* mY2;
QDoubleSpinBox* mX3;
QDoubleSpinBox* mY3;
QWidget* mBezierCurveTab;
QPushButton* mBezierCurveButton;
QPushButton* mHermiteCurveButton;

QWidget* mColorPalletTab;
QPushButton* mColorButton;


std::vector<Point> mPointList;

ShapeContainer* mShapeContainer;
};