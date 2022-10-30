#pragma once

#include <vector>
#include "objects/CanvasObject.h"
#include "neuronalNet.h"
#include "netModel.h"

class XOR: public QSFML::Objects::CanvasObject
{
    public:
        XOR(const std::string &name = "XOR",
            CanvasObject *parent = nullptr);
        ~XOR();


        void update() override;
    private:
        void setup();

        NeuronalNet::BackpropNet *m_net;
        std::vector<NeuronalNet::Graphics::NetModel *> m_netModel;

        NeuronalNet::MultiSignalVector *m_trainigsSet;
        NeuronalNet::MultiSignalVector *m_resultSet;

        NeuronalNet::Debug::Timer m_trainigTimer;
        NeuronalNet::Debug::Timer m_learnTimer;

        float m_currentError;
        size_t m_iteration;
};
