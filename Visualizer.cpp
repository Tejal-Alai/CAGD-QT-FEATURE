#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "ShapeContainer.h"
#include "Clipping.h"
#include <QPushButton>
#include <QGridLayout>
#include <QInputDialog>
#include <iostream>
#include "Transform.h"
#include "BezeirCurve.h"
#include "Hermite.cpp"


Visualizer::Visualizer(QWindow *parent)  : QMainWindow(nullptr)
{
    mShapeContainer = new ShapeContainer();
   
    setupUi();
    connect(mRenderer, SIGNAL(shapesUpdated()), mRenderer, SLOT(update()));
}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi() {

resize(1100, 634);
mCentralWidget = new QWidget(this);
mGridLayoutWidget = new QWidget(mCentralWidget);
mGridLayout = new QGridLayout(mGridLayoutWidget);
mGridLayout->setSpacing(6);

mAddShapeButton = new QPushButton("Add Shape", mGridLayoutWidget);
mGridLayout->addWidget(mAddShapeButton, 0, 0, 1, 2);
connect(mAddShapeButton, &QPushButton::clicked, this, &Visualizer::addShape);

mAddClippingArea = new QPushButton("Add Clipping Area", mGridLayoutWidget);
mGridLayout->addWidget(mAddClippingArea, 0, 2, 1, 2);
connect(mAddClippingArea, &QPushButton::clicked, this, &Visualizer::clippingArea);

mClip = new QPushButton("Clip", mGridLayoutWidget);
mGridLayout->addWidget(mClip, 0, 4, 1, 2);
connect(mClip, &QPushButton::clicked, this, &Visualizer::clip);

QLabel* labelX = new QLabel("X: ", mGridLayoutWidget);
mGridLayout->addWidget(labelX, 1, 0, 1, 1);

mShapeX = new QDoubleSpinBox(mGridLayoutWidget);
mShapeX->setMinimum(-100.000000000000000);
mShapeX->setMaximum(100.000000000000000);
mGridLayout->addWidget(mShapeX, 1, 3, 1, 1);

QLabel* labelY = new QLabel("Y: ", mGridLayoutWidget);
mGridLayout->addWidget(labelY, 1, 2, 1, 1);

mShapeY = new QDoubleSpinBox(mGridLayoutWidget);
mShapeY->setMinimum(-100.000000000000000);
mShapeY->setMaximum(100.000000000000000);
mGridLayout->addWidget(mShapeY, 1, 1, 1, 1);

mAddPoint = new QPushButton("Add Point", mGridLayoutWidget);
mGridLayout->addWidget(mAddPoint, 1, 4, 1, 1);
connect(mAddPoint, &QPushButton::clicked, this, &Visualizer::addPoint);

mShapeListWidget = new QListWidget(mGridLayoutWidget);
mGridLayout->addWidget(mShapeListWidget, 2, 0, 1, 4);

mRenderer = new OpenGLWindow(QColor(0, 0, 0), mCentralWidget);
mGridLayout->addWidget(mRenderer, 2, 2, 1, 6);

mTabWidget = new QTabWidget(mGridLayoutWidget);
mGridLayout->addWidget(mTabWidget, 0, 8, 3, 1);

//Translate Tab
mTranslateTab = new QWidget();
mTabWidget->addTab(mTranslateTab, "Translate");

QLabel* labelTX = new QLabel("X: ", mTranslateTab);

labelTX->setGeometry(QRect(10, 50, 49, 16));

mTranslateX = new QDoubleSpinBox(mTranslateTab);
mTranslateX->setMinimum(-100.000000000000000);
mTranslateX->setMaximum(100.000000000000000);
mTranslateX->setGeometry(QRect(70, 50, 75, 22));

QLabel* labelTY = new QLabel("Y: ", mTranslateTab);

labelTY->setGeometry(QRect(10, 110, 49, 16));

mTranslateY = new QDoubleSpinBox(mTranslateTab);
mTranslateY->setMinimum(-100.000000000000000);
mTranslateY->setMaximum(100.000000000000000);
mTranslateY->setGeometry(QRect(70, 110, 62, 22));

mTranslateButton = new QPushButton( "Translate",mTranslateTab );
mTranslateButton->setGeometry(QRect(15, 170, 72, 24));
connect(mTranslateButton, &QPushButton::clicked, this, &Visualizer::translateShape);

QLabel* mSelectShapeLabel = new QLabel("Shape  Index:", mTranslateTab);
mSelectShapeLabel->setGeometry(QRect(10, 140, 71, 16));
mShapeIndex = new QSpinBox(mTranslateTab);
mShapeIndex->setGeometry(QRect(100, 140, 75, 22));


//rotate tab

mRotateTab = new QWidget();
mTabWidget->addTab(mRotateTab, "Rotate");

QLabel* labelAngle = new QLabel("Angle :", mRotateTab);
labelAngle->setGeometry(QRect(10, 70, 49, 16));

mRotationAngle = new QDoubleSpinBox(mRotateTab);
mRotationAngle->setMinimum(-100.000000000000000);
mRotationAngle->setMaximum(100.000000000000000);
mRotationAngle->setGeometry(QRect(90, 70, 62, 22));

mRotateButton = new QPushButton("Rotate", mRotateTab);
mRotateButton->setGeometry(QRect(12, 160, 78, 24));
connect(mRotateButton, &QPushButton::clicked, this, &Visualizer::rotateShape);

QLabel* mRotateSelectShapeLabel = new QLabel("Shape Index: ", mRotateTab);
mRotateSelectShapeLabel->setGeometry(QRect(10, 120, 71, 16));

mRotateShapeIndex = new QSpinBox(mRotateTab);
mRotateShapeIndex->setGeometry(QRect(90, 120, 42, 22));

//scale tab

mScaleTab = new QWidget();
mTabWidget->addTab(mScaleTab, "Scale");

QLabel* labelScaleFactor = new QLabel("Scale Factor :", mScaleTab);
labelScaleFactor->setGeometry(QRect(10, 70, 71, 16));

mScaleFactor = new QDoubleSpinBox(mScaleTab);
mScaleFactor->setMinimum(-100.000000000000000);
mScaleFactor->setMaximum(100.000000000000000);
mScaleFactor->setGeometry(QRect(90, 70, 62, 22));

mScaleButton = new QPushButton("Scale", mScaleTab);
mScaleButton->setGeometry(QRect(50, 173, 91, 31));
connect(mScaleButton, &QPushButton::clicked, this, &Visualizer::scaleShape);

QLabel* mScaleSelectShapeLabel = new QLabel("Shape Index: ", mScaleTab);
mScaleSelectShapeLabel->setGeometry(QRect(10, 120, 71, 16));
mScaleShapeIndex = new QSpinBox(mScaleTab);
mScaleShapeIndex->setGeometry(QRect(90, 120, 42, 22));

//bezeir and hermite curve

mBezierCurveTab = new QWidget();
mTabWidget->addTab(mBezierCurveTab, "Curves");

mX0 = new QDoubleSpinBox(mBezierCurveTab);
mX0->setMinimum(-100.000000000000000);
mX0->setMaximum(100.000000000000000);
mX0->setGeometry(QRect(10, 20, 62, 22));

mY0 = new QDoubleSpinBox(mBezierCurveTab);
mY0->setGeometry(QRect(100, 20, 42, 22));
mY0->setMinimum(-100.000000000000000);
mY0->setMaximum(100.000000000000000);

mX1 = new QDoubleSpinBox(mBezierCurveTab);
mX1->setGeometry(QRect(10, 60, 62, 22));
mX1->setMinimum(-100.000000000000000);
mX1->setMaximum(100.000000000000000);

mY1 = new QDoubleSpinBox(mBezierCurveTab);
mY1->setGeometry(QRect(100, 60, 62, 22));
mY1->setMinimum(-100.000000000000000);
mY1->setMaximum(100.000000000000000);

mX2 = new QDoubleSpinBox(mBezierCurveTab);
mX2->setGeometry(QRect(10, 100, 62, 22));
mX2->setMinimum(-100.000000000000000);
mX2->setMaximum(100.000000000000000);

mY2 = new QDoubleSpinBox(mBezierCurveTab);
mY2->setGeometry(QRect(100, 100, 62, 22));
mY2->setMinimum(-100.000000000000000);
mY2->setMaximum(100.000000000000000);

mX3 = new QDoubleSpinBox(mBezierCurveTab);
mX3->setGeometry(QRect(10, 140, 62, 22));
mX3->setMinimum(-100.000000000000000);
mX3->setMaximum(100.000000000000000);

mY3 = new QDoubleSpinBox(mBezierCurveTab);
mY3->setGeometry(QRect(100, 140, 62, 22));
mY3->setMinimum(-100.000000000000000);
mY3->setMaximum(100.000000000000000);

mBezierCurveButton = new QPushButton("Bezier Curve", mBezierCurveTab);
mBezierCurveButton->setGeometry(QRect(50, 173, 91, 31));
connect(mBezierCurveButton, &QPushButton::clicked, this, &Visualizer::drawBezierCurve);

mHermiteCurveButton = new QPushButton("Hermite Curve",mBezierCurveTab);
mHermiteCurveButton->setGeometry(QRect(50, 210, 91, 24));
connect(mHermiteCurveButton, &QPushButton::clicked, this, &Visualizer::drawHermiteCurve);

//color pallet
mColorPalletTab = new QWidget();
mTabWidget->addTab(mColorPalletTab, "Color");

mColorButton = new QPushButton("Color", mColorPalletTab);
mColorButton->setGeometry(QRect(50, 210, 91, 24));
connect(mColorButton, &QPushButton::clicked, this, &Visualizer::colorPicker);

setCentralWidget(mCentralWidget);

}



