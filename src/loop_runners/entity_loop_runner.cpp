#include "loop_runners/entity_loop_runner.h"
#include "core/entity.h"

namespace loopRunners {
    void EntityLoopRunner::AddEntity(std::shared_ptr<core::Entity> entity) {
        entities.emplace_back(entity);
    }

    void EntityLoopRunner::Update(double deltaTime) {
        for (auto &entity: entities)
        {
            entity->PreUpdate(deltaTime);
        }

        for (auto &entity: entities)
        {
            entity->Update(deltaTime);
        }

        for (auto &entity: entities)
        {
            entity->PostUpdate(deltaTime);
        }
    }

    void EntityLoopRunner::Render() {
        for (auto &entity: entities)
        {
            entity->PreRender();
        }

        for (auto &entity: entities)
        {
            entity->Render();
        }

        for (auto &entity: entities)
        {
            entity->PostRender();
        }
    }
}