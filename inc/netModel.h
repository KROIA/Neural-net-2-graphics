#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "components/Drawable.h"
#include "objects/CanvasObject.h"

#include "backend/net.h"
#include "neuronPainter.h"
#include "connectionPainter.h"
#include "pixelPainter.h"

namespace NeuronalNet
{
	namespace Graphics
	{
		using std::vector;

        class NetModel : public QSFML::Objects::CanvasObject
		{
                class NetModelPainter;
                friend NetModelPainter;
			public:

			

			NetModel(Net* net);
			~NetModel();

			void build();
			void setVisualConfiguration(size_t conf);
            static size_t getStandardVisualConfiguration();

			void setStreamIndex(size_t index);
			size_t getStreamIndex() const;

			void setPos(const sf::Vector2f& pos);
			const sf::Vector2f& getPos() const;

			void setNeuronSpacing(const sf::Vector2f& sp);
			const sf::Vector2f& getNeuronSpacing();

			void setConnectionWidth(float w);
			void setSignalWidth(float w);
			void setNeuronSize(float size);

			float getConnectionWidth() const;
			float getSignalWidth() const;
			float getNeuronSize() const;

            void update() override;

			//void setOptimization(Optimization opt);
			//void setVisualConfiguration(size_t conf);

           // void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
            //void drawDebug(sf::RenderWindow* window,
         //				   const sf::Vector2f& offset = sf::Vector2f(0, 0));

            void updateGraphics();
			protected:
			void clear();
			void updateNeuronDimensions();

			//void internal_neuronSize(float size);

			vector<GraphicsNeuronInterface*> m_neuronInterface;	
			vector<NeuronPainter*> m_neuronList;					// All Neurons
			vector<NeuronPainter*> m_inputNeurons;					
			vector<vector<NeuronPainter*> > m_hiddenNeurons;
			vector<NeuronPainter*> m_outputNeurons;

			vector<GraphicsConnectionInterface*> m_connectionInterface;
			vector<ConnectionPainter*> m_connectionList;
			vector<PixelPainter*> m_pixelPainterList;

            vector<QSFML::Components::Drawable*> m_drawableList; // All drawable Objects

			const Net* m_net;

			float m_connectionWidth;
			float m_signalWidth;
			float m_neuronSize;
			size_t m_streamIndex;

			//sf::Vector2f m_pos;
			sf::Vector2f m_neuronSpacing;
            size_t m_visualConfiguration;
            sf::Vector2f m_pos;

            NetModelPainter *m_modelPainter;

            private:
            class NetModelPainter: public QSFML::Components::Drawable
            {
                public:
                    NetModelPainter(const std::string &name = "NetModelPainter");
                    NetModelPainter(const Drawable &other);
                    ~NetModelPainter();

                    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

                    NetModel *m_model;
            };

		};


	};
};
