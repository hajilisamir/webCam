#include "widget.h"
#include "ui_widget.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QFileDialog>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mCamera = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    mLayout = new QVBoxLayout;
    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);
    ui->scrollArea->setLayout(mLayout);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_captureButton_clicked()
{
    auto filename = QFileDialog::getSaveFileName(this, "Capure", "/",
                                 "Image (*.jpg;*.jpeg)");
    if(filename.isEmpty()){
        return;
    }
    mCameraImageCapture->setCaptureDestination
            (QCameraImageCapture::CaptureToFile);
    QImageEncoderSettings imageEncoderSettigs;
    imageEncoderSettigs.setCodec("image/jpeg");
    imageEncoderSettigs.setResolution(1600, 1200);
    mCameraImageCapture->setEncodingSettings((imageEncoderSettigs));
    mCamera->setCaptureMode(QCamera::CaptureStillImage);
    mCamera->start();
    mCamera->searchAndLock();
    mCameraImageCapture->capture(filename);
    mCamera->unlock();
}

void Widget::on_stopButton_clicked()
{
    mCamera->stop();
}

void Widget::on_playButton_clicked()
{
    mCamera->start();
}
