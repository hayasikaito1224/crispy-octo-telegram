//=============================================================================
//
// �e�N�X�`���N���X [texture.h]
// Author : ���}���@�V��
//
//=============================================================================
#ifndef _TEXTURE_H_
#define _TEXTURE_H_

//*****************************************************************************
// �w�b�_�t�@�C���̃C���N���[�h
//*****************************************************************************
#include "manager.h"

//=============================================================================
// �}�N����`
//=============================================================================
#define FILENAME_TEX "data/SCRIPT/texture.txt"

//*****************************************************************************
//	�e�N�X�`���N���X
//*****************************************************************************
class CTexture
{
public:
	//�e�N�X�`���̎��
	typedef enum
	{
		TEXTURETYPE_PUSH = 0,
		TEXTURETYPE_NAME,
		TEXTURETYPE_TIME,		
		TEXTURETYPE_MACHINE,
		TEXTURETYPE_EFFECT,
		TEXTURETYPE_MAX
	} TEXTURETYPE;

	CTexture();						// �R���X�g���N�^
	~CTexture();					// �f�X�g���N�^

	HRESULT Init(void);				// ����������
	void Uninit(void);				// �I������
	void Update(void);				// �X�V����
	void Draw(void);				// �`�揈��

	static CTexture *Create(void);		// ��������
	LPDIRECT3DTEXTURE9 SetTextureType(int nType);				// �e�N�X�`���̎�ނ�ݒ�

private:
	static LPDIRECT3DTEXTURE9	m_pTexture[MAX_TEXTURE];		// �e�N�X�`���̃|�C���^
	static int m_nType;
	int m_nNumTexture;
	int m_nTextType;


};
#endif //!_TEXTURE_H_