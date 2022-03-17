.set LOCALID_RIVAL, 2

LittlerootTown_MapScripts::
	.byte 0



EventScript_caja::
	msgbox LittlerootTown_Text_RicasBayas, MSGBOX_SIGN
	end

EventScript_Letrero1::
	msgbox LittlerootTown_Text_LetreroSeño, MSGBOX_SIGN
	end

EventScript_Nina::
	lock
	faceplayer
	msgbox LittlerootTown_Text_Buscando, MSGBOX_NPC
	end

EventScript_Seno::
	lock
	faceplayer
	msgbox LittlerootTown_Text_BuenosDías, MSGBOX_NPC
	waitmessage
	pokemart LittlerootTown_Mart_Pokemart
	msgbox LittlerootTown_Text_Gracias, MSGBOX_NPC
	release
	goto_if_unset FLAG_PRIMER_ENCUENTRO_CON_RIVAL, LittlerootTown_EventScript_PrimeraVez
	end

LittlerootTown_EventScript_PrimeraVez:
	setflag FLAG_PRIMER_ENCUENTRO_CON_RIVAL
	addobject LOCALID_RIVAL
	delay 10
	msgbox LittlerootTown_Text_Hermano, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER , Player1
	waitmovement 0
	applymovement 2, Rival_Viene
	waitmovement 0
	msgbox LittlerootTown_Text_QueDice, MSGBOX_DEFAULT
	waitmessage
	applymovement 2, A_Lo_Oscurito
	applymovement OBJ_EVENT_ID_PLAYER, A_Lo_Oscurito
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Player1
	waitmovement 0
	delay 10
	msgbox LittlerootTown_Text_Mensaje, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_Chiste
	goto_if_eq VAR_RESULT, YES, LittlerootTown_Matriculate
	end

LittlerootTown_Chiste:
	msgbox LittlerootTown_Text_Chiste, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_Chiste
	goto_if_eq VAR_RESULT, YES, LittlerootTown_Matriculate
	end

LittlerootTown_Matriculate:
	msgbox LittlerootTown_Text_AsiSeHabla, MSGBOX_DEFAULT
	waitmessage

	msgbox LittlerootTown_Text_VenALaVilla, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 2, Rival_Va_Bait
	waitmovement 0
	msgbox LittlerootTown_Text_PromesaDeMon, MSGBOX_DEFAULT
	waitmessage
	closemessage
	applymovement 2, Rival_Va
	waitmovement 0
	removeobject LOCALID_RIVAL
	setflag FLAG_HIDE_PRIMER_ENCUENTRO_RIVAL
	release
	end

	.align 2
LittlerootTown_Mart_Pokemart:
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_NONE
	release
	end


LittlerootTown_Text_RicasBayas:
	.string "¡Que ricas bayas!$"

LittlerootTown_Text_LetreroSeño:
	.string "Viveres Santa María.$"

LittlerootTown_Text_Buscando:
	.string "Estoy buscando objetos cerca de estos\n"
	.string "Manglares.$"

LittlerootTown_Text_BuenosDías:
	.string "Buenos días Veci.$"

LittlerootTown_Text_Gracias:
	.string "Gracias Veci, regresará.$"

LittlerootTown_Text_Hermano:
	.string "¡ÑA!$"

LittlerootTown_Text_QueDice:
	.string "¿¡QUÉ DICE ÑA!?\n"
	.string "¿Te enteraste de lo de la invasión?\p"
	.string "Esos desgraciados no saben\n"
	.string "con quien se meten.\p"
	.string "Mira, te voy a compartir información\n"
	.string "confidencial.$"

LittlerootTown_Text_Mensaje:
	.string "Estamos montando una organización\n"
	.string "entre varias villas, nos llamamos\p"
	.string "El team Flora.\p"
	.string "Queremos evitar que esos turistas\n"
	.string "entren a toda costa.\p"
	.string "Todo para mantener\n"
	.string "el orden natural de las islas.\p"
	.string "Cuando me dijeron que reclute gente\n"
	.string "inmediatamente pensé en ti.\p"
	.string "¿Así que qué dices?$"

LittlerootTown_Text_Chiste:
	.string "¡JA! Que buen chiste.$"

LittlerootTown_Text_AsiSeHabla:
	.string "Así se habla, toma este papel\n"
	.string "y llénalo con tus datos.\p"
	.string "No te olvides de poner mi nombre\n"
	.string "para que conste que YO te recluté.$\l"

LittlerootTown_Text_VenALaVilla:
	.string "Anda a la villa roca seca,\n"
	.string "cuando llegues sabrás donde es.\p"
	.string "Te espero.$"

LittlerootTown_Text_PromesaDeMon:
	.string "¡Casi lo olvido!\n"
	.string "Podrás tener tu primer\p"
	.string "¡Pokémon!\p"
	.string "Nos vemos.$"

Rival_Viene:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

Player1:
	face_left
	step_end

A_Lo_Oscurito:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

Rival_Va_Bait:
	walk_left
	walk_left
	walk_left
	face_up
	delay_16
	delay_8
	emote_exclamation_mark
	delay_16
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Rival_Va:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

