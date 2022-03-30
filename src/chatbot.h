#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>


class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation


    //// STUDENT CODE
    ////
    // Task 2: Implementing the Rule of 5: (Based on Udacity Skript / Tutorial Material)
        // 1) Define appropriate Destructor
        // 2) Overload assignment operator for shallow copy
        // 3) Overload Copy constructor for shallow copy
        // 4) Create Move constructor for transfering ownership
        // 5) Overload assignment operator for moving ressource ownership

    ~ChatBot();                                 // Destructor (Rule 1)
    ChatBot &operator=(const ChatBot &source);  // Copy Operator (Rule 2)
    ChatBot(const ChatBot &source);             // Copy Constructor (Rule 3)
    ChatBot(ChatBot &&source);                  // Move Constructor (Rule 4)
    ChatBot &operator=(ChatBot &&source);       // Move Operator (Rule 5)

    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic* GetChatLogicHandle() { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
