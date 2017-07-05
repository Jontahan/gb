#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    emu = new emulator();
    connect(emu, SIGNAL(debug(QString)), SLOT(consolePrint(QString)));
    emu->play("/home/jonathaj/Downloads/Tetris (World)/Tetris (World).gb");

    lcdImage = new QImage(256, 256, QImage::Format_RGB32);

    /*
    QRgb* imgdata = (QRgb*)lcdImage->bits();
    for(int i = 0; i < 256 * 256; ++i)
        imgdata[i] = 0xff000000 | ((i / 256) << 8) | (i & 0xff);
    ui->lcdLabel->setPixmap(QPixmap::fromImage(*lcdImage));
    ui->lcdLabel->setFixedWidth(256);
    ui->lcdLabel->setFixedHeight(256);
    */

    connect(ui->refreshButton,SIGNAL(clicked(bool)),SLOT(updateLCD()));
    connect(ui->stepButton,SIGNAL(clicked(bool)),SLOT(stepCPU()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::consolePrint(QString str){
    ui->consoleEdit->append(str);
}

void MainWindow::stepCPU(){
    emu->step();
}

void MainWindow::updateLCD(){
    uint colors[4] = {0xff000000,0xff343434,0xff777777,0xffaaaaaa};

    //ui->consoleEdit->append("updating LCD...");
    auto frame = emu->getFrame(ui->spinBox->value());

    QRgb* imgdata = (QRgb*)lcdImage->bits();
    for(int i = 0; i < 256 * 256; ++i)
        imgdata[i] = colors[frame[i]];
    ui->lcdLabel->setPixmap(QPixmap::fromImage(*lcdImage));
}
