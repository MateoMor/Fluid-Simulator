#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

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
    void toggleDockWidget();

protected:
    // Esta función se llama cuando la ventana cambia de tamaño
    void resizeEvent(QResizeEvent *event) override;
private slots:
    void on_ButtonThrow_clicked();
    void on_ButtonExplosion_clicked();
    void on_ButtonDelete_clicked();
    void on_ButtonSplash_clicked();
    void on_ButtonSelect_clicked();
    void on_actionStart_triggered();
    void on_actionPause_triggered();
    void on_actionRestar_triggered();
    void on_actionForward_triggered();
    void on_actionBack_triggered();
    void on_actionLargeForward_triggered();
    void on_actionLargeBackward_triggered();
};


#endif // MAINWINDOW_H
