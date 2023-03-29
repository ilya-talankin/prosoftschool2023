#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), mainTimer(this)
{
    //установка временного интервала между появлениями снежинок
    quint32 interval = QRandomGenerator::global()->bounded(100, 1000);
    mainTimer.setInterval(interval);
    //лямбда для создания снежинки
    auto createButton = [this](){

        //создание
        QPushButton* snowFlake = new QPushButton("*", this);
        snowFlake->resize(FLAKESIZE, FLAKESIZE);

        //перемещение
        quint32 x = QRandomGenerator::global()->bounded(0, this->width() - FLAKESIZE);
        quint32 y = QRandomGenerator::global()->bounded(0, 100);
        snowFlake->move(x, y);
        snowFlake->show();

        //установка нового временного интервала между появлениями снежинок
        quint32 interval = QRandomGenerator::global()->bounded(100, 1000);
        this->mainTimer.setInterval(interval);

        //создание таймера для перемещения снежинки на 1 или 2 пикселя
        QTimer* timer = new QTimer(this);
        qint32 timeInterval = QRandomGenerator::global()->bounded(10, 100);
        timer->setInterval(timeInterval);

        //лямбда для перемещения
        auto stepOut = [this, snowFlake](){
            int x = snowFlake->x();
            int y = snowFlake->y();

            //проверка на проигрыш
            if (y > this->height() - FLAKESIZE) {
                QPalette pal = QPalette();
                pal.setColor(QPalette::Window, Qt::red);
                this->setAutoFillBackground(true);
                this->setPalette(pal);

                snowFlake->deleteLater();
                QWidget::setWindowTitle ("You LOOSE!");
            } else {
                short dy = 1;
                if (snowFlake->underMouse())
                    ++dy;
                snowFlake -> move(x, y + dy);
            }
        };
        QObject::connect(timer, &QTimer::timeout, snowFlake, stepOut);
        timer->start();

        QObject::connect(snowFlake, &QPushButton::clicked, snowFlake, &QPushButton::deleteLater);

    };
    QObject::connect(&mainTimer, &QTimer::timeout, createButton);
    mainTimer.start();
}
MainWindow::~MainWindow()
{
}

