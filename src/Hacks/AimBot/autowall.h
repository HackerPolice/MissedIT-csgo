#pragma once

#include "../../SDK/vector.h"
#include "../../SDK/IEngineTrace.h"
#include "legitbot.h"
#include "../../Utils/math.h"
#include "../../Utils/entity.h"
#include "../../interfaces.h"

namespace AutoWall
{
	struct FireBulletData
	{
		Vector src;
		trace_t enter_trace;
		Vector direction;
		CTraceFilter filter;
		float trace_length = 0;
		float trace_length_remaining = 0;
		float current_damage = 0;
		int penetrate_count = 0;
	};

	int GetDamage(const Vector& vecPoint,C_BasePlayer* player, bool teamCheck, FireBulletData& fData);
	void ScaleDamage(HitGroups hitgroup, C_BasePlayer* enemy, float weapon_armor_ratio, float& current_damage);
	bool SimulateFireBullet(C_BasePlayer* localplayer, C_BaseCombatWeapon* pWeapon, bool teamCheck, AutoWall::FireBulletData& data);
}