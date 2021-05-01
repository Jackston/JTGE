/******************************************************************************
MIT License

Copyright (c) 2021 Jackston

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#include "JTGE/Engine.hpp"
#include "JTGE/IGameCore.hpp"
#include "Renderer/TerminalRenderer.hpp"

namespace JTGE {

class Engine::ImplT
{
public:
    ImplT(std::unique_ptr<IGameCore> game)
        : m_game(std::move(game))
        , m_renderer()
    {
        if (m_game != nullptr)
        {
            m_game->config();
        }
    }

    void run(const Engine& self)
    {
        if (m_game == nullptr)
        {
            return;
        }

        m_game->initialize();
        runGameLoop();
        m_game->deinitialize();
    }

private:
    void runGameLoop()
    {
        while (true)
        {
            m_game->update(0.0f);
            m_game->render(m_renderer);

            break; //tmp
        }
    }

private:
    std::unique_ptr<IGameCore> m_game;
    TerminalRenderer m_renderer;
};

Engine::Engine(std::unique_ptr<IGameCore> game)
    : m_pImpl(std::make_unique<ImplT>(std::move(game)))
{}

Engine::~Engine() = default;

void Engine::run()
{
    m_pImpl->run(*this);
}

} // namespace JTGE
