
#pragma once

#include "VIBuffer.h"

BEGIN(Engine)


class VIBufferModel abstract : public VIBuffer
{
protected:
	VIBufferModel() = default;
public:
	virtual ~VIBufferModel();

public:
	virtual void		Render();
protected:
	virtual void		InitRasterizerState();
protected:
	virtual void		Release();

protected:
	void MakeVertexNormal(BYTE* _pVertices, WORD* _pIndices);
	void SetNormalVectorByBasic(BYTE* _pVertices);
	void SetNormalVectorByAverage(BYTE* _pVertices, WORD* _pIndices, int _iPrimitives, int _iOffset, bool _bStrip);
	D3DXVECTOR3 GetTriAngleNormal(BYTE* _pVertices, USHORT _nIndex_0, USHORT _nIndex_1, USHORT _nIndex_2);
};


END
