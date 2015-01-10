#ifndef STATE_H
#define STATE_H

namespace State
{
class TcpOctetStream;
class TcpState;

class TcpConnection
{
public:
    TcpConnection();
    void ActiveOpen();
    void PassiveOpen();
    void Close();
    void Send();
    void Acknowledge();
    void Synchronize();
    void ProcessOctet(TcpOctetStream*);

private:
    void ChangeState(TcpState*);

private:
    TcpState* _state;
    friend class TcpState;
};

class TcpState
{
public:
    virtual void ActiveOpen(TcpConnection*);
    virtual void PassiveOpen(TcpConnection*);
    virtual void Close(TcpConnection*);
    virtual void Send(TcpConnection*);
    virtual void Acknowledge(TcpConnection*);
    virtual void Synchronize(TcpConnection*);
    virtual void Transit(TcpConnection*, TcpOctetStream*);

protected:
    void ChangeState(TcpConnection*, TcpState*);
};

class TcpClosed : public TcpState
{
public:
    static TcpState* GetInstance();
    virtual void ActiveOpen(TcpConnection*);
    virtual void PassiveOpen(TcpConnection*);
};

class TcpListen : public TcpState
{
public:
    static TcpState* GetInstance();
    virtual void Send(TcpConnection*);
};

class TcpEstablished : public TcpState
{
public:
    static TcpState* GetInstance();
    virtual void Close(TcpConnection*);
    virtual void Transit(TcpConnection*, TcpOctetStream*);
};

void TestState();

}
#endif // STATE_H
