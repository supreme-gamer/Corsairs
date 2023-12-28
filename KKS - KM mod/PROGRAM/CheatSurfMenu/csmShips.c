
/*
	CheatSurfMenu от 26.12.2021 для ККС 1.7.3 (26.11.21)
	Генерация кораблей
	Основано на меню дебаггера от boal
	26.12.21
*/

int iSND = -1;

string totalInfo, back2totalInfo;
string sTextA = " получен и укомплектован морскими волками!";
string sTextB = " получена и укомплектована морскими волками!";

void InitInterface(string iniName)
{
	GameInterface.title = "CSM_title_ships";

	SendMessage(&GameInterface, "ls", MSG_INTERFACE_INIT, iniName);

	csmInfoData();
	csmCheatsInfo(8);

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
					"\n\n********** ПОЛУЧИТЬ УНИКАЛЬНЫЙ КОРАБЛЬ **********" +
					"\n1  > " + descF1 + "\n2  > " + descF2 + "\n3  > " + descF3 +
					"\n4  > " + descF4 + "\n5  > " + descF5 + "\n6  > " + descF6 +
					"\n7  > " + descF7 + "\n8  > " + descF8 + "\n9  > " + descF9 +
					"\n10 > " + descF10 + "\n11 > " + descF11 + "\n12 > " + descF12 +
					"\n13 > " + descF13 + "\n14 > " + descF14 + "\n15 > " + descF15 +
					"\n16 > " + descF16 + "\n17 > " + descF17 + "\n18 > " + descF18 +
					"\n19 > " + descF19 + "\n20 > " + descF20 + "\n21 > " + descF21 +
					"\n22 > " + descF22 + "\n23 > " + descF23 + "\n24 > " + descF24 +
					"\n25 > " + descF25 + "\n26 > " + descF26 + "\n27 > " + descF27 +
					"\n28 > " + descF28 + "\n29 > " + descF29 + "\n30 > " + descF30 + "\n31 > " + descF31 +
					"\n\n********** СГЕНЕРИРОВАТЬ КОРАБЛЬ **********" +
					"\n32 > " + descF32 + "\n33 > " + descF33 +
					"\n34 > " + descF34 + "\n35 > " + descF35 + "\n36 > " + descF36 +
					"\n37 > " + descF37 + "\n38 > " + descF38 + "\n39 > " + descF39 +
					"\n40 > " + descF40 + "\n41 > " + descF41 + "\n42 > " + descF42 +
					"\n43 > " + descF43 + "\n44 > " + descF44 + "\n45 > " + descF45 +
					"\n46 > " + descF46 + "\n47 > " + descF47 + "\n48 > " + descF48 +
					"\n49 > " + descF49 + "\n50 > " + descF50 + "\n51 > " + descF51 +
					"\n52 > " + descF52 + "\n53 > " + descF53 + "\n54 > " + descF54 +
					"\n55 > " + descF55 + "\n56 > " + descF56 + "\n57 > " + descF57 +
					"\n58 > " + descF58 + "\n59 > " + descF59 + "\n60 > " + descF60 +
					"\n61 > " + descF61 +
					"\n\n********** ПРОЧЕЕ **********" +
					"\n62 > " + descF62 + "\n\n63 > " + descF63 + "\n64 > " + descF64 +
					"\n65 > " + descF65 + "\n66 > " + descF66 + "\n67 > " + descF67 +
					"\n68 > " + descF68 + "\n69 > " + descF69 + "\n70 > " + descF70;
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

					Statistic_AddValue(pchar, "Cheats.CSM8.F" + i, 1);

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

	csmCheatsInfo(8);
}

string descF1 = "Чёрная жемчужина";
void csmInfoDataF1()
{
	totalInfo = "#1 " + descF1;

	csmAddShip(SHIP_BLACKPEARL, 5, 5, descF1, "BlackPearl", descF1 + sTextB + "\nАвторы: Bonjourmonami (модель), Legendary Spider (текстуры). Адаптация и доработка: BiGPiMP, Layder", 0);
}

