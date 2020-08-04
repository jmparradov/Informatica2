#ifndef PAUSE_H
#define PAUSE_H

#include <QWidget>

namespace Ui {
class pause;
}

class pause : public QWidget
{
    Q_OBJECT

public:
    explicit pause(QWidget *parent = nullptr);
    ~pause();

private slots:
    void on_continuebutton_clicked();

    void on_savebutton_clicked();

    void on_loadbutton_clicked();

    void on_exitbutton_clicked();

private:
    Ui::pause *ui;
};

#endif // PAUSE_H
