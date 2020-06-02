#include <string>
#include <vector>
#include <QWidget>
#pragma once
class Message {
public:
	std::string message;
};

class User {
public:
	std::string uniqueUsername;
	std::string name;
};

class UserMessage : public Message, public User {

};

class ChatSession: public ChatWindow{
public:
	void addMessage(User _u, Message _m);
	UserMessage getMessages();
};

class ChatWindow: public QWidget,  public User, public Observer, public ChatSession{
public:
	void update();
	void sendMessage();
};


class Subject : public ChatSession{
private:
	std::vector<Observer*> listObs;
public:
	Subject();
	~Subject();
	void registerObserver(Observer* _obs);
	void unregisterObserver(Observer* _obs);
	void notify();
};

class Observer {
public:
	virtual void update() = 0;
};