string descF2 = "Летучий голландец";
void csmInfoDataF2()
{
	totalInfo = "#2 " + descF2;

	csmAddShip(SHIP_FDM, 12, 10, descF2, "flyingdutchman_l", descF2 + sTextA + "\nАвтор: ZarethPL (модель). Адаптация для ГПК: BiGPiMP, остров, Prosto_pirat, Layder (иконка)", 0);
}

string descF3 = "Калеуче";
void csmInfoDataF3()
{
	totalInfo = "#3 " + descF3;

	csmAddShip(SHIP_CURSED_FDM, 12, 10, descF3, "flyingdutchman", descF3 + sTextA, 0);
}

string descF4 = "Месть королевы Анны";
void csmInfoDataF4()
{
	totalInfo = "#4 " + descF4;

	csmAddShip(SHIP_QAR, 5, 5, descF4, "QAR", descF4 + sTextB + "\nАвтор: Bonjourmonami (модель). Авторы сборки: Babb и BiGPiMP (адаптация к ГПК), Layder (иконка)", 0);
}

string descF5 = "Мановар 'Мортиферо'";
void csmInfoDataF5()
{
	totalInfo = "#5 " + descF5;

	csmAddShip(SHIP_LSHIP_QUEST, 8, 10, "Мортиферо", "Santisima", descF5 + sTextA, 0);
}

string descF6 = "Королевский мановар 'Солей Руаяль'";
void csmInfoDataF6()
{
	totalInfo = "#6 " + descF6;

	csmAddShip(SHIP_SOLEYRU, 8, 10, "Солей Руаяль", "SoleyRu", descF6 + sTextA, 0);
}

string descF7 = "Линкор 1-го ранга 'Виктори'";
void csmInfoDataF7()
{
	totalInfo = "#7 " + descF7;

	csmAddShip(SHIP_MANOWARV, 8, 10, "Виктори", "ManowarV", descF7 + sTextA, 0);
}

string descF8 = "Быстрый фрегат 'Фортуна'";
void csmInfoDataF8()
{
	totalInfo = "#8 " + descF8;

	csmAddShip(SHIP_FRIGATE_L, 5, 5, "Фортуна", "ArabellaShip", descF8 + sTextA, 0);
}

string descF9 = "Малый фрегат 'Гриффондор'";
void csmInfoDataF9()
{
	totalInfo = "#9 " + descF9;

	csmAddShip(SHIP_CORVETTE_QUEST, 5, 5, "Гриффондор", "corvette_quest", descF9 + sTextA, 0);
}

string descF10 = "Патрульный бриг 'Валькирия'";
void csmInfoDataF10()
{
	totalInfo = "#10 " + descF10;

	csmAddShip(SHIP_VALCIRIA, 4, 5, "Валькирия", "valciria", descF10 + sTextA, 0);
}

string descF11 = "Приватирский кеч 'Мираж'";
void csmInfoDataF11()
{
	totalInfo = "#11 " + descF11;

	csmAddShip(SHIP_MIRAGE, 4, 5, "Мираж", "Mirage", descF11 + sTextA, 0);
}

string descF12 = "Легкая шебека 'Мэйфэнг'";
void csmInfoDataF12()
{
	totalInfo = "#12 " + descF12;

	csmAddShip(SHIP_MAYFANG, 4, 5, "Мэйфэнг", "Mayfang", descF12 + sTextB, 0);
}

string descF13 = "Полакр 'Тореро'";
void csmInfoDataF13()
{
	totalInfo = "#13 " + descF13;

	csmAddShip(SHIP_POLACRE_QUEST, 5, 5, "Тореро", "Polacre_q", descF13 + sTextA, 0);
}

string descF14 = "Фрегат 'Россия'";
void csmInfoDataF14()
{
	totalInfo = "#14 " + descF14;

	csmAddShip(SHIP_ROSSIYA, 5, 5, "Россия", "Rossiya", descF14 + sTextA, 0);
}

string descF15 = "Фрегат 'Сюрприз'";
void csmInfoDataF15()
{
	totalInfo = "#15 " + descF15;

	csmAddShip(SHIP_SURPRISE, 5, 5, "Сюрприз", "Surprise", descF15 + sTextA + "\nАвтор: Jack Harrison (модель). Автор сборки: Black-Max", 0);
}

