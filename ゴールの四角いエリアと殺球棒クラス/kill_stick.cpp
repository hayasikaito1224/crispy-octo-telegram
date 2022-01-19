//=============================================================================
//
// 殺球棒 [kill_stick.cpp]
// Author : 小笠原　彪我
//
//=============================================================================
//=============================================================================
//インクルードファイル
//=============================================================================
#include "kill_stick.h"
#include "manager.h"
#include "game.h"
#include "stage.h"
#include "stage_data.h"
#include "model_single.h"
//=============================================================================
// 静的メンバ変数宣言
//=============================================================================

//=============================================================================
// コンストラクタ
//=============================================================================
CKillStick::CKillStick()
{
	// 変数をクリア
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fReflectRight = 0.0f;
	m_fReflectLeft = 0.0f;
	m_bReflection = false;
}
//=============================================================================
// デストラクタ
//=============================================================================
CKillStick::~CKillStick()
{
}
//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CKillStick::Init(void)
{
	m_pModelSingle = CModelSingle::Create(KILLSTICK_X_FILL);	// モデル生成
	m_pModelSingle->SetPosition(m_pos);		// 位置を設定
	m_pModelSingle->SetRotation(m_rot);		// 向きを設定

	return S_OK;
}
//=============================================================================
// 終了処理
//=============================================================================
void CKillStick::Uninit(void)
{
}
//=============================================================================
// 更新処理
//=============================================================================
void CKillStick::Update(void)
{
	// 移動量を反転させる判定
	if (m_bReflection == false)
	{
		m_move.x = MOVE_KILLSTICK;
	}
	else
	{
		m_move.x = -MOVE_KILLSTICK;
	}

	// 任意の位置で移動量反転
	// 位置が正の値の場合
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
	// 位置が負の値の場合
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

	// 移動量の更新
	m_pos += m_move;

	// 位置の設定
	m_pModelSingle->SetPosition(m_pos);
}
//=============================================================================
// 描画処理
//=============================================================================
void CKillStick::Draw(void)
{
}
//=============================================================================
// 殺球棒を生成
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
		pKillStick->m_fReflectLeft =  pos.x - REFRECT_DIFF_INC;	// 左の反射位置
		pKillStick->m_fReflectRight = pos.x + REFRECT_DIFF_INC;	// 右の反射位置
	}
	return pKillStick;
}
