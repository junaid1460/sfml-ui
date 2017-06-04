#include<cmath>
#include<algorithm>
#include <SFML/Graphics.hpp>
namespace crook{
    namespace shapes {
        class  RoundedRectagle: public sf::Shape
        {
            public:
            int t = 30;
            EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0))
            {
                this->m_radius = radius;
                update();
            }

            void setRadius(const sf::Vector2f& radius)
            {
                m_radius = radius;
                update();
            }

            const sf::Vector2f& getRadius() const
            {
                return m_radius;
            }

            virtual unsigned int getPointCount() const
            {
                return this->t; // fixed, but could be an attribute of the class if needed
            }

            virtual sf::Vector2f getPoint(unsigned int index) const
            {
                static const float pi = 3.141592654f;

                float angle = index * 2 * pi / getPointCount() - pi / 2;
                float x = std::cos(angle) * m_radius.x;
                float y = std::sin(angle) * m_radius.y;

                return sf::Vector2f(m_radius.x + x, m_radius.y + y);
            }

        private:

            sf::Vector2f m_radius;
        };

    }
}