string descF16 = "Фрегат 'Конституция'";
void csmInfoDataF16()
{
	totalInfo = "#16 " + descF16;

	csmAddShip(SHIP_CONSTITUTION, 6, 5, "Конституция", "Constitution", descF16 + sTextA + "\nАвтор: ZarethPL", 0);
}

string descF17 = "Бриг 'Спиди'";
void csmInfoDataF17()
{
	totalInfo = "#17 " + descF17;

	csmAddShip(SHIP_SPEEDY, 4, 3, "Спиди", "Speedy", descF17 + sTextA + "\nАвтор: pgargon (модель). Авторы сборки: Gekkon, остров", 0);
}

string descF18 = "Корвет 'Пёс войны'";
void csmInfoDataF18()
{
	totalInfo = "#18 " + descF18;

	csmAddShip(SHIP_WARDOG, 5, 5, "Пёс войны", "Corvette_questCoAS", descF18 + sTextA, 0);
}

string descF19 = "Фрегат 'Арабелла'";
void csmInfoDataF19()
{
	totalInfo = "#19 " + descF19;

	csmAddShip(SHIP_ARABELLA, 5, 5, "Арабелла", "ArabellaShipCoAS", descF19 + sTextA, 0);
}

string descF20 = "Фрегат 'Королева'";
void csmInfoDataF20()
{
	totalInfo = "#20 " + descF20;

	csmAddShip(SHIP_FRIGATEQUEEN, 5, 5, "Королева", "FrigateQueen", descF20 + sTextA, 0);
}

string descF21 = "Бриг 'Морской волк'";
void csmInfoDataF21()
{
	totalInfo = "#21 " + descF21;

	csmAddShip(SHIP_BRIGSW, 4, 3, "Морской волк", "BrigSW", descF21 + sTextA, 0);
}

string descF22 = "Бриг 'Королева'";
void csmInfoDataF22()
{
	totalInfo = "#22 " + descF22;

	csmAddShip(SHIP_BRIGQUEEN, 4, 3, "Королева", "BrigQueen", descF22 + sTextA, 0);
}

string descF23 = "Люггер 'Нормандия'";
void csmInfoDataF23()
{
	totalInfo = "#23 " + descF23;

	csmAddShip(SHIP_LUGGERQUEST, 2, 2, "Нормандия", "LuggerQuestCoAS", descF23 + sTextA, 0);
}

string descF24 = "Линкор 4-го ранга 'Центурион'";
void csmInfoDataF24()
{
	totalInfo = "#24 " + descF24;

	csmAddShip(SHIP_CENTURION, 7, 7, "Центурион", "Centurion", descF24 + sTextA, 0);
}

string descF25 = "Линкор 3-го ранга 'Превосходный'";
void csmInfoDataF25()
{
	totalInfo = "#25 " + descF25;

	csmAddShip(SHIP_LESUPERBE, 7, 7, "Превосходный", "LeSuperbe", descF25 + sTextA, 0);
}

string descF26 = "Фрегат 'Эссекс'";
void csmInfoDataF26()
{
	totalInfo = "#26 " + descF26;

	csmAddShip(SHIP_ESSEX, 5, 5, "Эссекс", "Essex", descF26 + sTextA, 0);
}

string descF27 = "Фрегат 'Модаунт'";
void csmInfoDataF27()
{
	totalInfo = "#27 " + descF27;

	csmAddShip(SHIP_MORDAUNT, 5, 5, "Модаунт", "Mordaunt", descF27 + sTextA + "\nАвторы: Sir Deane, Jan Marten", 0);
}

string descF28 = "Тяжёлый фрегат 'Оксфорд'";
void csmInfoDataF28()
{
	totalInfo = "#28 " + descF28;

	csmAddShip(SHIP_OXFORD, 7, 7, "Оксфорд", "Oxford", descF28 + sTextA + "\nАвторы: Sir Deane, Jan Marten", 0);
}

