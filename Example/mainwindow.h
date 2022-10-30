#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Canvas.h"
#include "XOR.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


    private:
        Ui::MainWindow *ui;
        QSFML::Canvas *m_canvas_1;

        XOR *m_xor;
};
#endif // MAINWINDOW_H
