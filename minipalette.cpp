#include "minipalette.h"
#include "ui_minipalette.h"

#include <QString>
#include <QPalette>
#include <QColor>

MiniPalette::MiniPalette(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MiniPalette)
{
    ui->setupUi(this);

    ui->redSlider->setMaximum(MAX_COLOR_SCALE);
    mRedController.bind(ui->redSlider, ui->redText, ui->colorViewer, ColorBase::RED);

    ui->greenSlider->setMaximum(MAX_COLOR_SCALE);
    mGreenController.bind(ui->greenSlider, ui->greenText, ui->colorViewer, ColorBase::GREEN);

    ui->blueSlider->setMaximum(MAX_COLOR_SCALE);
    mBlueController.bind(ui->blueSlider, ui->blueText, ui->colorViewer, ColorBase::BLUE);

    /* Set viewer to black */
    mRedController.setValue(0);
    mGreenController.setValue(0);
    mBlueController.setValue(0);
}

MiniPalette::~MiniPalette()
{
    delete ui;
}

void ColorController::setValue(int value)
{
    if (value > MAX_COLOR_SCALE) {
        value = MAX_COLOR_SCALE;
    }
    else if (value < 0) {
        value = 0;
    }
    this->mSlider->setValue(value);
    this->mText->setText(QString::number(value));

    /* Tried many times until finding this role is correct */
#define ROLE QPalette::Base

    QPalette pa = mTarget->palette();
    QColor oldColor = pa.color(ROLE);
    int oldRed = oldColor.red();
    int oldGreen = oldColor.green();
    int oldBlue = oldColor.blue();


#define MAX_ALPHA		255
    switch (mBase) {
    case ColorBase::RED:
        pa.setColor(ROLE, QColor(value, oldGreen, oldBlue, MAX_ALPHA));
        break;
    case ColorBase::GREEN:
        pa.setColor(ROLE, QColor(oldRed, value, oldBlue, MAX_ALPHA));
        break;
    case ColorBase::BLUE:
        pa.setColor(ROLE, QColor(oldRed, oldGreen, value, MAX_ALPHA));
        break;
    default:
        break;
    }
    mTarget->setPalette(pa);
}


/* Auto generated slot functions */
void MiniPalette::on_redSlider_valueChanged(int value)
{
    mRedController.setValue(value);
}

void MiniPalette::on_redText_textChanged(const QString &arg1)
{
    mRedController.setValue(arg1.toInt());
}

void MiniPalette::on_greenSlider_valueChanged(int value)
{
    mGreenController.setValue(value);
}

void MiniPalette::on_greenText_textChanged(const QString &arg1)
{
    mGreenController.setValue(arg1.toInt());
}

void MiniPalette::on_blueSlider_valueChanged(int value)
{
    mBlueController.setValue(value);
}

void MiniPalette::on_blueText_textChanged(const QString &arg1)
{
    mBlueController.setValue(arg1.toInt());
}