string descF29 = "Линкор 3-го ранга 'Резолюция': новый уник вместо 'Сан Фелипе'";
void csmInfoDataF29()
{
	totalInfo = "#29 " + descF29;

	csmAddShip(SHIP_RESOLUTION, 7, 7, "Резолюция", "Resolution", descF29 + sTextA + "\nАвторы: Sir Deane, Jan Marten", 0);
}

string descF30 = "Линкор 2-го ранга 'Принц'";
void csmInfoDataF30()
{
	totalInfo = "#30 " + descF30;

	csmAddShip(SHIP_PRINCE, 8, 10, "Принц", "Prince", descF30 + sTextA + "\nАвторы: Sir Deane, Jan Marten", 0);
}

string descF31 = "Кеч 'Несравненный'";
void csmInfoDataF31()
{
	totalInfo = "#31 " + descF31;

	csmAddShip(SHIP_Nonsuch, 2, 2, "Несравненный", "Nonsuch", descF31 + sTextA, 0);
}

string descF32 = "Английский флагманский линкор";
void csmInfoDataF32()
{
	totalInfo = "#32 " + descF32;

	csmAddShip(SHIP_LSHIP_ENG, 8, 10, "Виктори", "manowar_e", descF32 + sTextA, 1);
}

string descF33 = "Испанский флагманский линкор";
void csmInfoDataF33()
{
	totalInfo = "#33 " + descF33;

	csmAddShip(SHIP_LSHIP_SPA, 8, 10, "", "manowar", descF33 + sTextA, 1);
}

string descF34 = "Голландский флагманский линкор: в АХЕ это бывший Le Superbe";
void csmInfoDataF34()
{
	totalInfo = "#34 " + descF34;

	csmAddShip(SHIP_LSHIP_HOL, 7, 10, "", "battleship", descF34 + sTextA, 1);
}

string descF35 = "Французский флагманский линкор";
void csmInfoDataF35()
{
	totalInfo = "#35 " + descF35;

	csmAddShip(SHIP_LSHIP_FRA, 7, 10, "", "warship", descF35 + sTextA, 1);
}

string descF36 = "Военный корабль";
void csmInfoDataF36()
{
	totalInfo = "#36 " + descF36;

	csmAddShip(SHIP_LINESHIP, 7, 7, "", "lineship", descF36 + sTextA, 1);
}

string descF37 = "Тяжелый фрегат";
void csmInfoDataF37()
{
	totalInfo = "#37 " + descF37;

	csmAddShip(SHIP_FRIGATE_H, 5, 5, "", "Frigate_h", descF37 + sTextA, 1);
}

string descF38 = "Ост-Индец";
void csmInfoDataF38()
{
	totalInfo = "#38 " + descF38;

	csmAddShip(SHIP_EASTINDIAMAN, 5, 5, "", "eastindiaman", descF38 + sTextA, 1);
}

string descF39 = "Торговый галеон";
void csmInfoDataF39()
{
	totalInfo = "#39 " + descF39;

	csmAddShip(SHIP_NAVIO, 5, 5, "", "navio", descF39 + sTextA, 1);
}

string descF40 = "Фрегат";
void csmInfoDataF40()
{
	totalInfo = "#40 " + descF40;

	csmAddShip(SHIP_FRIGATE, 4, 5, "", "frigate", descF40 + sTextA, 1);
}

string descF41 = "Военный галеон";
void csmInfoDataF41()
{
	totalInfo = "#41 " + descF41;

	csmAddShip(SHIP_GALEON_H, 5, 5, "", "galeon_h", descF41 + sTextA, 1);
}

string descF42 = "Полакр";
void csmInfoDataF42()
{
	totalInfo = "#42 " + descF42;

	csmAddShip(SHIP_POLACRE, 4, 5, "", "Polacre", descF42 + sTextA, 1);
}

string descF43 = "Щебека";
void csmInfoDataF43()
{
	totalInfo = "#43 " + descF43;

	csmAddShip(SHIP_XebekVML, 4, 5, "", "XebekVML", descF43 + sTextB, 1);
}

string descF44 = "Корвет";
void csmInfoDataF44()
{
	totalInfo = "#44 " + descF44;

	csmAddShip(SHIP_CORVETTE, 4, 5, "", "corvette", descF44 + sTextA, 1);
}

