// ------------------------------------------------------------------------------------------------
// inPreCompileShaderBinary.cpp		�R���p�C���σo�C�i���f�[�^��ǂݍ���(.fx)�Ƃ������S��������
// Date:2024/04/15
// Author:Keigo Onari
// ------------------------------------------------------------------------------------------------

// ==========================================
// �C���N���[�h
// ==========================================
#include "inPreCompileShaderBinary.h"
#include <fstream>
#include <vector>

// ==========================================
// �ǂݍ���
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
