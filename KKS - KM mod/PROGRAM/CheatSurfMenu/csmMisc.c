
/*
	CheatSurfMenu от 26.12.2021 для ККС 1.7.3 (26.11.21)
	Разное
	Основано на меню дебаггера от boal
	26.12.21
*/

int iSND = -1;

string totalInfo, back2totalInfo;
string sPS = "Interface\sobitie_na_karte_001";

void InitInterface(string iniName)
{
	GameInterface.title = "CSM_title_misc";

	SendMessage(&GameInterface, "ls", MSG_INTERFACE_INIT, iniName);

	csmInfoData();
	csmCheatsInfo(9);

	csmFTS("INFO_TEXT", totalInfo);

	SendMessage(&GameInterface, "lsl", MSG_INTERFACE_MSG_TO_NODE, "INFO_TEXT", 5);

	csmSEH("InterfaceBreak", "ProcessBreakExit", 0);
	csmSEH("exitCancel", "ProcessCancelExit", 0);
	csmSEH("evntDoPostExit", "DoPostExit", 0);
	csmSEH("ievnt_command", "ProcCommand", 0);
	csmSEH("SetScrollerPos", "csmSetScrollerPos", 0);
	csmSEH("ScrollPosChange", "csmProcScrollPosChange", 0);
	csmSEH("ScrollTopChange", "csmProcScrollChange", 0);
	csmSEH("MouseRClickUP", "csmHideInfo", 0);
	csmSEH("csmShowInfo", "csmShowInfo", 0);

	csmOnStartEndMenu(0);
}

void ProcessBreakExit()
{
	IDoExit(RC_INTERFACE_ANY_EXIT);
}

void ProcessCancelExit()
{
	IDoExit(RC_INTERFACE_ANY_EXIT);
}

void IDoExit(int exitCode)
{
	csmDEH("InterfaceBreak", "ProcessBreakExit");
	csmDEH("exitCancel", "ProcessCancelExit");
	csmDEH("evntDoPostExit", "DoPostExit");
	csmDEH("ievnt_command", "ProcCommand");
 	csmDEH("SetScrollerPos", "csmSetScrollerPos");
	csmDEH("ScrollPosChange", "csmProcScrollPosChange");
	csmDEH("ScrollTopChange", "csmProcScrollChange");
	csmDEH("MouseRClickUP", "csmHideInfo");
	csmDEH("csmShowInfo", "csmShowInfo");

	interfaceResultCommand = exitCode;

	csmOnStartEndMenu(1);
}

void DoPostExit()
{
	int exitCode = GetEventData();

	IDoExit(exitCode);
}

void csmMenuCommon()
{
	cLog();

	csmHideImages();

	csmStopSND(iSND, -1);

	totalInfo += "\n\n";
}

void csmInfoData()
{
	back2totalInfo = csmB2TI("\n\n");

	if (!csmCA(pchar, "CSM.Welcome"))
	{
		csmSND("Welcome_" + rand(3));
		csmPS("interface\bort_jurnal_001", 0);

		totalInfo = csmMenuText(0);
	}
	else
	{
		totalInfo = csmMenuText(1) +
					"\n\n---------- Изменить дату месяца на 1 день ----------" + NS() +
					"1  > " + descF1 + NS() + "2  > " + descF2 + NS() +
					"\n\n---------- Настройки игры ----------" + NS() +
					"3  > " + descF3 + NS() + "4  > " + descF4 + NS() +
					"\n---------- Вкл \ откл  ----------" + NS() +
					"5  > " + descF5 + NS() + "6  > " + descF6 + NS() +
					"7  > " + descF7 + NS() + "8  > " + descF8 + NS() + "9  > " + descF9 + NS() +
					"\n\n---------- Корабельное ----------" + NS() +
					"10 > " + descF10 + NS() + "11 > " + descF11 + NS() + "12 > " + descF12 + NS() +
					"13 > " + descF13 + NS() + "14 > " + descF14 + NS() + "15 > " + descF15 + NS() +
					"16 > " + descF16 + NS() + "17 > " + descF17 + NS() + "18 > " + descF18 + NS() +
					"19 > " + descF19 + NS() +
					"\n\n---------- Глобальная карта ----------" + NS() +
					"20 > " + descF20 + NS() + "21 > " + descF21 + NS() +
					"22 > " + descF22 + NS() + "23 > " + descF23 + NS() + "24 > " + descF24 + NS() +
					"\n\n25 > " + descF25 + NS() + "26 > " + descF26 + NS() + "27 > " + descF27 + NS() +
					"28 > " + descF28 + NS() + "29 > " + descF29 + NS() + "30 > " + descF30 + NS() +
					"31 > " + descF31 + NS() + "32 > " + descF32 + NS() + "33 > " + descF33 + NS() +
					"34 > " + descF34 + NS() + "35 > " + descF35 + NS() + "36 > " + descF36 + NS() +
					"37 > " + descF37 + NS() + "38 > " + descF38 + NS() + "39 > " + descF39 + NS() +
					"40 > " + descF40 + NS() + "41 > " + descF41 + NS() + "42 > " + descF42 + NS() +
					"43 > " + descF43 + NS() + "44 > " + descF44 + NS() + "45 > " + descF45 + NS() +
					"46 > " + descF46 + NS() + "47 > " + descF47 + NS() + "48 > " + descF48 + NS() +
					"49 > " + descF49 + NS() + "50 > " + descF50 + NS() + "51 > " + descF51 + NS() +
					"52 > " + descF52 + NS() + "53 > " + descF53 + NS() + "54 > " + descF54 + NS() +
					"55 > " + descF55 + NS() + "56 > " + descF56 + NS() + "57 > " + descF57 + NS() +
					"58 > " + descF58 + NS() + "59 > " + descF59 + NS() + "60 > " + descF60 + NS() +
					"61 > " + descF61 + NS() + "62 > " + descF62 + NS() + "63 > " + descF63 + NS() +
					"64 > " + descF64 + NS() + "65 > " + descF65 + NS() + "66 > " + descF66 + NS() +
					"\n\n67 > " + descF67 + NS() + "68 > " + descF68 + NS() + "69 > " + descF69 + NS() + "70 > " + descF70;
	}
}

void ProcCommand()
{
	int i;

	string sCom = GetEventData();
	string sNode = GetEventData();
	string cFunc;

	if (!csmCA(pchar, "CSM.Welcome"))
	{
		csmQFD("csmWelcome", 0.1);
		return;
	}

	if (sCom == "activate" || sCom == "click")
	{
		if (csmHS(sNode, "B_F"))
		{
			for (i = 1; i <= 70; i++)
			{
				if (sNode == "B_F" + i)
				{
					cFunc = "csmInfoDataF" + i;

					call cFunc();

					Statistic_AddValue(pchar, "Cheats.CSM9.F" + i, 1);

					break;
				}
			}
		}
		else
		{
			if (csmHS(sNode, "B_M"))
			{
				for (i = 0; i <= 9; i++)
				{
					if (sNode == "B_M" + i)
					{
						IDoExit(csmRunMenu(i));
						break;
					}
				}
			}
		}
	}

	csmCheatsInfo(9);
}

string descF1 = "вперед";
void csmInfoDataF1()
{
	totalInfo = "#1 Изменить дату месяца на 1 день " + descF1;
	csmMenuCommon();

	LAi_Fade("", "");
	AddDataToCurrent(0, 0, 1);

	csmPS(sPS, 0);
	sLog("Дата текущего месяца изменена на 1 день вперед.");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	ProcessCancelExit();
}

string descF2 = "назад";
void csmInfoDataF2()
{
	totalInfo = "#2 Изменить дату месяца на 1 день " + descF2;
	csmMenuCommon();

	bool bExit = false;

	if (GetDataDay() != 1)
	{
		bExit = true;
		LAi_Fade("", "");
		AddDataToCurrent(0, 0, -1);

		iSND = csmSND("Ahha");
		sLog("Дата текущего месяца изменена на 1 день назад.");
	}
	else
	{
		iSND = csmSND("WTF");
		totalInfo += "В 1-ый день месяца этого сделать нельзя...";
	}

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);

	if (bExit)
		ProcessCancelExit();
}

