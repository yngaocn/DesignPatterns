#include "State.h"
#include <iostream>

namespace State
{

TcpConnection::TcpConnection()
{
    _state=TcpClosed::GetInstance();
}

void TcpConnection::ActiveOpen()
{
    _state->ActiveOpen(this);
}

void TcpConnection::PassiveOpen()
{
    _state->PassiveOpen(this);
}

void TcpConnection::Close()
{
    _state->Close(this);
}

void TcpConnection::Send()
{
    _state->Send(this);
}

void TcpConnection::Acknowledge()
{
    _state->Acknowledge(this);
}

void TcpConnection::Synchronize()
{
    _state->Synchronize(this);
}

void TcpConnection::ProcessOctet(TcpOctetStream* stream)
{
    std::cout<<"process octet"<<std::endl;
}

void TcpConnection::ChangeState(TcpState* state)
{
    _state=state;
}

void TcpState::ActiveOpen(TcpConnection*)
{
}

void TcpState::PassiveOpen(TcpConnection*)
{
}

void TcpState::Close(TcpConnection*)
{
}

void TcpState::Send(TcpConnection*)
{
}

void TcpState::Acknowledge(TcpConnection*)
{
}

void TcpState::Synchronize(TcpConnection*)
{
}

void TcpState::Transit(TcpConnection*, TcpOctetStream*)
{
}

void TcpState::ChangeState(TcpConnection* conn, TcpState* state)
{
    conn->ChangeState(state);
}

TcpState* TcpClosed::GetInstance()
{
    static TcpClosed state;
    return &state;
}

void TcpClosed::ActiveOpen(TcpConnection* conn)
{
    std::cout<<"TcpClosed::ActiveOpen"<<std::endl;
    ChangeState(conn, TcpEstablished::GetInstance());
}

void TcpClosed::PassiveOpen(TcpConnection* conn)
{
    std::cout<<"TcpClosed::PassiveOpen"<<std::endl;
    ChangeState(conn, TcpListen::GetInstance());
}

TcpState* TcpListen::GetInstance()
{
    static TcpListen state;
    return &state;
}

void TcpListen::Send(TcpConnection* conn)
{
    std::cout<<"TcpListen::Send"<<std::endl;
    ChangeState(conn, TcpEstablished::GetInstance());
}

TcpState* TcpEstablished::GetInstance()
{
    static TcpEstablished state;
    return &state;
}

void TcpEstablished::Close(TcpConnection* conn)
{
    std::cout<<"TcpEstablished::Closed"<<std::endl;
    ChangeState(conn, TcpClosed::GetInstance());
}

void TcpEstablished::Transit(TcpConnection* conn, TcpOctetStream* stream)
{
    std::cout<<"transit message..."<<std::endl;
    conn->ProcessOctet(stream);
}

void TestState()
{
    std::cout<<"----------Test State----------"<<std::endl;
    TcpConnection conn;
    conn.PassiveOpen();
    conn.Send();
}

}
