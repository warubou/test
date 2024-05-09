// ------------------------------------------------------------------------------------------------
// inPreCompileShaderBinary.h		�R���p�C���σo�C�i���f�[�^��ǂݍ���(.fx)�Ƃ������S��������
// Date:2024/04/15
// Author:Keigo Onari
// ------------------------------------------------------------------------------------------------
#pragma once
#ifndef IN_PRECOMPILE_SHADER_BYTE_CODE_H_
#define IN_PRECOMPILE_SHADER_BYTE_CODE_H_

// ==========================================
// �C���N���[�h
// ==========================================
#include <string>

// ==========================================
// �N���X
// ==========================================
class InPreCompileShaderBinary
{
public:
	InPreCompileShaderBinary(void) {}
	InPreCompileShaderBinary(const std::string& filePath) { Read(filePath); }
	~InPreCompileShaderBinary(void){}

	// ==========================================
	// �ǂݍ���
	// �����F�t�@�C���p�X
	// ==========================================
	void Read(const std::string& filePath);

	// ==========================================
	// �Q�b�^�[
	// ==========================================
	const size_t& GetBufferSize(void)const { return static_cast<size_t>(_fileSize); }
	const std::string& GetBinaryBuffer(void)const { return _binaryBuffer; }

private:
	std::streampos _fileSize;
	std::string _binaryBuffer;
};

#endif // IN_PRECOMPILE_SHADER_BYTE_CODE_H_