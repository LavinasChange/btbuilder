#ifndef __BTCONST_H
#define __BTCONST_H
/*-------------------------------------------------------------------------*\
  <btconst.h> -- Bt Builder constants header file.

  Date      Programmer  Description
  11/20/00  Dennis      Created.
\*-------------------------------------------------------------------------*/

#define BT_SPELLTYPES 32
#define BTSPELLTYPE_SCRYSIGHT      21
#define BTSPELLTYPE_LIGHT          22
#define BTSPELLTYPE_ARMORBONUS     23
#define BTSPELLTYPE_HITBONUS       24
#define BTSPELLTYPE_TRAPDESTROY    25
#define BTSPELLTYPE_DOORDETECT     26
#define BTSPELLTYPE_SUMMONILLUSION 19
#define BTSPELLTYPE_SUMMONMONSTER  18
#define BTSPELLTYPE_REGENBARD      29
extern char *spellTypes[];

#define BT_EFFECTIVERANGES 2
extern char *effectiveRanges[];

#define BT_AREAEFFECT 4
extern char *areaEffect[];

#define BT_DURATION 6
extern char *durations[];

#define BT_MONSTEREXTRADAMAGE 11
extern char *extraDamage[];

#define BT_RANGEDTYPES 4
#define BTRANGEDTYPE_NONE  0
#define BTRANGEDTYPE_FOE   1
#define BTRANGEDTYPE_GROUP 2
#define BTRANGEDTYPE_MAGIC 3
extern char *rangedTypes[];

#define BT_COMBATACTIONS 6
#define BTCOMBATACTION_ATTACK          0
#define BTCOMBATACTION_MOVEANDATTACK   1
#define BTCOMBATACTION_DEPENDENTATTACK 2
#define BTCOMBATACTION_SPECIALATTACK   3
#define BTCOMBATACTION_RANDOM          4
#define BTCOMBATACTION_NOTHING         5
extern char *combatActions[];

#define BT_ITEMTYPES 13
#define BTITEM_HANDWEAPON 1
extern char *itemTypes[];

#define BTTIMESUSABLE_UNLIMITED 255

#define BT_CONDITIONALCOMMANDS 18
#define BTCONDITION_ANYONEITEM      0
#define BTCONDITION_EVERYONEITEM    1
#define BTCONDITION_LASTINPUT       2
#define BTCONDITION_ANSWERYES       3
#define BTCONDITION_LOCALFLAGSET    4
#define BTCONDITION_LOCALFLAGCLEAR  5
#define BTCONDITION_GROUPFACING     6
#define BTCONDITION_MONSTERINPARTY  7
#define BTCONDITION_JOBINPARTY      8
#define BTCONDITION_COUNTERGREATER  10
#define BTCONDITION_COUNTEREQUAL    11
#define BTCONDITION_COMBATWON       12
#define BTCONDITION_GLOBALFLAGSET   13
#define BTCONDITION_GLOBALFLAGCLEAR 14
#define BTCONDITION_RANDOM          15
#define BTCONDITION_RACEINPARTY     16
#define BTCONDITION_CANTAKEGOLD     17
extern char *conditionalCommands[];

