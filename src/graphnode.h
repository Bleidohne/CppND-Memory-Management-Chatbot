#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <vector>
#include <string>
#include "chatbot.h"
#include <memory>     // Task 4: Include needed for smart pointers. 


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    // Task 4: Make edges unique: 
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;
    // std::vector<GraphEdge *> _childEdges;  // edges to subsequent nodes

    // data handles (not owned)
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 
    ChatBot _chatBot;                      // Task 5: Remove *. 

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
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);                      // Task 4: No change, parent is only reference.
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);       // Task 4: Use unique_pointer to own child node 

    //// STUDENT CODE
    ////

    void MoveChatbotHere(ChatBot chatbot);                          // Task 5: chatbot is now a unique pointer, so argument has to be changed (* removed). 

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */