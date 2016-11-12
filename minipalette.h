#ifndef MINIPALETTE_H
#define MINIPALETTE_H

#include <QMainWindow>
#include <QSlider>
#include <QLineEdit>

namespace Ui {
class MiniPalette;
}

#define MAX_COLOR_SCALE 	255

namespace ColorBase {
enum Base {
    RED   = 1,
    GREEN = 2,
    BLUE  = 3,
};
}

struct ColorController
{
   QSlider*   mSlider;
   QLineEdit* mText;
   QWidget*   mTarget;
   ColorBase::Base mBase;

   void bind(QSlider* slider, QLineEdit* text, QWidget* target, ColorBase::Base base)
   {
       mSlider = slider;
       mText = text;
       mTarget = target;
       mBase = base;
   }

   void setValue(int value);
};

class MiniPalette : public QMainWindow
{
    Q_OBJECT

public:
    explicit MiniPalette(QWidget *parent = 0);
    ~MiniPalette();

private slots:
    void on_redSlider_valueChanged(int value);

    void on_redText_textChanged(const QString &arg1);

    void on_greenSlider_valueChanged(int value);

    void on_greenText_textChanged(const QString &arg1);

    void on_blueSlider_valueChanged(int value);

    void on_blueText_textChanged(const QString &arg1);

private:
    Ui::MiniPalette *ui;

    ColorController mRedController;
    ColorController mGreenController;
    ColorController mBlueController;
};

#endif // MINIPALETTE_H
