// ------------------------------------------------------------------------------------------------
// inPreCompileShaderBinary.h		コンパイル済バイナリデータを読み込み(.fx)というか全部いける
// Date:2024/04/15
// Author:Keigo Onari
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef IN_PRECOMPILE_SHADER_BYTE_CODE_H_
#define IN_PRECOMPILE_SHADER_BYTE_CODE_H_

// ==========================================
// インクルード
// ==========================================
#include <string>

// ==========================================
// クラス
// ==========================================
class InPreCompileShaderBinary
{
public:
	InPreCompileShaderBinary(void) {}
	InPreCompileShaderBinary(const std::string& filePath) { Read(filePath); }
	~InPreCompileShaderBinary(void){}

	// ==========================================
	// 読み込み
	// 引数：ファイルパス
	// ==========================================
	void Read(const std::string& filePath);

	// ==========================================
	// ゲッター
	// ==========================================
	const size_t& GetBufferSize(void)const { return static_cast<size_t>(_fileSize); }
	const std::string& GetBinaryBuffer(void)const { return _binaryBuffer; }

private:
	std::streampos _fileSize;
	std::string _binaryBuffer;
};

#endif // IN_PRECOMPILE_SHADER_BYTE_CODE_H_