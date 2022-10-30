#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "VisibleCamera.h"
#include "BackgroundGrid.h"
#include "netModel.h"

using namespace QSFML;
using namespace QSFML::Objects;
using namespace NeuronalNet;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    CanvasSettings settings;
    //settings.timing.frameTime = 100;
    //settings.layout.autoAjustSize = false;
    settings.layout.fixedSize = sf::Vector2u(300,100);
    settings.contextSettings.antialiasingLevel = 8;
    m_canvas_1 = new Canvas(ui->canvasWidget_1,settings);

    VisibleCamera *cam      = new VisibleCamera("Camera");
    BackgroundGrid *grid    = new BackgroundGrid("Grid");
    CanvasObject *obj       = new CanvasObject("Test");

    grid->setSize(sf::IntRect(0,0,1800,1600));
    grid->setLineColor({sf::Color(130,130,130),
                        sf::Color(100,100,100),
                        sf::Color(100,100,100),
                        sf::Color(100,100,100),
                        sf::Color(100,100,100)});
    cam->setMaxMovingBounds(sf::FloatRect(grid->getSize()));

    obj->addChild(grid);
    obj->addChild(cam);

    m_canvas_1->addObject(obj);

    m_xor = new XOR();
    m_canvas_1->addObject(m_xor);


}

MainWindow::~MainWindow()
{
    delete ui;
}


