/******************************************************************************************
*	Chili DirectX Framework Version 16.07.20											  *
*	Graphics.h																			  *
*	Copyright 2016 PlanetChili <http://www.planetchili.net>								  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once
#include <d3d11.h>
#include <wrl.h>
#include "ChiliException.h"
#include "Colors.h"
#include "RectF.h"

class Graphics
{
public:
	class Exception : public ChiliException
	{
	public:
		Exception( HRESULT hr,const std::wstring& note,const wchar_t* file,unsigned int line );
		std::wstring GetErrorName() const;
		std::wstring GetErrorDescription() const;
		virtual std::wstring GetFullMessage() const override;
		virtual std::wstring GetExceptionType() const override;
	private:
		HRESULT hr;
	};
private:
	// vertex format for the framebuffer fullscreen textured quad
	struct FSQVertex
	{
		float x,y,z;		// position
		float u,v;			// texcoords
	};
public:
	Graphics( class HWNDKey& key );
	Graphics( const Graphics& ) = delete;
	Graphics& operator=( const Graphics& ) = delete;
	void EndFrame();
	void BeginFrame();
	void PutPixel( int x,int y,int r,int g,int b )
	{
		PutPixel( x,y,{ unsigned char( r ),unsigned char( g ),unsigned char( b ) } );
	}
	void PutPixel( int x,int y,Color c );
	void DrawRect( int x0,int y0,int x1,int y1,Color c );
	void DrawRect(const RectF& rect, Color c) {
		DrawRect(int (rect.left), int (rect.top), int (rect.right), int (rect.bottom), c);
	}
	void DrawCircle( int x,int y,int radius,Color c );
	void DrawLine(const Vec2& pos0, const Vec2& pos1, Color c) {
		/*Po-Han Lin's EFLA Line Algorithm www.edepot.com/algorithm.html */
		bool yLonger = false;
		int shortLen = (int)pos1.y - (int)pos0.y;
		int longLen = (int)pos1.x - (int)pos0.x;
		int shortAbs = ((shortLen >> 31) ^ shortLen) - (shortLen >> 31);
		int longAbs = ((longLen >> 31) ^ longLen) - (longLen >> 31);
		if (shortAbs > longAbs) {
			int swap = shortLen;
			shortLen = longLen;
			longLen = swap;
			yLonger = true;
		}
		int decInc;
		if (longLen == 0) {
			decInc = 0;
		} else {
			decInc = (shortLen << 16) / longLen;
		}
		int bucket1 = (int)pos0.x << 16;
		int bucket2 = (int)pos0.y;
		int bucket3 = (int)pos0.y << 16;
		int bucket4 = (int)pos0.x;
		if (yLonger) {
			if (longLen>0) {
				longLen += pos0.y;
				for (int j = 0x8000 + bucket1; bucket2 <= longLen; bucket2++) {
					PutPixel(j >> 16, bucket2, c);
					j += decInc;
				}
				return;
			}
			longLen += pos0.y;
			for (int j = 0x8000 + bucket1; bucket2 >= longLen; --bucket2) {
				PutPixel(j >> 16, bucket2, c);
				j -= decInc;
			}
			return;
		}

		if (longLen > 0) {
			longLen += pos0.x;
			for (int j = 0x8000 + bucket3; bucket4 <= longLen; ++bucket4) {
				PutPixel(bucket4, j >> 16, c);
				j += decInc;
			}
			return;
		}
		longLen += pos0.x;
		for (int j = 0x8000 + bucket3; bucket4 >= longLen; --bucket4) {
			PutPixel(bucket4, j >> 16, c);
			j -= decInc;
		}
	}
	~Graphics();
private:
	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color*                                              pSysBuffer = nullptr;
public:
	static constexpr int ScreenWidth = 800;
	static constexpr int ScreenHeight = 600;
};