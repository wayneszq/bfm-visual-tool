#pragma once
/*********************************************************************

Author: Bemfoo
Date: 2019-10-26
Description: The main widget window of Basel face model visual tool.

**********************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <qslider.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qstatusbar.h>
#include "OpenGLWidget.h"
#include "bfm.h"

class QSlider;
class QPushButton;
class QLabel;
class QComboBox;
class QOpenGLWidget;
class QKeyEvent;
class QWheelEvent;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

	void keyPressEvent(QKeyEvent *event);
	void wheelEvent(QWheelEvent *event);

private slots: 
	void generateRandomFace();
	void synShapeSlider();
	void synTexSlider();
	void setShapePc();
	void setTexPc();
	void savePly();

private:
	Ui::MainWindowClass ui;
	
	OpenGLWidget *openGLWidget;
	QPushButton *genRndFaceBtn;
	QPushButton *savePlyBtn;
	QPushButton *setShapePcBtn;
	QPushButton *setTexPcBtn;
	
	QSlider *shapeSlider;
	QSlider *texSlider;
	QSlider	*rndRangeSlider;

	QComboBox *shapeComboBox;
	QComboBox *texComboBox;

	QTextEdit *saveFilename;

	void initUI();
	void initSignalSlots();
};
