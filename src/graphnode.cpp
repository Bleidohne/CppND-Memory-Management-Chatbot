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

    // Task 0: Warmup Task. _chatBot is already deleted as it is managed by ChatLogic and not GraphNode.
    // delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)   // Task 4: Use Unique_Pointer
{
    _childEdges.push_back(std::move(edge));     // Task 4: Use move to transfer ownership
}

//// STUDENT CODE
////
// Task 5: chatbot is now a unique pointer, so argument has to be changed (* removed). 
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);          // Task 5: Move chatbot around. 
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));      // Task 5: Move chatbot around. 
    // Task 5: This is not needed anymore. Chatbot cleares on it's own if it get's out of scope. 
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    // Task 4: Unique pointer should be returned: 
    return _childEdges[index].get();                // use the get() function of the smart pointer.

    ////
    //// EOF STUDENT CODE
}