#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//// STUDENT CODE
////

// Note to reviewer: in the first review, I was told this function call was
// supposed to take chatbot by value instead of reference (e.g., without the "&"), but when
// I changed it to do that, it caused an extra unneeded copy, and also resulted in a segmentation
// fault when cpp window is closed, so I changed back to "&chatbot" to take by referece.
void GraphNode::MoveChatbotHere(ChatBot &chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(std::unique_ptr<GraphNode> &newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

std::unique_ptr<GraphEdge> *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return &_childEdges[index];

    ////
    //// EOF STUDENT CODE
}