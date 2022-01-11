//=============================================================================
//
// 時間経過の処理 [timercount.cpp]
// Author : 土居大輝
//
//=============================================================================

//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "timercount.h"
#include "number.h"
#include"player.h"
#include"game.h"
#include"fade.h"
//#include"ui.h"

//=============================================================================
//コンストラクタ
//=============================================================================
CTimerCount::CTimerCount(int nPriority) : CScene(nPriority)
{
	m_bStop = false;
	m_dwCurrentTime = 0;
	// 現在の時間を取得
	m_dwExecLastTime = timeGetTime();
	m_bFade = false;
	m_bLimit = false;
}

//=============================================================================
//デストラクタ
//=============================================================================
CTimerCount::~CTimerCount()
{
}

//=============================================================================
//初期化処理
//=============================================================================
HRESULT CTimerCount::Init(void)
{
	// 数字の生成
	for (int nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		m_apNumber[nCntTime] = CNumber::Create(D3DXVECTOR3(m_pos.x + m_size.x + SPACE_TIME * nCntTime, m_pos.y, 0.0f), D3DXVECTOR3(m_size.x, m_size.y, 0.0f), CTexture::TEXTURETYPE_TIME);
	}

	//m_bFade = false;

	return S_OK;
}

//=============================================================================
//終了処理
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
//更新処理
//=============================================================================
void CTimerCount::Update(void)
{
	m_dwCurrentTime = timeGetTime();	// 現在の時間を取得

										//フェードの取得
	CFade *pFade = CManager::GetFade();

	// 時間経過処理（1秒で減らす）
	if ((m_dwCurrentTime - m_dwExecLastTime) >= REDUCE_TIME && m_nTimerCount != 0)
	{
		if (m_bStop == false)
		{
			AddTimerCount(-1);
			m_dwCurrentTime = 0;
			m_dwExecLastTime = timeGetTime();
		}
	}

	// 数字
	m_apNumber[0]->SetNumber(m_nTimerCount % (int)pow(10, 3) / (int)pow(10, 2));
	m_apNumber[1]->SetNumber(m_nTimerCount % (int)pow(10, 2) / (int)pow(10, 1));
	m_apNumber[2]->SetNumber(m_nTimerCount % (int)pow(10, 1));

	//時間切れになったら
	if (m_nTimerCount == 0)
	{
		m_bLimit = true;

		if (m_bFade == false)
		{
			// 画面遷移 / フェード処理
			pFade->SetFade(CManager::MODE_RESULT);
			m_bFade = true;
		}

	}


	if (m_bLimit = true)
	{

	}

	//if (m_nTime <= 30)
	//{
	//	//サウンド取得
	//	//CSound *pSound = CManager::GetSound();

	//	// 残り時間少なくなると色を変える
	//	m_col.a = 1.0f;
	//	m_col.r = 1.0f;
	//	m_apNumber[0]->SetColor(m_col);
	//	m_apNumber[1]->SetColor(m_col);
	//	m_apNumber[2]->SetColor(m_col);
	//}
	//m_mode = CManager::GetMode();
	//if (m_mode == CManager::MODE_GAME)
	//{
	//	// 時間切れ
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
	//			// リザルト行き
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
//描画処理
//=============================================================================
void CTimerCount::Draw(void)
{
	for (int nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		m_apNumber[nCntTime]->Draw();
	}
}

//=============================================================================
//時間の加算
//=============================================================================
void CTimerCount::AddTimerCount(int nValue)
{
	m_nTimerCount += nValue;
}
//=============================================================================
//時間の取得
//=============================================================================
int CTimerCount::GetTimerCount(void)
{
	return m_nTimerCount;
}

//=============================================================================
//時間の生成
//=============================================================================
CTimerCount * CTimerCount::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size, int time, bool bStop)
{
	// 時間のインスタンス生成
	CTimerCount *pTimerCount = new CTimerCount;

	// 時間の準備
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
