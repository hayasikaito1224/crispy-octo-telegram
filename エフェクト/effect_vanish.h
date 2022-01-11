//=============================================================================
//
// ���ŃG�t�F�N�g�N���X [effect_vanish.h]
// Author : �y����P
//
//=============================================================================

//*****************************************************************************
//�C���N���[�h�t�@�C��
//*****************************************************************************
#include "billeffect.h"

//*****************************************************************************
//�}�N����`
//*****************************************************************************
//����
#define VANISH_LIFE 180
//�ʒu
#define VANISH_EFFECT_POS_X 0.0f
#define VANISH_EFFECT_POS_Y 100.0f
#define VANISH_EFFECT_POS_Z 0.0f
//�傫��
#define VANISH_EFFECT_SCALE_X 20.0f
#define VANISH_EFFECT_SCALE_Y 20.0f
#define VANISH_EFFECT_SCALE_Z 20.0f
//����
#define VANISH_EFFECT_MOVE_X 10.0f
#define VANISH_EFFECT_MOVE_Y 0.0f
#define VANISH_EFFECT_MOVE_Z 0.0f

//*****************************************************************************
//�N���X��`
//*****************************************************************************

class CEffectVanish : public CBillEffect
{
public:

	CEffectVanish(int nPriority = 3);
	~CEffectVanish();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 scale, D3DXVECTOR3 move, int life);	// ����������
	void Uninit(void);	// �I������
	void Update(void);	// �X�V����
	void Draw(void);	// �`�揈��
	static CEffectVanish *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, D3DXVECTOR3 move, int life, int nType);		//�G�t�F�N�g�̐���

private:
	D3DXVECTOR3 m_move;  //�ړ�
	D3DXVECTOR3 m_scale;  //�ړ�
	D3DXVECTOR3	m_rot;  // ����

	int m_nType;
	int m_nLife;		//����
	D3DCOLORVALUE m_colval;
	bool m_bUninit;		//�폜�t���O
	D3DXVECTOR3 m_Fastpos;  //�x�N�g���v�Z
	float m_Vec;
};
