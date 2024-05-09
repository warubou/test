// ------------------------------------------------------------------------------------------------
// inPreCompileShaderBinary.cpp		コンパイル済バイナリデータを読み込み(.fx)というか全部いける
// Date:2024/04/15
// Author:Keigo Onari
// ------------------------------------------------------------------------------------------------

// ==========================================
// インクルード
// ==========================================
#include "inPreCompileShaderBinary.h"
#include <fstream>
#include <vector>

// ==========================================
// 読み込み
// ==========================================
void InPreCompileShaderBinary::Read(const std::string& filePath)
{
	std::ifstream ifs(filePath, std::ios::binary);

	if (!ifs.is_open())
	{
		return;
	}

	ifs.seekg(0, std::ios::end);
	_fileSize = ifs.tellg();
	ifs.seekg(0, std::ios::beg);

	std::vector<char>byteBuffer(_fileSize);
	ifs.read(byteBuffer.data(), _fileSize);

	_binaryBuffer.insert(_binaryBuffer.end(), byteBuffer.begin(), byteBuffer.end());

	ifs.close();

	return;
}