string descF3 = "Изменить сложность игры";
void csmInfoDataF3()
{
	totalInfo = "#3 " + descF3;
	csmMenuCommon();

	int iS = MOD_SKILL_ENEMY_RATE;
	int iR = MOD_EXP_RATE;

	string sLvl = csmCS("m_Complexity") + ": ";
	string sLvlCur = "Выбранная сложность игры: ";
	string sExp = csmCS("Exp_Rate_Speed") + ": ";
	string sNext = " (чем меньше это значение, тем быстрее растут умения)\nСледующий выбор: ";
	string sLvlN, sLvlX;
	string sLvlA = csmCS("m_Complexity_1");
	string sLvlB = csmCS("m_Complexity_3");
	string sLvlC = csmCS("m_Complexity_5");
	string sLvlD = csmCS("m_Complexity_7");
	string sLvlE = csmCS("m_Complexity_9");
	string sLvl1 = " (очень легко)!\n";
	string sLvl2 = " (легко)!\n";
	string sLvl3 = " (средне)!\n";
	string sLvl4 = " (тяжело)!\n";
	string sLvl5 = " (очень тяжело)!\n";

	if (iS < 2)
		iS = 2;

	if (iS > 10)
		iS = 10;

	switch (iS)
	{
		case 2: iR = 30; iS = 4; sLvlX = sLvlB + sLvl2; sLvlN = sLvlC + sLvl3; break;
		case 4: iR = 50; iS = 6; sLvlX = sLvlC + sLvl3; sLvlN = sLvlD + sLvl4; break;
		case 6: iR = 75; iS = 8; sLvlX = sLvlD + sLvl4; sLvlN = sLvlE + sLvl5; break;
		case 8: iR = 105; iS = 10; sLvlX = sLvlE + sLvl5; sLvlN = sLvlA + sLvl1; break;
		case 10: iR = 15; iS = 2; sLvlX = sLvlA + sLvl1; sLvlN = sLvlB + sLvl2; break;
	}

	MOD_SKILL_ENEMY_RATE = iS;
	MOD_EXP_RATE = iR;

	iSND = csmSND("ReputationGood");
	totalInfo += sLvlCur + sLvlX + sExp + iR + sNext + sLvlN + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF4 = "Сменить тип морского сражения (динамика или тактика)";
void csmInfoDataF4()
{
	totalInfo = "#4 " + descF4;
	csmMenuCommon();

	if (iArcadeSails == 1)
	{
		iArcadeSails = 0;

		iSND = csmSND("Default");
		totalInfo += "Включен режим тактического морского боя.\n\nВнимание!\n\nВсе корабли будут:\n1) гораздо менее маневренными\n2) дольше перезаряжать орудия и работать с парусами";
	}
	else
	{
		iArcadeSails = 1;

		iSND = csmSND("Ahha");
		totalInfo += "Включен режим динамического морского боя (по умолчанию)!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF5 = "дозарядку огнестрела";
void csmInfoDataF5()
{
	totalInfo = "#5 Вкл \ откл " + descF5;
	csmMenuCommon();

	if (bRechargePistolOnLine)
	{
		bRechargePistolOnLine = false;

		iSND = csmSND("Default");
		totalInfo += "Дозарядка огнестрельного оружия отключена.";
	}
	else
	{
		bRechargePistolOnLine = true;

		iSND = csmSND("Ahha");
		totalInfo += "Дозарядка огнестрельного оружия включена!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF6 = "раздел добычи";
void csmInfoDataF6()
{
	totalInfo = "#6 Вкл \ откл " + descF6;
	csmMenuCommon();

	if (bPartitionSet)
	{
		bPartitionSet = false;

		iSND = csmSND("Default");
		totalInfo += "Раздел добычи отключен.";
	}
	else
	{
		bPartitionSet = true;

		iSND = csmSND("Ahha");
		totalInfo += "Раздел добычи включен!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF7 = "вероятность дождей";
void csmInfoDataF7()
{
	totalInfo = "#7 Вкл \ откл " + descF7;
	csmMenuCommon();

	string sI = "Вероятность дождей ";

	if (bRains)
	{
		bRains = 0;

		iSND = csmSND("Default");
		sI += "отключена.\n\nВнимание!\nВылеты игры при дожде исправлены, технической нужды отключать их больше нет.";
	}
	else
	{
		bRains = 1;

		iSND = csmSND("Ahha");
		sI += "включена!";
	}

	totalInfo += sI + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF8 = "возможность захвата колоний";
void csmInfoDataF8()
{
	totalInfo = "#8 Вкл \ откл " + descF8;
	csmMenuCommon();

	bool bEnable = true;

	if (bEnable || csmCA(pchar, "questTemp.Tieyasal_WinEnd"))
	{
		if (bWorldAlivePause)
		{
			bWorldAlivePause = false;

			iSND = csmSND("Ahha");
			totalInfo += "Колонии можно захватывать!\nНации тоже станут захватывать чужие колонии в свои владения.\n\nВажно!\nПри выполнении квестов могут возникнуть нелепые, а то и вовсе тупиковые ситуации!\nДанную опцию лучше активировать после завершения основного сюжета игры.";
		}
		else
		{
			bWorldAlivePause = true;

			iSND = csmSND("Default");
			totalInfo += "Колонии можно только грабить.";
		}
	}
	else
	{
		bWorldAlivePause = true;

		iSND = csmSND("WTF");
		totalInfo += "Во избежание возможных проблем, эта опция доступна лишь после завершения основного сюжета игры.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF9 = "режим Hardcore";
void csmInfoDataF9()
{
	totalInfo = "#9 Вкл \ откл " + descF9;
	csmMenuCommon();

	if (bHardcoreGame)
	{
		bHardcoreGame = false;

		iSND = csmSND("Ahha");
		totalInfo += "Режим Hardcore выключен. Сохраняться можно где угодно.";
	}
	else
	{
		bHardcoreGame = true;

		iSND = csmSND("Hardcore");
		totalInfo += "Внимание!\nВключен режим Hardcore! Сохраняться можно только в церквях!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

// Существенно рассширено Sticksъ -->
string descF10 = "Изменить форму матросов на корабле ГГ (32 варианта)";
void csmInfoDataF10()
{
	totalInfo = "#10 " + descF10;
	csmMenuCommon();

	string sF = "Ahha";
	string message;
	string sMSGe = "английская военная форма";
	string sMSGf = "французская военная форма";
	string sMSGs = "испанская военная форма";
	string sMSGh = "голландская военная форма";
	string sMSGc = ", но на всех не хватило";
	string sTXTa = " (солдаты из ГПК)";
	string sTXTb = " (солдаты из ККС)";
	string sTXTc = " (солдаты из ГПК и ККС)";

	if (!csmCA(pchar, "GenQuest.BoardCrewType")) // добавим аттрибут для переключения типов команд
		pchar.GenQuest.BoardCrewType = 0; // 0 - пусть будет дефолт

	int type = sti(pchar.GenQuest.BoardCrewType);
	type++;

	if (type > 32)
		type = 0;

	totalInfo += type + "/32\n\n";

	switch (type)
	{
		case 0:	message = "обычная матросская форма"; break;
		// Англия
		case 1: message = sMSGe + sTXTa; break;
		case 2: message = sMSGe + sMSGc + sTXTa; break;
		case 3: message = sMSGe + sTXTb; break;
		case 4: message = sMSGe + sMSGc + sTXTb; break;
		case 5: message = sMSGe + sTXTc; break;
		case 6: message = sMSGe + sMSGc + sTXTc; break;
		// Франция
		case 7: message = sMSGf + sTXTa; break;
		case 8: message = sMSGf + sMSGc + sTXTa; break;
		case 9: message = sMSGf + sTXTb; break;
		case 10: message = sMSGf + sMSGc + sTXTb; break;
		case 11: message = sMSGf + sTXTc; break;
		case 12: message = sMSGf + sMSGc + sTXTc; break;
		// Испания
		case 13: message = sMSGs + sTXTa; break;
		case 14: message = sMSGs + sMSGc + sTXTa; break;
		case 15: message = sMSGs + sTXTb; break;
		case 16: message = sMSGs + sMSGc + sTXTb; break;
		case 17: message = sMSGs + sTXTc; break;
		case 18: message = sMSGs + sMSGc + sTXTc; break;
		// Голландия
		case 19: message = sMSGh + sTXTa; break;
		case 20: message = sMSGh + sMSGc + sTXTa; break;
		case 21: message = sMSGh + sTXTb; break;
		case 22: message = sMSGh + sMSGc + sTXTb; break;
		case 23: message = sMSGh + sTXTc; break;
		case 24: message = sMSGh + sMSGc + sTXTc; break;
		// Прочее
		case 25: message = "святая форма"; break;
		case 26: message = "пиратская форма"; break;
		case 27: message = "рвань"; break;
		case 28: message = "форма деловых людей"; break;
		case 29: message = "индейская и людоедская форма"; break;
		case 30: message = "загробная форма"; iSND = csmPS("Types\skel", 0); break;
		case 31: message = "рыбья форма"; sF = "DavyJones"; break;
		case 32: message = "загробная и рыбья форма"; sF = "DavyJones"; break;
	}

	pchar.GenQuest.BoardCrewType = type;

	if (type != 30)
		iSND = csmSND(sF);

	csmPS(sPS, 0);
	totalInfo += "Команде на корабле ГГ выдана " + message + "!" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}
// <--

string descF11 = "Вкл \ выкл продажу кораблей на верфях с установленными орудиями";
void csmInfoDataF11()
{
	totalInfo = "#11 " + descF11;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.AllCannonsShipyardShip"))
	{
		pchar.CSM.AllCannonsShipyardShip = true;

		iSND = csmSND("Ahha");
		totalInfo += "Корабли на верфях продаются с установленными орудиями!";
	}
	else
	{
		csmDA(pchar, "CSM.AllCannonsShipyardShip");

		iSND = csmSND("Default");
		totalInfo += "Корабли на верфях продаются без пушек.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF12 = "Вкл \ выкл выход из строя орудий на корабле ГГ";
void csmInfoDataF12()
{
	totalInfo = "#12 " + descF12;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.NoCannonsBoom"))
	{
		pchar.CSM.NoCannonsBoom = true;

		iSND = csmSND("Ahha");
		totalInfo += "Орудия на корабле ГГ не будут получать никаких повреждений!";
	}
	else
	{
		csmDA(pchar, "CSM.NoCannonsBoom");

		iSND = csmSND("Default");
		totalInfo += "Орудия на корабле ГГ будут повреждаться при стрельбе и от попаданий по ним вражеских снарядов.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF13 = "Вкл \ откл генерацию взрывов и эпидемий на кораблях в море";
void csmInfoDataF13()
{
	totalInfo = "#13 " + descF13;
	csmMenuCommon();

	string sI = "Генерация взрывов и эпидемий на вражеских кораблях в море ";

	if (!csmCA(pchar, "CSM.ShipSituationsOff"))
	{
		pchar.CSM.ShipSituationsOff = true;

//		if (CheckShipSituation_GenQuest()) // 2do: потестить
//			csmDA(pchar,"GenQuest.ShipSituation");

		bSeaCanGenerateShipSituation = false;
		pchar.CanGenerateShipSituation = false;

		iSND = csmSND("Ahha");
		sI += "запрещена!";
	}
	else
	{
		csmDA(pchar, "CSM.ShipSituationsOff");

		bSeaCanGenerateShipSituation = true;
		pchar.CanGenerateShipSituation = true;

		iSND = csmSND("Default");
		sI += "разрешена.";
	}

	totalInfo += sI + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF14 = "Вкл \ откл возможность определения нациями своих флагманских кораблей";
void csmInfoDataF14()
{
	totalInfo = "#14 " + descF14;
	csmMenuCommon();

	string sRefresh = "\nИзменение вступит в силу только после смены игровых суток.";

	if (!csmCA(pchar, "CSM.NoCheckAndIdentifyShips"))
	{
		pchar.CSM.NoCheckAndIdentifyShips = true;

		iSND = csmSND("Medic");
		totalInfo += "Нации не будут опознавать свои флагманские корабли и трубить тревогу!" + sRefresh;
	}
	else
	{
		csmDA(pchar, "CSM.NoCheckAndIdentifyShips");

		iSND = csmSND("Default");
		totalInfo += "Нации опознают свои флагманские корабли и будут трубить тревогу." + sRefresh;
	}

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF15 = "Вкл \ выкл пропажу кораблей ГГ на приколе при разграблении колонии";
void csmInfoDataF15()
{
	totalInfo = "#15 " + descF15;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.NotDeleteShipsInStock"))
	{
		pchar.CSM.NotDeleteShipsInStock = true;

		iSND = csmSND("Ahha");
		totalInfo += "Ваши корабли стоящие на приколе не будут пропадать после разграбления колонии!";
	}
	else
	{
		csmDA(pchar, "CSM.NotDeleteShipsInStock");

		iSND = csmSND("Default");
		totalInfo += "Ваши корабли стоящие на приколе будут пропадать при разграблении колонии...";
	}

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF16 = "Удалить \ добавить кораблю статус 'ворованный' (влияет на стоимость)";
void csmInfoDataF16()
{
	totalInfo = "#16 " + descF16;
	csmMenuCommon();

	ref rMS = csmGRS(pchar);

	if (csmCheckShip(pchar))
	{
		if (rMS.Stolen == true)
		{
			rMS.Stolen = false;

			iSND = csmSND("Ahha");
			totalInfo += "Корабль теперь не ворованный!";
		}
		else
		{
			rMS.Stolen = true;

			iSND = csmSND("Default");
			totalInfo += "Корабль имеет статус 'ворованный'...";
		}
	}
	else
	{
		iSND = csmSND("Default");
		totalInfo += "А где же Ваш корабль, капитан?!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF17 = "Вкл \ выкл проверку типа и кол-ва кораблей для захода в ГПК";
void csmInfoDataF17()
{
	totalInfo = "#17 " + descF17;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.LSCFreeArrival"))
	{
		pchar.CSM.LSCFreeArrival = true;

		iSND = csmSND("Ahha");
		totalInfo += "В ГПК можно заявляться на любом корабле и хоть при полной эскадре!";
	}
	else
	{
		csmDA(pchar, "CSM.LSCFreeArrival");

		iSND = csmSND("Default");
		totalInfo += "В ГПК нельзя зайти на большом корабле или в составе эскадры.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF18 = "Вкл \ выкл возможность заниматься контрабандой на любом корабле";
void csmInfoDataF18()
{
	totalInfo = "#18 " + descF18;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.FreeSmuggling"))
	{
		pchar.CSM.FreeSmuggling = true;

		iSND = csmSND("Ahha");
		totalInfo += "Включена свободная контрабанда!\nНа сделку можно заявляться на любом корабле и хоть при полной эскадре!";
	}
	else
	{
		csmDA(pchar, "CSM.FreeSmuggling");

		iSND = csmSND("Default");
		totalInfo += "Контрабанда выставлена по умолчанию.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF19 = "Освятить корабль";
void csmInfoDataF19()
{
	totalInfo = "#19 " + descF19;
	csmMenuCommon();

	if (!csmCA(pchar, "GenQuest.Shipshine"))
	{
		pchar.GenQuest.Shipshine = true;

		iSND = csmPS("Voice\Russian\priest_bead", 0);
		totalInfo += "Корабль был освящен! Число матросов для найма в тавернах увеличилось вдвое!";
	}
	else
	{
		csmDA(Pchar, "GenQuest.Shipshine");

		iSND = csmSND("Default");
		totalInfo += "Освящение утратило свою силу...";
	}

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

// by Sticksъ -->
string descF20 = "Изменить скорость перемещения всех кораблей";
void csmInfoDataF20()
{
	totalInfo = "#20 " + descF20;
	csmMenuCommon();
    string message = "Скорость всех корабликов на глобальной карте: ";

	if (!csmCA(pchar, "CSM.FastTravelMode"))
	{
		pchar.CSM.FastTravelMode = true;
		worldMap.shipSpeedOppositeWind = 3.0;   // против ветра
		worldMap.shipSpeedOverWind = 3.0;       // по ветру
		message = message + "лютая";
	}
	else
	{
		csmDA(pchar, "CSM.FastTravelMode");
		worldMap.shipSpeedOppositeWind = 0.3;   // как в оригинале
		worldMap.shipSpeedOverWind = 0.8;       // как в оригинале
		message = message + "нормальная";
	}

	iSND = csmPS("Interface\abordage_wining", 0);
	totalInfo += message + "\nАвтор: Sticks";

	if (IsEntity(&worldMap))
		totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!";

	totalInfo += back2totalInfo;
    csmFTS("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
}
// by Sticksъ <--

string descF21 = "Изменить скорость течения времени";
void csmInfoDataF21()
{
	totalInfo = "#21 " + descF21;
	csmMenuCommon();

	float fWMT = stf(worldMap.date.hourPerSec);
	string sDef = " (норма 0.75)";
	string sReduced = "Скорость течения времени на глобальной карте уменьшена и равна: ";
	string sNext = "\nСледующим нажатием выставится значение: ";
	string sNormal = "Скорость течения времени на глобальной карте нормализирована, текущее значение: ";

	switch (fWMT)
	{
		case 1.5:
			fWMT = 1.25;
			totalInfo += sReduced + fWMT + sDef + sNext + "1.0";
		break;
		case 1.25:
			fWMT = 1.0;
			totalInfo += sReduced + fWMT + sDef + sNext + "0.75";
		break;
		case 1.0:
			fWMT = 0.75;
			totalInfo += sReduced + fWMT + sDef + sNext + "0.5";
		break;
		case 0.75:
			fWMT = 0.5;
			totalInfo += sReduced + fWMT + sDef + sNext + "0.25";
		break;
		case 0.5:
			fWMT = 0.25;
			totalInfo += sReduced + fWMT + sNext + "1.5";
		break;
		case 0.25:
			fWMT = 1.5;
			totalInfo += sNormal + fWMT + sNext + "1.25";
		break;
	}

	if (fWMT < 0.1)
		fWMT = 0.1;

	if (fWMT > 1.5)
		fWMT = 1.5;

	worldMap.date.hourPerSec = fWMT;

	if (IsEntity(&worldMap))
		totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!";

	iSND = csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF22 = "Вкл \ откл 'пустую глобалку' (кроме квестовых кораблей)";
void csmInfoDataF22()
{
	totalInfo = "#22 " + descF22;
	csmMenuCommon();

	string sLA = "Все простые корабли, лодки, бочонки и шторм на глобальной карте отключены!";
	string sLB = "Состояние глобальной карты приведено в исходное положение.";

	if (!csmCA(pchar, "CSM.WorldMapEncountersOff"))
	{
		pchar.CSM.WorldMapEncountersOff = true;

		iEncountersRate = 0;

		iSND = csmSND("Ahha");
		totalInfo += sLA + "\nКвестовых кораблей это не касается.";
	}
	else
	{
		csmDA(pchar, "CSM.WorldMapEncountersOff");

		iEncountersRate = 1;
		pchar.worldmapencountersoff = "0";

		iSND = csmSND("Default");
		totalInfo += sLB;
	}

	if (IsEntity(&worldMap))
		totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!";

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF23 = "Вкл \ откл враждебные корабли и шторм";
void csmInfoDataF23()
{
	totalInfo = "#23 " + descF23;
	csmMenuCommon();

	string sL = "Враждебные корабли и шторм на глобальной карте ";

	if (csmCA(pchar, "worldmapencountersoff") && pchar.worldmapencountersoff == "1")
	{
		pchar.worldmapencountersoff = "0";

		iSND = csmSND("Default");
		totalInfo += sL + "включены.";
	}
	else
	{
		pchar.worldmapencountersoff = "1";

		iSND = csmSND("Ahha");
		totalInfo += sL + "отключены!\nКвестовых кораблей это не касается.";
	}

	if (IsEntity(&worldMap) && !csmCA(pchar, "CSM.WorldMapEncountersOff"))
		totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!";

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF24 = "Изменить дальность видимости кораблей";
void csmInfoDataF24()
{
	totalInfo = "#24 " + descF24;
	csmMenuCommon();

	string sL = "Дальность видимости всех кораблей на глобальной карте ";

	if (!csmCA(pchar, "CSM.MapShipDistView"))
	{
		pchar.CSM.MapShipDistView = true;

		worldMap.enemyshipViewDistMin = 980.0;
		worldMap.enemyshipViewDistMax = 999.0;

		iSND = csmSND("Ahha");
		sL += "увеличена!";
	}
	else
	{
		csmDA(pchar, "CSM.MapShipDistView");

		worldMap.enemyshipViewDistMin = 60.0;
		worldMap.enemyshipViewDistMax = 120.0;

		iSND = csmSND("Default");
		sL += "выставлена по умолчанию.";
	}

	totalInfo += sL;

	if (IsEntity(&worldMap))
		totalInfo += "\n\nЧтобы изменения вступили в силу, глобальную карту нужно перезагрузить!";

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF25 = "Узнать текущие цены на товары в магазинах архипелага";
void csmInfoDataF25()
{
	totalInfo = "#25 " + descF25;
	csmMenuCommon();

	ref rC, rXep;

	int iC;

	bBettaTestMode = true;

	rC = GetColonyByIndex(FindColony("Pirates"));

	if (rC != -1)
		SetPriceListByStoreMan(rC);
/*
	// Магаза на базе ГГ пока формально нет
	rXep = csmCID("Islamona_carpenter");

	if (rXep.id != -1 && rXep.dialog.currentnode == "carpenter_17")
	{
		rC = GetColonyByIndex(FindColony("IslaMona"));

		if (rC != -1)
			SetPriceListByStoreMan(rC);
	}
*/
	for (iC = 0; iC < MAX_COLONIES; iC++)
	{
		if (csmCA(&colonies[iC], "StoreNum") && colonies[iC].StoreNum != Pirates_STORE && colonies[iC].StoreNum != IslaMona_STORE)
			SetPriceListByStoreMan(&Colonies[iC]);
	}

	bBettaTestMode = false;

	PlayStereoSound("notebook");
	iSND = csmSND("Goods");
	totalInfo += "Информация по ценам на товары во всех магазинах архипелага обновлена!" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF26 = "Вкл \ откл 100% шанс встретить торговца картой сокровищ";
void csmInfoDataF26()
{
	totalInfo = "#26 " + descF26;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.TreasureMapTrader"))
	{
		pchar.CSM.TreasureMapTrader = true;

		iSND = csmSND("Ahha");
		totalInfo += "Шанс встретить в таверне торговца картой сокровищ 100%!\nЕсли для него есть свободное место, конечно.";
	}
	else
	{
		csmDA(pchar, "CSM.TreasureMapTrader");

		iSND = csmSND("Default");
		totalInfo += "Шанс встретить в таверне торговца картой сокровищ выставлен по умолчанию.";
	}

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF27 = "Вкл \ выкл сбрасывание музыки при смене одинаковых локаций в джунглях";
void csmInfoDataF27()
{
	totalInfo = "#27 " + descF27;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.ContinuousMusic"))
	{
		pchar.CSM.ContinuousMusic = true;

		iSND = csmSND("Ahha");
		totalInfo += "Музыка не будет сбрасываться при смене одинаковых типов локаций в джунглях!";
	}
	else
	{
		csmDA(pchar, "CSM.ContinuousMusic");

		iSND = csmSND("Default");
		totalInfo += "Музыка будет сбрасываться при смене одинаковых типов локаций в джунглях.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF28 = "Вкл \ выкл быстрый переход во вражеских колониях";
void csmInfoDataF28()
{
	totalInfo = "#28 " + descF28;
	csmMenuCommon();

	if (csmCA(pchar, "CSM.FastTravelEnemy"))
	{
		csmDA(pchar, "CSM.FastTravelEnemy");

		iSND = csmSND("Default");
		totalInfo += "Быстрый переход во вражеских поселениях запрещен...";
	}
	else
	{
		pchar.CSM.FastTravelEnemy = true;

		iSND = csmSND("Ahha");
		totalInfo += "Разрешен быстрый переход во всех вражеских поселениях!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF29 = "Вкл \ выкл охотников за головами";
void csmInfoDataF29()
{
	totalInfo = "#29 " + descF29;
	csmMenuCommon();

	if (!csmCA(pchar, "GenQuest.HunterLongPause"))
	{
		pchar.GenQuest.HunterLongPause = true;

		iSND = csmSND("Ahha");
		totalInfo += "ОЗГ запрещены!";
	}
	else
	{
		csmDA(pchar, "GenQuest.HunterLongPause");

		iSND = csmSND("Default");
		totalInfo += "ОЗГ разрешены.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF30 = "Убрать любой таймер с экрана";
void csmInfoDataF30()
{
	totalInfo = "#30 " + descF30;
	csmMenuCommon();

	if (csmCA(pchar, "showTimer"))
	{
		csmDA(pchar, "showTimer");

		iSND = csmSND("Ahha");
		totalInfo += "Таймер был убран!";
	}
	else
	{
		iSND = csmSND("WTF");
		totalInfo += "Никакого таймера нет - убирать нечего...";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF31 = "Вкл \ выкл все предметы в продаже у лоточников";
void csmInfoDataF31()
{
	totalInfo = "#31 " + descF31;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.AllItemsInTrade"))
	{
		pchar.CSM.AllItemsInTrade = true;

		iSND = csmSND("Ahha");
		totalInfo += "У лоточников в продаже появились все предметы!";
	}
	else
	{
		csmDA(pchar, "CSM.AllItemsInTrade");

		iSND = csmSND("Default");
		totalInfo += "Ассортимент товаров у лоточников выставлен по умолчанию.";
	}

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF32 = "Вкл \ выкл все корабли в продаже у верфистов";
void csmInfoDataF32()
{
	totalInfo = "#32 " + descF32;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.AllShipsInTrade"))
	{
		pchar.CSM.AllShipsInTrade = true;

		iSND = csmSND("Ahha");
		totalInfo += "У верфистов в продаже появились все корабли!";
	}
	else
	{
		csmDA(pchar, "CSM.AllShipsInTrade");

		iSND = csmSND("Default");
		totalInfo += "Ассортимент кораблей у верфистов выставлен по умолчанию.";
	}

	csmPS(sPS, 0);
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF33 = "Вкл \ откл счетчик активированных опций в ЧМ";
void csmInfoDataF33()
{
	totalInfo = "#33 " + descF33;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.CMStatsOff"))
	{
		pchar.CSM.CMStatsOff = true;

		totalInfo += "Отображение счётчика активированных опций в ЧМ убрано.";
	}
	else
	{
		csmDA(pchar, "CSM.CMStatsOff");

		totalInfo += "Счётчик активированных опций в ЧМ возвращен.";
	}

	iSND = csmSND("Ahha");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

// by Sticksъ -->
string descF34 = "Изменить направление ветра на море (сбрасывается каждый час)";
void csmInfoDataF34()
{
    totalInfo = "#34 " + descF34;
	csmMenuCommon();

	string sN;

	if (!IsEntity(&worldMap))
	{
		// 0Pi или 2Pi - южный ветер, 0.5Pi - западный, Pi - северный, 1.5Pi - восточный
		Weather.Wind.Angle = stf(Weather.Wind.Angle) + 0.785; // каждый раз добавляем четверть пи
		if (stf(Weather.Wind.Angle) > 6.28)
			Weather.Wind.Angle = 0;
		pchar.wind.angle = Weather.Wind.Angle;
		fWeatherAngle = stf(Weather.Wind.Angle);

		string windDirection;
		float cut = 0.25; // для более точного попадания в диапазон

		if (fWeatherAngle > 5.495 + cut || fWeatherAngle < 0.785 - cut)
		{
			windDirection = "южный";
			sN = "0_n";
		}
		else
		{
			if (fWeatherAngle > 0.0 + cut && fWeatherAngle < 1.57 - cut)
			{
				windDirection = "юго-западный";
				sN = "1_ne";
			}
			else
			{
				if (fWeatherAngle > 0.78 + cut && fWeatherAngle < 2.355 - cut)
				{
					windDirection = "западный";
					sN = "2_e";
				}
				else
				{
					if (fWeatherAngle > 1.57 + cut && fWeatherAngle < 3.14 - cut)
					{
						windDirection = "северо-западный";
						sN = "3_se";
					}
					else
					{
						if (fWeatherAngle > 2.355 + cut && fWeatherAngle < 3.925 - cut)
						{
							windDirection = "северный";
							sN = "4_s";
						}
						else
						{
							if (fWeatherAngle > 3.14 + cut && fWeatherAngle < 4.71 - cut)
							{
								windDirection = "северо-восточный";
								sN = "5_sw";
							}
							else
							{
								if (fWeatherAngle > 3.925 + cut && fWeatherAngle < 5.495 - cut)
								{
									windDirection = "восточный";
									sN = "6_w";
								}
								else
								{
									if (fWeatherAngle > 4.71 + cut && fWeatherAngle < 6.28 - cut)
									{
										windDirection = "юго-восточный";
										sN = "7_nw";
									}
								}
							}
						}
					}
				}
			}
		}

		csmSNP("", "INTERFACES\_CheatSurfMenu_\Compass\" + sN + ".tga", 0);

		iSND = csmPS("Interface\abordage_wining", 0);
		totalInfo += "Ветер переменился на " + windDirection + "!\nНа компасе ниже, красным цветом, указано направление ветра.\nАвтор: Sticks";
	}
    else
	{
		iSND = csmSND("WTF");
		totalInfo += "На глобальной карте не работает...";
	}

	totalInfo += back2totalInfo;
    csmFTS("INFO_TEXT", totalInfo);
    // ProcessCancelExit();
}
// by Sticksъ <--

string descF35 = "Сильный ветер на море (сбрасывается каждый час)";
void csmInfoDataF35()
{
	totalInfo = "#35 " + descF35;
	csmMenuCommon();

	if (!IsEntity(&worldMap))
	{
		Weather.Wind.Speed = 16.0;
		pchar.wind.speed = Weather.Wind.Speed;
		fWeatherSpeed = stf(Weather.Wind.Speed);

		iSND = csmPS("Interface\abordage_wining", 0);
		totalInfo += "Порывы ветра на море составляют: " + stf(fWeatherSpeed);
	}
	else
	{
		iSND = csmSND("WTF");
		totalInfo += "На глобальной карте не работает...";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF36 = "Отключить все партиклы в локации (включатся после перезагрузки)";
void csmInfoDataF36()
{
	totalInfo = "#36 " + descF36;
	csmMenuCommon();

	PauseParticles(true);

	iSND = csmPS(sPS, 0);
	totalInfo += "Партиклы в текущей локации отключены!\nОни снова заработают со сменой локации." + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF37 = "Открыть все острова, выход в море, быстрые переходы и т.д. (юзать в ОЧЕНЬ крайнем случае!)";
void csmInfoDataF37()
{
	totalInfo = "#37 " + descF37;
	csmMenuCommon();

	int i;

	bDisableFastReload = false;
	bQuestDisableMapEnter = false;
	chrDisableReloadToLocation = false;
	bDisableCharacterMenu = false;

	LocatorReloadEnterDisable("Fortfrance_town", "reload5_back", false);
	LocatorReloadEnterDisable("Fortfrance_town", "basement1", false);
	LocatorReloadEnterDisable("Fortfrance_town", "reloadPr1", false);
	LocatorReloadEnterDisable("Charles_townhall", "reload3", false);

	csmDAM(pchar, "", "questTemp.Sharlie.Lock,GenQuest.CannotWait,NoNavyPenalty");

	i = FindColony("Fortfrance");

	csmDA(colonies[i], "DontSetShipInPort");

	for (i = 0; i < MAX_ISLANDS; i++)
	{
		if (!csmCA(&Islands[i], "hidden"))
			Island_SetReloadEnableGlobal(Islands[i].id, true);
	}

	iSND = csmSND("ReputationGood");
	totalInfo += "Все ограничения сняты!" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF38 = "Вкл \ выкл получение достижений в Steam";
void csmInfoDataF38()
{
	totalInfo = "#38 " + descF38;
	csmMenuCommon();

	if (bSteamAchievements)
	{
		bSteamAchievements = false;

		iSND = csmSND("Default");
		totalInfo += "Достижения в Steam отключены...";
	}
	else
	{
		bSteamAchievements = true;

		iSND = csmSND("Ahha");
		totalInfo += "Достижения в Steam включены!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF39 = "Сменить погоду на следующую (+1 час)";
void csmInfoDataF39()
{
	totalInfo = "#39 " + descF39;
	csmMenuCommon();

	CSM_LoadNextWeather();

	iSND = csmPS(sPS, 0);
	totalInfo += "Погода изменена!" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF40 = "Сменить погоду на предыдущую (-1 час)";
void csmInfoDataF40()
{
	totalInfo = "#40 " + descF40;
	csmMenuCommon();

	CSM_LoadPrevWeather();

	iSND = csmPS(sPS, 0);
	totalInfo += "Погода изменена!" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF41 = "Сброс счетчика убитых пиратов в поселениях";
void csmInfoDataF41()
{
	totalInfo = "#41 " + descF41;
	csmMenuCommon();

	if (csmCA(pchar, "GenQuest.Piratekill") && sti(pchar.GenQuest.Piratekill) > 0)
	{
		pchar.GenQuest.Piratekill = 0;

		iSND = csmSND("Ahha");
		totalInfo += "Счётчик убитых пиратов в поселениях сброшен до 0!";
	}
	else
	{
		iSND = csmSND("Default");
		totalInfo += "Счёт убитым пиратам в поселениях равен 0, сбрасывать его незачем.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF42 = "Пустить Золотой флот";
void csmInfoDataF42()
{
	totalInfo = "#42 " + descF42;
	csmMenuCommon();

	isGoldFleet = true;
	GoldMonth = csmCS("target_month_" + GetAddingDataMonth(0, 0, 0));
	AddTemplRumour("Init_GoldFleet", id_counter + 1);
	StartGoldFleet("");

	PlayStereoSound("notebook");
	iSND = csmPS(sPS, 0);
	totalInfo += "Золотой флот вышел из Порто Белло (Мэйн) и взял курс на Гавану (Куба)!" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF43 = "Вернуть камеру к герою, если она за кого-то 'зацепилась'";
void csmInfoDataF43()
{
	totalInfo = "#43 " + descF43;
	csmMenuCommon();

	if (csmCA(pchar, "chr_ai.type") && pchar.chr_ai.type == LAI_TYPE_PLAYER)
	{
		locCameraTarget(pchar);
		locCameraFollow();

		iSND = csmSND("Ahha");
		totalInfo += "Камера возвращена за спину главного героя!";
	}
	else
	{
		iSND = csmSND("Default");
		totalInfo += "Главный герой не находится под управлением игрока.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF44 = "Убрать \ поставить корабли охраны у Тортуги";
void csmInfoDataF44()
{
	totalInfo = "#44 " + descF44;
	csmMenuCommon();

	ref rXep;
	string sLA = "\nИзменение вступит в силу при смене суток.";
	string sLB = "Корабли охраны у Тортуги ";

	rXep = csmCID("Tortuga_Mayor");

	if (rXep.name == "Франсуа" && rXep.lastname == "Левассер")
	{
		if (csmCA(pchar, "questTemp.Sharlie.DelTerGuard"))
		{
			csmDA(pchar, "questTemp.Sharlie.DelTerGuard");

			iSND = csmSND("Default");
			totalInfo += sLB + "возвращены обратно." + sLA;
		}
		else
		{
			pchar.questTemp.Sharlie.DelTerGuard = "true";

			iSND = csmSND("Ahha");
			totalInfo += sLB + "убраны!" + sLA;
		}
	}
	else
	{
		if (!csmCA(pchar, "questTemp.Sharlie.DelTerGuard"))
			pchar.questTemp.Sharlie.DelTerGuard = "true";

		iSND = csmSND("WTF");
		totalInfo += "В данной опции уже нет надобности!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF45 = "Вкл \ выкл логи по квестам, получению опыта и развитию свободных кэпов";
void csmInfoDataF45()
{
	totalInfo = "#45 " + descF45;
	csmMenuCommon();

	string sI = "Ведение логов по квестам, получаемому опыту и развитию свободных капитанов ";

	if (!bExpLogShow || !bPGGLogShow || !bQuestLogShow)
	{
		bExpLogShow = true;
		bPGGLogShow = true;
		bQuestLogShow = true;

		iSND = csmSND("Ahha");
		sI += "включено!";
	}
	else
	{
		bExpLogShow = false;
		bPGGLogShow = false;
		bQuestLogShow = false;

		iSND = csmSND("Default");
		sI += "отключено.";
	}

	csmPS(sPS, 0);
	totalInfo += sI + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF46 = "Улучшить качество отображения моря";
void csmInfoDataF46()
{
	totalInfo = "#46 " + descF46;
	csmMenuCommon();

	string message = "Вариант моря изменен на ";
	string sMod = "\n\nОпция заточена под текстуры неба от Sergg (мод SkyBox).\nНа 'ваниле' картинка может отличаться от задуманной.";

	if (!csmCA(pchar, "CSM.WavesType"))
	{
		pchar.CSM.WavesType = -1; // Размер волн, плотность тумана, и прочее зависят от силы ветра
		SM_WavesEnable();
		message = message + "модифицированный.\nВолны соответствуют силе ветра." + sMod;
	}
	else
	{
		int type = sti(pchar.CSM.WavesType);
		type++;
		pchar.CSM.WavesType = type;

		if (type > SM_TotalWaves)
		{
			csmDA(pchar, "CSM.WavesType");
			SM_WavesDisable();
			message = message + "оригинальный.";
		}
		else
		{
			message = message + "модифицированный.\nВолны не зависят от силы ветра. ";
			if (type == 0) // Случайный тип волны при генерациях окружения
				message = message + "Меняются при смене локаций.";
			else
				message = message + "Тип волны : " + type + ".";
			message += sMod;
		}

	}

	Whr_UpdateWeather();

	if (csmCA(pchar, "CSM.WavesType"))
		totalInfo += sti(pchar.CSM.WavesType) + 3 + "/8\n";
	else
		totalInfo += "1/8\n";

	iSND = csmPS(sPS, 0);
	totalInfo += message + "\n\nАвтор: Sticks" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF47 = "Разрешить \ запретить собирать толпу солдат в помощь (на корабле ГГ, через 'Мысли вслух')";
void csmInfoDataF47()
{
	totalInfo = "#47 " + descF47;
	csmMenuCommon();

	string message = "";
	string info = "";

	if (!csmCA(pchar, "CSM.SquadEnabled"))
	{
		pchar.CSM.SquadEnabled = true;
		message = message + "Для сбора отряда зайдите в каюту и выберете соотв. мыслю.";
		info = "\n\n Качество экипировки людей зависит от количества на корабле грузов: оружие, порох, лекарства, ром, провиант. Чем этих грузов больше, тем более лучшие доспехи, оружие и зелья найдутся для отряда\n\n";

		// заменяем стандартный диалог на модифицированный
		PChar.Dialog.Filename = "MainHero_dialog_Squad.c";
	}
	else
	{
		csmDA(pchar, "CSM.SquadEnabled");
		message = message + "Сбор отряда отключен. Если у вас уже есть отряд, то он будет автоматически распущен.";

		// заменяем стандартный диалог на модифицированный
		PChar.Dialog.Filename = "MainHero_dialog.c";
	}

	iSND = csmPS(sPS, 0);
	totalInfo += message + info + "\nАвтор: Sticks" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF48 = "Больше бандитов в джунглях, дуэльной пьяни, каторжников, индейцев и т.д.";
void csmInfoDataF48()
{
	totalInfo = "#48 " + descF48;
	csmMenuCommon();

	string message = "";

	if (!csmCA(pchar, "CSM.MoreBands"))
	{
		pchar.CSM.MoreBands = true;
		message = message + "Повышенное количество противников.";
		iSND = csmPS("Types\warrior02", 0);
	}
	else
	{
		csmDA(pchar, "CSM.MoreBands");
		message = message + "Обычное количество противников.";
		iSND = csmPS("Types\warrior_dam02", 0);
	}

	totalInfo += message + "\nАвтор: Sticks" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF49 = "Вкл \ выкл ускорение времени всегда и везде";
void csmInfoDataF49()
{
	totalInfo = "#49 " + descF49;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.TimeScaleEnable"))
	{
		pchar.CSM.TimeScaleEnable = true;

		iSND = csmSND("Ahha");
		totalInfo += "Ускорение и замедление времени работает всегда и везде!";
	}
	else
	{
		csmDA(pchar, "CSM.TimeScaleEnable");
		SetTimeScale(1.0);

		iSND = csmSND("Default");
		totalInfo += "Возможность ускорения и замедления времени выставлена по умолчанию.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF50 = "Вкл \ выкл дипломатических агентов в пиратских тавернах";
void csmInfoDataF50()
{
	totalInfo = "#50 " + descF50;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.RelationAgent"))
	{
		pchar.CSM.RelationAgent = true;

		iSND = csmSND("Ahha");
		totalInfo += "В пиратских тавернах будут встречаться дипломатические агенты!";
	}
	else
	{
		csmDA(pchar, "CSM.RelationAgent");

		iSND = csmSND("Default");
		totalInfo += "Дипломатические агенты в пиратских тавернах отключены.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF51 = "Вкл \ выкл торговлю личными вещами в магазинах пиратов";
void csmInfoDataF51()
{
	totalInfo = "#51 " + descF51;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.Merchants"))
	{
		pchar.CSM.Merchants = true;

		iSND = csmSND("Ahha");
		totalInfo += "В пиратских магазинах можно продавать личные вещи!";
	}
	else
	{
		csmDA(pchar, "CSM.Merchants");

		iSND = csmSND("Default");
		totalInfo += "В магазинах пиратов нельзя будет продать личные вещи.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF52 = "Вкл \ выкл новые звуки пушечных выстрелов";
void csmInfoDataF52()
{
	totalInfo = "#52 " + descF52;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.ArtillerySoundMod"))
	{
		pchar.CSM.ArtillerySoundMod = true;

		iSND = csmPS("SticksMod\ArtillerySoundMod\asm_heavy_04", 0);
		totalInfo += "Рандумизатор звуков артиллерии включён!";
	}
	else
	{
		csmDA(pchar, "CSM.ArtillerySoundMod");

		iSND = csmPS("Sea Battles\cannon_fire_11", 0);
		totalInfo += "Рандумизатор звуков артиллерии выключен!";
	}

	totalInfo += "\nАвтор: Sticks" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF53 = "Урегулировать конфликты с жителями ГПК";
void csmInfoDataF53()
{
	totalInfo = "#53 " + descF53;
	csmMenuCommon();

	bool bA = csmCA(loadedLocation, "type") && loadedLocation.type == "LostShipsCity";
	bool bB = csmCA(loadedLocation, "type.LSC") && loadedLocation.type.LSC == true;
	bool bC = csmCA(loadedLocation, "islandId") && loadedLocation.islandId == "LostShipsCity";

	if (bA || bB || bC)
	{
		pchar.GenQuest.NarvalConflict = 0;
		pchar.GenQuest.RivadosConflict = 0;
		pchar.GenQuest.SharkConflict = 0;
		pchar.GenQuest.CitizenConflict = 0;
		csmDAM(pchar, "GenQuest", "CitizenConflict,NarvalConflict,RivadosConflict,SharkConflict");
		LAi_group_SetRelation("LSC_NARVAL", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// мирим с нарвалами
		LAi_group_SetRelation("LSC_RIVADOS", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// мирим с ривадос
		LAi_group_SetRelation("LSC_SHARK", LAI_GROUP_PLAYER, LAI_GROUP_NEITRAL);// мирим с пиратами
		LSC_OpenSanAvgustinDoors();//открыть вход в резиденцию
		LSC_OpenTartarusDoors();//открыть вход в тюрьму
		LocatorReloadEnterDisable("LostShipsCity_town", "reload33", false);// открыть вход к клану ривадос
		LocatorReloadEnterDisable("LostShipsCity_town", "reload48", false);// открыть вход к клану нарвал
		WaitDate("", 0, 0, 0, 0, 5);

		iSND = csmSND("Ahha");
		totalInfo += "Все конфликты с обитателями ГПК улажены!\nАвтор: Krizis";
	}
	else
	{
		iSND = csmSND("WTF");
		totalInfo += "Вы должны находиться в ГПК!";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF54 = "Вкл \ выкл удаление трупов при абордажах";
void csmInfoDataF54()
{
	totalInfo = "#54 " + descF54;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.DontClearDead"))
	{
		pchar.CSM.DontClearDead = true;

		iSND = csmSND("Ahha");
		totalInfo += "Трупы всех павших бойцов не будут исчезать со временем!";
	}
	else
	{
		csmDA(pchar, "CSM.DontClearDead");

		iSND = csmSND("Default");
		totalInfo += "Процесс удаления трупов выставлен по умолчанию.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF55 = "Вкл \ выкл автосбор лута при абордажах";
void csmInfoDataF55()
{
	totalInfo = "#55 " + descF55;
	csmMenuCommon();

	string sT = "Автолутинг при абордаже кораблей и грабеже колоний ";

	csmDEH(EVENT_LOCATION_LOAD, "csmDeleteLootCollectorBox");
	csmDEH(EVENT_LOCATION_UNLOAD, "csmDeleteLootCollectorBox");

	if (!csmCA(pchar, "CSM.LootCollector.Enable"))
	{
		pchar.CSM.LootCollector.Enable = 1;

		csmSEH(EVENT_LOCATION_LOAD, "csmDeleteLootCollectorBox", 0);
		csmSEH(EVENT_LOCATION_UNLOAD, "csmDeleteLootCollectorBox", 0);

		iSND = csmSND("Ahha");
		totalInfo += sT + "включен!\n\nЗапуск сундука со всей добычей доступен в любой момент и в любом месте после окончания боя.\nГорячая клавиша по умолчанию: 'тильда', она же русская 'ё' (можно изменить в настройках игры).";
	}
	else
	{
		csmDA(pchar, "CSM.LootCollector.Enable");

		iSND = csmSND("Default");
		totalInfo += sT + "отключен.";
	}

	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF56 = "Вкл \ выкл режим 'Shotgun'";
void csmInfoDataF56()
{
	totalInfo = "#56 " + descF56;
	csmMenuCommon();

	int i = 0;

	string sI = "Режим 'Shotgun' "; // хз как добавить визуал шотгана, в К2 работает, а тут нет...

	if (globalSGMode)
	{
		iSND = csmSND("Default");
		sI += "отключен.";
	}
	else
	{
		i++;

		iSND = csmSND("Ahha");
		sI += "включен!";
	}

	globalSGMode = i;
	pchar.shotgun = its(i);

	totalInfo += sI + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF57 = "Вкл \ выкл расталкиватель толпы в бою (3 режима)";
void csmInfoDataF57()
{
	totalInfo = "#57 " + descF57;
	csmMenuCommon();

	SM_PusherSwitch();

	if (csmCA(pchar, "CSM.CrowdPusher"))
	{
		switch(sti(pchar.CSM.CrowdPusher))
		{
			case 1: totalInfo += "Толкач толпы: слабый"; break;
			case 2: totalInfo += "Толкач толпы: умеренный"; break;
			case 3: totalInfo += "Толкач толпы: усиленный"; break;
		}

		iSND = csmSND("Ahha");
		totalInfo += "\n\nОтпихивает прочь дружественные или нейтральные НПС, мешающие перемещению ГГ (прочь с дороги)\nБолее плавную работу обеспечивает слабый и умеренный режим.\nУсиленный эффективнее работает с большими толпами.";
		totalInfo += "\n\nВражеские, квестовые и некоторые особые персонажи (грузчики, бомжи, спящие и пр) не отпихиваются.";
	}
	else
	{
		iSND = csmSND("Default");
		totalInfo += "Расталкиватель толпы выключен!";
	}

	totalInfo += "\nАвтор: Sticks" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF58 = "Альтернативный режим стрельбы из пушек (4 режима)";
void csmInfoDataF58()
{
	totalInfo = "#58 " + descF58;
	csmMenuCommon();

	SM_AltFireSwitch();

	if (csmCAM(pchar, "CSM", "AltFire,AltFire.Mode", "&"))
	{
		switch(sti(pchar.CSM.AltFire.Mode))
		{
			case 1: totalInfo += "Беглый огонь: умеренный (DPS близкий к ванили)"; break;
			case 2: totalInfo += "Беглый огонь: ускоренный"; break;
			case 3: totalInfo += "Беглый огонь: читёрский"; break;
		}
		totalInfo += "\n\nКнопка атаки начинает непрерывную очередь по прицелу от вида с палубы, или по ближайшим врагам. Прекращает стрельбу повторное нажатие кл. атаки или смена вида палуба/море.";
	} else
		totalInfo += "Режим стрельбы по умолчанию";

	iSND = csmPS("Sea Battles\cannon_fire_11", 0);
	totalInfo += "\nАвтор: Sticks" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

// Sticks --> Upd: только по пистолям оставил, сабли бох с ними
string descF59 = "Изменить глобальный модификатор урона от огнестрела";
void csmInfoDataF59()
{
	totalInfo = "#59 " + descF59;
	csmMenuCommon();

	float dmg = 0.5;
	string inf = "Умножает урон, наносимый любыми персонажами, в том числе и ГГ, на заданную величину\n\n";
	string message = "Глобальный модификатор урона от пистолей и мушкетов ";

	if (!csmCA(pchar, "CSM.GlobalGunDamageMultipler"))
	{
		pchar.CSM.GlobalGunDamageMultipler = dmg;
		message += "равен x" + pchar.CSM.GlobalGunDamageMultipler;
		iSND = csmPS("Types\warrior02", 0);
	}
	else
	{
		dmg = stf(pchar.CSM.GlobalGunDamageMultipler);
		switch (dmg)
		{
			case 0.5:
				pchar.CSM.GlobalGunDamageMultipler = 0.75;
			break;
			case 0.75:
				pchar.CSM.GlobalGunDamageMultipler = 1.25;
			break;
			case 1.25:
				pchar.CSM.GlobalGunDamageMultipler = 2.0;
			break;
			case 2.0:
				pchar.CSM.GlobalGunDamageMultipler = 3.0;
			break;
			case 3.0:
				pchar.CSM.GlobalGunDamageMultipler = 4.0;
			break;
			case 4.0:
				csmDA(pchar, "CSM.GlobalGunDamageMultipler");
				message += "отключен (по умолчанию)";
				iSND = csmPS("Types\warrior_dam02", 0);
			break;
		}

		if (csmCA(pchar, "CSM.GlobalGunDamageMultipler")) {
			message += "равен x" + pchar.CSM.GlobalGunDamageMultipler;
			iSND = csmPS("Types\warrior02", 0);
		}
	}

	totalInfo += inf + message + "\nАвтор: Sticks" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

//krizis отказ от предложенного задания не запрещает взять другой квест сразу же, как это было в оригинале(ограничения навыков/репутации работают)
string descF60 = "Вкл \ выкл взятие ген-ых квестов без перезагрузки сохранений";
void csmInfoDataF60()
{
	totalInfo = "#60 " + descF60;
	csmMenuCommon();

	if (!csmCA(pchar, "CSM.FreeGiveQuest"))
	{
		pchar.CSM.FreeGiveQuest = true;

		iSND = csmSND("Ahha");
		totalInfo += "Квесты теперь можно брать много раз на дню, без сейвлоадов!";
	}
	else
	{
		csmDA(pchar, "CSM.FreeGiveQuest");

		iSND = csmSND("Default");
		totalInfo += "Квесты нельзя брать много раз на дню без сейвлоадов.";
	}

	totalInfo += "\nАвтор: Krizis" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF61 = "Вкл \ выкл дачу взяток солдатам во вражеских городах";
void csmInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	csmMenuCommon();
	
	if (!csmCA(pchar, "CSM.Bribe"))
	{
		pchar.CSM.Bribe = true;

		iSND = csmSND("Ahha");
		totalInfo += "Солдаты во вражеских поселениях не гнушаются брать взятки!";
	}
	else
	{
		csmDA(pchar, "CSM.Bribe");

		iSND = csmSND("Default");
		totalInfo += "Солдаты мзду не берут - им за державу обидно.";
	}

	totalInfo += "\nАвтор: Krizis" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF62 = "Вкл \ выкл ловушки в сундуках";
void csmInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	csmMenuCommon();

	string sT = "Срабатывание ловушек в сундуках домов ";

	if (!csmCA(pchar, "CSM.NoTraps"))
	{
		pchar.CSM.NoTraps = 1;

		iSND = csmSND("Ahha");
		sT += "отключено!";
	}
	else
	{
		csmDA(pchar, "CSM.NoTraps");

		iSND = csmSND("Default");
		sT += "включено.";
	}

	totalInfo += sT + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF63 = "Изменить положение кнопок ЧМ";
void csmInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	csmMenuCommon();

	if (csmCA(pchar, "CSM.Buttons.Dir"))
		csmDA(pchar, "CSM.Buttons.Dir");
	else
		pchar.CSM.Buttons.Dir = 1;

	iSND = csmSND("Ahha");
	totalInfo += "Положение кнопок в ЧМ изменено на " + csmSetButtonsDir() + "!" + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	IDoExit(RC_INTERFACE_RUN_CSM_MISC);
}

string descF64 = "Кэпы кораблей будут \ не будут сбрасывать товары в море";
void csmInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	csmMenuCommon();

	string sI = "Капитаны вражеских кораблей ";

	if (csmCA(pchar, "CSM.DropGoodsOff"))
	{
		csmDA(pchar, "CSM.DropGoodsOff");

		iSND = csmSND("Default");
		sI += "могут сбрасывать свой груз в море.";
	}
	else
	{
		pchar.CSM.DropGoodsOff = 1;

		iSND = csmSND("Ahha");
		sI += "не смогут сбросить свой груз в море!\nМин это не касается.";
	}

	totalInfo += sI + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF65 = "Вкл \ выкл компактный интерфейс алхимии";
void csmInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	csmMenuCommon();

	string sI = "Компактный интерфейс алхимии ";
	string sF = "WTF";

	if (csmCA(pchar, "CSM.AlchemyCompact"))
	{
		csmDA(pchar, "CSM.AlchemyCompact");

		sF = "Default";
		sI += "отключён.";
	}
	else
	{
		if (csmCD("RESOURCE\INI\INTERFACES\", "alchemy_compact.ini") > 0)
		{
			pchar.CSM.AlchemyCompact = true;

			sF = "Ahha";
			sI += "включён!";
		}
		else
			sI = "Не найден файл: RESOURCE \ INI \ INTERFACES \ alchemy_compact.ini";
	}

	iSND = csmSND(sF);
	totalInfo += sI + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF66 = "Бесконечные слоты для быстрых сохранений (F6) \ по умолчанию";
void csmInfoDataF66()
{
	totalInfo = "#66 " + descF66;
	csmMenuCommon();

	string sR = strcut(&descF66, 0, strlen(descF66) - 20);

	if (csmCA(pchar, "CSM.InfinityQuickSaves"))
	{
		csmDA(pchar, "CSM.InfinityQuickSaves")

		iSND = csmSND("Default");
		sR += "отключены.";
	}
	else
	{
		pchar.CSM.InfinityQuickSaves = true;

		iSND = csmSND("Ahha");
		sR += "включены!\nПо F9 будет загружаться любое самое крайнее сохранение.";
	}

	totalInfo += sR + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF67 = "ПУСТО";
void csmInfoDataF67()
{
	totalInfo = "#67 " + descF67;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF68 = "ПУСТО";
void csmInfoDataF68()
{
	totalInfo = "#68 " + descF68;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF69 = "ПУСТО";
void csmInfoDataF69()
{
	totalInfo = "#69 " + descF69;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF70 = "ПУСТО";
void csmInfoDataF70()
{
	totalInfo = "#70 " + descF70;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}
