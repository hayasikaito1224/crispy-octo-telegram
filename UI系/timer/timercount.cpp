//=============================================================================
//
// ���Ԍo�߂̏��� [timercount.cpp]
// Author : �y����P
//
//=============================================================================

//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "timercount.h"
#include "number.h"
#include"player.h"
#include"game.h"
#include"fade.h"
//#include"ui.h"

//=============================================================================
//�R���X�g���N�^
//=============================================================================
CTimerCount::CTimerCount(int nPriority) : CScene(nPriority)
{
	m_bStop = false;
	m_dwCurrentTime = 0;
	// ���݂̎��Ԃ��擾
	m_dwExecLastTime = timeGetTime();
	m_bFade = false;
	m_bLimit = false;
}

//=============================================================================
//�f�X�g���N�^
//=============================================================================
CTimerCount::~CTimerCount()
{
}

//=============================================================================
//����������
//=============================================================================
HRESULT CTimerCount::Init(void)
{
	// �����̐���
	for (int nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		m_apNumber[nCntTime] = CNumber::Create(D3DXVECTOR3(m_pos.x + m_size.x + SPACE_TIME * nCntTime, m_pos.y, 0.0f), D3DXVECTOR3(m_size.x, m_size.y, 0.0f), CTexture::TEXTURETYPE_TIME);
	}

	//m_bFade = false;

	return S_OK;
}

//=============================================================================
//�I������
//=============================================================================
void CTimerCount::Uninit(void)
{
	for (int nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		if (m_apNumber[nCntTime] != NULL)
		{
			m_apNumber[nCntTime]->Uninit();
			delete m_apNumber[nCntTime];
			m_apNumber[nCntTime] = NULL;
		}
	}
	Release();
}

//=============================================================================
//�X�V����
//=============================================================================
void CTimerCount::Update(void)
{
	m_dwCurrentTime = timeGetTime();	// ���݂̎��Ԃ��擾

										//�t�F�[�h�̎擾
	CFade *pFade = CManager::GetFade();

	// ���Ԍo�ߏ����i1�b�Ō��炷�j
	if ((m_dwCurrentTime - m_dwExecLastTime) >= REDUCE_TIME && m_nTimerCount != 0)
	{
		if (m_bStop == false)
		{
			AddTimerCount(-1);
			m_dwCurrentTime = 0;
			m_dwExecLastTime = timeGetTime();
		}
	}

	// ����
	m_apNumber[0]->SetNumber(m_nTimerCount % (int)pow(10, 3) / (int)pow(10, 2));
	m_apNumber[1]->SetNumber(m_nTimerCount % (int)pow(10, 2) / (int)pow(10, 1));
	m_apNumber[2]->SetNumber(m_nTimerCount % (int)pow(10, 1));

	//���Ԑ؂�ɂȂ�����
	if (m_nTimerCount == 0)
	{
		m_bLimit = true;

		if (m_bFade == false)
		{
			// ��ʑJ�� / �t�F�[�h����
			pFade->SetFade(CManager::MODE_RESULT);
			m_bFade = true;
		}

	}


	if (m_bLimit = true)
	{

	}

	//if (m_nTime <= 30)
	//{
	//	//�T�E���h�擾
	//	//CSound *pSound = CManager::GetSound();

	//	// �c�莞�ԏ��Ȃ��Ȃ�ƐF��ς���
	//	m_col.a = 1.0f;
	//	m_col.r = 1.0f;
	//	m_apNumber[0]->SetColor(m_col);
	//	m_apNumber[1]->SetColor(m_col);
	//	m_apNumber[2]->SetColor(m_col);
	//}
	//m_mode = CManager::GetMode();
	//if (m_mode == CManager::MODE_GAME)
	//{
	//	// ���Ԑ؂�
	//	if (m_nTime == 0)
	//	{
	//		if (m_bflag == false)
	//		{
	//			CUI::Create(D3DXVECTOR3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(TIMEUP_WIDTH, TIMEUP_HEIGHT, 0.0f), CTexture::TEXTURETYPE_TIMEUP);
	//			m_bflag = true;
	//		}
	//		m_IntervalTime++;
	//		if (m_IntervalTime >= INTERVAL_TIME)
	//		{
	//			// ���U���g�s��
	//			if (m_fade == false)
	//			{
	//				pFade->SetFade(CManager::MODE_RESULT);
	//				m_fade = true;
	//				m_bStop = true;
	//			}
	//		}
	//		m_nTime = 0;
	//	}
	//}
}

//=============================================================================
//�`�揈��
//=============================================================================
void CTimerCount::Draw(void)
{
	for (int nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		m_apNumber[nCntTime]->Draw();
	}
}

//=============================================================================
//���Ԃ̉��Z
//=============================================================================
void CTimerCount::AddTimerCount(int nValue)
{
	m_nTimerCount += nValue;
}
//=============================================================================
//���Ԃ̎擾
//=============================================================================
int CTimerCount::GetTimerCount(void)
{
	return m_nTimerCount;
}

//=============================================================================
//���Ԃ̐���
//=============================================================================
CTimerCount * CTimerCount::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, int time, bool bStop)
{
	// ���Ԃ̃C���X�^���X����
	CTimerCount *pTimerCount = new CTimerCount;

	// ���Ԃ̏���
	if (pTimerCount != NULL)
	{
		pTimerCount->m_bStop = bStop;
		pTimerCount->m_nTimerCount = time;
		pTimerCount->m_pos = pos;
		pTimerCount->m_size = size;
		pTimerCount->Init();
	}
	return pTimerCount;
}
