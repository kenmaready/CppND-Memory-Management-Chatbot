#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include <memory>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    ChatBot _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    std::unique_ptr<GraphEdge> *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    // Note to reviewer: I switched the funcitionality of AddEdgeToParentNode
    // and AddEdgeToChildNode because they seemed backwards to me and it was difficult
    // to keep them straight:
    void AddEdgeToParentNode(std::unique_ptr<GraphEdge> edge);
    void AddEdgeToChildNode(GraphEdge *edge);

    //// STUDENT CODE
    ////

    // Note to reviewer: in the first review, I was told this function call was
    // supposed to take chatbot by value ainstead of reference, but when I changed it 
    // to do that, it caused an extra unneeded copy, and also resulted in a segmentation
    // fault when cpp window is closed, so I changed back to "&chatbot" to take by referece:
    void MoveChatbotHere(ChatBot &chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(std::unique_ptr<GraphNode> &newNode);
};

#endif /* GRAPHNODE_H_ */