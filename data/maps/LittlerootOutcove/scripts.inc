LittlerootOutcove_MapScripts::
	.byte 0

LittlerootOutcove_Static::
	lockall
	applymovement LOCALID_TREECKO, Common_Movement_FaceLeft
	applymovement LOCALID_BULBASAUR, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TREECKO, Common_Movement_ExclamationMark
	applymovement LOCALID_BULBASAUR, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TREECKO, Common_Movement_Delay48
	applymovement LOCALID_BULBASAUR, Common_Movement_Delay48
	waitmovement 0
	waitse
	playmoncry SPECIES_TREECKO, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_BULBASAUR, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_BULBASAUR, 5, ITEM_VENUSAURITE, SPECIES_TREECKO, 5, ITEM_SCEPTILITE, 
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EventScript_RemoveStatic
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EventScript_RemoveStatic
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, EventScript_RemoveStatic
	release
	end

EventScript_RemoveStatic::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_TREECKO
	removeobject LOCALID_BULBASAUR
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end
