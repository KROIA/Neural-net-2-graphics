#pragma once

#include "graphicsUtilities.h"
#include "backend/graphicsNeuronInterface.h"
#include "components/Drawable.h"


namespace NeuronalNet
{
	namespace Graphics
	{
		using std::string;

        class NeuronPainter	:	public QSFML::Components::Drawable, public GraphicsNeuronInterface
		{
			public:
			NeuronPainter();
			NeuronPainter(const NeuronPainter& other);
			~NeuronPainter();

			const NeuronPainter& operator=(const NeuronPainter& other);

            static size_t getStandardVisualConfiguration();

			void setPos(const sf::Vector2f& pos);
			const sf::Vector2f& getPos() const;
			void setSize(float size);
			float getSize() const;

			//virtual void setOptimization(Optimization opt);
			


			// Interface implementation
            void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

            virtual void updateNeuron(float netinput, float output,
                                      float minN, float maxN,
                                      float minO, float maxO) override;

			static const float standardSize;
			protected:

			sf::Color m_color;
			sf::Text  m_outputText;
			sf::Vector2f m_pos;
			float m_size;

			sf::CircleShape m_circleShape;

			static const string m_fontPath;
			static sf::Font m_font;

			// Data from Net
			float m_netinput;
			float m_output;

            // What will be showed, enable/disable specific functions
            size_t m_visualConfiguration;

			// Performance settings
			//bool m_useTextLabel; 
			
		};
	};
};







