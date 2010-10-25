feral_orphan = Creature:new {
	objectName = "@mob/creature_names:dire_cat_feral_orphan",
	socialGroup = "Dire Cat",
	pvpFaction = "",
	faction = "",
	level = 16,
	chanceHit = 0.300000,
	damageMin = 160,
	damageMax = 170,
	range = 0,
	baseXp = 960,
	baseHAM = 1300,
	armor = 0,
	resists = {20,20,0,10,10,0,0,0,-1},
	meatType = "meat_carnivore",
	meatAmount = 65,
	hideType = "hide_bristley",
	hideAmount = 35,
	boneType = "bone_mammal",
	boneAmount = 30,
	milk = 0,
	tamingChance = 0.050000,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE,
	creatureBitmask = PACK + HERD,
	diet = CARNIVORE,

	templates = {},
	lootgroups = {},
	weapons = {},
	attacks = {
		{"stunattack","stunChance=50"}
	}
}

CreatureTemplates:addCreatureTemplate(feral_orphan, "feral_orphan")