string descF45 = "Галеон";
void csmInfoDataF45()
{
	totalInfo = "#45 " + descF45;

	csmAddShip(SHIP_GALEON_L, 4, 5, "", "galeon_l", descF45 + sTextA, 1);
}

string descF46 = "Пинас";
void csmInfoDataF46()
{
	totalInfo = "#46 " + descF46;

	csmAddShip(SHIP_PINNACE, 3, 4, "", "pinnace", descF46 + sTextA, 1);
}

string descF47 = "Каравелла";
void csmInfoDataF47()
{
	totalInfo = "#47 " + descF47;

	csmAddShip(SHIP_CARAVEL, 3, 4, "", "caravel", descF47 + sTextB, 1);
}

string descF48 = "Флейт";
void csmInfoDataF48()
{
	totalInfo = "#48 " + descF48;

	csmAddShip(SHIP_FLEUT, 2, 4, "", "fleut", descF48 + sTextA, 1);
}

string descF49 = "Шнява";
void csmInfoDataF49()
{
	totalInfo = "#49 " + descF49;

	csmAddShip(SHIP_SHNYAVA, 3, 4, "", "shnyava", descF49 + sTextB, 1);
}

string descF50 = "Каракка";
void csmInfoDataF50()
{
	totalInfo = "#50 " + descF50;

	csmAddShip(SHIP_CARACCA, 3, 4, "", "caracca", descF50 + sTextB, 1);
}

string descF51 = "Военная шхуна";
void csmInfoDataF51()
{
	totalInfo = "#51 " + descF51;

	csmAddShip(SHIP_SCHOONER_W, 3, 3, "", "schooner_w", descF51 + sTextB, 1);
}

string descF52 = "Бриг";
void csmInfoDataF52()
{
	totalInfo = "#52 " + descF52;

	csmAddShip(SHIP_BRIG, 3, 3, "", "brig", descF52 + sTextA, 1);
}

string descF53 = "Бригантина";
void csmInfoDataF53()
{
	totalInfo = "#53 " + descF53;

	csmAddShip(SHIP_BRIGANTINE, 3, 2, "", "Brigantine", descF53 + sTextB, 1);
}

string descF54 = "Баркентина";
void csmInfoDataF54()
{
	totalInfo = "#54 " + descF54;

	csmAddShip(SHIP_BARKENTINE, 2, 2, "", "barkentine", descF54 + sTextB, 1);
}

string descF55 = "Торговая шхуна";
void csmInfoDataF55()
{
	totalInfo = "#55 " + descF55;

	csmAddShip(SHIP_SCHOONER, 2, 2, "", "schooner", descF55 + sTextB, 1);
}

string descF56 = "Шлюп";
void csmInfoDataF56()
{
	totalInfo = "#56 " + descF56;

	csmAddShip(SHIP_SLOOP, 2, 2, "", "sloop", descF56 + sTextA, 1);
}

string descF57 = "Курьерский люггер";
void csmInfoDataF57()
{
	totalInfo = "#57 " + descF57;

	csmAddShip(SHIP_CAREERLUGGER, 1, 1, "", "LuggerQuest", descF57 + sTextA, 1);
}

string descF58 = "Люггер";
void csmInfoDataF58()
{
	totalInfo = "#58 " + descF58;

	csmAddShip(SHIP_LUGGER, 1, 1, "", "lugger", descF58 + sTextA, 1);
}

string descF59 = "Барк";
void csmInfoDataF59()
{
	totalInfo = "#59 " + descF59;

	csmAddShip(SHIP_BARQUE, 0, 1, "", "Barque", descF59 + sTextA, 1);
}

string descF60 = "Тартана";
void csmInfoDataF60()
{
	totalInfo = "#60 " + descF60;

	csmAddShip(SHIP_WAR_TARTANE, 0, 1, "", "WarTartane", descF60 + sTextB, 2);
}

