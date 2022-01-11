//=============================================================================
//
// 消滅エフェクトクラス [effect_vanish.h]
// Author : 土居大輝
//
//=============================================================================

//*****************************************************************************
//インクルードファイル
//*****************************************************************************
#include "billeffect.h"

//*****************************************************************************
//マクロ定義
//*****************************************************************************
//寿命
#define VANISH_LIFE 180
//位置
#define VANISH_EFFECT_POS_X 0.0f
#define VANISH_EFFECT_POS_Y 100.0f
#define VANISH_EFFECT_POS_Z 0.0f
//大きさ
#define VANISH_EFFECT_SCALE_X 20.0f
#define VANISH_EFFECT_SCALE_Y 20.0f
#define VANISH_EFFECT_SCALE_Z 20.0f
//動き
#define VANISH_EFFECT_MOVE_X 10.0f
#define VANISH_EFFECT_MOVE_Y 0.0f
#define VANISH_EFFECT_MOVE_Z 0.0f

//*****************************************************************************
//クラス定義
//*****************************************************************************

class CEffectVanish : public CBillEffect
{
public:

	CEffectVanish(int nPriority = 3);
	~CEffectVanish();

	HRESULT Init(D3DXVECTOR3 pos, D3DXVECTOR3 scale, D3DXVECTOR3 move, int life);	// 初期化処理
	void Uninit(void);	// 終了処理
	void Update(void);	// 更新処理
	void Draw(void);	// 描画処理
	static CEffectVanish *Create(D3DXVECTOR3 pos, D3DXVECTOR3 scale, D3DXVECTOR3 move, int life, int nType);		//エフェクトの生成

private:
	D3DXVECTOR3 m_move;  //移動
	D3DXVECTOR3 m_scale;  //移動
	D3DXVECTOR3	m_rot;  // 向き

	int m_nType;
	int m_nLife;		//寿命
	D3DCOLORVALUE m_colval;
	bool m_bUninit;		//削除フラグ
	D3DXVECTOR3 m_Fastpos;  //ベクトル計算
	float m_Vec;
};
