// wsJoinServer.h: interface for the CwsGameServer class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __WSJOINSERVER_H__
#define __WSJOINSERVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyWinsockBase.h"


#define MAX_SOCKETINDEX		65536	// ���� �ε��� �ִ� ����

#define MAX_SOCKETBUFFER	100		// ���ϴ� ���� �ִ� ����

class CSocketBuffer
{
public:
	int		live;		// 
	char	Ip_addr[16];		// ip�ּ�
	
	SOCKET	m_socket;	// ���� ��ȣ

	int		m_SendBufLen;			// ����ũ��
	int		m_RecvBufLen;			// ���� ���� ũ�� 

public:

	CSocketBuffer() 
	{
		Clear();
	};
	void Clear()
	{
		live = 0;
		memset(Ip_addr, 0, 16);
		m_socket = INVALID_SOCKET;
		m_SendBufLen = 0;
		m_RecvBufLen = 0;
	};
};

class CwsJoinServer : public MyWinsockBase
{
public:
	int		m_SockIndex[MAX_SOCKETINDEX];	// ���ϴ� ���� �迭 �ε���
	
	CSocketBuffer	sb[MAX_SOCKETBUFFER];

	DWORD	m_WinClientMsg;

public:
	int SetSocketBuffer(int index, SOCKET socket, char * ip);
	BOOL AcceptSocket(SOCKET & clientSocket, IN_ADDR & cInAddr);
	BOOL DataSend(short uindex, char *buf, int len);
	BOOL CreateServer(char *ip_addr, WORD port, DWORD WinServerMsg, DWORD WinClientMsg);
	
	CwsJoinServer();
	virtual ~CwsJoinServer();

};

#endif
