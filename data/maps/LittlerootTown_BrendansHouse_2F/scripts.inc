.set LOCALID_MOM, 1

LittlerootTown_BrendansHouse_2F_MapScripts::
	.byte 0

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, FEMALE, LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_Text_ClockIsStopped:
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom:
	.string "everything's all there on your desk.$"

PlayersHouse_2F_Text_Notebook:
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap:
	.string "HOENN region map.$"








EventScrip_Madre::
	faceplayer
	goto_if_unset FLAG_HABLAR_CON_MADRE, Ya_tienes_La_Baya
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, Que_Zeus_Te_Bendiga_Mujer
	goto_if_eq VAR_RESULT, MALE, Que_Zeus_Te_Bendiga_Hombre
	end

Ya_tienes_La_Baya:
	msgbox Text_Baya_Pregunta, MSGBOX_NPC
	waitmessage
	checkitem ITEM_ORAN_BERRY 
	goto_if_eq VAR_RESULT, TRUE, Gracias_Adios_Madre
	applymovement LOCALID_MOM, Signo
	msgbox Text_Que_Fue_Madre, MSGBOX_NPC
	waitmessage
	end

Gracias_Adios_Madre:
	removeitem ITEM_ORAN_BERRY
	msgbox Text_Adios_Madre
	waitmessage
	applymovement LOCALID_MOM, Corazon
	waitmovement 0
	setflag FLAG_HABLAR_CON_MADRE
    setvar VAR_NO_HE_DADO_BALLA, 1
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, Adios_Hijita
	goto_if_eq VAR_RESULT, MALE, Adios_Hijito
	end

Adios_Hijita:
	msgbox Text_Adios_Hijita, MSGBOX_NPC
	end

Adios_Hijito:
	msgbox Text_Adios_Hijito, MSGBOX_NPC
	end

Que_Zeus_Te_Bendiga_Mujer:
	msgbox Text_Que_Zeus_Te_Bendiga_Mujer, MSGBOX_NPC
	end

Que_Zeus_Te_Bendiga_Hombre:
	msgbox Text_Que_Zeus_Te_Bendiga_Hombre, MSGBOX_NPC
	end

EventScrip_Periodico_Pereza::
	msgbox Text_Periodico_Pereza, MSGBOX_SIGN
	end

EventScrip_InicioDeTodoTrigger::
    lockall
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, Si_Eres_Mujer
	goto_if_eq VAR_RESULT, MALE, Si_Eres_Hombre
	end

Si_Eres_Hombre:
	msgbox Text_Ven_A_Ver, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player1
    waitmovement 0
    msgbox Text_Periodico, MSGBOX_DEFAULT
    waitmessage
    applymovement LOCALID_MOM, Move_Mom1
    waitmovement 0
    msgbox Text_Indignada, MSGBOX_DEFAULT
    waitmessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player2
    waitmovement 0
    msgbox Text_Dinero, MSGBOX_DEFAULT
    applymovement LOCALID_MOM, Move_Mom2
    waitmovement 0
    setvar VAR_INICIO, 1
    releaseall
    end
    
Si_Eres_Mujer:
	lockall
	msgbox Text_Ven_A_Ver_Mujer, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player1
    waitmovement 0
    msgbox Text_Periodico, MSGBOX_DEFAULT
    waitmessage
    applymovement LOCALID_MOM, Move_Mom1
    waitmovement 0
    msgbox Text_Indignada, MSGBOX_DEFAULT
    waitmessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player2
    waitmovement 0
    msgbox Text_Dinero_Mujer, MSGBOX_DEFAULT
    applymovement LOCALID_MOM, Move_Mom2
    waitmovement 0
    setvar VAR_INICIO, 1
    releaseall
    end

EventScrip_InicioDeTodoTrigger1::
    lockall
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, Si_Eres_Mujer1
	goto_if_eq VAR_RESULT, MALE, Si_Eres_Hombre1
	end
    
Si_Eres_Hombre1:
    msgbox Text_Ven_A_Ver, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player11
    waitmovement 0
    msgbox Text_Periodico, MSGBOX_DEFAULT
    waitmessage
    applymovement LOCALID_MOM, Move_Mom1
    waitmovement 0
    msgbox Text_Indignada, MSGBOX_DEFAULT
    waitmessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player2
    waitmovement 0
    msgbox Text_Dinero, MSGBOX_DEFAULT
    applymovement LOCALID_MOM, Move_Mom2
    waitmovement 0
    setvar VAR_INICIO, 1
    releaseall
    end

Si_Eres_Mujer1:
    msgbox Text_Ven_A_Ver_Mujer, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player11
    waitmovement 0
    msgbox Text_Periodico, MSGBOX_DEFAULT
    waitmessage
    applymovement LOCALID_MOM, Move_Mom1
    waitmovement 0
    msgbox Text_Indignada, MSGBOX_DEFAULT
    waitmessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player2
    waitmovement 0
    msgbox Text_Dinero_Mujer, MSGBOX_DEFAULT
    applymovement LOCALID_MOM, Move_Mom2
    waitmovement 0
    setvar VAR_INICIO, 1
    releaseall
    end

