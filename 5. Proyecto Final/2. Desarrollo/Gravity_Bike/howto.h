#ifndef HOWTO_H
#define HOWTO_H

#include <QWidget>

namespace Ui {
class Howto;
}

class Howto : public QWidget
{
    Q_OBJECT

public:
    explicit Howto(QWidget *parent = nullptr);
    ~Howto();

private slots:
    void on_backbutton_clicked();

private:
    Ui::Howto *ui;
};

#endif // HOWTO_H