#define BT_SPECIALCOMMANDS 61
#define BTSPECIALCOMMAND_STOP             1
#define BTSPECIALCOMMAND_SPIN             2
#define BTSPECIALCOMMAND_GETINPUT         6
#define BTSPECIALCOMMAND_SETLOCALFLAG     7
#define BTSPECIALCOMMAND_CLEARLOCALFLAG   8
#define BTSPECIALCOMMAND_TAKEITEM         9
#define BTSPECIALCOMMAND_GIVEITEM         10
#define BTSPECIALCOMMAND_SELLITEM         11
#define BTSPECIALCOMMAND_PRINT            13
#define BTSPECIALCOMMAND_REGENERATESPELLS 14
#define BTSPECIALCOMMAND_TAKESPELLS       15
#define BTSPECIALCOMMAND_HEALHITPOINTS    16
#define BTSPECIALCOMMAND_DAMAGEHITPOINTS  17
#define BTSPECIALCOMMAND_REGENERATESONGS  18
#define BTSPECIALCOMMAND_TAKESONGS        19
#define BTSPECIALCOMMAND_BACKONE          20
#define BTSPECIALCOMMAND_FORWARDONE       21
#define BTSPECIALCOMMAND_TELEPORT         22
#define BTSPECIALCOMMAND_GUILD            23
#define BTSPECIALCOMMAND_REVIEW           24
#define BTSPECIALCOMMAND_SHOP             25
#define BTSPECIALCOMMAND_TRAP             26
#define BTSPECIALCOMMAND_DRAWPICTURE      27
#define BTSPECIALCOMMAND_CLEARSPECIALAT   28
#define BTSPECIALCOMMAND_SETSPECIALAT     29
#define BTSPECIALCOMMAND_PRINTLABEL       30
#define BTSPECIALCOMMAND_MONSTERJOIN      31
#define BTSPECIALCOMMAND_ALLMONSTERSLEAVE 32
#define BTSPECIALCOMMAND_SETCOUNTER       35
#define BTSPECIALCOMMAND_ADDCOUNTER       36
#define BTSPECIALCOMMAND_SETENCOUNTER     37
#define BTSPECIALCOMMAND_SETNUMENCOUNTER  38
#define BTSPECIALCOMMAND_BEGINCOMBAT      39
#define BTSPECIALCOMMAND_SETGLOBALFLAG    41
#define BTSPECIALCOMMAND_CLEARGLOBALFLAG  42
#define BTSPECIALCOMMAND_GIVEGOLD         43
#define BTSPECIALCOMMAND_GIVEXP           44
#define BTSPECIALCOMMAND_PRESSANYKEY      45
#define BTSPECIALCOMMAND_MONSTERLEAVE     46
#define BTSPECIALCOMMAND_SETDIRECTION     48
#define BTSPECIALCOMMAND_CLEARSPECIAL     49
#define BTSPECIALCOMMAND_SETSPECIAL       50
#define BTSPECIALCOMMAND_CLEARTEXT        52
#define BTSPECIALCOMMAND_TAKEGOLD         53
#define BTSPECIALCOMMAND_DRAWFULLPICTURE  54
#define BTSPECIALCOMMAND_GOTO             57
#define BTSPECIALCOMMAND_SUBTRACTCOUNTER  58
extern char *specialCommands[];

#define  BTSPECIAL_NONE -1

#define BT_DIRECTIONS 4
#define BTDIRECTION_NORTH 0
#define BTDIRECTION_EAST  1
#define BTDIRECTION_SOUTH 2
#define BTDIRECTION_WEST  3
extern char *directions[];

#define BT_MAPTYPES 4
extern char *mapTypes[];

#define BT_STATS 5
#define BTSTAT_MAX 18
#define BTSTAT_ST 0
#define BTSTAT_IQ 1
#define BTSTAT_DX 2
#define BTSTAT_CN 3
#define BTSTAT_LK 4
extern char *statAbbrev[];

#define BTJOB_MONSTER  11
#define BTJOB_ILLUSION 12

#define BT_ITEMS 8
#define BT_PARTYSIZE 7
#define BT_BACK 4

#define BTITEM_NONE 0x4000

#define BTITEM_CANNOTEQUIP 0
#define BTITEM_NOTEQUIPPED 1
#define BTITEM_EQUIPPED    2

#define BTSAVE_DIFFICULTY 20

#define BTSTATUS_DEAD 0

#define BTCOMBAT_MAXENCOUNTERS 4

#define BTTARGET_INDIVIDUAL  0x0FFF
#define BTTARGET_GROUPSHIFT  24
#define BTTARGET_PARTY       1
#define BTTARGET_MONSTER     2

#endif