EventScrip_InicioDeTodoTrigger2::
    lockall
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, Si_Eres_Mujer2
	goto_if_eq VAR_RESULT, MALE, Si_Eres_Hombre2
	end

Si_Eres_Hombre2:
    msgbox Text_Ven_A_Ver, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player12
    waitmovement 0
    msgbox Text_Periodico, MSGBOX_DEFAULT
    waitmessage
    applymovement LOCALID_MOM, Move_Mom1
    waitmovement 0
    msgbox Text_Indignada, MSGBOX_DEFAULT
    waitmessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player2
    waitmovement 0
    msgbox Text_Dinero, MSGBOX_DEFAULT
    applymovement LOCALID_MOM, Move_Mom2
    waitmovement 0
    setvar VAR_INICIO, 1
    releaseall
    end

Si_Eres_Mujer2:
    msgbox Text_Ven_A_Ver_Mujer, MSGBOX_DEFAULT
    waitmessage
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player12
    waitmovement 0
    msgbox Text_Periodico, MSGBOX_DEFAULT
    waitmessage
    applymovement LOCALID_MOM, Move_Mom1
    waitmovement 0
    msgbox Text_Indignada, MSGBOX_DEFAULT
    waitmessage
    applymovement OBJ_EVENT_ID_PLAYER, Move_Player2
    waitmovement 0
    msgbox Text_Dinero_Mujer, MSGBOX_DEFAULT
    applymovement LOCALID_MOM, Move_Mom2
    waitmovement 0
    setvar VAR_INICIO, 1
    releaseall
    end

Text_Adios_Madre:
	.string "Gracias.\p"
	.string "Esa mirada en tu rostro...\p"
	.string "Entiendo, Dios te guiará en tu camino.\n"
	.string "No olvides de donde vienes y...\p"
	.string "Recuerda que siempre te amaré.$"

Text_Adios_Hijito:
	.string "Adiós hijito.$"

Text_Adios_Hijita:
	.string "Adiós hijita.$"

Text_Que_Fue_Madre:
	.string "¡¿Qué fue?!$"

Text_Baya_Pregunta:
	.string "¿Ya tienes la baya?$"

Text_Que_Zeus_Te_Bendiga_Hombre:
	.string "Que Diosito te bendiga hijito.$"

Text_Que_Zeus_Te_Bendiga_Mujer:
	.string "Que Diosito te bendiga hijita.$"

Text_Ven_A_Ver:
    .string "Hijito ven a ver.$"

Text_Ven_A_Ver_Mujer:
	.string "Hijita ven a ver.$"

Text_Periodico: 
    .string "Usted leyó el periódico.\p"
    .string "La empresa Anatura Ltda. Ha anunciado\n"
    .string "la construcción de un nuevo hotel en\p"
    .string "las Islas Galápagos.\p"
    .string "Pionero en este territorio, posibilitará\n"
    .string "el ingreso turistico al archipielago.\p"
    .string "Han presentado planes de exploración,\n"
    .string "guías turísticas, actividades recreativas\p"
    .string "y por supuesto...\p"
    .string "Captura de los pokémon únicos que\n"
    .string "allí habitan.\p"
    .string "El gobierno ha revisado y aprobado\n"
    .string "todos estos planes,\p"
    .string "así que prepárense para una\n"
    .string "experiencia sin igual.$"

Text_Indignada:
    .string "No puedo creer que esa empresa\n"
    .string "vaya a meterse en nuestra sagrada isla.\p"
    .string "En fin, cuando uno tiene su edad\n"
    .string "de poco sirve indignarse.\p"
    .string "Anda al mercado y trae una baya\n"
    .string "para el almuerzo.$"

Text_Dinero:
    .string "Usted recivió ¥20.\p"
    .string "Que diosito te bendiga hijito.$" 

Text_Dinero_Mujer:
    .string "Usted recivió ¥20.\p"
    .string "Que diosito te bendiga hijita.$" 

Text_Periodico_Pereza:
	.string "Es un periódico, que pereza leerlo\n"
	.string "a leerlo.$"

Move_Player1:
    walk_up
    walk_up
    walk_right
    face_down
    step_end

Move_Mom1:
    face_up
    step_end

Move_Player2:
    walk_right
    face_down
    step_end

Move_Mom2:
    face_left
    step_end
    
Move_Player11:
    walk_right
	walk_up
    walk_right
    face_down
    step_end
 
Move_Player12:
    walk_right
    face_down
    step_end

Signo:
	emote_exclamation_mark
	step_end

Corazon:
	emote_heart
	step_end
	