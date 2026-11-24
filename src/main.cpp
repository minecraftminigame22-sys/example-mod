#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

void hideBtn(CCNode* parent, const std::string& id) {
    if (!parent) return;
    if (auto btn = typeinfo_cast<CCMenuItemSpriteExtra*>(parent->getChildByIDRecursive(id))) {
        btn->setCascadeOpacityEnabled(true);
        btn->setOpacity(0);
        btn->m_scaleMultiplier = 1.0f;
    }
}

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        hideBtn(this, "ai.predictivebuffer/button");
        return true;
    }
};

class $modify(PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        hideBtn(this, "ai.predictivebuffer/button");
    }
};
