kaeline_ungasan_missions =
	{
		{
			missionType = "deliver",
			primarySpawns =
			{
				{ npcTemplate = "flip", planetName = "tatooine", npcName = "Flip" }
			},
			secondarySpawns =	{},
			itemSpawns =
			{
				{ itemTemplate = "object/tangible/mission/quest_item/kaeline_ungasan_q1_needed.iff", itemName = "Datadisc" }
			},
			rewards =
			{
				{ rewardType = "credits", amount = 250 },
			}
		},
		{
			missionType = "confiscate",
			primarySpawns =
			{
				{ npcTemplate = "sil_ondatek", planetName = "tatooine", npcName = "Sil Onda'tek" }
			},
			secondarySpawns =	{},
			itemSpawns =
			{
				{ itemTemplate = "object/tangible/mission/quest_item/kaeline_ungasan_q2_needed.iff", itemName = "Jabba's Enforcers" }
			},
			rewards =
			{
				{ rewardType = "credits", amount = 5000 },
			}
		},
		{
			missionType = "assassinate",
			primarySpawns =
			{
				{ npcTemplate = "assassin", planetName = "tatooine", npcName = "an Assassin" }
			},
			secondarySpawns = {},
			itemSpawns = {},
			rewards =
			{
				{ rewardType = "credits", amount = 7000 },
			}
		},

	}

npcMapKaelineUngasan =
	{
		{
			spawnData = { planetName = "tatooine", npcTemplate = "kaeline_ungasan", x = -2815.58, z = 5, y = 1940.55, direction = 335.154, cellID = 0, position = STAND },
			worldPosition = { x = -2816, y = 1941 },
			npcNumber = 1,
			stfFile = "@static_npc/tatooine/kaeline_ungasan",
			missions = kaeline_ungasan_missions
		},
	}

KaelineUngasan = ThemeParkLogic:new {
	numberOfActs = 1,
	npcMap = npcMapKaelineUngasan,
	className = "KaelineUngasan",
	screenPlayState = "kaeline_ungasan_quest",
	distance = 800,
	missionCompletionMessageStf = "@theme_park/messages:static_completion_message",
}

registerScreenPlay("KaelineUngasan", true)

kaeline_ungasan_mission_giver_conv_handler = mission_giver_conv_handler:new {
	themePark = KaelineUngasan
}
kaeline_ungasan_mission_target_conv_handler = mission_target_conv_handler:new {
	themePark = KaelineUngasan
}