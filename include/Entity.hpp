#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <functional>

namespace sf {

class Entity : public sf::Sprite {
private:
    std::string m_name;
    std::function<void(const std::string &)> m_signalCallback;

protected:
    void sendSignal(const std::string &signal);
    void setName(const std::string &name);

public:
    Entity();
    ~Entity();
    virtual void input(const Event &event);
    virtual void process(float delta);
    virtual void fixedProcess();
    virtual void onCollision(const Entity &entity);
    virtual void onSignal(const std::string &signal);
    virtual const std::vector<sf::FloatRect> getBounds() const;

    const std::string &getName() const;
    void setSignalCallback(const std::function<void(const std::string &)> &func);
    bool collidesWith(const sf::Entity &other) const;
};

}

#endif