#include "pch.h"
#include "..\Headers\KeyMgr.h"

_IMPLEMENT_SINGLETON(CKeyMgr)
CKeyMgr::CKeyMgr()
	: m_dwKey(0), m_dwKeyPressed(0), m_dwKeyDown(0)
{
}


CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::Update()
{
	m_dwKey = 0;

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		m_dwKey |= KEY_LBUTTON;
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		m_dwKey |= KEY_RBUTTON;
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		m_dwKey |= KEY_RETURN;
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
		m_dwKey |= KEY_SHIFT;
	if (GetAsyncKeyState('W') & 0x8000)
		m_dwKey |= KEY_UP;
	if (GetAsyncKeyState('S') & 0x8000)
		m_dwKey |= KEY_DOWN;
	if (GetAsyncKeyState('A') & 0x8000)
		m_dwKey |= KEY_LEFT;
	if (GetAsyncKeyState('D') & 0x8000)
		m_dwKey |= KEY_RIGHT;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		m_dwKey |= KEY_SPACE;

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		m_dwKey |= KEY_ESC;
	if (GetAsyncKeyState('1') & 0x8000)
		m_dwKey |= KEY_1;
	if (GetAsyncKeyState('2') & 0x8000)
		m_dwKey |= KEY_2;
	if (GetAsyncKeyState('3') & 0x8000)
		m_dwKey |= KEY_3;
}

bool CKeyMgr::KeyUp(DWORD dwKey)
{
	if (m_dwKey & dwKey)
	{
		m_dwKeyPressed |= dwKey;
		return false;
	}
	else if (m_dwKeyPressed & dwKey)
	{
		m_dwKeyPressed ^= dwKey;
		return true;
	}

	return false;
}

bool CKeyMgr::KeyDown(DWORD dwKey)
{
	if (!(m_dwKeyDown & dwKey) && (m_dwKey & dwKey))
	{
		m_dwKeyDown |= dwKey;
		return true;
	}
	else if (!(m_dwKey & dwKey) && (m_dwKeyDown & dwKey))
	{
		m_dwKeyDown ^= dwKey;
		return false;
	}

	return false;
}

bool CKeyMgr::KeyPressing(DWORD dwKey)
{
	if (m_dwKey & dwKey)
		return true;

	return false;
}

bool CKeyMgr::KeyCombine(DWORD dwFirstKey, DWORD dwSecondKey)
{
	if (KeyDown(dwSecondKey) && (m_dwKey & dwFirstKey))
		return true;

	return false;
}