void Visualizer::addShape()
{
    Shape shape;
    shape.addPoints(mPointList);
    mShapeContainer->addShape(shape);
    mRenderer->addShape(shape);

    mPointList.clear();
    QString itemText = QString("Shape: %1").arg(mShapeContainer->getShapes().size());
    QListWidgetItem* newItem = new QListWidgetItem(itemText);
    mShapeListWidget->addItem(newItem);
}


void Visualizer::clippingArea()
{
    Shape shape;
    shape.addPoints(mPointList);
    mShapeContainer->addClippingArea(shape);
    mRenderer->addClippingArea(shape);
    mPointList.clear();
}

void Visualizer::clip()
{
    std::vector<Shape> shapes = mShapeContainer->getShapes();
    Shape clippingArea = mShapeContainer->getClippingArea();
    clippingArea.pointsToShape();
    int size = shapes.size();

    mRenderer->addShape(clippingArea);
    for (int i = 0; i < size; i++) {
        shapes.at(i).pointsToShape();
        Clipping cl(clippingArea, shapes.at(i));
        Shape clippedP = cl.getClippedPolygon();
        mRenderer->addShape(clippedP);
    }
}
void Visualizer::translateShape()
{
    std::vector<Shape> shapes= mShapeContainer->getShapes();
    int translateIndex = mShapeIndex->value();

    std::vector<Point> shapePoints = shapes[translateIndex-1].getPoints();

    double translateX = mTranslateX->value();
    double translateY = mTranslateY->value();
    Point translationPoint = Point(translateX, translateY, 0);
   
    Transform tf = Transform();
    tf.translate(shapePoints, translationPoint);
    mRenderer->translate(shapePoints, translateIndex);
}

