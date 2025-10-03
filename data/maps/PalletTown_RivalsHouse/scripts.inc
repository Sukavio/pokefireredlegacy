# 1 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 2 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ LOCALID_DAISY,    1
# 3 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ LOCALID_TOWN_MAP, 2
# 4 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 5 "data/maps/PalletTown_RivalsHouse/scripts.pory"
.equ RECEIVED_TOWN_MAP, VAR_TEMP_1
# 6 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 7 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_MapScripts::
# 8 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
# 9 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	.byte 0
# 10 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 11 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_OnTransition::
# 12 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
# 13 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
# 14 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 15 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 16 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
# 17 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
# 18 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setobjectxyperm LOCALID_DAISY, 5, 4
# 19 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	return
# 20 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 21 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
# 22 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar RECEIVED_TOWN_MAP, TRUE
# 23 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	return
# 24 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 25 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Daisy::
# 26 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 27 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	faceplayer
# 28 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 29 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_set FLAG_GOT_HM01, PalletTown_RivalsHouse_EventScript_GroomMon
# 30 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
# 31 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
# 32 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
# 33 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
# 34 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
# 35 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 36 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
# 37 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 38 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 39 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 40 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 41 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_HeardBattledRival::
# 42 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
# 43 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 44 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 45 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 46 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_GroomMon::
# 47 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 48 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special QuestLog_CutRecording
# 49 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 350, PalletTown_RivalsHouse_EventScript_RateMonFriendship
# 50 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
# 51 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
# 52 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
# 53 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special ChoosePartyMon
# 54 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitstate
# 55 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	lock
# 56 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	faceplayer
# 57 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
# 58 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	specialvar VAR_RESULT, GetPartyMonSpecies
# 59 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
# 60 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
# 61 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 62 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 63 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	playfanfare MUS_HEAL
# 64 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitfanfare
# 65 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special DaisyMassageServices
# 66 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 67 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	special BufferMonNickname
# 68 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
# 69 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 70 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 71 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 72 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 73 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_CantGroomEgg::
# 74 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
# 75 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 76 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 77 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 78 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 79 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_DeclineGrooming::
# 80 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
# 81 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 82 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 83 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 84 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 85 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_RateMonFriendship::
# 86 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
# 87 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	specialvar VAR_RESULT, GetLeadMonFriendship
# 88 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	switch VAR_RESULT
# 89 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
# 90 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
# 91 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
# 92 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
# 93 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
# 94 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
# 95 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
# 96 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 97 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 98 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
# 99 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
# 100 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 101 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 102 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 103 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 104 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
# 105 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
# 106 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 107 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 108 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 109 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 110 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
# 111 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
# 112 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 113 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 114 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 115 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 116 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
# 117 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
# 118 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 119 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 120 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 121 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 122 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
# 123 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
# 124 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 125 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 126 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 127 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 128 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
# 129 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
# 130 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 131 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 132 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 133 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 134 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
# 135 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
# 136 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_ForgotTownMap
# 137 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 138 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 139 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 140 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
# 141 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
# 142 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 143 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 144 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 145 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_ForgotTownMap::
# 146 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ForgotTownMap
# 147 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 148 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	checkitemspace ITEM_TOWN_MAP
# 149 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
# 150 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
# 151 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 152 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	removeobject LOCALID_TOWN_MAP
# 153 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
# 154 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 15
# 155 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
# 156 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 157 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 12
# 158 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
# 159 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
# 160 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 161 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 162 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 163 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_GiveTownMap::
# 164 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
# 165 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	closemessage
# 166 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	checkitemspace ITEM_TOWN_MAP
# 167 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
# 168 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
# 169 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 170 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	removeobject LOCALID_TOWN_MAP
# 171 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
# 172 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 15
# 173 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
# 174 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	waitmovement 0
# 175 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	delay 12
# 176 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_OBTAIN_KEY_ITEM
# 177 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 178 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 179 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 180 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
# 181 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
# 182 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 183 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 184 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 185 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_ExplainTownMap::
# 186 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
# 187 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	release
# 188 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 189 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 190 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_TownMap::
# 191 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
# 192 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 193 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 194 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Bookshelf::
# 195 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
# 196 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
# 197 "data/maps/PalletTown_RivalsHouse/scripts.pory"

# 198 "data/maps/PalletTown_RivalsHouse/scripts.pory"
PalletTown_RivalsHouse_EventScript_Picture::
# 199 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
# 200 "data/maps/PalletTown_RivalsHouse/scripts.pory"
	end
