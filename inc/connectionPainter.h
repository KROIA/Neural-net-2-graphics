#pragma once



#include "backend/graphicsConnectionInterface.h"
#include "neuronPainter.h"
#include "components/Drawable.h"

namespace NeuronalNet
{
	namespace Graphics
	{
        class ConnectionPainter : public QSFML::Components::Drawable, public GraphicsConnectionInterface
		{
			public:
			ConnectionPainter(NeuronPainter* a,
					   NeuronPainter* b);
			~ConnectionPainter();


            static size_t getStandardVisualConfiguration();
			
			void setConnectionWidth(float w);
			void setSignalWidth(float w);
			float getConnectionWidth() const;
			float getSignalWidth() const;

			//void setOptimization(Optimization opt);
			void setWeightAlpha(uint8_t alpha);
			uint8_t getWeightAlpha() const;
			void setSignalAlpha(uint8_t alpha);
			uint8_t getSignalAlpha() const;


			// Interface implementation
            void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

            void updateConnection(float weight, float signal,
                                  float minW, float maxW,
                                  float minS, float maxS) override;

			
			static float getStandardConnectionWidth();
			static float getStandardSignalWidth();

			protected:
			void setLinePos(sf::ConvexShape& line,float width);

			NeuronPainter* m_startNeuron;
			NeuronPainter* m_endNeuron;

			sf::Color m_weightColor;
			sf::Color m_signalColor;

			sf::ConvexShape m_connectionLine;
			sf::ConvexShape m_singalLine;

			float m_connectionWidth;
			float m_signalWidth;

			float m_weight;
			float m_signal;

			static float m_globalMinSignal;
			static float m_globalMaxSignal;

			static const float m_standardConnectionWidth;
			static const float m_standardSignalWidth;

            size_t m_visualConfiguration;

			// Performance settings
			// bool m_useWeightAsConnection;

		};
	};
};
