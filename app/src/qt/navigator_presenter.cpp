/*
 navigator_presenter.cpp     MindForger thinking notebook

 Copyright (C) 2016-2018 Martin Dvorak <martin.dvorak@mindforger.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#include "navigator_presenter.h"

namespace m8r {

NavigatorPresenter::NavigatorPresenter(NavigatorView* view, QObject* parent, KnowledgeGraph* knowledgeGraph)
    : QObject(parent),
      view{view},
      knowledgeGraph{knowledgeGraph},
      // TODO improve configuration
      subgraph{knowledgeGraph->getNode(KnowledgeGraphNodeType::MIND), 150}
{
    // signals
    QObject::connect(view, SIGNAL(nodeSelectedSignal(NavigatorNode*)), this, SLOT(nodeSelectedSlot(NavigatorNode*)));
}

NavigatorPresenter::~NavigatorPresenter()
{
}

void NavigatorPresenter::showInitialView()
{
    knowledgeGraph->getRelatedNodes(knowledgeGraph->getNode(KnowledgeGraphNodeType::MIND), subgraph);
    view->refreshOnNextTimerTick(&subgraph);
}

void NavigatorPresenter::nodeSelectedSlot(NavigatorNode* node)
{
    knowledgeGraph->getRelatedNodes(node->getKnowledgeGraphNode(), subgraph);
    view->refreshOnNextTimerTick(&subgraph);
    switch(node->getKnowledgeGraphNode()->getType()) {
    case KnowledgeGraphNodeType::OUTLINE:
        emit outlineSelectedSignal(static_cast<Outline*>(node->getKnowledgeGraphNode()->getThing()));
        break;
    case KnowledgeGraphNodeType::NOTE:
        emit noteSelectedSignal(static_cast<Note*>(node->getKnowledgeGraphNode()->getThing()));
        break;
    default:
        emit thingSelectedSignal();
        break;
    }
}

} // m8r namespace