void Visualizer::rotateShape()
{
    std::vector<Shape> shapes = mShapeContainer->getShapes();
    int rotateIndex = mRotateShapeIndex->value();

    std::vector<Point> shapePoints = shapes[rotateIndex-1].getPoints();

    double rotationAngle = mRotationAngle->value();

    Transform rotateShape = Transform();
    rotateShape.rotate(shapePoints, rotationAngle);

    mRenderer->rotate(shapePoints, rotateIndex);
}

void Visualizer::scaleShape()
{
    std::vector<Shape> shapes = mShapeContainer->getShapes();
    int scaleIndex = mScaleShapeIndex->value();

    std::vector<Point> shapePoints = shapes[scaleIndex - 1].getPoints();

    double scaleFactor = mScaleFactor->value();

    Transform scaleShape = Transform();
    scaleShape.scale(shapePoints, scaleFactor);

    mRenderer->scale(shapePoints, scaleIndex);

}

void Visualizer::drawBezierCurve()
{
    
    mVertices.clear();

    mColors.clear();

    mColorss.clear();

    mVerticess.clear();

    double pX0=mX0->value();
    double pY0=mY0->value();
    double pX1=mX1->value();
    double pY1=mY1->value();
    double pX2=mX2->value();
    double pY2=mY2->value();
    double pX3=mX3->value();
    double pY3=mY3->value();

    Point p0 = Point(pX0, pY0, 0);
    Point p1 = Point(pX1, pY1, 0);
    Point p2 = Point(pX2, pY2, 0);
    Point p3 = Point(pX3, pY3, 0);

    BezeirCurve bezier(p0, p1, p2, p3);
    bezier.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);
     mVertices<< p0.x()<< p0.y() << p0.z();
     mColors << 0.0f << 1.0f << 0.0f;
    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }
    mVertices << p3.x() << p3.y() << p3.z();
    mColors << 0.0f << 1.0f << 0.0f;
    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();

}

void Visualizer::addPoint()
{
    double x = mShapeY->value();
    double y = mShapeX->value();
    Point p = Point(x, y, 0);
    mPointList.push_back(p);
}

void Visualizer::drawHermiteCurve()
{

    mVertices.clear();

    mColors.clear();

    mColorss.clear();

    mVerticess.clear();

    double pX0 = mX0->value();
    double pY0 = mY0->value();
    double pX1 = mX1->value();
    double pY1 = mY1->value();
    double pX2 = mX2->value();
    double pY2 = mY2->value();
    double pX3 = mX3->value();
    double pY3 = mY3->value();

    Point p0 = Point(pX0, pY0, 0);
    Point p1 = Point(pX1, pY1, 0);
    Point p2 = Point(pX2, pY2, 0);
    Point p3 = Point(pX3, pY3, 0);

    Hermite hermite(p0, p1, p2, p3);
    hermite.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);

    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }
    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}

void Visualizer::colorPicker()
{
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor();
    if (selectedColor.isValid())
    {
        int red = selectedColor.red();
        int green = selectedColor.green();
        int blue = selectedColor.blue();
        int alpha = selectedColor.alpha();
        QString color = QString("%1, %2, %3, %4").arg(red).arg(green).arg(blue).arg(alpha);
        mRenderer->writeStringToFile(color, "FragmentShader.glsl");
    }
}