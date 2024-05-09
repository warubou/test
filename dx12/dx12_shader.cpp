#include "dx12_shader.h"
#include "dx12_header.h"

namespace ko
{
	namespace dx12
	{
		Shader::Shader() {}
		Shader::~Shader() {}

		HRESULT Shader::CompileShader(const LPCWSTR& vsFileName, const LPCSTR& vsEntryPoint, const LPCSTR& vsTarget,
									  const LPCWSTR& psFileName, const LPCSTR& psEntryPoint, const LPCSTR& psTarget)
		{
			HRESULT hr = CompileVertexShader(vsFileName, vsEntryPoint, vsTarget);
			ERROR_CHECK_HRESULT(hr);

			hr = CompilePixelShader(psFileName, psEntryPoint, psTarget);
			ERROR_CHECK_HRESULT(hr);

			return hr;
		}

		HRESULT Shader::CompileVertexShader(const LPCWSTR& vsFileName, const LPCSTR& vsEntryPoint, const LPCSTR& vsTarget)
		{
			return compileShader(&_vsBlob, vsFileName, vsEntryPoint, vsTarget);
		}

		HRESULT Shader::CompilePixelShader(const LPCWSTR& psFileName, const LPCSTR& psEntryPoint, const LPCSTR& psTarget)
		{
			return compileShader(&_psBlob, psFileName, psEntryPoint, psTarget);
		}

		HRESULT Shader::CompileGeometryShader(const LPCWSTR& gsFileName, const LPCSTR& gsEntryPoint, const LPCSTR& gsTarget)
		{
			return compileShader(&_gsBlob, gsFileName, gsEntryPoint, gsTarget);
		}

		const std::string& Shader::GetVSCompileBinaryData(void)const
		{
			return _bufferVS;
		}

		const std::string& Shader::GetPSCompileBinaryData(void)const
		{
			return _bufferPS;
		}
		const std::string& Shader::GetGSCompileBinaryData(void)const
		{
			return _bufferGS;
		}

		size_t Shader::GetVSCompileBinaryDataSize(void)const
		{
			return _bufferSizeVS;
		}

		size_t Shader::GetPSCompileBinaryDataSize(void)const
		{
			return _bufferSizePS;
		}

		size_t Shader::GetGSCompileBinaryDataSize(void)const
		{
			return _bufferSizeGS;
		}

		ID3DBlob* Shader::GetVSBlob(void)const
		{
			return _vsBlob;
		}

		ID3DBlob* Shader::GetPSBlob(void)const
		{
			return _psBlob;
		}

		ID3DBlob* Shader::GetGSBlob(void)const
		{
			return _gsBlob;
		}

		bool Shader::ReadPreCompileShaderBinary(const std::string& fileName, ShaderType type)
		{
			_pIpcsb = new InPreCompileShaderBinary(fileName);

			switch (type)
			{
			case _VS:
				_bufferVS = _pIpcsb->GetBinaryBuffer();
				_bufferSizeVS = _pIpcsb->GetBufferSize();
				break;
			case _PS:
				_bufferPS = _pIpcsb->GetBinaryBuffer();
				_bufferSizePS = _pIpcsb->GetBufferSize();
				break;
			case _GS:
				_bufferGS = _pIpcsb->GetBinaryBuffer();
				_bufferSizeGS = _pIpcsb->GetBufferSize();
				break;
			case _CS:
				break;
			default:
				break;
			}

			return true;
		}

		HRESULT Shader::compileShader(ID3DBlob** pSBlob, const LPCWSTR& filePath, const LPCSTR& entryPoint, const LPCSTR& target)
		{
			ID3DBlob* errorBlob = nullptr;
			HRESULT hr = D3DCompileFromFile(
				filePath,
				nullptr,
				D3D_COMPILE_STANDARD_FILE_INCLUDE,
				entryPoint,
				target,
				D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
				0,
				pSBlob, &errorBlob
			);

			if (FAILED(hr))
			{
				MessageBox(NULL, reinterpret_cast<char*>(errorBlob->GetBufferPointer()), "ShaderCompileError", MB_OK | MB_ICONERROR);
			}

			if (errorBlob)
				errorBlob->Release();
			return hr;
		}
	}
}