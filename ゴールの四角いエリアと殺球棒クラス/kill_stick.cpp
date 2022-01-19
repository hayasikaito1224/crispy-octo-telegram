//=============================================================================
//
// �E���_ [kill_stick.cpp]
// Author : ���}���@�V��
//
//=============================================================================
//=============================================================================
//�C���N���[�h�t�@�C��
//=============================================================================
#include "kill_stick.h"
#include "manager.h"
#include "game.h"
#include "stage.h"
#include "stage_data.h"
#include "model_single.h"
//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CKillStick::CKillStick()
{
	// �ϐ����N���A
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fReflectRight = 0.0f;
	m_fReflectLeft = 0.0f;
	m_bReflection = false;
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CKillStick::~CKillStick()
{
}
//=============================================================================
// ����������
//=============================================================================
HRESULT CKillStick::Init(void)
{
	m_pModelSingle = CModelSingle::Create(KILLSTICK_X_FILL);	// ���f������
	m_pModelSingle->SetPosition(m_pos);		// �ʒu��ݒ�
	m_pModelSingle->SetRotation(m_rot);		// ������ݒ�

	return S_OK;
}
//=============================================================================
// �I������
//=============================================================================
void CKillStick::Uninit(void)
{
}
//=============================================================================
// �X�V����
//=============================================================================
void CKillStick::Update(void)
{
	// �ړ��ʂ𔽓]�����锻��
	if (m_bReflection == false)
	{
		m_move.x = MOVE_KILLSTICK;
	}
	else
	{
		m_move.x = -MOVE_KILLSTICK;
	}

	// �C�ӂ̈ʒu�ňړ��ʔ��]
	// �ʒu�����̒l�̏ꍇ
	if (POS_CENTER < m_pos.x)
	{
		if (m_pos.x < m_fReflectLeft)
		{
			m_bReflection = false;
		}
		else if (m_pos.x > m_fReflectRight)
		{
			m_bReflection = true;
		}
	}
	// �ʒu�����̒l�̏ꍇ
	else if (m_pos.x < POS_CENTER)
	{
		if (m_pos.x < m_fReflectLeft)
		{
			m_bReflection = false;
		}
		else if (m_pos.x > m_fReflectRight)
		{
			m_bReflection = true;
		}
	}

	// �ړ��ʂ̍X�V
	m_pos += m_move;

	// �ʒu�̐ݒ�
	m_pModelSingle->SetPosition(m_pos);
}
//=============================================================================
// �`�揈��
//=============================================================================
void CKillStick::Draw(void)
{
}
//=============================================================================
// �E���_�𐶐�
//=============================================================================
CKillStick *CKillStick::Create(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	CKillStick *pKillStick = NULL;
	pKillStick = new CKillStick;

	if (pKillStick != NULL)
	{
		pKillStick->Init();
		pKillStick->m_pos = pos;
		pKillStick->m_rot = rot;
		pKillStick->m_fReflectLeft =  pos.x - REFRECT_DIFF_INC;	// ���̔��ˈʒu
		pKillStick->m_fReflectRight = pos.x + REFRECT_DIFF_INC;	// �E�̔��ˈʒu
	}
	return pKillStick;
}
