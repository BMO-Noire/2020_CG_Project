#pragma once

typedef struct tagVertex_Color
{
	vec3 vPos;
	vec3 vColor;
}VTXCOL;

typedef struct tagVertex_Normal
{
	vec3 vPos;
	vec3 vColor;
	vec3 vNormal;
}VTXNORMAL;

typedef struct tagVertex_UV
{
	vec3 vPos;
	vec3 vColor;
	vec2 vTexUV;
}VTXUV;

typedef struct tagCamera_Desc
{
	vec3		vEye; // ī�޶��� ��ġ.In.WorldSpace
	vec3		vAt; // ī�޶� �ٶ󺸴� ��.
	vec3		vAxisY; // �� ��ǥ��󿡼��� y�຤���� ����.
}CAMERADESC;

typedef struct tagProjection_Desc
{
	float		fFovY; // �� ī�޶��� �þ� ����.
	float		fAspect; // �� �������� ����, ���� ����.
	float		fNear;
	float		fFar;
}PROJDESC;

typedef struct tagTextureSet
{
	int iWidth;
	int iHeight;
	int iChannel;
	unsigned char* pData;
}TEXTURESET;

typedef struct tagPolygon16
{
	unsigned short		_0, _1, _2;
}POLYGON16;

typedef struct tagPolygon32
{
	unsigned long		_0, _1, _2;
}POLYGON32;