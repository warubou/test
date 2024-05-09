#pragma once
#ifndef DX12_SHADER_H_
#define DX12_SHADER_H_

#include <d3dcompiler.h>
#include <string>
#include "../inPreCompileShader/inPreCompileShaderBinary.h"

#pragma comment(lib, "d3dcompiler.lib")

namespace ko
{
	namespace dx12
	{
		enum ShaderType
		{
			_VS = 0,
			_PS,
			_HS,		// –¢ŽÀ‘•
			_DS,		// –¢ŽÀ‘•
			_GS,		// –¢ŽÀ‘•

			_CS,		// –¢ŽÀ‘•

			_ALL,
		};

		class Shader
		{
		public:
			Shader();
			~Shader();

			HRESULT CompileShader(const LPCWSTR& vsFileName, const LPCSTR& vsEntryPoint, const LPCSTR& vsTarget,
								  const LPCWSTR& psFileName, const LPCSTR& psEntryPoint, const LPCSTR& psTarget);

			HRESULT CompileVertexShader(const LPCWSTR& vsFileName, const LPCSTR& vsEntryPoint = "VSMain", const LPCSTR& vsTarget = "vs_5_0");
			HRESULT CompilePixelShader(const LPCWSTR& psFileName, const LPCSTR& psEntryPoint = "PSMain", const LPCSTR& psTarget = "ps_5_0");
			HRESULT CompileGeometryShader(const LPCWSTR& gsFileName, const LPCSTR& gsEntryPoint = "GSMain", const LPCSTR& gsTarget = "gs_5_0");

			const std::string& GetVSCompileBinaryData(void)const;
			const std::string& GetPSCompileBinaryData(void)const;
			const std::string& GetGSCompileBinaryData(void)const;

			size_t GetVSCompileBinaryDataSize(void)const;
			size_t GetPSCompileBinaryDataSize(void)const;
			size_t GetGSCompileBinaryDataSize(void)const;

			ID3DBlob* GetVSBlob(void)const;
			ID3DBlob* GetPSBlob(void)const;
			ID3DBlob* GetGSBlob(void)const;

			bool ReadPreCompileShaderBinary(const std::string& fileName, ShaderType type);

		private:
			InPreCompileShaderBinary* _pIpcsb;
			std::string _bufferVS;
			std::string _bufferPS;
			std::string _bufferGS;
			size_t _bufferSizeVS;
			size_t _bufferSizePS;
			size_t _bufferSizeGS;

			ID3DBlob* _vsBlob;
			ID3DBlob* _psBlob;
			ID3DBlob* _gsBlob;

			HRESULT compileShader(ID3DBlob** pSBlob, const LPCWSTR& filePath, const LPCSTR& entryPoint, const LPCSTR& target);
		};
	}
}

#endif // DX12_SHADER_H_