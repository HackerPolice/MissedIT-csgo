#pragma once

#include "../DefaultHeader.hpp"

namespace Ragebot {

    inline bool shouldAim = false,
                shouldSlow = false,
                doubleTap = false;
    extern std::vector<int64_t> friends;
    extern int targetAimbot;
    inline Vector prevBestSpot;
    inline int prevDamage = 0, dtTick_Count = 0, dtTick_Need = 0;
    inline C_BasePlayer *LockedEnemy;
    inline ItemDefinitionIndex prevWeapon = ItemDefinitionIndex::INVALID;

    void CreateMove(CUserCmd*);
    void FireGameEvent(IGameEvent* event);
	  inline void UpdateValues();
}

void Ragebot::UpdateValues()
{
    if (!Settings::Ragebot::enabled || !engine->IsInGame())
      return;
		
    C_BasePlayer* localplayer = (C_BasePlayer*)entityList->GetClientEntity(engine->GetLocalPlayer());
    if (!localplayer->GetAlive())
		  return;

	  C_BaseCombatWeapon* activeWeapon = (C_BaseCombatWeapon*)entityList->GetClientEntityFromHandle(localplayer->GetActiveWeapon());
    if (!activeWeapon)
		  return;

    ItemDefinitionIndex index = ItemDefinitionIndex::INVALID;

    if (Settings::Ragebot::weapons.find(*activeWeapon->GetItemDefinitionIndex()) != Settings::Ragebot::weapons.end())
		  index = *activeWeapon->GetItemDefinitionIndex();

    const RagebotWeapon_t& currentWeaponSetting = Settings::Ragebot::weapons.at(index);

    Settings::Ragebot::silent = currentWeaponSetting.silent;
    Settings::Ragebot::friendly = currentWeaponSetting.friendly;
    Settings::Ragebot::AutoShoot::enabled = currentWeaponSetting.autoShootEnabled;
    Settings::Ragebot::AutoShoot::autoscope = currentWeaponSetting.autoScopeEnabled;
    Settings::Ragebot::HitChance::enabled = currentWeaponSetting.HitChanceEnabled;
    Settings::Ragebot::HitChance::value = currentWeaponSetting.HitChance;
    Settings::Ragebot::MinDamage = currentWeaponSetting.MinDamage;
    Settings::Ragebot::AutoSlow::enabled = currentWeaponSetting.autoSlow;
    Settings::Ragebot::ScopeControl::enabled = currentWeaponSetting.scopeControlEnabled;
  	Settings::Ragebot::damagePrediction = currentWeaponSetting.DmagePredictionType;
	  Settings::Ragebot::enemySelectionType = currentWeaponSetting.enemySelectionType;
    
    for (int bone = 0; bone < 6; bone++){
      Settings::Ragebot::AutoAim::desireBones[bone] = currentWeaponSetting.desireBones[bone];
      Settings::Ragebot::AutoAim::desiredMultiBones[bone] = currentWeaponSetting.desiredMultiBones[bone];
    }
		  
}