string descF61 = "Баркас";
void csmInfoDataF61()
{
	totalInfo = "#61 " + descF61;
	csmMenuCommon();

	csmSNP("", "INTERFACES\Ships\Tartane.tga", 0);

	pchar.Ship.Type = GenerateShipExt(SHIP_TARTANE, true, pchar);

	SetBaseShipData(pchar);
	SetRandomNameToShip(pchar);

	SetCrewQuantityFull(pchar);

	AddCrewMorale(pchar, 100);

	csmCrewExp(pchar, "", "100");

	NullCharacterGoods(pchar);
	RecalculateCargoLoad(pchar);

	csmSG(pchar, "Weapon,Rum,Food,Medicament", "25,5,50", 2);

	iSND = csmSND("ShipBad");
	totalInfo += "Баркас " + sTextA + "\n" + csmGetShipInfo(pchar) + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
}

string descF62 = "Сохранять \ не сохранять текстуры парусов и гербов при смене корабля";
void csmInfoDataF62()
{
	totalInfo = "#62 " + descF62;
	csmMenuCommon();

	string sI = "Текстуры парусов и гербов из ЧМ при смене корабля ";

	if (!csmCA(pchar, "CSM.ShipCosmetic"))
	{
		pchar.CSM.ShipCosmetic = true;

		iSND = csmSND("Ahha");
		sI += "будут сохраняться!";
	}
	else
	{
		csmDA(pchar, "CSM.ShipCosmetic");

		iSND = csmSND("Default");
		sI += "не будут сохраняться.";
	}

	totalInfo += sI + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF63 = "ПУСТО";
void csmInfoDataF63()
{
	totalInfo = "#63 " + descF63;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF64 = "ПУСТО";
void csmInfoDataF64()
{
	totalInfo = "#64 " + descF64;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF65 = "ПУСТО";
void csmInfoDataF65()
{
	totalInfo = "#65 " + descF65;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
	// ProcessCancelExit();
}

string descF66 = "ПУСТО";
void csmInfoDataF66()
{
	totalInfo = "#66 " + descF66;
	csmMenuCommon();

	iSND = csmSND("WTF");
	totalInfo += back2totalInfo;
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

void csmCargoAutoFill(int iQ)
{
	if (iQ < 1)
		iQ = 1;

	if (iQ > 100)
		iQ = 100;

	iQ *= 100;

	csmSG(pchar, "Balls,Rum,Bombs,Grapes,Knippels,Powder,Food,Weapon,Medicament", its(iQ) + "," + its(iQ / 10), 2);
}

void csmAddShip(int iShip, int iCaliber, int iCargo, string sName, string sPic, string sInfo, int iS)
{
	ref rShip;

	string sF = "Ship";

	csmMenuCommon();

	csmSNP("", "INTERFACES\Ships\" + sPic + ".tga", 1);

	pchar.Ship.Type = GenerateShipExt(iShip, true, pchar);

	SetBaseShipData(pchar);
	pchar.Ship.Cannons.Type = iCaliber;

	if (sName == "")
		SetRandomNameToShip(pchar);
	else
		pchar.Ship.Name = sName;

	SetCrewQuantityFull(pchar);
	AddCrewMorale(pchar, 100);
	csmCrewExp(pchar, "", "100");

	csmCargoAutoFill(iCargo);

	if (iS < 1)
		sF += "Good";
	else
	{
		if (iS > 1)
			sF += "Bad";

		CSM_MaximizeCannonsNum(pchar); // Sticks Upd: чтоб не мучиться с перетыком кнопок по апгрейду, добавлением в трюм недостающих пух и их установкой у всех неквестовых.
	}

	if (csmCA(pchar, "CSM.ShipCosmetic"))
	{
		rShip = csmGRS(pchar);

		if (csmCA(pchar, "CSM.SailsTex"))
			SetShipSailsFromFile(pchar, pchar.CSM.SailsTex);

		if (csmCA(pchar, "CSM.GeraldTex"))
			rShip.ShipSails.gerald_name = pchar.CSM.GeraldTex;
	}

	iSND = csmSND(sF);
	totalInfo += sInfo + "\n" + csmGetShipInfo(pchar) + back2totalInfo;
	csmFTS("INFO_TEXT", totalInfo);
}
