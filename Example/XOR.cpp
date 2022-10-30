#include "XOR.h"
using namespace QSFML;
using namespace QSFML::Objects;
using namespace NeuronalNet;

XOR::XOR(const std::string &name,
         CanvasObject *parent)
    :   CanvasObject(name, parent)
{
    setup();
}
XOR::~XOR()
{

}

void XOR::update()
{
    ++m_iteration;
    m_trainigTimer.unpause();
    m_net->setInputVector(*m_trainigsSet);
    m_net->calculate();
    if(m_iteration == 1)
        m_learnTimer.start();
    m_learnTimer.unpause();
    m_net->learn(*m_resultSet);
    m_learnTimer.pause();
    m_trainigTimer.pause();

    MultiSignalVector err = m_net->getError();
    m_currentError = err.getRootMeanSquare();

    //m_net->setLearnParameter(m_currentError);

    if (m_iteration%100 == 0)
    {
        std::cout << "iteration [" << m_iteration << "]\t Error: " << m_currentError << "\tTrainigtime: "
                  << m_trainigTimer.getMillis() << " ms\tlearnTime: "<< m_learnTimer.getMicros()/(double)m_iteration<< " us/training " <<"\n";
    }
}

void XOR::setup()
{
    m_currentError = 0;
    m_iteration = 0;
    m_trainigsSet = new MultiSignalVector(4,2);
    m_resultSet   = new MultiSignalVector(4,1);

    (*m_trainigsSet)[0] = SignalVector(vector<float>{ 0,0 });
    (*m_trainigsSet)[1] = SignalVector(vector<float>{ 0,1 });
    (*m_trainigsSet)[2] = SignalVector(vector<float>{ 1,0 });
    (*m_trainigsSet)[3] = SignalVector(vector<float>{ 1,1 });

    (*m_resultSet)[0] = SignalVector(vector<float>{ 0 });
    (*m_resultSet)[1] = SignalVector(vector<float>{ 1 });
    (*m_resultSet)[2] = SignalVector(vector<float>{ 1 });
    (*m_resultSet)[3] = SignalVector(vector<float>{ 0 });

    m_net = new BackpropNet();
    m_net->setDimensions(2, 1, 3, 1);
    m_net->setStreamSize(m_trainigsSet->size());
    m_net->setActivation(Activation::sigmoid);
    m_net->setHardware(Hardware::cpu);
    m_net->setLearnParameter(1.0);
    m_net->enableBias(true);
    m_net->build();

    sf::Vector2f spacing(80, 20);
    float neuronSize = 15;

    Graphics::NetModel *model1 = new Graphics::NetModel(m_net);
    model1->setStreamIndex(0);
    model1->setNeuronSize(neuronSize);
    model1->setPos(sf::Vector2f(100, 100));
    model1->setNeuronSpacing(spacing);
    m_netModel.push_back(model1);

    Graphics::NetModel *model2 = new Graphics::NetModel(m_net);
    model2->setStreamIndex(1);
    model2->setNeuronSize(neuronSize);
    model2->setPos(sf::Vector2f(100, 500));
    model2->setNeuronSpacing(spacing);
    m_netModel.push_back(model2);

    Graphics::NetModel *model3 = new Graphics::NetModel(m_net);
    model3->setStreamIndex(2);
    model3->setNeuronSize(neuronSize);
    model3->setPos(sf::Vector2f(1100, 100));
    model3->setNeuronSpacing(spacing);
    m_netModel.push_back(model3);

    Graphics::NetModel *model4 = new Graphics::NetModel(m_net);
    model4->setStreamIndex(3);
    model4->setNeuronSize(neuronSize);
    model4->setPos(sf::Vector2f(1100, 500));
    model4->setNeuronSpacing(spacing);
    m_netModel.push_back(model4);

    addChild(model1);
    addChild(model2);
    addChild(model3);
    addChild(model4);
}
