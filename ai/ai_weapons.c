/*
Copyright (C) 1997-2001 Id Software, Inc.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "../g_local.h"
#include "ai_local.h"

//WEAP_NONE,
//WEAP_BLASTER
//WEAP_SHOTGUN
//WEAP_SUPERSHOTGUN
//WEAP_MACHINEGUN
//WEAP_CHAINGUN
//WEAP_GRENADES
//WEAP_GRENADELAUNCHER
//WEAP_ROCKETLAUNCHER
//WEAP_HYPERBLASTER
//WEAP_RAILGUN
//WEAP_BFG
//WEAP_GRAPPLE

//==========================================
// AI_InitAIWeapons
//
// AIWeapons are the way the AI uses to analize
// weapon types, for choosing and fire them
//==========================================
void AI_InitAIWeapons(void)
{
	//clear all
	memset(&AIWeapons, 0, sizeof(ai_weapon_t) * WEAP_TOTAL);

	//BLASTER
	AIWeapons[WEAP_BLASTER].aimType = AI_AIMSTYLE_PREDICTION;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_BLASTER].RangeWeight[AIWEAP_LONG_RANGE] = 0.05F; //blaster must always have some value
	AIWeapons[WEAP_BLASTER].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.05F;
	AIWeapons[WEAP_BLASTER].RangeWeight[AIWEAP_SHORT_RANGE] = 0.1F;
	AIWeapons[WEAP_BLASTER].RangeWeight[AIWEAP_MELEE_RANGE] = 0.2F;
	/* END */
	AIWeapons[WEAP_BLASTER].weaponItem = NULL;//FindItemByClassname("weapon_blaster");
	AIWeapons[WEAP_BLASTER].ammoItem = NULL;		//doesn't use ammo

	//SHOTGUN
	AIWeapons[WEAP_SHOTGUN].aimType = AI_AIMSTYLE_INSTANTHIT;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_SHOTGUN].RangeWeight[AIWEAP_LONG_RANGE] = 0.1F;
	AIWeapons[WEAP_SHOTGUN].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.1F;
	AIWeapons[WEAP_SHOTGUN].RangeWeight[AIWEAP_SHORT_RANGE] = 0.2F;
	AIWeapons[WEAP_SHOTGUN].RangeWeight[AIWEAP_MELEE_RANGE] = 0.3F;
	/* END */
	AIWeapons[WEAP_SHOTGUN].weaponItem = NULL;//FindItemByClassname("weapon_shotgun");
	AIWeapons[WEAP_SHOTGUN].ammoItem = NULL;//FindItemByClassname("ammo_shells");

	//MACHINEGUN
	AIWeapons[WEAP_MACHINEGUN].aimType = AI_AIMSTYLE_INSTANTHIT;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_MACHINEGUN].RangeWeight[AIWEAP_LONG_RANGE] = 0.3F;
	AIWeapons[WEAP_MACHINEGUN].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.3F;
	AIWeapons[WEAP_MACHINEGUN].RangeWeight[AIWEAP_SHORT_RANGE] = 0.3F;
	AIWeapons[WEAP_MACHINEGUN].RangeWeight[AIWEAP_MELEE_RANGE] = 0.4F;
	/* END */
	AIWeapons[WEAP_MACHINEGUN].weaponItem = NULL;//FindItemByClassname("weapon_machinegun");
	AIWeapons[WEAP_MACHINEGUN].ammoItem = NULL;//FindItemByClassname("ammo_bullets");

	//CHAINGUN
	AIWeapons[WEAP_CHAINGUN].aimType = AI_AIMSTYLE_INSTANTHIT;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_CHAINGUN].RangeWeight[AIWEAP_LONG_RANGE] = 0.4F;
	AIWeapons[WEAP_CHAINGUN].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.6F;
	AIWeapons[WEAP_CHAINGUN].RangeWeight[AIWEAP_SHORT_RANGE] = 0.7F;
	AIWeapons[WEAP_CHAINGUN].RangeWeight[AIWEAP_MELEE_RANGE] = 0.7F;
	/* END */
	AIWeapons[WEAP_CHAINGUN].weaponItem = NULL;//FindItemByClassname("weapon_chaingun");
	AIWeapons[WEAP_CHAINGUN].ammoItem = NULL;//FindItemByClassname("ammo_bullets");

	//GRENADES
	AIWeapons[WEAP_GRENADES].aimType = AI_AIMSTYLE_DROP;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_GRENADES].RangeWeight[AIWEAP_LONG_RANGE] = 0.0F;
	AIWeapons[WEAP_GRENADES].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.0F;
	AIWeapons[WEAP_GRENADES].RangeWeight[AIWEAP_SHORT_RANGE] = 0.2F;
	AIWeapons[WEAP_GRENADES].RangeWeight[AIWEAP_MELEE_RANGE] = 0.2F;
	/* END */
	AIWeapons[WEAP_GRENADES].weaponItem = NULL;//FindItemByClassname("ammo_grenades");
	AIWeapons[WEAP_GRENADES].ammoItem = NULL;//FindItemByClassname("ammo_grenades");

	//ROCKETLAUNCHER
	AIWeapons[WEAP_ROCKETLAUNCHER].aimType = AI_AIMSTYLE_PREDICTION_EXPLOSIVE;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_ROCKETLAUNCHER].RangeWeight[AIWEAP_LONG_RANGE] = 0.2F;	//machinegun is better
	AIWeapons[WEAP_ROCKETLAUNCHER].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.7F;
	AIWeapons[WEAP_ROCKETLAUNCHER].RangeWeight[AIWEAP_SHORT_RANGE] = 0.9F;
	AIWeapons[WEAP_ROCKETLAUNCHER].RangeWeight[AIWEAP_MELEE_RANGE] = 0.6F;
	/* END */
	AIWeapons[WEAP_ROCKETLAUNCHER].weaponItem = NULL;//FindItemByClassname("weapon_rocketlauncher");
	AIWeapons[WEAP_ROCKETLAUNCHER].ammoItem = NULL;//FindItemByClassname("ammo_rockets");

	//WEAP_MAUSER
	AIWeapons[WEAP_RIFLE].aimType = AI_AIMSTYLE_INSTANTHIT;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_RIFLE].RangeWeight[AIWEAP_LONG_RANGE] = 0.9F;
	AIWeapons[WEAP_RIFLE].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.6F;
	AIWeapons[WEAP_RIFLE].RangeWeight[AIWEAP_SHORT_RANGE] = 0.4F;
	AIWeapons[WEAP_RIFLE].RangeWeight[AIWEAP_MELEE_RANGE] = 0.3F;
	/* END */
	AIWeapons[WEAP_RIFLE].weaponItem = NULL;//FindItemByClassname("weapon_railgun");
	AIWeapons[WEAP_RIFLE].ammoItem = NULL;//FindItemByClassname("ammo_slugs");

	//WEAP_FLAMER
	AIWeapons[WEAP_FLAMER].aimType = AI_AIMSTYLE_INSTANTHIT;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_FLAMER].RangeWeight[AIWEAP_LONG_RANGE] = 0.0F;
	AIWeapons[WEAP_FLAMER].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.0F;
	AIWeapons[WEAP_FLAMER].RangeWeight[AIWEAP_SHORT_RANGE] = 0.0F;
	AIWeapons[WEAP_FLAMER].RangeWeight[AIWEAP_MELEE_RANGE] = 0.9F;
	/* END */
	AIWeapons[WEAP_FLAMER].weaponItem = NULL;//FindItemByClassname("weapon_railgun");
	AIWeapons[WEAP_FLAMER].ammoItem = NULL;//FindItemByClassname("ammo_slugs");

	//WEAP_MELEE
	AIWeapons[WEAP_MELEE].aimType = AI_AIMSTYLE_INSTANTHIT;
	/* MetalGod made explicit floats */
	AIWeapons[WEAP_MELEE].RangeWeight[AIWEAP_LONG_RANGE] = 0.0F;
	AIWeapons[WEAP_MELEE].RangeWeight[AIWEAP_MEDIUM_RANGE] = 0.0F;
	AIWeapons[WEAP_MELEE].RangeWeight[AIWEAP_SHORT_RANGE] = 0.0F;
	AIWeapons[WEAP_MELEE].RangeWeight[AIWEAP_MELEE_RANGE] = 0.9F;
	/* END */
	AIWeapons[WEAP_MELEE].weaponItem = NULL;//FindItemByClassname("weapon_railgun");
	AIWeapons[WEAP_MELEE].ammoItem = NULL;//FindItemByClassname("ammo_slugs");
}
