#ifndef BITWOLF_ENGINE_TUTORIAL_H
#define BITWOLF_ENGINE_TUTORIAL_H


#include "../../utils/base/Scene.h"

class Tutorial : public Scene {
public:
    Tutorial();
    QString getName() override;
};


#endif //BITWOLF_ENGINE_TUTORIAL_H
